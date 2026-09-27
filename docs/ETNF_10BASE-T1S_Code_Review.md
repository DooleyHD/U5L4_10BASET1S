# R-Car U5L ETNF(10BASE-T1S) 샘플 코드 분석 — UM·레지스터 맵 대조 리뷰

## 0. 분석 대상과 범위

| 구분 | 자료 | 비고 |
|---|---|---|
| 코드 | `U5L_COM08_ETNF_sample+project.zip` → `U5L_ETNF_01_T1S_COM` (App), `R_driver/ETNF`, `R_device_U5L/ETNF` | ETNF 관련 소스 전부 정독 |
| User's Manual | `r01uh1109ej0100-r-caru5x-etnf.pdf` (R-Car U5x ETNF IP UM, Rev.0.40) | 텍스트 전체 정독 (그림은 텍스트로 추출된 범위만) |
| 레지스터 맵 | `R_device_U5L/cmsis/U5L_UM04pre4_ver0.5.h` (SVD 기반 디바이스 헤더) 중 `ETNF0_inst_0`, `SELB_ETNF0_inst_0` | UM이 "레지스터 상세는 SVD / Appendix_ETNF.xlsx 참조"라고 하므로 이 헤더를 레지스터 맵 기준으로 사용 |

> `Appendix_ETNF.xlsx`(레지스터 리셋값, PHY 메모리 맵)는 Drive에서 찾지 못했습니다. 그래서 **리셋값이 필요한 항목은 "확인 필요"** 로 표시했습니다.

---

## 1. 한 장 요약 (쉽게)

ETNF는 크게 3층입니다.

```
 [App]  App_main.c / App_sub.c / App_interrupt.c / App_ETNF_cfg.c
   │   (프레임 4개를 TX Queue 0~3에 넣고, 수신 후 비교)
   ▼
 [Driver] R_driver_ETNF.c  ──►  ETNF0 레지스터 (0x5CFD_0000)
   │                             ├ AVB-DMAC : 디스크립터로 URAM↔FIFO DMA
   │                             └ E-MAC    : FIFO↔PHY, T1S(반이중)/RMII 선택
   │                          ──►  SELB_ETNF0.T1SCTL0 (0x5CC7_F000) : 내장 T1S PHY 주소/MDIO 경로
   ▼
 [내장 PHY: CT25205 PCS/PMA + PLCA]  ── MDIO(Clause22 + 13/14 간접 Clause45) 로 설정
   │
   ▼ 3-pin OA TC14 인터페이스 (ETS0_TX / ETS0_RX_MDC / ETS0_ED_MDIO)
 [외부 T1S 트랜시버] ── 2-wire 멀티드롭 버스
```

- **PLCA**는 "CAN처럼 한 줄에 여러 노드가 붙는" T1S에서 충돌을 없애려고, 노드 ID 순서대로 발언권(Transmit Opportunity)을 돌리는 방식입니다. ID 0 = 코디네이터(BEACON 송신).
- 샘플의 현재 설정: `APP_COM_MODE = APP_ETNF_AVB_LB` (**MAC 내부 루프백**), `APP_COM_IF = T1S`, TX Queue 0~3에 각각 payload `0x11/0x22/0x33/0x44` 프레임 → 분리 필터(Separation Filter)로 RX Queue 2~5에 1개씩 수신 → 비교.

**결론:** 데모 시나리오(큐당 프레임 1개, 루프백)는 우연히 동작하지만, 드라이버·ISR에 **UM과 어긋나는 치명적 버그가 여러 개** 있습니다. 실제 T1S 버스(다른 노드 존재, 연속 수신)나 모드 전환(Operation→Config, Standby), PHY 읽기에서 **무한 루프·잘못된 포인터·버퍼 오버런**이 날 수 있습니다. 양산 MCAL/미들웨어에 그대로 쓰면 안 됩니다.

---

## 2. 초기화 순서: 코드 vs UM Figure 3.39

| UM Fig 3.39 단계 | 코드 위치 | 판정 |
|---|---|---|
| ① Configuration 모드 전환 | `App_Init_ETNF` → `R_ETNF_ChangeMode(config)` | ✅ (Reset→Config 경로는 정상) |
| ② E-MAC 초기화 (MAHR/MALR→ECMR→RFLR→ECSIPR→PHY init) | `App_InitSetting_EMAC` → `R_ETNF_ConfigEMAC`, T1SCTL0, PHY soft reset | ✅ 순서 일치 (Fig 3.42) |
| ③ **gPTP 클럭 선택 (CCC.CSEL)** | **없음** (`APP_GPTP_CLK` 정의만 있고 미사용) | ❌ 누락 → [M3] |
| ④ DBAT 설정 | `R_ETNF_SetDescBaseAddrTable` | ✅ |
| ⑤ 송신부 설정 (DIC/TIC→TGC→TCCR→CBS) | `App_InitSetting_AVBDMAC_TX` | ⚠️ 코드는 RX를 먼저 하지만 둘 다 Config 모드라 순서 영향 없음 |
| ⑥ 수신부 설정 (DIC/RICx→RCR→RQCi→RPC→SFO→SFPi→SFMi) | `App_InitSetting_AVBDMAC_RX` | ⚠️ RQC/RPC 설정 버그 → [C4] |
| ⑦ DBAT 내용 / 디스크립터 체인 작성 | `R_ETNF_Config_DBAT`, `App_Make_RxDesc/TxDesc` | ⚠️ BE 큐 디스크립터 크기 불일치 → [M2] |
| ⑧ Operation 모드 | `R_ETNF_ChangeMode(operation)` | ✅ |
| ⑨ PHY 설정 (PIR) | `App_ConfigureT1SPHYSetting` (PLCA) | ✅ (AVB_LB 모드에선 생략) |
| ⑩ RE=1, TE=1 | `R_ETNF_Enable_TXRX` | ✅ |

---

## 3. 레지스터 맵 (UM/SVD 기준) 과 샘플 설정값 검증

### 3.1 베이스 주소

| 블록 | 주소 | 코드 | 판정 |
|---|---|---|---|
| ETNF0_inst_0 | `0x5CFD_0000` | `ETNF_inst_0_BASE` | ✅ |
| SELB_ETNF0_inst_0 (T1SCTL0) | `0x5CC7_F000` | `ETNF0_T1S_inst_0_BASE` | ✅ |

`R_driver_ETNF_reg.h`의 오프셋 58개(CCC~CEFCR)를 SVD와 모두 대조했습니다. **오프셋은 전부 일치**합니다. 드라이버에 정의가 없는 레지스터: `EIC/EIS`, `ISS`, `CIE`, `RIEx/RIDx`, `TIE/TID`, `APFTP`, `MPR`, 각종 에러 카운터(`TROC/DCDC/LCC/FRECR/…`). 에러 처리가 없는 이유이기도 합니다 → [m9].

### 3.2 핵심 레지스터 비트 맵과 샘플 값

| 레지스터 (offset) | 비트 필드 (UM/SVD) | 샘플 설정 | 검증 |
|---|---|---|---|
| **CCC** (0x000) | OPC[1:0], GAC[7], DTSR[8], CSEL[17:16] (00:미사용 / 01:clk_chi(내부전용) / 10:Tx clock / 11:gPTP clock), BOC[20], LBME[24], FCE[25] | OPC만 변경, AVB_LB 시 LBME=1 | ❌ CSEL 미설정. 드라이버 enum 값도 1씩 밀려 있음 [M3] |
| **CSR** (0x00C) | OPS[3:0] (0001 Reset / 0010 Config / 0100 Op / 1000 Standby), DTS[8], TPO0-3[19:16], RPO[20], TDUO[21] | 폴링 | ❌ 마스크 0x7 [C3], `CSR != 0` 대기 [C1] |
| **ECMR** (0x500) | PRM[0], **DM[1] (0:T1S 반이중, 1:RMII)**, TE[5], RE[6], TXF[16], RXF[17], PFR[18], ZPF[19], RZPF[20], DPAD[21], RCSC[23], TRCCM[26] | TRCCM=0, DPAD=1(패딩 안 함), DM=T1S (AVB_LB면 RMII), PRM=0 | ✅ 비트 위치 일치 / ⚠️ 리드백 마스크 [m3] |
| **RFLR** (0x508) | RFL[17:0] | 0xFFF (4095 B) | ✅ |
| **ECSIPR** (0x518) | ICDIP[0] | 0 | ✅ |
| **PIR** (0x520) | MDC[0], MMD[1] (1=write), MDO[2], MDI[3] | 비트뱅잉 MDIO | ✅ 비트 일치 / ❌ 읽기 버그 [C5] |
| **MAHR** (0x5C0) / **MALR** (0x5C8) | MA[47:16] / MA[15:0] | 74:90:50:00 / 00:00 (또는 00:01) | ✅ (구조체 주석 "lower/upper"는 반대로 적혀 있으나 값은 맞음) |
| **RCR** (0x090) | EFFS[0], ENCF[1], ESF[3:2], ETS0[4], ETS2[5], RFCL[28:16] (권장 0x1800) | EFFS=1, ENCF=1, ESF=01, ETS0=0, ETS2=1, RFCL=0x1800 | ✅ 값 / ⚠️ 마스크 오타 [m4] |
| **RQC0~4** (0x094~) | 큐당 8bit: RSMr[1:0], UFCCr[5:4], PIAr[6] | 6개 큐 모두 0 | ❌ 루프 버그 [C4] (현재 값이 전부 0이라 증상 없음) |
| **RPC** (0x0B0) | PCNT[10:8], DCNT[23:16] | 0/0 의도 | ❌ RCR 값으로 덮어씀 [C4] |
| **SFO** (0x0FC) | FBP[5:0] | 14 (payload 시작) | ✅ |
| **SFPi** (0x100~) | 필터 s = SFP(2s), SFP(2s+1) | s0~3 = 0x11…/0x22…/0x33…/0x44… (6 byte) | ✅ Config 모드 직접 쓰기 허용 (Operation 중엔 SFV/SFL 사용해야 함) |
| **SFM0/1** (0x1C0/4) | CFM | 0xFFFFFFFF / 0x0000FFFF (6 byte 비교) | ✅ |
| **TGC** (0x300) | TSM0-3[3:0], TQP[5:4], TBD0[9:8], TBD1[13:12], TBD2[17:16], TBD3[21:20] | TQP=00 (Non-AVB, 우선순위 Q3>Q2>Q1>Q0), TBD=2 | ✅ |
| **TCCR** (0x304) | TSRQ0-3[3:0], TFEN[8], TFR[9], MFEN[16], MFR[17] | TFEN=1, MFEN=0 | ✅ (단 CSEL=00이라 타임스탬프 무의미 [M3]) |
| **DIC** (0x350) | DPE1-15[15:1] | **DPE2** | ❌ TX 디스크립터는 DIE=1 사용 → 불일치 [C6] |
| **RIC0** (0x360) | FRE0-17 | 0x3F (큐 0~5) | ✅ |
| **T1SCTL0** (SELB+0x000) | PHY_ADD[4:0], MDIO_SHARE[16], PMA_CFG[24], 예약 [15:5]·[23:17] ("리셋값 그대로 쓰기") | PHY_ADD=2, MDIO_SHARE=1 (RX_MDC/ED_MDIO 공유), PMA_CFG=1(filtered), 예약비트=1 | ⚠️ 예약 비트 리셋값 확인 필요 [m5] |

### 3.3 내장 T1S PHY (MDIO) 레지스터 — UM 5.5.1 대조

주소는 `MMD<<16 | reg` 형식(22bit)이고, 코드는 Clause 22 레지스터 13/14 간접 접근으로 Clause 45에 접근합니다 (UM 5.6).

| 레지스터 | 주소 | UM 비트 | 샘플 값 | 판정 |
|---|---|---|---|---|
| CONTROL | 0x000000 | RESET[15], LOOP[14], LCTL[12], LRST[9] | 리셋 후 LCTL=1 (PCS_LB면 LOOP=1) | ✅ |
| STATUS | 0x000001 | LNOK[5], ANAB[3], LKST[2] (Latch-Low), EXTC[0] | 4비트 모두 1이 될 때까지 대기 | ✅ (단 타임아웃 없음) |
| T1STWEAKS | 0x3F8001 | PKTLOOP[15], ENIE[7], UNJT[6], RXNRZ[3], SCRD[2], NCOLM[1], RXDLY[0] | NCOLM=1, RXDLY=1 (=기본값) | ✅ |
| T1SPLCAEXT | 0x3F8002 | PREN[15], 예약[11]=1 고정, LDEN[1], LDR[0] | bit11=1 | ✅ |
| T1SPMACTRL | 0x2108F9 | PMARST[15], TXDIS[14], LPWR[11], MULT[10] RO, LOOP[0] | PMA_LB면 LOOP=1 | ❌ 외부 OA 트랜시버 사용 시 LOOP 무시됨 [M4] |
| PLCACTRL0 | 0x3FCA01 | EN[15], RST[14] | EN=1 | ✅ |
| PLCACTRL1 | 0x3FCA02 | NCNT[15:8], ID[7:0] | Master: NCNT=9, ID=0 / Slave: ID=1 | ✅ |
| T1STXCCTL | 0x3F8005 | CMD[1:0] (00 NORQ / 11 RESETRQ) | RESETRQ → NORQ | ✅ |

> MDIO 주소 0에는 응답하지 않습니다 (UM 5.5). 그래서 `PHY_ADD=2`를 쓰는 것은 맞습니다.

---

## 4. 발견 사항 (심각도 순)

🔴 **Critical**: 멈춤/크래시/메모리 파손 가능 · 🟠 **Major**: 기능 오동작 · 🟡 **Minor**: 품질/유지보수

### 🔴 C1. Operation→Config 전환에서 무한 루프
- **위치:** `R_driver/ETNF/R_driver_ETNF.c:128` `while( rETNFnCSR(n) != 0 );`
- **이유:** CSR에는 OPS[3:0]가 항상 들어 있습니다 (Operation 모드면 0100B). 그래서 CSR이 0이 될 수 없습니다.
- **UM:** Fig 3.41. 기다려야 할 조건은 **RPO=0, TPO0-3=0, TDUO=0** 입니다.
- **수정:** `while( (rETNFnCSR(n) & 0x003F0000UL) != 0 );` (TPO0-3 = bit19:16, RPO = bit20, TDUO = bit21)

### 🔴 C2. Config 모드 도달 판정에 OPC enum과 OPS 값을 비교
- **위치:** `R_driver_ETNF.c:141` `R_ETNF_Get_CurrentMode(n) != ETNF_e_OPC_config_mode`
- **이유:** OPS의 Config 값은 `0010B = 2`이고 `ETNF_e_OPC_config_mode = 1` 입니다. 그래서 항상 "실패"로 판정되어, 필요 없는 재시도 경로(Operation으로 되돌린 뒤 다시 Config)를 탑니다.
- **수정:** `ETNF_e_OPS_config_mode`와 비교해야 합니다.

### 🔴 C3. 모드 상태 마스크가 3bit라 Standby 전환 시 영구 대기
- **위치:** `R_driver/ETNF/R_driver_ETNF.h:617, 635` `& 0x00000007`
- **이유:** OPS는 [3:0]이고 Standby 값은 `1000B`입니다. `& 0x7` 하면 0이 되어 `WaitModeChenge(standby)`가 끝나지 않습니다.
- **수정:** `& 0x0000000F`

### 🔴 C4. `R_ETNF_Config_AVBDMAC_Rx` 의 RQC/RPC 설정 오류
- **위치:** `R_driver_ETNF.c:389, 437-441`
- **증상 1:** `queue = config_rxq->queue;` 를 루프 밖에서 한 번만 계산합니다. 그래서 6개 큐의 설정이 모두 **큐 0 슬롯에 OR** 됩니다. 현재 샘플은 RSM/UFCC/PIA가 전부 0이라 증상이 없지만, UFCC(미읽음 프레임 카운터 정지 레벨)나 PIA를 쓰는 순간 오동작합니다.
- **증상 2:** RPC에 `DCNT/PCNT`를 쓴 직후 `Reg32WRC(&RPC, value, …)`로 **RCR 값(0x1800_0027)** 을 다시 씁니다. 예약 비트[31:24]에 0x18이 들어가 UM의 "예약 비트는 리셋값으로 쓰기" 규칙을 위반합니다.
- **수정:** 루프 안에서 `queue = config_rxq->queue;`로 계산하고, RPC는 계산값 변수로 한 번만 쓰도록 합니다. `Reg32WRC` 반환값도 `ret`에 누적해야 합니다.

### 🔴 C5. PHY 레지스터 읽기 결과가 초기화되지 않은 변수
- **위치:** `R_driver_ETNF.c:743` `uint16_t read;` → `:781` `read |= …`
- **영향:** 스택에 남아 있던 값이 섞입니다. 그래서 PHY 리셋 완료 대기(`bit15==0`)나 PLCA STATUS 대기 루프가 **무한 대기하거나 잘못 통과**할 수 있습니다 (최적화 레벨에 따라 달라짐).
- **수정:** `uint16_t read = 0U;`

### 🔴 C6. TX 디스크립터 인터럽트 처리 로직 붕괴 (현재는 다른 버그에 가려져 있음)
- **위치:** `App_interrupt.c:150-160`, `:215`, `App_ETNF_cfg.h:109`, `App_sub.c:501`
- 문제 1: `break;`가 `if` 밖에 있어 DPF15만 검사하고 루프를 빠져나옵니다. 그 결과 `tx_desc`와 `int_index`가 **초기화되지 않은 채** 사용되고, 쓰레기 포인터를 역참조합니다.
- 문제 2: 읽을 때는 `ETNF_CurrTxDesc[i]`, 쓸 때는 `ETNF_CurrTxDesc[int_index-1]`로 인덱스 기준이 다릅니다. `R_ETNF_CurrentTxDescSetting`은 `[DIE-1]`에 저장합니다.
- 문제 3: TX 큐 4개가 모두 `DIE=1`이라, `ETNF_CurrTxDesc[0]`을 마지막 큐가 덮어씁니다.
- 문제 4: `DIC`는 **DPE2**만 켜고, 디스크립터는 **DIE=1**을 씁니다. 그래서 TX 인터럽트가 아예 발생하지 않고, 위 버그들이 드러나지 않습니다. 누군가 DIC를 DPE1로 "고치는" 순간 크래시가 납니다.
- **UM 3.1.2.7:** 큐별 인터럽트를 쓰려면 `TIS.TDPFt`/`RIS3.RDPFr`를 쓰고 DPE1은 끄라고 권고합니다. 큐마다 다른 DIE를 쓰거나 큐별 인터럽트로 바꾸는 것을 권장합니다.

### 🔴 C7. MNG ISR 연산자 우선순위 오류 (현재 벡터 미연결)
- **위치:** `App_interrupt.c:241` `if( ( Lul & (TFUF|TFWF) != 0 ) )`
- `!=`가 `&`보다 먼저 계산되어 결과가 `Lul & 1`, 즉 FTF0 검사가 됩니다. `LulCompareUnit`도 초기화되지 않은 채 쓰일 수 있습니다.
- 벡터 테이블에서 INTETNF0MNG는 `IntFunc_dummy`라 현재는 죽은 코드입니다 (`vecttable_pe0.s:369`).

### 🟠 M1. RX ISR이 LINKFIX를 따라가지 않음 → 큐당 두 번째 프레임부터 처리 불가
- **위치:** `App_interrupt.c:117` (LINK/LEMPTY만 처리)
- **UM Fig 3.17:** SW 흐름은 `LINK, LINKFIX → SWdescr = SWdescr.DPTR` 입니다.
- 샘플 RX 체인은 `[FEMPTY][LINKFIX→처음]` 구조입니다. 첫 프레임을 처리한 뒤 `ETNF_CurrRxDesc`가 LINKFIX를 가리킨 채 멈춥니다. 다음 인터럽트에서는 while 조건(FSINGLE…)이 거짓이라 **데이터를 버립니다**. 데모는 큐마다 프레임이 1개뿐이라 통과합니다.

### 🟠 M2. Best Effort 큐의 디스크립터 크기 불일치 (Normal 8B vs Extended 20B)
- **UM 3.1.7.1 / 3.1.2.6:** 타임스탬프를 쓰는 큐는 Extended(20B), 쓰지 않는 큐는 Normal(8B)로 HW가 처리합니다. **NC(큐1)는 항상 Extended**, BE(큐0)는 `RCR.ETS0`를 따르고 스트림은 `ETS2`를 따릅니다.
- 샘플은 `ETS0=0`인데 `App_RxDescQueue_BE`를 Extended 배열로 선언했습니다 (`App_ETNF_cfg.c:212`). HW는 +8 위치(TS0=0, DT=0 → Invalid)를 다음 디스크립터로 읽고, `App_Handle_Rx`는 TS0~TS2(+8~+19)를 써서 이웃 디스크립터를 덮어씁니다 (`App_interrupt.c:445`).
- **영향:** 필터와 매칭되지 않는 프레임(실제 버스의 다른 노드 트래픽)이 BE 큐로 들어오면 체인이 깨집니다.
- **수정:** BE를 Normal 디스크립터로 분리하거나 `ETS0=1`로 맞춥니다.

### 🟠 M3. gPTP 클럭(CCC.CSEL) 미설정 + enum 값 오류
- UM Fig 3.39는 CSEL 설정을 초기화 필수 단계로 둡니다. 샘플은 설정하지 않아 CSEL=00(미사용)입니다. 그런데 `ETS2=1`, `TFEN=1`, TX `TSR=1`로 타임스탬프를 요구하므로 **타임스탬프 값이 무의미**합니다.
- `R_driver_ETNF_reg.h:187-188`: `ETNF_e_CSEL_tx_clock=1`은 실제로 **01B = clk_chi(내부 전용)** 이고, `ETNF_e_CSEL_gPTP_clock=2`는 실제로 **10B = Ethernet Tx clock** 입니다. 값이 한 칸씩 밀려 있으니 `tx_clock=2`, `gPTP_clock=3`으로 고쳐야 합니다.

### 🟠 M4. PMA 루프백 모드는 이 하드웨어 구성에서 동작하지 않음
- **UM 5.5.1.9 CAUTION:** 외부 OA 트랜시버와 함께 쓰면 `T1SPMACTRL.LOOP`는 **무시**되고, 루프백은 트랜시버 쪽에서 켜야 합니다.
- U5L은 ETS0_TX/RX_MDC/ED_MDIO로 외부 TC14 트랜시버를 쓰는 구성입니다. 그래서 `APP_ETNF_PMA_LB` 경로(`App_sub.c:596`)로는 검증이 되지 않습니다.

### 🟠 M5. 수신 결과 버퍼 오버런
- `App_interrupt.c:435`: `if( SIZE < pos )`는 pos==530을 허용하고, 루프 인덱스 `i`는 되감기지 않아 `App_RxData[530]`에 **범위 밖 쓰기**가 일어납니다. `<=`로 바꾸고 인덱스를 `pos` 기준으로 통일해야 합니다.
- `App_interrupt.c:402`: `App_RxTs[App_RxCount]`(크기 6)에 경계 검사가 없습니다. 멀티드롭 T1S 버스에서 다른 노드의 프레임이 오면 넘칩니다.

### 🟠 M6. 스트림 RX 버퍼 배열 범위 밖 포인터
- `App_sub.c:59` `App_RxBuffer_ST[APP_NUM_RXQ-2]`(4행)인데, `:413` 루프는 `APP_NUM_RXQ`(6)까지 돌아 i=4,5에서 범위 밖 주소를 DPTR로 씁니다. 현재는 DBAT에 연결되지 않아 증상이 없습니다.

### 🟠 M7. RMII 빌드 시 컴파일 에러
- `App_sub.c:217` `R_ETNF_WritePhyReg( n, ETH_PHY_RESET, APP_RMIIPHY_DADDR );` 는 인자가 3개입니다 (필요한 것은 4개). PHY 주소와 값의 위치도 바뀌어 있습니다.
- 올바른 형태: `R_ETNF_WritePhyReg(n, APP_RMIIPHY_DADDR, ETH_PHY_CONTROL_REG_ID, ETH_PHY_RESET);`

### 🟡 Minor
| # | 위치 | 내용 |
|---|---|---|
| m1 | `R_driver_ETNF.c:979` | EtherType 바이트 순서가 반대입니다. `ET1 = type & 0xFF`라서 0x9000이 선로에 `00 90`으로 나갑니다 (네트워크 바이트 순서는 Big-endian). 루프백에서는 대칭이라 드러나지 않지만 타 장비와 통신하면 틀립니다. |
| m2 | `App_sub.c:207`, `R_driver_ETNF.c:378/430/441` | `Reg32WRC` 리드백 결과를 버립니다. 레지스터 리드백 검증(FuSa 관점 안전 메커니즘)이 사실상 무효입니다. |
| m3 | `R_driver_ETNF.c:234` | ECMR 리드백 마스크 `0x04BF00C3`에 예약 bit7과 RE(bit6)가 들어가 있습니다. 의도는 `0x04BF0003`입니다. |
| m4 | `R_driver_ETNF.c:378` | 마스크 `0x01FFF003F`(16진 9자리) 오타입니다. 값이 우연히 `0x1FFF003F`와 같아서 동작합니다. |
| m5 | `R_driver_ETNF.c:264-268` | T1SCTL0 예약 비트[23:17]·[15:5]에 1을 씁니다. UM은 "리셋값으로 쓰기"라고 하는데 리셋값은 Appendix_ETNF.xlsx에만 있어 **확인이 필요**합니다. 주석은 "14 to 5"지만 실제로는 15:5를 설정하며, 이것이 UM 예약 영역과 일치합니다. |
| m6 | `R_driver_ETNF.c:87` | 주석은 "DTS=0까지 대기"인데 코드는 DTS=1을 기다립니다. **코드가 맞습니다** (UM Fig 3.40). |
| m7 | `R_driver_ETNF.h:605`, `App_interrupt.c:53` | 프로토타입 이름(`_IntFunc…`)과 정의 이름(`IntFunc…`)이 다릅니다. `#pragma interrupt … channel=`은 RH850(CC-RH) 문법이라 Cortex-M33/GCC에서는 무시됩니다 (벡터 테이블이 실제 연결 지점). `ETNF_s_frame`이 `union`이라 SA/DA/ET가 겹칩니다 (미사용). |
| m8 | `R_driver_ETNF.c:562` | MDC 주기를 CPU 루프(1000회)로 만듭니다. 클럭이 바뀌면 IEEE 802.3 Clause 22 상한(2.5 MHz)을 넘을 수 있으니 타이머 기반으로 바꾸기를 권장합니다. |
| m9 | 전역 | **모든 폴링 루프에 타임아웃이 없습니다** (모드 전환, PHY 리셋, PLCA 상태, `App_RxCount` 대기). `INTETNF0ERR`는 dummy라 `ESR/EIS/RIS2(QFF)` 에러 처리도 없습니다. 차량용(ISO 26262)으로 쓰려면 타임아웃과 에러 보고, DEM 연계가 필요합니다. |
| m10 | `App_main.c:74-92` | RxTx 분기의 P13_7 핸드셰이크에 `#if (NORMAL && T1S)` 가드가 없습니다. 그래서 루프백 모드에서 RxTx를 고르면 GPIO 입력을 영원히 기다립니다. |
| m11 | UM 자체 | ECMR.ZPF 설명에 "(DM = 1) … in T1S mode"라고 되어 있지만 DM=0이 T1S입니다. **UM 표기 오류로 보이며 Renesas 확인이 필요**합니다. 드라이버 enum 주석도 같은 표기를 따릅니다. |
| m12 | UM 확인 불가 | RIS0/DIS/TIS 플래그를 지우는 방식(0 쓰기)이 UM/SVD 본문에 명시되어 있지 않습니다. R-Car AVB 관례(write-0-clear)와 코드는 일치하지만 Appendix로 확인이 필요합니다. |

---

## 5. 수정 우선순위 제안

1. **C5 (PHY read 초기화)**, **C1/C2/C3 (모드 전환)**: 각각 한두 줄 수정이고, 무한 대기를 없애는 효과가 큽니다.
2. **M1 + M2 + M5**: 실제 T1S 버스(다중 노드, 연속 수신)에서 반드시 문제가 됩니다. RX 경로는 UM Fig 3.17 흐름대로 다시 작성하는 것을 권장합니다.
3. **C6**: TX 완료 통지를 쓸 계획이면 큐별 인터럽트(TIS.TDPFt) 구조로 다시 설계합니다.
4. **M3**: gPTP나 타임스탬프를 쓰려면 CSEL 설정과 enum 수정이 필수입니다.
5. **C4, m2~m4**: 리드백 검증을 살려 FuSa 근거로 쓸 수 있게 정리합니다.
6. **m9**: 양산 적용 시 타임아웃과 에러 인터럽트 처리를 추가합니다.

---

## 6. 확인이 필요한 항목 (자료 부족)
- `Appendix_ETNF.xlsx` (레지스터 리셋값, PHY 메모리 맵): T1SCTL0 예약 비트 리셋값과 인터럽트 플래그 클리어 방식.
- AVB_LB + T1S 조합(현재 기본 설정)에서 DM=RMII로 바꾸는데, RMII REFCLK 핀은 열지 않습니다. UM 3.1.10은 "루프백 시 Tx clock 또는 RMII ref clock 공급 필요"라고 합니다. 실보드에서 이 조합이 동작했다면 내부 클럭이 공급되는 것으로 보이지만, 제품 UM의 클럭 섹션으로 확인해야 합니다.
