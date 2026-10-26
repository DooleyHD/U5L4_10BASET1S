/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name    : R_driver_RSCANFD_reg.h
* Version      : 1.00
* Module(s)    : RSCANFD
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : Register definition of RSCANFD that is used commonly by RH850 and
*                R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef __R_driver_RSCANFD_reg_H__
#define __R_driver_RSCANFD_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "R_device_RSCANFD.h"       /* Product-specific definition */


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define rRSCFDnCFDCmNCFG(n,m)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0000 + (m)*0x0010))         /* Channel m Nominal Bit Rate Configuration Register */
#define rRSCFDnCFDCmCTR(n,m)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0004 + (m)*0x0010))         /* Channel m Control Register */
#define rRSCFDnCFDCmSTS(n,m)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0008 + (m)*0x0010))         /* Channel m Status Register */
#define rRSCFDnCFDCmERFL(n,m)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x000C + (m)*0x0010))         /* Channel m Error Flag Register */
#define rRSCFDnCFDGIPV(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0080))                      /* Global IP Version Register */
#define rRSCFDnCFDGCFG(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0084))                      /* Global Configuration Register */
#define rRSCFDnCFDGCTR(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0088))                      /* Global Control Register */
#define rRSCFDnCFDGSTS(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x008C))                      /* Global Status Register */
#define rRSCFDnCFDGERFL(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0090))                      /* Global Error Flag Register */
#define rRSCFDnCFDGTSC(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0094))                      /* Global Timestamp Counter Register */
#define rRSCFDnCFDGAFLECTR(n)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0098))                      /* Global Acceptance Filter List Entry Control Register */
#define rRSCFDnCFDGAFLCFGv(n,v)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x009C + (v)*0x0004))         /* Global Acceptance Filter List Configuration Register v */
#define rRSCFDnCFDRMNB(n)           (*(volatile uint32_t *) (RSCFDn_base(n) + 0x00AC))                      /* Receive Message Buffer Number Register */
#define rRSCFDnCFDRMNDt(n,t)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x00B0 + (t)*0x0004))         /* Receive Message Buffer New Data Register t */
#define rRSCFDnCFDRFCCx(n,x)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x00C0 + (x)*0x0004))         /* Receive FIFO Configuration / Control Register x */
#define rRSCFDnCFDRFSTSx(n,x)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x00E0 + (x)*0x0004))         /* Receive FIFO Status Register x */
#define rRSCFDnCFDRFPCTRx(n,x)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0100 + (x)*0x0004))         /* Receive FIFO Pointer Control Register x */
#define rRSCFDnCFDCFCCk(n,k)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0120 + (k)*0x0004))         /* Transmit/Receive FIFO Configuration / Control Register k */
#define rRSCFDnCFDCFCCEk(n,k)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0180 + (k)*0x0004))         /* Transmit/Receive FIFO Configuration / Control Enhancement Register k */
#define rRSCFDnCFDCFSTSk(n,k)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x01E0 + (k)*0x0004))         /* Transmit/Receive FIFO Status Register k */
#define rRSCFDnCFDCFPCTRk(n,k)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0240 + (k)*0x0004))         /* Transmit/Receive FIFO Pointer Control Register k */
#define rRSCFDnCFDFESTS(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02A0))                      /* FIFO Empty Status Register */
#define rRSCFDnCFDFFSTS(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02A4))                      /* FIFO Full Status Register */
#define rRSCFDnCFDFMSTS(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02A8))                      /* FIFO Message Lost Status Register */
#define rRSCFDnCFDRFISTS(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02AC))                      /* Receive FIFO Interrupt Flag Status Register */
#define rRSCFDnCFDCFRISTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02B0))                      /* Transmit/Receive FIFO Receive Interrupt Flag Status Register */
#define rRSCFDnCFDCFTISTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02B4))                      /* Transmit/Receive FIFO Transmit Interrupt Flag Status Register */
#define rRSCFDnCFDCFOFRISTS(n)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02B8))                      /* Transmit/Receive FIFO One Frame Receive Interrupt Flag Status Register */
#define rRSCFDnCFDCFOFTISTS(n)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02BC))                      /* Transmit/Receive FIFO One Frame Transmit Interrupt Flag Status Register */
#define rRSCFDnCFDCFMOWSTS(n)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02C0))                      /* Transmit/Receive FIFO Message Over Write Status Register */
#define rRSCFDnCFDFFFSTS(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x02C4))                      /* FIFO FDC Level Full Status Register */
#define rRSCFDnCFDTMCp(n,p)         (*(volatile uint8_t  *) (RSCFDn_base(n) + 0x02D0 + (p)*0x0001))         /* Transmit Message Buffer Control Register p */
#define rRSCFDnCFDTMSTSp(n,p)       (*(volatile uint8_t  *) (RSCFDn_base(n) + 0x07D0 + (p)*0x0001))         /* Transmit Message Buffer Status Register p */
#define rRSCFDnCFDTMTRSTSy(n,y)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0CD0 + (y)*0x0004))         /* Transmit Message Buffer Transmission Request Status Register y */
#define rRSCFDnCFDTMTARSTSy(n,y)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0D70 + (y)*0x0004))         /* Transmit Message Buffer Transmission Abort Request Status Register y */
#define rRSCFDnCFDTMTCSTSy(n,y)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0E10 + (y)*0x0004))         /* Transmit Message Buffer Transmission Completion Status Register y */
#define rRSCFDnCFDTMTASTSy(n,y)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0EB0 + (y)*0x0004))         /* Transmit Message Buffer Transmission Abort Status Register y */
#define rRSCFDnCFDTMIECy(n,y)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x0F50 + (y)*0x0004))         /* Transmit Message Buffer Interrupt Enable Configuration Register y */
#define rRSCFDnCFDTXQCC0m(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1000 + (m)*0x0004))         /* Transmit Queue Configuration / Control Register 0 m */
#define rRSCFDnCFDTXQSTS0m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1020 + (m)*0x0004))         /* Transmit Queue Status Register 0 m */
#define rRSCFDnCFDTXQPCTR0m(n,m)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1040 + (m)*0x0004))         /* Transmit Queue Pointer Control Register 0 m */
#define rRSCFDnCFDTXQCC1m(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1060 + (m)*0x0004))         /* Transmit Queue Configuration / Control Register 1 m */
#define rRSCFDnCFDTXQSTS1m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1080 + (m)*0x0004))         /* Transmit Queue Status Register 1 m */
#define rRSCFDnCFDTXQPCTR1m(n,m)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x10A0 + (m)*0x0004))         /* Transmit Queue Pointer Control Register 1 m */
#define rRSCFDnCFDTXQCC2m(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x10C0 + (m)*0x0004))         /* Transmit Queue Configuration / Control Register 2 m */
#define rRSCFDnCFDTXQSTS2m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x10E0 + (m)*0x0004))         /* Transmit Queue Status Register 2 m */
#define rRSCFDnCFDTXQPCTR2m(n,m)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1100 + (m)*0x0004))         /* Transmit Queue Pointer Control Register 2 m */
#define rRSCFDnCFDTXQCC3m(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1120 + (m)*0x0004))         /* Transmit Queue Configuration / Control Register 3 m */
#define rRSCFDnCFDTXQSTS3m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1140 + (m)*0x0004))         /* Transmit Queue Status Register 3 m */
#define rRSCFDnCFDTXQPCTR3m(n,m)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1160 + (m)*0x0004))         /* Transmit Queue Pointer Control Register 3 m */
#define rRSCFDnCFDTXQESTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1180))                      /* Transmit Queue Empty Status Register */
#define rRSCFDnCFDTXQFISTS(n)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1184))                      /* Transmit Queue Full Interrupt Status Register */
#define rRSCFDnCFDTXQMSTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1188))                      /* Transmit Queue Message Lost Status Register */
#define rRSCFDnCFDTXQOWSTS(n)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x118C))                      /* Transmit Queue Message Overwrite Status Register */
#define rRSCFDnCFDTXQISTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1190))                      /* Transmit Queue Interrupt Status Register */
#define rRSCFDnCFDTXQOFTISTS(n)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1194))                      /* Transmit Queue One Frame Transmit Interrupt Status Register */
#define rRSCFDnCFDTXQOFRISTS(n)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1198))                      /* Transmit Queue One Frame Receive Interrupt Status Register */
#define rRSCFDnCFDTXQFSTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x119C))                      /* Transmit Queue Full Status Register */
#define rRSCFDnCFDTHLCCm(n,m)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1200 + (m)*0x0004))         /* Transmit History List Configuration / Control Register m */
#define rRSCFDnCFDTHLSTSm(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1220 + (m)*0x0004))         /* Transmit History List Status Register m */
#define rRSCFDnCFDTHLPCTRm(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1240 + (m)*0x0004))         /* Transmit History List Pointer Control Register m */
#define rRSCFDnCFDGTINTSTSz(n,z)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1300 + (z)*0x0004))         /* Global Transmit Interrupt Status Register z */
#define rRSCFDnCFDGTSTCFG(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1308))                      /* Global Test Configuration Register */
#define rRSCFDnCFDGTSTCTR(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x130C))                      /* Global Test Control Register */
#define rRSCFDnCFDGFDCFG(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1314))                      /* Global FD Configuration register */
#define rRSCFDnCFDGLOCKK(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x131C))                      /* Global Lock Key Register */
#define rRSCFDnCFDCDTCT(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1330))                      /* DMA Transfer Control Register */
#define rRSCFDnCFDCDTSTS(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1334))                      /* DMA Transfer Status Register */
#define rRSCFDnCFDCDTTCT(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1340))                      /* DMA Transmit Transfer Control Register */
#define rRSCFDnCFDCDTTSTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1344))                      /* DMA Transmit Transfer Status Register */
#define rRSCFDnCFDGRINTSTSm(n,m)    (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1350 + (m)*0x0004))         /* Global Receive Interrupt Status Register m */
#define rRSCFDnCFDGPFLECTR(n)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1370))                      /* Pretended Network Filter List Entry control Register */
#define rRSCFDnCFDGPFLCFGv(n,v)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1374 + (v)*0x0004))         /* Pretended Network Filter List Entry Configuration Register v */
#define rRSCFDnCFDGRSTC(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1380))                      /* Global Reset Control Register */
#define rRSCFDnCFDGFCMC(n)          (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1384))                      /* Global Flexible CAN mode Configuration Register */
#define rRSCFDnCFDGFTBAC(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x138C))                      /* Global Flexible transmission buffer assignment Configuration Register */
#define rRSCFDnCFDGFFIMC(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1390))                      /* Global Virtual Machine Mode configuration Register */
#define rRSCFDnCFDGVMEIS(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1394))                      /* Global Virtual Machine Error Interrupt Select Register */
#define rRSCFDnCFDVMCFGm(n,m)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x13A0 + (m)*0x0004))         /* Global Virtual Machine Transmit/ Receive FIFO TXQ configuration Register m */
#define rRSCFDnCFDVMRFCFG(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x13C0))                      /* Global Virtual Machine Receive FIFO configuration Register */
#define rRSCFDnCFDVMISTSm(n,m)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x13E0 + (m)*0x0004))         /* Virtual Machine Interrupt Status Register m */
#define rRSCFDnCFDCmDCFG(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1400 + (m)*0x0020))         /* Channel m Data Bit Rate Configuration Register */
#define rRSCFDnCFDCmFDCFG(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1404 + (m)*0x0020))         /* Channel m CANFD Configuration Register */
#define rRSCFDnCFDCmFDCTR(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1408 + (m)*0x0020))         /* Channel m CANFD Control Register */
#define rRSCFDnCFDCmFDSTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x140C + (m)*0x0020))         /* Channel m CANFD Status Register */
#define rRSCFDnCFDCmFDCRC(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1410 + (m)*0x0020))         /* Channel m CANFD CRC Register */
#define rRSCFDnCFDCmBLCT(n)         (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1418 + (m)*0x0020))         /* Channel m Bus load Control Register */
#define rRSCFDnCFDCmBLSTS(n)        (*(volatile uint32_t *) (RSCFDn_base(n) + 0x141C + (m)*0x0020))         /* Channel m Bus load Status Register */
#define rRSCFDnCFDGAFLIDj(n,j)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1800 + (j)*0x0010))         /* Global Acceptance Filter List ID Register j */
#define rRSCFDnCFDGAFLMj(n,j)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1804 + (j)*0x0010))         /* Global Acceptance Filter List Mask Register j */
#define rRSCFDnCFDGAFLP0j(n,j)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1808 + (j)*0x0010))         /* Global Acceptance Filter List Pointer 0 Register j */
#define rRSCFDnCFDGAFLP1j(n,j)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x180C + (j)*0x0010))         /* Global Acceptance Filter List Pointer 1 Register j */
#define rRSCFDnCFDGPFLIDs(n,s)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A00 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List ID Registers s = [1…4] */
#define rRSCFDnCFDGPFLMs(n,s)       (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A04 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Mask Registers s = [1...4] */
#define rRSCFDnCFDGPFLP0s(n,s)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A08 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Pointer 0 Registers s = [1...4] */
#define rRSCFDnCFDGPFLP1s(n,s)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A0C + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Pointer 1 Registers s = [1...4] */
#define rRSCFDnCFDGPFLPTs(n,s)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A10 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Filter Payload Type Registers s = [1...4] */
#define rRSCFDnCFDGPFLPD0s(n,s)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A14 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Payload Data 0 Registers s = [1...4] */
#define rRSCFDnCFDGPFLPM0s(n,s)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A18 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Payload Mask 0 Registers s = [1...4] */
#define rRSCFDnCFDGPFLPD1s(n,s)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A1C + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Payload Data 1 Registers s = [1...4] */
#define rRSCFDnCFDGPFLPM1s(n,s)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x1A20 + ((s)-1)*0x0040))     /* Global Pretended Network Filter List Payload Mask 1 Registers s = [1...4] */
#define rRSCFDnCFDTHLACC0m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x8000 + (m)*0x0008))         /* Channel m Transmit History List Access Register 0[m] */
#define rRSCFDnCFDTHLACC1m(n,m)     (*(volatile uint32_t *) (RSCFDn_base(n) + 0x8004 + (m)*0x0008))         /* Channel m Transmit History List Access Register 1[m] */
#define rRSCFDnCFDRPGACCr(n,r)      (*(volatile uint32_t *) (RSCFDn_base(n) + 0x8400 + (r)*0x0004))         /* RAM Test Page Access Register r */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* RSCFDnCFDCmNCFG.NTSEG2: : */
typedef enum{
    RSCFD_e_NTSEG2_disable = 0,   /* 0000000: Setting prohibited */
    RSCFD_e_NTSEG2_enable  = 127  /* 1111110: 127 Tq */
}RSCFD_e_NTSEG2;

/* RSCFDnCFDCmCTR.ROM: Restricted Operation Mode */
typedef enum{
    RSCFD_e_ROM_disable = 0,    /* 0: Restricted Operation Mode is disabled */
    RSCFD_e_ROM_enable  = 1     /* 1: Restricted Operation Mode is enabled */
}RSCFD_e_ROM;

/* RSCFDnCFDCmCTR.CRCT: CRC Error Test */
typedef enum{
    RSCFD_e_CRCT_disable = 0,   /* 0: First data bit of reception stream not inverted */
    RSCFD_e_CRCT_enable  = 1    /* 1: First data bit of reception stream inverted */
}RSCFD_e_CRCT;

/* RSCFDnCFDCmCTR.TRR: TEC/REC Reset */
typedef enum{
    RSCFD_e_TRR_normal       = 0,   /* 0: Error counter normal operation */
    RSCFD_e_TRR_assert_reset = 1    /* 1: Error counter reset */
}RSCFD_e_TRR;

/* RSCFDnCFDCmCTR.TRH: TEC/REC Hold */
typedef enum{
    RSCFD_e_TRH_normal       = 0,   /* 0: Error counter normal operation */
    RSCFD_e_TRH_hold_counter = 1    /* 1: Error counter frozen */
}RSCFD_e_TRH;

/* RSCFDnCFDCmCTR.TRWE: TEC/REC Write Enable */
typedef enum{
    RSCFD_e_TRWE_disable = 0,   /* 0: Error Counter write disabled */
    RSCFD_e_TRWE_enable  = 1    /* 1: Error Counter write enabled */
}RSCFD_e_TRWE;

/* RSCFDnCFDCmCTR.CTMS: Channel Test Mode Select */
typedef enum{
    RSCFD_e_CTMS_basic_test_mode  = 0,  /* 00: Basic test mode */
    RSCFD_e_CTMS_listen_only_mode = 1,  /* 01: Listen-Only mode */
    RSCFD_e_CTMS_selftest_mode_0  = 2,  /* 10: Self-test mode 0 (External Loop back mode) */
    RSCFD_e_CTMS_selftest_mode_1  = 3   /* 11: Self-test mode 1 (Internal Loop back mode) */
}RSCFD_e_CTMS;

/* RSCFDnCFDCmCTR.CTME: Channel Test Mode Enable */
typedef enum{
    RSCFD_e_CTME_disable = 0,   /* 0: Channel Test Mode disabled */
    RSCFD_e_CTME_enable  = 1    /* 1: Channel Test Mode enabled */
}RSCFD_e_CTME;

/* RSCFDnCFDCmCTR.ERRD: Channel Error Display */
typedef enum{
    RSCFD_e_ERRD_1st_error = 0, /* 0: Only the 1st set of error codes displayed */
    RSCFD_e_ERRD_acc_error = 1  /* 1: Accumulated error codes displayed */
}RSCFD_e_ERRD;

/* RSCFDnCFDCmCTR.BOM: Channel Bus-Off Mode */
typedef enum{
    RSCFD_e_BOM_normal               = 0,   /* 00: Normal mode (comply with ISO 11898-1 (2015)) */
    RSCFD_e_BOM_halt_at_busoff_start = 1,   /* 01: Entry to Halt Mode automatically at Bus-Off start */
    RSCFD_e_BOM_halt_at_busoff_end   = 2,   /* 10: Entry to Halt Mode automatically at Bus-Off end */
    RSCFD_e_BOM_halt_by_soft         = 3    /* 11: Entry to Halt Mode (during Bus-Off Recovery Period) by S/W */
}RSCFD_e_BOM;

/* RSCFDnCFDCmCTR.TDCVFIE: Transceiver Delay Compensation Violation Interrupt enable */
typedef enum{
    RSCFD_e_TDCVFIE_disable = 0,    /* 0: Transceiver Delay Compensation Violation Interrupt disabled */
    RSCFD_e_TDCVFIE_enable  = 1     /* 1: Transceiver Delay Compensation Violation Interrupt enabled */
}RSCFD_e_TDCVFIE;

/* RSCFDnCFDCmCTR.SOCOIE: Successful Occurrence Counter Overflow Interrupt enable */
typedef enum{
    RSCFD_e_SOCOIE_disable = 0, /* 0: Successful occurrence counter overflow interrupt disabled */
    RSCFD_e_SOCOIE_enable  = 1  /* 1: Successful occurrence counter overflow interrupt enabled */
}RSCFD_e_SOCOIE;

/* RSCFDnCFDCmCTR.EOCOIE: Error occurrence counter overflow Interrupt enable */
typedef enum{
    RSCFD_e_EOCOIE_disable = 0, /* 0: Error occurrence counter overflow Interrupt disabled */
    RSCFD_e_EOCOIE_enable  = 1  /* 1: Error occurrence counter overflow Interrupt is enabled */
}RSCFD_e_EOCOIE;

/* RSCFDnCFDCmCTR.TAIE: Transmit Abort Interrupt Enable */
typedef enum{
    RSCFD_e_TAIE_disable = 0,   /* 0: Tx abort Interrupt disabled */
    RSCFD_e_TAIE_enable  = 1    /* 1: Tx abort Interrupt enabled */
}RSCFD_e_TAIE;

/* RSCFDnCFDCmCTR.ALIE: Arbitration Lost Interrupt Enable */
typedef enum{
    RSCFD_e_ALIE_disable = 0,   /* 0: Arbitration Lost Interrupt disabled */
    RSCFD_e_ALIE_enable  = 1    /* 1: Arbitration Lost Interrupt enabled */
}RSCFD_e_ALIE;

/* RSCFDnCFDCmCTR.BLIE: Bus Lock Interrupt Enable */
typedef enum{
    RSCFD_e_BLIE_disable = 0,   /* 0: Bus Lock Interrupt disabled */
    RSCFD_e_BLIE_enable  = 1    /* 1: Bus Lock Interrupt enabled */
}RSCFD_e_BLIE;

/* RSCFDnCFDCmCTR.OLIE: Overload Interrupt Enable */
typedef enum{
    RSCFD_e_OLIE_disable = 0,   /* 0: Overload Interrupt disabled */
    RSCFD_e_OLIE_enable  = 1    /* 1: Overload Interrupt enabled */
}RSCFD_e_OLIE;

/* RSCFDnCFDCmCTR.BORIE: Bus-Off Recovery Interrupt Enable */
typedef enum{
    RSCFD_e_BORIE_disable = 0,  /* 0: Bus-Off Recovery Interrupt disabled */
    RSCFD_e_BORIE_enable  = 1   /* 1: Bus-Off Recovery Interrupt enabled */
}RSCFD_e_BORIE;

/* RSCFDnCFDCmCTR.BOEIE: Bus-Off Entry Interrupt Enable */
typedef enum{
    RSCFD_e_BOEIE_disable = 0,  /* 0: Bus-Off Entry Interrupt disabled */
    RSCFD_e_BOEIE_enable  = 1   /* 1: Bus-Off Entry Interrupt enabled */
}RSCFD_e_BOEIE;

/* RSCFDnCFDCmCTR.EPIE: Error Passive Interrupt Enable */
typedef enum{
    RSCFD_e_EPIE_disable = 0,   /* 0: Error Passive Interrupt disabled */
    RSCFD_e_EPIE_enable  = 1    /* 1: Error Passive Interrupt enabled */
}RSCFD_e_EPIE;

/* RSCFDnCFDCmCTR.EWIE: Error Warning Interrupt Enable */
typedef enum{
    RSCFD_e_EWIE_disable = 0,   /* 0: Error Warning Interrupt disabled */
    RSCFD_e_EWIE_enable  = 1    /* 1: Error Warning Interrupt enabled */
}RSCFD_e_EWIE;

/* RSCFDnCFDCmCTR.BEIE: Bus Error Interrupt Enable */
typedef enum{
    RSCFD_e_BEIE_disable = 0,   /* 0: Bus Error Interrupt disabled */
    RSCFD_e_BEIE_enable  = 1    /* 1: Bus Error Interrupt enabled */
}RSCFD_e_BEIE;

/* RSCFDnCFDCmCTR.RTBO: Return from Bus-Off */
typedef enum{
    RSCFD_e_RTBO_not_cansel_busoff = 0, /* 0: Channel is not forced to return from Bus-Off */
    RSCFD_e_RTBO_cansel_busoff     = 1  /* 1: Channel is forced to return from Bus-Off */
}RSCFD_e_RTBO;

/* RSCFDnCFDCmCTR.CSLPR: Channel Stop Request */
typedef enum{
    RSCFD_e_CSLPR_not_request_ch_stop = 0,  /* 0: Channel Stop Request disabled */
    RSCFD_e_CSLPR_resuest_ch_stop     = 1   /* 1: Channel Stop Request enabled */
}RSCFD_e_CSLPR;

/* RSCFDnCFDCmCTR.CHMDC: Channel Mode Control */
typedef enum{
    RSCFD_e_CHMDC_request_ch_com_mode   = 0,    /* 00: Channel Communication Mode request */
    RSCFD_e_CHMDC_request_ch_reset_mode = 1,    /* 01: Channel Reset request */
    RSCFD_e_CHMDC_request_ch_halt_mode  = 2,    /* 10: Channel Halt request */
    RSCFD_e_CHMDC_keep_current_mode     = 3     /* 11: Keep current value */
}RSCFD_e_CHMDC;

/* RSCFDnCFDCmSTS.ESIF: Error State Indication Flag */
typedef enum{
    RSCFD_e_ESIF_not_received_ESI = 0,  /* 0: No CANFD message has been received with the ESI flag was set */
    RSCFD_e_ESIF_received_ESI     = 1   /* 1: At least 1 CANFD message was received where the ESI flag was set */
}RSCFD_e_ESIF;

/* RSCFDnCFDCmSTS.COMSTS: Channel Communication Status */
typedef enum{
    RSCFD_e_COMSTS_not_com_ready = 0,   /* 0: Channel is not ready for communication */
    RSCFD_e_COMSTS_com_ready     = 1    /* 1: Channel is ready for communication */
}RSCFD_e_COMSTS;

/* RSCFDnCFDCmSTS.RECSTS: Channel Receive Status */
typedef enum{
    RSCFD_e_RECSTS_not_receive = 0, /* 0: Channel is not receiving */
    RSCFD_e_RECSTS_receiving   = 1  /* 1: Channel is receiving */
}RSCFD_e_RECSTS;

/* RSCFDnCFDCmSTS.TRMSTS: Channel Transmit Status */
typedef enum{
    RSCFD_e_TRMSTS_not_transmit = 0,    /* 0: Channel is not transmitting */
    RSCFD_e_TRMSTS_transmitting = 1     /* 1: Channel is transmitting */
}RSCFD_e_TRMSTS;

/* RSCFDnCFDCmSTS.BOSTS: Channel Bus-Off Status */
typedef enum{
    RSCFD_e_BOSTS_not_busoff_state = 0, /* 0: Channel not in Bus-Off state */
    RSCFD_e_BOSTS_busoff_state     = 1  /* 1: Channel in Bus-Off state */
}RSCFD_e_BOSTS;

/* RSCFDnCFDCmSTS.EPSTS: Channel Error Passive Status */
typedef enum{
    RSCFD_e_EPSTS_not_error_passive_state = 0,  /* 0: Channel not in Error Passive state. */
    RSCFD_e_EPSTS_error_passive_state     = 1   /* 1: Channel in Error Passive state. */
}RSCFD_e_EPSTS;

/* RSCFDnCFDCmSTS.CSLPSTS: Channel STOP Status */
typedef enum{
    RSCFD_e_CSLPSTS_not_stop_mode = 0,  /* 0: Channel not in Stop Mode */
    RSCFD_e_CSLPSTS_stop_mode     = 1   /* 1: Channel in Stop Mode */
}RSCFD_e_CSLPSTS;

/* RSCFDnCFDCmSTS.CHLTSTS: Channel HALT Status */
typedef enum{
    RSCFD_e_CHLTSTS_not_halt_mode = 0,  /* 0: Channel not in Halt Mode */
    RSCFD_e_CHLTSTS_halt_mode     = 1   /* 1: Channel in Halt Mode */
}RSCFD_e_CHLTSTS;

/* RSCFDnCFDCmSTS.CRSTSTS: Channel RESET Status */
typedef enum{
    RSCFD_e_CRSTSTS_not_reset_mode = 0, /* 0: Channel not in Reset Mode */
    RSCFD_e_CRSTSTS_reset_mode     = 1  /* 1: Channel in Reset Mode */
}RSCFD_e_CRSTSTS;

/* RSCFDnCFDCmERFL.ADERR: Acknowledge Delimiter Error */
typedef enum{
    RSCFD_e_ADERR_not_detect = 0,   /* 0: Channel Ack Del Error not detected */
    RSCFD_e_ADERR_detect     = 1    /* 1: Channel Ack Del Error detected */
}RSCFD_e_ADERR;

/* RSCFDnCFDCmERFL.B0ERR: Bit 0 Error */
typedef enum{
    RSCFD_e_B0ERR_not_detect = 0,   /* 0: Channel Bit 0 Error not detected */
    RSCFD_e_B0ERR_detect     = 1    /* 1: Channel Bit 0 Error detected */
}RSCFD_e_B0ERR;

/* RSCFDnCFDCmERFL.B1ERR: Bit 1 Error */
typedef enum{
    RSCFD_e_B1ERR_not_detect = 0,   /* 0: Channel Bit 1 Error not detected */
    RSCFD_e_B1ERR_detect     = 1    /* 1: Channel Bit 1 Error detected */
}RSCFD_e_B1ERR;

/* RSCFDnCFDCmERFL.CERR: CRC Error */
typedef enum{
    RSCFD_e_CERR_not_detect = 0,    /* 0: Channel CRC Error not detected */
    RSCFD_e_CERR_detect     = 1     /* 1: Channel CRC Error detected */
}RSCFD_e_CERR;

/* RSCFDnCFDCmERFL.AERR: Acknowledge Error */
typedef enum{
    RSCFD_e_AERR_not_detect = 0,    /* 0: Channel Ack Error not detected */
    RSCFD_e_AERR_detect     = 1     /* 1: Channel Ack Error detected */
}RSCFD_e_AERR;

/* RSCFDnCFDCmERFL.FERR: Form Error */
typedef enum{
    RSCFD_e_FERR_not_detect = 0,    /* 0: Channel Form Error not detected */
    RSCFD_e_FERR_detect     = 1     /* 1: Channel Form Error detected */
}RSCFD_e_FERR;

/* RSCFDnCFDCmERFL.SERR: Stuff Error */
typedef enum{
    RSCFD_e_SERR_not_detect = 0,    /* 0: Channel stuff Error not detected */
    RSCFD_e_SERR_detect     = 1     /* 1: Channel stuff Error detected */
}RSCFD_e_SERR;

/* RSCFDnCFDCmERFL.ALF: Arbitration Lost Flag */
typedef enum{
    RSCFD_e_ALF_not_detect = 0, /* 0: Channel Arbitration Lost not detected */
    RSCFD_e_ALF_detect     = 1  /* 1: Channel Arbitration Lost detected */
}RSCFD_e_ALF;

/* RSCFDnCFDCmERFL.BLF: Bus Lock Flag */
typedef enum{
    RSCFD_e_BLF_not_detect = 0, /* 0: Channel Bus Lock not detected */
    RSCFD_e_BLF_detect     = 1  /* 1: Channel Bus Lock detected */
}RSCFD_e_BLF;

/* RSCFDnCFDCmERFL.OVLF: Overload Flag */
typedef enum{
    RSCFD_e_OVLF_not_detect = 0,    /* 0: Channel Overload not detected */
    RSCFD_e_OVLF_detect     = 1     /* 1: Channel Overload detected */
}RSCFD_e_OVLF;

/* RSCFDnCFDCmERFL.BORF: Bus-Off Recovery Flag */
typedef enum{
    RSCFD_e_BORF_not_detect = 0,    /* 0: Channel Bus-Off Recovery not detected */
    RSCFD_e_BORF_detect     = 1     /* 1: Channel Bus-Off Recovery detected */
}RSCFD_e_BORF;

/* RSCFDnCFDCmERFL.BOEF: Bus-Off Entry Flag */
typedef enum{
    RSCFD_e_BOEF_not_detect = 0,    /* 0: Channel Bus-Off Entry not detected */
    RSCFD_e_BOEF_detect     = 1     /* 1: Channel Bus-Off Entry detected */
}RSCFD_e_BOEF;

/* RSCFDnCFDCmERFL.EPF: Error Passive Flag */
typedef enum{
    RSCFD_e_EPF_not_detect = 0, /* 0: Channel Error Passive not detected */
    RSCFD_e_EPF_detect     = 1  /* 1: Channel Error Passive detected */
}RSCFD_e_EPF;

/* RSCFDnCFDCmERFL.EWF: Error Warning Flag */
typedef enum{
    RSCFD_e_EWF_not_detect = 0, /* 0: Channel Error Warning not detected */
    RSCFD_e_EWF_detect     = 1  /* 1: Channel Error Warning detected */
}RSCFD_e_EWF;

/* RSCFDnCFDCmERFL.BEF: Bus Error Flag */
typedef enum{
    RSCFD_e_BEF_not_detect = 0, /* 0: Channel Bus Error not detected */
    RSCFD_e_BEF_detect     = 1  /* 1: Channel Bus Error detected */
}RSCFD_e_BEF;

/* RSCFDnCFDCmFDCFG.CFDTE: CANFD Tolerance enable */
typedef enum{
    RSCFD_e_CFDTE_disable = 0,  /* 0: CANFD Tolerance mode disabled */
    RSCFD_e_CFDTE_enable  = 1   /* 1: CANFD Tolerance mode enabled. */
}RSCFD_e_CFDTE;

/* RSCFDnCFDCmFDCFG.CLOE: Classical CAN only enable */
typedef enum{
    RSCFD_e_CLOE_disable = 0,   /* 0: Classical only mode disabled */
    RSCFD_e_CLOE_enable  = 1    /* 1: Classical only mode enabled */
}RSCFD_e_CLOE;

/* RSCFDnCFDCmFDCFG.REFE: Rx edge filter enable */
typedef enum{
    RSCFD_e_REFE_disable = 0,   /* 0: Rx edge filter is disabled */
    RSCFD_e_REFE_enable  = 1    /* 1: Rx edge filter is enabled */
}RSCFD_e_REFE;

/* RSCFDnCFDCmFDCFG.FDOE: CANFD only enable */
typedef enum{
    RSCFD_e_FDOE_disable = 0,   /* 0: CANFD only mode disabled */
    RSCFD_e_FDOE_enable  = 1    /* 1: CANFD only mode enabled */
}RSCFD_e_FDOE;

/* RSCFDnCFDCmFDCFG.GWBRS: Gateway BRS configuration bit */
typedef enum{
    RSCFD_e_GWBRS_BRS_0 = 0,    /* 0: GW frame is transmitted with BRS = 0 */
    RSCFD_e_GWBRS_BRS_1 = 1     /* 1: GW frame is transmitted with BRS = 1 */
}RSCFD_e_GWBRS;

/* RSCFDnCFDCmFDCFG.GWFDF: Gateway FDF configuration bit */
typedef enum{
    RSCFD_e_GWFDF_CCAN_frame  = 0,  /* 0: GW frame is transmitted as Classical CAN frame */
    RSCFD_e_GWFDF_CANFD_frame = 1   /* 1: GW frame is transmitted as CANFD frame */
}RSCFD_e_GWFDF;

/* RSCFDnCFDCmFDCFG.GWEN: CAN2.0, CANFD less_thangreater_than CAN2.0, CANFD Multi Gateway Enable */
typedef enum{
    RSCFD_e_GWEN_disable = 0,   /* 0: Multi Gateway Disabled */
    RSCFD_e_GWEN_enable  = 1    /* 1: Multi Gateway Enable */
}RSCFD_e_GWEN;

/* RSCFDnCFDCmFDCFG.RPNMD: Return Pretended Network Filter Mode */
typedef enum{
    RSCFD_e_RPNMD_return_to_AFL        = 0, /* 00B: Return to Acceptance Filter Mode */
    RSCFD_e_RPNMD_return_to_PNF_ID_AFL = 1, /* 01B: Return to Pretended Network Filter ID only and Acceptance Filter Mode */
    RSCFD_e_RPNMD_return_to_PNF_AFL    = 2, /* 10B: Return to Pretended Network Filter and Acceptance Filter Mode */
    RSCFD_e_RPNMD_return_to_PNF        = 3  /* 11B: Return to Pretended Network Filter Mode (Not return) */
}RSCFD_e_RPNMD;

/* RSCFDnCFDCmFDCFG.ESIC: Error State Indication Configuration */
typedef enum{
    RSCFD_e_ESIC_indicate_itself = 0,   /* 0: The ESI bit in the frame will be representing the Error state of the node itself */
    RSCFD_e_ESIC_bus_error       = 1    /* 1: The ESI bit in the frame will be representing the Error state of message buffer if the node itself is not in error passive. If the node is in Error Passive then the ESI bit will be driven by the node itself */
}RSCFD_e_ESIC;

/* RSCFDnCFDCmFDCFG.TDCE: Transceiver Delay Compensation Enable */
typedef enum{
    RSCFD_e_TDCE_disable = 0,   /* 0: Transceiver Delay Compensation Disabled */
    RSCFD_e_TDCE_enable  = 1    /* 1: Transceiver Delay Compensation Enabled */
}RSCFD_e_TDCE;

/* RSCFDnCFDCmFDCFG.TDCOC: Transceiver Delay Compensation Offset Configuration */
typedef enum{
    RSCFD_e_TDCOC_measured_and_offset = 0,  /* 0: Measured + offset */
    RSCFD_e_TDCOC_offset_only         = 1   /* 1: offset only */
}RSCFD_e_TDCOC;

/* RSCFDnCFDCmFDCFG.EOCCFG: Error Occurrence Counter Configuration */
typedef enum{
    RSCFD_e_EOCCFG_all_tx_rx             = 0,   /* 000: All Transmitter or Receiver CAN Frames */
    RSCFD_e_EOCCFG_all_tx                = 1,   /* 001: All Transmitter CAN Frames */
    RSCFD_e_EOCCFG_all_rx                = 2,   /* 010: All Receiver CAN Frames */
    RSCFD_e_EOCCFG_setting_prohibit1     = 3,   /* 011: Setting prohibited */
    RSCFD_e_EOCCFG_only_tx_rx_CANFD_data = 4,   /* 100: Only Transmitter or Receiver CANFD Data-Phase (fast bits) */
    RSCFD_e_EOCCFG_only_tx_CANFD_data    = 5,   /* 101: Only Transmitter CANFD Data-Phase (fast bits) */
    RSCFD_e_EOCCFG_only_rx_CANFD_data    = 6,   /* 110: Only Receiver CANFD Data-Phase (fast bits) */
    RSCFD_e_EOCCFG_setting_prohibit2     = 7    /* 111: Setting prohibited */
}RSCFD_e_EOCCFG;

/* RSCFDnCFDCmFDCTR.KEY: Key code. */
typedef enum{
    RSCFD_e_KEY_key_value = 0xC4    /* These bits control the right or wrong of rewriting of PNMDC bit. */
}RSCFD_e_KEY;

/* RSCFDnCFDCmFDCTR.PNMDC: Pretended Network Filter Mode Control */
typedef enum{
    RSCFD_e_PNMDC_request_AFL        = 0,   /* 00B: Acceptance Filter Mode request */
    RSCFD_e_PNMDC_request_PNF_ID_AFL = 1,   /* 01B: Pretended Network Filter ID only and Acceptance Filter Mode request */
    RSCFD_e_PNMDC_request_PNF_AFL    = 2,   /* 10B: Pretended Network Filter and Acceptance Filter Mode request */
    RSCFD_e_PNMDC_request_PNF        = 3    /* 11B: Pretended Network Filter Mode request */
}RSCFD_e_PNMDC;

/* RSCFDnCFDCmFDCTR.SOCCLR: Successful Occurrence Counter Clear */
typedef enum{
    RSCFD_e_SOCCLR_not_clear_success_counter = 0,   /* 0: No Successful Occurrence Counter clear */
    RSCFD_e_SOCCLR_clear_success_counter     = 1    /* 1: Clear Successful Occurrence Counter */
}RSCFD_e_SOCCLR;

/* RSCFDnCFDCmFDCTR.EOCCLR: Error Occurrence Counter Clear */
typedef enum{
    RSCFD_e_EOCCLR_not_clear_error_counter = 0, /* 0: No Error Occurrence Counter clear */
    RSCFD_e_EOCCLR_clear_error_counter     = 1  /* 1: Clear Error Occurrence Counter */
}RSCFD_e_EOCCLR;

/* RSCFDnCFDCmFDSTS.TDCVF: Transmitter Delay Compensation Violation Flag */
typedef enum{
    RSCFD_e_TDCVF_not_detect = 0,   /* 0: Transmitter Delay Compensation Violation has not occurred */
    RSCFD_e_TDCVF_detect     = 1    /* 1: Transmitter Delay Compensation Violation has occurred */
}RSCFD_e_TDCVF;

/* RSCFDnCFDCmFDSTS.PNSTS: Pretended Network Filter State */
typedef enum{
    RSCFD_e_PNSTS_AFL_mode        = 0,  /* 00B: Acceptance Filter Mode */
    RSCFD_e_PNSTS_PNF_ID_AFL_mode = 1,  /* 01B: Pretended Network Filter ID only and Acceptance Filter Mode */
    RSCFD_e_PNSTS_PNF_AFL_mode    = 2,  /* 10B: Pretended Network Filter and Acceptance Filter Mode */
    RSCFD_e_PNSTS_PNF_mode        = 3   /* 11B: Pretended Network Filter Mode */
}RSCFD_e_PNSTS;

/* RSCFDnCFDCmFDSTS.SOCO: Successful occurrence counter overflow */
typedef enum{
    RSCFD_e_SOCO_not_overflow = 0,  /* 0: Successful occurrence counter has not overflowed */
    RSCFD_e_SOCO_overflow     = 1   /* 1: Successful occurrence counter has overflowed */
}RSCFD_e_SOCO;

/* RSCFDnCFDCmFDSTS.EOCO: Error occurrence counter overflow */
typedef enum{
    RSCFD_e_EOCO_not_overflow = 0,  /* 0: Error occurrence counter has not overflowed */
    RSCFD_e_EOCO_overflow     = 1   /* 1: Error occurrence counter has overflowed */
}RSCFD_e_EOCO;

/* RSCFDnCFDGIPV.PSI[13:11]: Number of channel */
typedef enum{
    RSCFD_e_PSI_CH_8_channel = 0,   /* 000B = channel number 8 */
    RSCFD_e_PSI_CH_6_channel = 2,   /* 010B = channel number 6 */
    RSCFD_e_PSI_CH_4_channel = 4,   /* 100B = channel number 4 */
    RSCFD_e_PSI_CH_2_channel = 6    /* 110B = channel number 2 */
                                    /* ohters: reserved */
}RSCFD_e_PSI_CH;

/* RSCFDnCFDGIPV.PSI[10:8]: Number of TXMB */
typedef enum{
    RSCFD_e_PSI_TXMB_64_per_ch = 0, /* 000B = 64 per channel */
    RSCFD_e_PSI_TXMB_32_per_ch = 1, /* 001B = 32 per channel */
    RSCFD_e_PSI_TXMB_16_per_ch = 2  /* 010B = 16 per channel */
                                    /* ohters: reserved */
}RSCFD_e_PSI_TXMB;

/* RSCFDnCFDGIPV.PSI[7:5]: Number of AFL rule */
typedef enum{
    RSCFD_e_PSI_AFL_192_per_ch = 0, /* 000B = 192 per channel */
    RSCFD_e_PSI_AFL_128_per_ch = 1, /* 001B = 128 per channel */
    RSCFD_e_PSI_AFL_64_per_ch  = 2  /* 010B = 64 per channel */
                                    /* ohters: reserved */
}RSCFD_e_PSI_AFL;

/* RSCFDnCFDGIPV.PSI[4:1]: Number of Shared Buffer */
typedef enum{
    RSCFD_e_PSI_CB_256_per_ch = 0,  /* 0000B = 256 per channel */
    RSCFD_e_PSI_CB_128_per_ch = 1,  /* 0001B = 128 per channel */
    RSCFD_e_PSI_CB_64_per_ch  = 2,  /* 0010B = 64 per channel */
    RSCFD_e_PSI_CB_48_per_ch  = 3,  /* 0011B = 48 per channel */
    RSCFD_e_PSI_CB_32_per_ch  = 4   /* 0100B = 32 per channel */
                                    /* ohters: reserved */
}RSCFD_e_PSI_CB;

/* RSCFDnCFDGIPV.PSI[0]: Same ID overwrite function of TXQ */
typedef enum{
    RSCFD_e_PSI_OV_implement     = 0,   /* 0B = implementannel */
    RSCFD_e_PSI_OV_not_implement = 1,   /* 1B = not implementannel */
}RSCFD_e_PSI_OV;

/* RSCFDnCFDGIPV.IPT: IP Type Release Number */
typedef enum{
    RSCFD_e_IPT_CAN   = 0,  /* 00B = IP Type RS-CAN */
    RSCFD_e_IPT_CANFD = 1   /* 01B = IP Type RS-CANFD */
}RSCFD_e_IPT;

/* RSCFDnCFDGIPV.IPV: IP Version Release Number */
typedef enum{
    RSCFD_e_IPV_release_4_1 = 0x42, /* 42H = IP Release 4.1 */
}RSCFD_e_IPV;

/* RSCFDnCFDGCFG.TSBTCS: Timestamp Bit Time Channel Select */
typedef enum{
    RSCFD_e_TSBTCS_channel_0 = 0,   /* 000: select clock from Channel 0 */
    RSCFD_e_TSBTCS_channel_1 = 1,   /* 001: select clock from Channel 1 */
    RSCFD_e_TSBTCS_channel_2 = 2,   /* 010: select clock from Channel 2 */
    RSCFD_e_TSBTCS_channel_3 = 3,   /* 011: select clock from Channel 3 */
    RSCFD_e_TSBTCS_channel_4 = 4,   /* 100: select clock from Channel 4 */
    RSCFD_e_TSBTCS_channel_5 = 5,   /* 101: select clock from Channel 5 */
    RSCFD_e_TSBTCS_channel_6 = 6,   /* 110: select clock from Channel 6 */
    RSCFD_e_TSBTCS_channel_7 = 7    /* 111: select clock from Channel 7 */
}RSCFD_e_TSBTCS;

/* RSCFDnCFDGCFG.TSSS: Timestamp Source Select */
typedef enum{
    RSCFD_e_TSSS_peripheral_clock = 0,  /* 0: Source clock for Timestamp counter is peripheral clock */
    RSCFD_e_TSSS_bit_time_clock   = 1   /* 1: Source clock for Timestamp counter is bit time clock */
}RSCFD_e_TSSS;

/* RSCFDnCFDGCFG.CMPOC: CANFD message Payload overflow configuration */
typedef enum{
    RSCFD_e_CMPOC_message_rejected = 0, /* 0: Message is rejected */
    RSCFD_e_CMPOC_message_payload  = 1  /* 1: Messages payload is cut to fit to configured message size */
}RSCFD_e_CMPOC;

/* RSCFDnCFDGCFG.DCS: Data Link Controller Clock Select */
typedef enum{
    RSCFD_e_DCS_internal_clean_clock     = 0,   /* 0: Internal clean clock */
    RSCFD_e_DCS_external_clock_connected = 1    /* 1: External Clock source connected to clk_xincan pin */
}RSCFD_e_DCS;

/* RSCFDnCFDGCFG.MME: Mirror Mode Enable */
typedef enum{
    RSCFD_e_MME_mirror_Mode_disabled = 0,   /* 0: Mirror Mode disabled */
    RSCFD_e_MME_mirror_Mode_enabled  = 1    /* 1: Mirror Mode enabled */
}RSCFD_e_MME;

/* RSCFDnCFDGCFG.DRE: DLC Replacement Enable */
typedef enum{
    RSCFD_e_DRE_DLC_replacement_disabled = 0,   /* 0: DLC replacement disabled */
    RSCFD_e_DRE_DLC_replacement_enabled  = 1    /* 1: DLC replacement enabled */
}RSCFD_e_DRE;

/* RSCFDnCFDGCFG.DCE: DLC Check Enable */
typedef enum{
    RSCFD_e_DCE_DLC_check_disabled = 0, /* 0: DLC check disabled */
    RSCFD_e_DCE_DLC_check_enabled  = 1  /* 1: DLC check enabled */
}RSCFD_e_DCE;

/* RSCFDnCFDGCFG.TPRI: Transmission Priority */
typedef enum{
    RSCFD_e_TPRI_ID_Priority                    = 0,    /* 0: ID Priority */
    RSCFD_e_TPRI_message_buffer_number_priority = 1     /* 1: Message Buffer Number Priority */
}RSCFD_e_TPRI;

/* RSCFDnCFDGCTR.TSRST: Timestamp Reset */
typedef enum{
    RSCFD_e_TSRST_timestamp_not_reset = 0,  /* 0: Timestamp not reset */
    RSCFD_e_TSRST_timestamp_reset     = 1   /* 1: Timestamp reset */
}RSCFD_e_TSRST;

/* RSCFDnCFDGCTR */
typedef enum{
    RSCFD_e_CFDGCTR_disabled = 0,   /* 0: GW FIFO Message overwrite Error Interrupt Disabled */
    RSCFD_e_CFDGCTR_enabled  = 1    /* 1: GW FIFO Message overwrite Error Interrupt Enabled */
}RSCFD_e_CFDGCTR;

/* RSCFDnCFDGCTR.GSLPR: Global Stop Request */
typedef enum{
    RSCFD_e_GSLPR_request_disabled = 0, /* 0: Global Stop Request Disabled */
    RSCFD_e_GSLPR_request_enabled  = 1  /* 1: Global Stop Request Enabled */
}RSCFD_e_GSLPR;

/* RSCFDnCFDGCTR.GMDC: Global Mode Control */
typedef enum{
    RSCFD_e_GMDC_global_operating_mode_request = 0, /* 00: Global Operating Mode Request */
    RSCFD_e_GMDC_global_reset_mode_request     = 1, /* 01: Global Reset Mode Request */
    RSCFD_e_GMDC_global_test_mode_request      = 2, /* 10: Global Test Mode Request */
    RSCFD_e_GMDC_keep_current_value            = 3  /* 11: Keep Current Value */
}RSCFD_e_GMDC;

/* RSCFDnCFDGSTS.GRAMINIT: Global RAM Initialization */
typedef enum{
    RSCFD_e_GRAMINIT_initialization_finished = 0,   /* 0: RAM initialization is finished */
    RSCFD_e_GRAMINIT_initialization_ongoing  = 1    /* 1: RAM initialization ongoing */
}RSCFD_e_GRAMINIT;

/* RSCFDnCFDGSTS.GSLPSTS: Global Stop Status */
typedef enum{
    RSCFD_e_GSLPSTS_not_in_stopmode = 0,    /* 0: Not in Stop Mode */
    RSCFD_e_GSLPSTS_in_stopmode     = 1     /* 1: In Stop Mode */
}RSCFD_e_GSLPSTS;

/* RSCFDnCFDGSTS.GHLTSTS: Global Test Status */
typedef enum{
    RSCFD_e_GHLTSTS_not_in_testmode = 0,    /* 0: Not in Test Mode */
    RSCFD_e_GHLTSTS_in_testmode     = 1     /* 1: In Test Mode */
}RSCFD_e_GHLTSTS;

/* RSCFDnCFDGSTS.GRSTSTS: Global Reset Status */
typedef enum{
    RSCFD_e_GRSTSTS_not_in_resetmode = 0,   /* 0: Not in Reset Mode */
    RSCFD_e_GRSTSTS_in_resetmode     = 1    /* 1: In Reset Mode */
}RSCFD_e_GRSTSTS;

/* RSCFDnCFDGERFL.EEFx: ECC Error Flag for Channel x */
typedef enum{
    RSCFD_e_EEFx_error_not_detected = 0,    /* error not detected */
    RSCFD_e_EEFx_error_detected     = 1     /* error detected */
}RSCFD_e_EEFx;

/* RSCFDnCFDGERFL */
typedef enum{
    RSCFD_e_CFDGERFL_not_detected = 0,  /* not detected */
    RSCFD_e_CFDGERFL_detected     = 1   /* detected */
}RSCFD_e_CFDGERFL;

/* RSCFDnCFDGTINTSTSz */
typedef enum{
    RSCFD_e_CFDGTINTSTSz_InterruptFlag_not_set = 0, /* not set */
    RSCFD_e_CFDGTINTSTSz_InterruptFlag_set     = 1  /* set */
}RSCFD_e_CFDGTINTSTSz_InterruptFlag;

/* RSCFDnCFDGAFLECTR.AFLDAE: Acceptance Filter List Data Access Enable */
typedef enum{
    RSCFD_e_AFLDAE_data_acess_disabled = 0, /* 0: Acceptance Filter List Data access disabled */
    RSCFD_e_AFLDAE_data_acess_enabled  = 1  /* 1: Acceptance Filter List Data access enabled */
}RSCFD_e_AFLDAE;

/* RSCFDnCFDGAFLIDj.GAFLIDE: Global Acceptance Filter List Entry IDE Field */
typedef enum{
    RSCFD_e_GAFLIDE_standard_identifier = 0,    /* 0: Standard Identifier of Rule entry ID is valid for acceptance filtering */
    RSCFD_e_GAFLIDE_extended_identifier = 1     /* 1: Extended Identifier of Rule entry ID is valid for acceptance filtering */
}RSCFD_e_GAFLIDE;

/* RSCFDnCFDGAFLIDj.GAFLRTR: Global Acceptance Filter List Entry RTR Field */
typedef enum{
    RSCFD_e_GAFLRTR_data_frame   = 0,   /* 0: Data Frame */
    RSCFD_e_GAFLRTR_remote_frame = 1    /* 1: Remote Frame */
}RSCFD_e_GAFLRTR;

/* RSCFDnCFDGAFLIDj.GAFLLB: Global Acceptance Filter List Entry Loopback Configuration */
typedef enum{
    RSCFD_e_GAFLLB_acceptance_filtering_RX = 0, /* 0: Global Acceptance Filter List entry ID for acceptance filtering has attribute 'RX' */
    RSCFD_e_GAFLLB_acceptance_filtering_TX = 1  /* 1: Global Acceptance Filter List entry ID for acceptance filtering has attribute 'TX' */
}RSCFD_e_GAFLLB;

/* RSCFDnCFDGAFLMj.GAFLIDEM: Global Acceptance Filter List IDE Mask */
typedef enum{
    RSCFD_e_GAFLIDEM_IDE_bit_not_considered = 0,    /* 0: IDE bit is not considered for ID matching */
    RSCFD_e_GAFLIDEM_IDE_bit_considered     = 1     /* 1: IDE bit is considered for ID matching */
}RSCFD_e_GAFLIDEM;

/* RSCFDnCFDGAFLMj.GAFLRTRM: Global Acceptance Filter List Entry RTR Mask */
typedef enum{
    RSCFD_e_GAFLRTRM_RTR_bit_not_considered = 0,    /* 0: RTR bit is not considered for ID matching */
    RSCFD_e_GAFLRTRM_RTR_bit_considered     = 1     /* 1: RTR bit is considered for ID matching */
}RSCFD_e_GAFLRTRM;

/* RSCFDnCFDGAFLP0j.GAFLRMV: Global Acceptance Filter List RX Message Buffer Valid */
typedef enum{
    RSCFD_e_GAFLRMV_message_buffer_valid   = 0, /* 0: Global Acceptance Filter List Single Message Buffer Direction Pointer is invalid */
    RSCFD_e_GAFLRMV_message_buffer_invalid = 1  /* 1: Global Acceptance Filter List Single Message Buffer Direction Pointer is valid */
}RSCFD_e_GAFLRMV;

/* RSCFDnCFDGAFLP0j.GAFLSRD2: Global Acceptance Filter List Select Routing destination 2 */
typedef enum{
    RSCFD_e_GAFLSRD2_routing_target_CFIFO2    = 0,  /* 0: Routing target is CFIFO2 */
    RSCFD_e_GAFLSRD2_routing_target_TX_Queue2 = 1   /* 1: Routing target is TX Queue 2 instead of CFIFO2 */
}RSCFD_e_GAFLSRD2;

/* RSCFDnCFDGAFLP0j.GAFLSRD1: Global Acceptance Filter List Select Routing destination 1 */
typedef enum{
    RSCFD_e_GAFLSRD1_routing_target_CFIFO1    = 0,  /* 0: Routing target is CFIFO1 */
    RSCFD_e_GAFLSRD1_routing_target_TX_Queue1 = 1   /* 1: Routing target is TX Queue 1 instead of CFIFO1 */
}RSCFD_e_GAFLSRD1;

/* RSCFDnCFDGAFLP0j.GAFLSRD0: Global Acceptance Filter List Select Routing destination 0 */
typedef enum{
    RSCFD_e_GAFLSRD0_routing_target_CFIFO0    = 0,  /* 0: Routing target is CFIFO0 */
    RSCFD_e_GAFLSRD0_routing_target_TX_Queue0 = 1   /* 1: Routing target is TX Queue 0 instead of CFIFO0 */
}RSCFD_e_GAFLSRD0;

/* RSCFDnCFDRMNB.RMPLS: Reception Message Buffer Payload Data Size */
typedef enum{
    RSCFD_e_RMPLS_8bytes  = 0,  /* 000: 8 bytes */
    RSCFD_e_RMPLS_12bytes = 1,  /* 001: 12 bytes */
    RSCFD_e_RMPLS_16bytes = 2,  /* 010: 16 bytes */
    RSCFD_e_RMPLS_20bytes = 3,  /* 011: 20 bytes */
    RSCFD_e_RMPLS_24bytes = 4,  /* 100: 24 bytes */
    RSCFD_e_RMPLS_32bytes = 5,  /* 101: 32 bytes */
    RSCFD_e_RMPLS_48bytes = 6,  /* 110: 48 bytes */
    RSCFD_e_RMPLS_64bytes = 7   /* 111: 64 bytes */
}RSCFD_e_RMPLS;

/* RSCFDnCFDRMNDt.RMNSu: RX Message Buffer New Data Status */
typedef enum{
    RSCFD_e_RMNSu_new_data_not_stored = 0,  /* 0: New Data not stored in corresponding RX Message Buffer */
    RSCFD_e_RMNSu_new_data_stored     = 1   /* 1: New Data stored in corresponding RX Message Buffer */
}RSCFD_e_RMNSu;

/* RSCFDnCFDRFCCx.DMAE: DMA Transfer Enable for RXFIFO for FFI Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDRFCCx_DMAE_request_disabled = 0,  /* 1'b0: DMA Transfer Request disabled for channel m */
    RSCFD_e_RSCFDnCFDRFCCx_DMAE_request_enabled  = 1   /* 1'b1: DMA Transfer Request enabled for channel m */
}RSCFD_e_RSCFDnCFDRFCCx_DMAE;

/* RSCFDnCFDRFCCx.MEIE: Message lost Error Interrupt Enable for FFI Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDRFCCx_MEIE_error_interrupt_disabled = 0,   /* 1'b0: Message Lost Error Interrupt Disabled */
    RSCFD_e_RSCFDnCFDRFCCx_MEIE_error_interrupt_enabled  = 1    /* 1'b1: Message Lost Error Interrupt Enabled */
}RSCFD_e_RSCFDnCFDRFCCx_MEIE;

/* RSCFDnCFDRFCCx.RFFIE: RX FIFO Full interrupt Enable */
typedef enum{
    RSCFD_e_RFFIE_interrupt_generation_disabled = 0,    /* 0: FIFO Interrupt generation disabled */
    RSCFD_e_RFFIE_interrupt_generation_enabled  = 1     /* 1: FIFO Interrupt generation enabled */
}RSCFD_e_RFFIE;

/* RSCFDnCFDRFCCx.RFIGCV: RX FIFO Interrupt Generation Counter Value */
typedef enum{
    RSCFD_e_RFIGCV_FIFO_1by8th_full = 0,    /* 000: Interrupt generated when FIFO is 1/8th full. */
    RSCFD_e_RFIGCV_FIFO_1by4th_full = 1,    /* 001: Interrupt generated when FIFO is 1/4th full. */
    RSCFD_e_RFIGCV_FIFO_3by8th_full = 2,    /* 010: Interrupt generated when FIFO is 3/8th full. */
    RSCFD_e_RFIGCV_FIFO_1by2_full   = 3,    /* 011: Interrupt generated when FIFO is 1/2 full. */
    RSCFD_e_RFIGCV_FIFO_5by8th_full = 4,    /* 100: Interrupt generated when FIFO is 5/8th full. */
    RSCFD_e_RFIGCV_FIFO_3by4th_full = 5,    /* 101: Interrupt generated when FIFO is 3/4th full. */
    RSCFD_e_RFIGCV_FIFO_7by8th_full = 6,    /* 110: Interrupt generated when FIFO is 7/8th full. */
    RSCFD_e_RFIGCV_FIFO_full        = 7     /* 111: Interrupt generated when FIFO is full. */
}RSCFD_e_RFIGCV;

/* RSCFDnCFDRFCCx.RFIM: RX FIFO Interrupt Mode */
typedef enum{
    RSCFD_e_RFIM_RXFIFO_reaches_RFIGCV = 0, /* 0: Interrupt generated when RX FIFO counter reaches RFIGCV value from values smaller than RFIGCV */
    RSCFD_e_RFIM_interrupt_generated   = 1  /* 1: Interrupt generated at the end of every received message storage */
}RSCFD_e_RFIM;
/* RSCFDnCFDRFCCx.RFDC: RX FIFO Depth Configuration */
typedef enum{
    RSCFD_e_RFDC_FIFO_depth_0messages   = 0,    /* 000: FIFO Depth = 0 messages */
    RSCFD_e_RFDC_FIFO_depth_4messages   = 1,    /* 001: FIFO Depth = 4 messages */
    RSCFD_e_RFDC_FIFO_depth_8messages   = 2,    /* 010: FIFO Depth = 8 messages */
    RSCFD_e_RFDC_FIFO_depth_16messages  = 3,    /* 011: FIFO Depth = 16 messages */
    RSCFD_e_RFDC_FIFO_depth_32messages  = 4,    /* 100: FIFO Depth = 32 messages */
    RSCFD_e_RFDC_FIFO_depth_48messages  = 5,    /* 101: FIFO Depth = 48 messages */
    RSCFD_e_RFDC_FIFO_depth_64messages  = 6,    /* 110: FIFO Depth = 64 messages */
    RSCFD_e_RFDC_FIFO_depth_128messages = 7     /* 111: FIFO Depth = 128 messages */
}RSCFD_e_RFDC;
/* RSCFDnCFDRFCCx.RFPLS: RX FIFO Payload Data Size configuration */
typedef enum{
    RSCFD_e_RFPLS_8bytes  = 0,  /* 000: 8 bytes */
    RSCFD_e_RFPLS_12bytes = 1,  /* 001: 12 bytes */
    RSCFD_e_RFPLS_16bytes = 2,  /* 010: 16 bytes */
    RSCFD_e_RFPLS_20bytes = 3,  /* 011: 20 bytes */
    RSCFD_e_RFPLS_24bytes = 4,  /* 100: 24 bytes */
    RSCFD_e_RFPLS_32bytes = 5,  /* 101: 32 bytes */
    RSCFD_e_RFPLS_48bytes = 6,  /* 110: 48 bytes */
    RSCFD_e_RFPLS_64bytes = 7   /* 111: 64 bytes */
}RSCFD_e_RFPLS;

/* RSCFDnCFDRFCCx.RFIE: RX FIFO Interrupt Enable */
typedef enum{
    RSCFD_e_RFIE_interrupt_generation_disabled = 0, /* 0: FIFO Interrupt generation disabled */
    RSCFD_e_RFIE_interrupt_generation_enabled  = 1  /* 1: FIFO Interrupt generation enabled */
}RSCFD_e_RFIE;

/* RSCFDnCFDRFCCx.RFE: RX FIFO Enable */
typedef enum{
    RSCFD_e_RFE_FIFO_disabled = 0,  /* 0: FIFO disabled */
    RSCFD_e_RFE_FIFO_enabled  = 1   /* 1: FIFO enabled */
}RSCFD_e_RFE;

/* RSCFDnCFDRFSTSx.RFDMASTS: DMA Transfer Status for RX FIFO for FFI Mode */
typedef enum{
    RSCFD_e_RFDMASTS_DMA_transfer_stopped = 0,  /* 1'b0: DMA transfer stopped */
    RSCFD_e_RFDMASTS_DMA_transfer_ongoing = 1   /* 1'b1: DMA transfer ongoing */
}RSCFD_e_RFDMASTS;

/* RSCFDnCFDRFSTSx.RFIF: RX FIFO Interrupt Flag */
typedef enum{
    RSCFD_e_RFIF_interrupt_condition_not_satisfied = 0, /* 0: FIFO Interrupt condition not satisfied */
    RSCFD_e_RFIF_interrupt_condition_satisfied     = 1  /* 1: FIFO Interrupt condition satisfied */
}RSCFD_e_RFIF;

/* RSCFDnCFDRFSTSx.RFMLT: RX FIFO Message Lost */
typedef enum{
    RSCFD_e_RFMLT_NO_message_lost_in_FIFO = 0,  /* 0: NO Message Lost in FIFO */
    RSCFD_e_RFMLT_FIFO_message_lost       = 1   /* 1: FIFO Message Lost */
}RSCFD_e_RFMLT;

/* RSCFDnCFDRFSTSx.RFFLL: RX FIFO Full */
typedef enum{
    RSCFD_e_RFFLL_FIFO_not_full = 0,    /* 0: FIFO Not Full */
    RSCFD_e_RFFLL_FIFO_full     = 1     /* 1: FIFO Full */
}RSCFD_e_RFFLL;

/* RSCFDnCFDRFPCTRx.RFEMP: RX FIFO Empty */
typedef enum{
    RSCFD_e_RFEMP_FIFO_not_empty = 0,   /* 0: FIFO Not Empty */
    RSCFD_e_RFEMP_FIFO_empty     = 1    /* 1: FIFO Empty */
}RSCFD_e_RFEMP;

/* RSCFDnCFDCFCCk.CFDC: Transmit/Receive FIFO Depth Configuration */
typedef enum{
    RSCFD_e_CFDC_FIFO_depth_0messages   = 0,    /* 000: FIFO Depth = 0 messages */
    RSCFD_e_CFDC_FIFO_depth_4messages   = 1,    /* 001: FIFO Depth = 4 messages */
    RSCFD_e_CFDC_FIFO_depth_8messages   = 2,    /* 010: FIFO Depth = 8 messages */
    RSCFD_e_CFDC_FIFO_depth_16messages  = 3,    /* 011: FIFO Depth = 16 messages */
    RSCFD_e_CFDC_FIFO_depth_32messages  = 4,    /* 100: FIFO Depth = 32 messages */
    RSCFD_e_CFDC_FIFO_depth_48messages  = 5,    /* 101: FIFO Depth = 48 messages */
    RSCFD_e_CFDC_FIFO_depth_64messages  = 6,    /* 110: FIFO Depth = 64 messages */
    RSCFD_e_CFDC_FIFO_depth_128messages = 7     /* 111: FIFO Depth = 128 messages */
}RSCFD_e_CFDC;

/* RSCFDnCFDRFCCx.CFIGCV: Transmit/Receive FIFO Interrupt Generation Counter Value */
typedef enum{
    RSCFD_e_CFIGCV_FIFO_1by8th_full = 0,    /* 000: Interrupt generated = when FIFO is 1/8th full. */
    RSCFD_e_CFIGCV_FIFO_1by4th_full = 1,    /* 001: Interrupt generated = when FIFO is 1/4th full. */
    RSCFD_e_CFIGCV_FIFO_3by8th_full = 2,    /* 010: Interrupt generated = when FIFO is 3/8th full. */
    RSCFD_e_CFIGCV_FIFO_1by2_full   = 3,    /* 011: Interrupt generated = when FIFO is 1/2 full. */
    RSCFD_e_CFIGCV_FIFO_5by8th_full = 4,    /* 100: Interrupt generated = when FIFO is 5/8th full. */
    RSCFD_e_CFIGCV_FIFO_3by4th_full = 5,    /* 101: Interrupt generated = when FIFO is 3/4th full. */
    RSCFD_e_CFIGCV_FIFO_7by8th_full = 6,    /* 110: Interrupt generated = when FIFO is 7/8th full. */
    RSCFD_e_CFIGCV_FIFO_full        = 7     /* 111: Interrupt generated = when FIFO is full. */
}RSCFD_e_CFIGCV;

/* RSCFDnCFDCFCCk.CFITR: Transmit/Receive FIFO Interval Timer Resolution */
typedef enum{
    RSCFD_e_CFITR_reference_clock_period_x1   = 0,  /* 0: Reference Clock Period x1 */
    RSCFD_e_CFITR_reference_clock_period_x10 = 1   /* 1: Reference Clock Period x10 */
}RSCFD_e_CFITR;

/* RSCFDnCFDCFCCk.CFITSS: Transmit/Receive FIFO Interval Timer Source Select */
typedef enum{
    RSCFD_e_CFITSS_reference_clock = 0, /* 0: Reference Clock (x1 / x10 period) */
    RSCFD_e_CFITSS_bit_time_clock  = 1  /* 1: Bit Time Clock of related channel (FIFO is linked to fixed channel) */
}RSCFD_e_CFITSS;

/* RSCFDnCFDCFCCk.CFM: Transmit/Receive FIFO Mode */
typedef enum{
    RSCFD_e_CFM_RX_FIFO_mode = 0,   /* 00: RX FIFO Mode */
    RSCFD_e_CFM_TX_FIFO_mode = 1,   /* 01: TX FIFO Mode */
    RSCFD_e_CFM_CAN_GW_FIFO_mode = 2   /* 10: CAN ― CAN GW FIFO Mode */
}RSCFD_e_CFM;

/* RSCFDnCFDCFCCk.CFPLS: Transmit/Receive FIFO Payload Data size configuration */
typedef enum{
    RSCFD_e_CFPLS_8bytes  = 0,  /* 000: 8 bytes */
    RSCFD_e_CFPLS_12bytes = 1,  /* 001: 12 bytes */
    RSCFD_e_CFPLS_16bytes = 2,  /* 010: 16 bytes */
    RSCFD_e_CFPLS_20bytes = 3,  /* 011: 20 bytes */
    RSCFD_e_CFPLS_24bytes = 4,  /* 100: 24 bytes */
    RSCFD_e_CFPLS_32bytes = 5,  /* 101: 32 bytes */
    RSCFD_e_CFPLS_48bytes = 6,  /* 110: 48 bytes */
    RSCFD_e_CFPLS_64bytes = 7   /* 111: 64 bytes */
}RSCFD_e_CFPLS;

/* RSCFDnCFDCFCCk.CFTXIE: Transmit/Receive FIFO TX Interrupt Enable */
typedef enum{
    RSCFD_e_CFTXIE_generation_disabled_for_frame_TX = 0,    /* 0: FIFO Interrupt generation disabled for Frame TX */
    RSCFD_e_CFTXIE_generation_enabled_for_frame_TX  = 1     /* 1: FIFO Interrupt generation enabled for Frame TX */
}RSCFD_e_CFTXIE;

/* RSCFDnCFDCFCCk.CFRXIE: Transmit/Receive FIFO RX Interrupt Enable */
typedef enum{
    RSCFD_e_CFRXIE_generation_disabled_for_frame_RX = 0,    /* 0: FIFO Interrupt generation disabled for Frame RX */
    RSCFD_e_CFRXIE_generation_enabled_for_frame_RX  = 1     /* 1: FIFO Interrupt generation enabled for Frame RX */
}RSCFD_e_CFRXIE;

/* RSCFDnCFDCFCCk.CFE: Transmit/Receive FIFO Enable */
typedef enum{
    RSCFD_e_CFE_FIFO_disabled = 0,  /* 0: FIFO disabled */
    RSCFD_e_CFE_FIFO_enabled  = 1   /* 1: FIFO enabled */
}RSCFD_e_CFE;

/* RSCFDnCFDCFCCEk.DMAE: DMA Transfer Enable for Transmit/Receive FIFO for FFI Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDCFCCEk_DMAE_DMA_transfer_request_disabled  = 0,    /* 1'b0: DMA Transfer Request disabled for channel m */
    RSCFD_e_RSCFDnCFDCFCCEk_DMAE_DMA_transfer_request_enabled   = 1     /* 1'b1: DMA Transfer Request enabled for channel m */
}RSCFD_e_RSCFDnCFDCFCCEk_DMAE;

/* RSCFDnCFDCFCCEk.MOWEIE: GW FIFO Message overwrite Error Interrupt Enable for FFI Mode */
typedef enum{
    RSCFD_e_MOWEIE_error_interrupt_disabled = 0,    /* 1'b0: GW FIFO Message overwrite Error Interrupt Disabled */
    RSCFD_e_MOWEIE_error_interrupt_enabled  = 1     /* 1'b1: GW FIFO Message overwrite Error Interrupt Enabled */
}RSCFD_e_MOWEIE;

/* RSCFDnCFDCFCCEk.MEIE: Message lost Error Interrupt Enable for FFI Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDCFCCEk_MEIE_message_lost_error_interrupt_disabled = 0, /* 1'b0: Message Lost Error Interrupt Disabled */
    RSCFD_e_RSCFDnCFDCFCCEk_MEIE_message_lost_error_interrupt_enabled  = 1  /* 1'b1: Message Lost Error Interrupt Enabled */
}RSCFD_e_RSCFDnCFDCFCCEk_MEIE;

/* RSCFDnCFDCFCCEk.CFBME: Transmit/Receive FIFO Buffering Mode Enable */
typedef enum{
    RSCFD_e_CFBME_transmission = 0,  /* 0: Transmission from Transmit/Receive FIFO */
    RSCFD_e_CFBME_transmission_halt = 1     /* 1: Transmission halt from Transmit/Receive FIFO */
}RSCFD_e_CFBME;

/* RSCFDnCFDCFCCEk.CFMOWM: Transmit/Receive FIFO message overwrite mode */
typedef enum{
    RSCFD_e_CFMOWM_message_discarded_mode = 0,  /* 0: Message discarded mode */
    RSCFD_e_CFMOWM_message_overwrite_mode = 1   /* 1: Message overwrite mode */
}RSCFD_e_CFMOWM;

/* RSCFDnCFDCFCCEk.CFOFTXIE: Transmit/Receive FIFO One Frame Transmission Interrupt Enable */
typedef enum{
    RSCFD_e_CFOFTXIE_TX_interrupt_generation_disabled = 0,  /* 0: One Frame TX Interrupt generation disabled */
    RSCFD_e_CFOFTXIE_TX_interrupt_generation_enabled  = 1   /* 1: One Frame TX Interrupt generation enabled */
}RSCFD_e_CFOFTXIE;

/* RSCFDnCFDCFCCEk.CFOFRXIE: Transmit/Receive FIFO One Frame Reception Interrupt Enable */
typedef enum{
    RSCFD_e_CFOFRXIE_RX_interrupt_generation_disabled = 0,  /* 0: One Frame RX Interrupt generation disabled */
    RSCFD_e_CFOFRXIE_RX_interrupt_generation_enabled  = 1   /* 1: One Frame RX Interrupt generation enabled */
}RSCFD_e_CFOFRXIE;

/* RSCFDnCFDCFCCEk.CFFIE: Transmit/Receive FIFO Full interrupt Enable */
typedef enum{
    RSCFD_e_CFFIE_FIFO_interrupt_generation_disabled = 0,   /* 0: FIFO Interrupt generation disabled */
    RSCFD_e_CFFIE_FIFO_interrupt_generation_enabled  = 1    /* 1: FIFO Interrupt generation enabled */
}RSCFD_e_CFFIE;

/* RSCFDnCFDCFSTSk.CFDMASTS: DMA Transfer Status for Common FIFO in FFI Mode */
typedef enum{
    RSCFD_e_CFDMASTS_DMA_transfer_request_disabled  = 0,    /* 1'b0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMASTS_DMA_transfer_request_enabled   = 1     /* 1'b1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMASTS;

/* RSCFDnCFDCFSTSk.CFMOW: Transmit/Receive FIFO message overwrite */
typedef enum{
    RSCFD_e_CFMOW_No_message_overwrite_occurred = 0,    /* 0: No Message overwrite occurred in FIFO */
    RSCFD_e_CFMOW_message_overwrite_occurred    = 1     /* 1: Message overwrite occurred in FIFO */
}RSCFD_e_CFMOW;

/* RSCFDnCFDCFSTSk.CFFIF: Transmit/Receive FIFO Full Interrupt Flag */
typedef enum{
    RSCFD_e_CFFIF_interrupt_condition_not_satisfied  = 0,   /* 0: Interrupt condition not satisfied for FIFO Full interrupt */
    RSCFD_e_CFFIF_interrupt_condition_satisfied      = 1    /* 1: Interrupt condition satisfied for FIFO Full interrupt */
}RSCFD_e_CFFIF;

/* RSCFDnCFDCFSTSk.CFDCFSTSk: Transmit/Receive TX FIFO Interrupt Flag */
typedef enum{
    RSCFD_e_CFDCFSTSk_interrupt_condition_interrupt_condition_not_satisfied  = 0,   /* interrupt condition not satisfied  */
    RSCFD_e_CFDCFSTSk_interrupt_condition_interrupt_condition_satisfied      = 1    /* interrupt condition satisfied  */
}RSCFD_e_CFDCFSTSk_interrupt_condition;

/* RSCFDnCFDCFSTSk.CFMLT: Transmit/Receive FIFO Message Lost */
typedef enum{
    RSCFD_e_CFMLT_No_message_lost_FIFO = 0, /* 0: No Message lost in FIFO */
    RSCFD_e_CFMLT_FIFO_message_lost    = 1  /* 1: FIFO Message Lost */
}RSCFD_e_CFMLT;

/* RSCFDnCFDCFSTSk.CFFLL: Transmit/Receive FIFO Full */
typedef enum{
    RSCFD_e_CFFLL_FIFO_not_full = 0,    /* 0: FIFO Not Full */
    RSCFD_e_CFFLL_FIFO_full     = 1     /* 1: FIFO Ful. */
}RSCFD_e_CFFLL;

/* RSCFDnCFDCFSTSk.CFEMP: Transmit/Receive FIFO Empty */
typedef enum{
    RSCFD_e_CFEMP_FIFO_not_empty = 0,   /* 0: FIFO Not Empty */
    RSCFD_e_CFEMP_FIFO_empty     = 1    /* 1: FIFO Empty */
}RSCFD_e_CFEMP;

/* RSCFDnCFDFESTS.CFDFESTS: Transmit/Receive FIFO Empty Status */
typedef enum{
    RSCFD_e_CFDFESTS_FIFO_status_FIFO_not_empty = 0,    /* FIFO not empty */
    RSCFD_e_CFDFESTS_FIFO_status_FIFO_empty     = 1     /* FIFO empty */
}RSCFD_e_CFDFESTS_FIFO_status;

/* RSCFDnCFDFMSTS.CFDFMSTS: Transmit/Receive FIFO Msg Lost Status */
typedef enum{
    RSCFD_e_CFDFMSTS_msg_lost_flag_not_set = 0, /* msg lost flag not set */
    RSCFD_e_CFDFMSTS_msg_lost_flag_set     = 1  /* msg lost flag set */
}RSCFD_e_CFDFMSTS;

/* RSCFDnCFDRFISTS.CFDRFISTS: RX FIFO[x] Interrupt Full Flag Status */
typedef enum{
    RSCFD_e_RSCFDnCFDRFISTS_CFDRFISTS_flag_not_set = 0, /* flag not set */
    RSCFD_e_RSCFDnCFDRFISTS_CFDRFISTS_flag_set     = 1  /* flag set */
}RSCFD_e_RSCFDnCFDRFISTS_CFDRFISTS;

/* RSCFDnCFDCFRISTS.CFDCFRISTS: Transmit/Receive FIFO [k] RX Interrupt Flag Status */
typedef enum{
    RSCFD_e_CFDCFRISTS_flag_not_set = 0,    /* flag not set */
    RSCFD_e_CFDCFRISTS_flag_set     = 1     /* flag set */
}RSCFD_e_CFDCFRISTS;

/* RSCFDnCFDFFFSTS.CFkFFLL: COMMON FIFO FDC level full Status */
typedef enum{
    RSCFD_e_CFkFFLL_FIFO_full_interrupt_not_set = 0,    /* 0: Corresponding FIFO Full interrupt not set */
    RSCFD_e_CFkFFLL_FIFO_full_interrupt_set     = 1     /* 1: Corresponding FIFO Full interrupt is set */
}RSCFD_e_CFkFFLL;

/* RSCFDnCFDFFFSTS.RFxFFLL: RX FIFO FDC level full Status */
typedef enum{
    RSCFD_e_RSCFDnCFDFFFSTS_RFxFFLL_FIFO_full_interrupt_not_set = 0,    /* 0: Corresponding FIFO Full interrupt not set */
    RSCFD_e_RSCFDnCFDFFFSTS_RFxFFLL_FIFO_full_interrupt_set     = 1     /* 1: Corresponding FIFO Full interrupt is set */
}RSCFD_e_RSCFDnCFDFFFSTS_RFxFFLL;

/* RSCFDnCFDCFMOWSTS.CFDCFMOWSTS: Transmit/Receive FIFO [k] Message overwrite Status */
typedef enum{
    RSCFD_e_CFDCFMOWSTS_FIFO_overwrite_flag_not_set = 0,    /* FIFO overwrite flag not set */
    RSCFD_e_CFDCFMOWSTS_FIFO_overwrite_flag_set     = 1     /* FIFO overwrite flag set */
}RSCFD_e_CFDCFMOWSTS;

/* RSCFDnCFDCDTCT.CFDCDTCT: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 7 */
typedef enum{
    RSCFD_e_RSCFDnCFDCDTCT_CFDCDTCT_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_RSCFDnCFDCDTCT_CFDCDTCT_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_RSCFDnCFDCDTCT_CFDCDTCT;

/* RSCFDnCFDCDTCT.CFDMAE6: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 6 */
typedef enum{
    RSCFD_e_CFDMAE6_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE6_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE6;

/* RSCFDnCFDCDTCT.CFDMAE5: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 5 */
typedef enum{
    RSCFD_e_CFDMAE5_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE5_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE5;

/* RSCFDnCFDCDTCT.CFDMAE4: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 4 */
typedef enum{
    RSCFD_e_CFDMAE4_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE4_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE4;

/* RSCFDnCFDCDTCT.CFDMAE3: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 3 */
typedef enum{
    RSCFD_e_CFDMAE3_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE3_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE3;

/* RSCFDnCFDCDTCT.CFDMAE2: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 2 */
typedef enum{
    RSCFD_e_CFDMAE2_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE2_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE2;

/* RSCFDnCFDCDTCT.CFDMAE1: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 1 */
typedef enum{
    RSCFD_e_CFDMAE1_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE1_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE1;

/* RSCFDnCFDCDTCT.CFDMAE0: DMA Transfer Enable for Transmit/Receive FIFO 0 of channel 0 */
typedef enum{
    RSCFD_e_CFDMAE0_disable = 0,    /* 0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDMAE0_enable  = 1     /* 1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDMAE0;

/* RSCFDnCFDCDTCT.RFDMAE7: DMA Transfer Enable for RXFIFO 7 */
typedef enum{
    RSCFD_e_RFDMAE7_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE7_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE7;

/* RSCFDnCFDCDTCT.RFDMAE6: DMA Transfer Enable for RXFIFO 6 */
typedef enum{
    RSCFD_e_RFDMAE6_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE6_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE6;

/* RSCFDnCFDCDTCT.RFDMAE5: DMA Transfer Enable for RXFIFO 5 */
typedef enum{
    RSCFD_e_RFDMAE5_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE5_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE5;

/* RSCFDnCFDCDTCT.RFDMAE4: DMA Transfer Enable for RXFIFO 4 */
typedef enum{
    RSCFD_e_RFDMAE4_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE4_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE4;

/* RSCFDnCFDCDTCT.RFDMAE3: DMA Transfer Enable for RXFIFO 3 */
typedef enum{
    RSCFD_e_RFDMAE3_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE3_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE3;

/* RSCFDnCFDCDTCT.RFDMAE2: DMA Transfer Enable for RXFIFO 2 */
typedef enum{
    RSCFD_e_RFDMAE2_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE2_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE2;

/* RSCFDnCFDCDTCT.RFDMAE1: DMA Transfer Enable for RXFIFO 1 */
typedef enum{
    RSCFD_e_RFDMAE1_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE1_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE1;

/* RSCFDnCFDCDTCT.RFDMAE0: DMA Transfer Enable for RXFIFO 0 */
typedef enum{
    RSCFD_e_RFDMAE0_disable = 0,    /* 0: DMA Transfer Request disabled */
    RSCFD_e_RFDMAE0_enable  = 1     /* 1: DMA Transfer Request enabled */
}RSCFD_e_RFDMAE0;

/* RSCFDnCFDCDTSTS */
typedef enum{
    RSCFD_e_CFDCDTSTS_stopped = 0,  /* stopped */
    RSCFD_e_CFDCDTSTS_ongoing = 1   /* ongoing */
}RSCFD_e_CFDCDTSTS;

/* RSCFDnCFDCDTTCT */
typedef enum{
    RSCFD_e_CFDCDTTCT_disabled = 0, /* disabled */
    RSCFD_e_CFDCDTTCT_enabled  = 1  /* enabled */
}RSCFD_e_CFDCDTTCT;

/* RSCFDnCFDCDTTSTS.CFDCDTTSTS: DMA TX Transfer Status only for Transmit/Receive FIFO 2 of channel 7 */
typedef enum{
    RSCFD_e_CFDCDTTSTS_stopped = 0, /* stopped */
    RSCFD_e_CFDCDTTSTS_enabled = 1  /* enabled */
}RSCFD_e_CFDCDTTSTS;

/* RSCFDnCFDGRINTSTSm */
typedef enum{
    RSCFD_e_CFDGRINTSTSm_not_set = 0,   /* not set */
    RSCFD_e_CFDGRINTSTSm_set     = 1    /* set */
}RSCFD_e_CFDGRINTSTSm;

/* RSCFDnCFDTMCp.TMOM: TX Message Buffer One-shot Mode */
typedef enum{
    RSCFD_e_TMOM_not_configured = 0,    /* 0: TX Message Buffer not configured in one-shot mode */
    RSCFD_e_TMOM_configured     = 1     /* 1: TX Message Buffer configured in one-shot mode */
}RSCFD_e_TMOM;

/* RSCFDnCFDTMCp.TMTAR: TX Message Buffer Transmission abort Request */
typedef enum{
    RSCFD_e_TMTAR_not_configured = 0,   /* 0: TX Message Buffer transmission request abort not requested */
    RSCFD_e_TMTAR_configured     = 1    /* 1: TX Message Buffer transmission request abort requested */
}RSCFD_e_TMTAR;

/* RSCFDnCFDTMCp.TMTR: TX Message Buffer Transmission Request */
typedef enum{
    RSCFD_e_TMTR_not_configured = 0,    /* 0: TX Message Buffer Transmission not requested */
    RSCFD_e_TMTR_configured     = 1     /* 1: TX Message Buffer Transmission requested */
}RSCFD_e_TMTR;

/* RSCFDnCFDTMSTSp.TMTARM: TX Message Buffer Transmission abort Request Mirrored */
typedef enum{
    RSCFD_e_TMTARM_not_requested = 0,   /* 0: TX Message Buffer transmission request abort not requested */
    RSCFD_e_TMTARM_requested     = 1    /* 1: TX Message Buffer transmission request abort requested */
}RSCFD_e_TMTARM;

/* RSCFDnCFDTMSTSp.TMTRM: TX Message Buffer Transmission Request Mirrored */
typedef enum{
    RSCFD_e_TMTRM_not_requested = 0,    /* 0: TX Message Buffer Transmission not requested */
    RSCFD_e_TMTRM_requested     = 1     /* 1: TX Message Buffer Transmission requested */
}RSCFD_e_TMTRM;

/* RSCFDnCFDTMSTSp.TMTRF: TX Message Buffer Transmission Result Flag */
typedef enum{
    RSCFD_e_TMTRF_no_result                = 0, /* 00B: No Result */
    RSCFD_e_TMTRF_trans_aborted_tx         = 1, /* 01B: Transmission aborted from the TX MB */
    RSCFD_e_TMTRF_trans_success_tx_not_req = 2, /* 10B: Transmission successful from the TX MB & Transmission abort was not requested */
    RSCFD_e_TMTRF_trans_success_tx_req     = 3  /* 11B: Transmission successful from the TX MB & Transmission abort was requested */
}RSCFD_e_TMTRF;

/* RSCFDnCFDTMSTSp.TMTSTS: TX Message Buffer Transmission Status */
typedef enum{
    RSCFD_e_TMTSTS_not_requested = 0,   /* 0: No transmission ongoing */
    RSCFD_e_TMTSTS_requested     = 1    /* 1: Transmission ongoing */
}RSCFD_e_TMTSTS;

/* RSCFDnCFDTXQCC0m */
typedef enum{
    RSCFD_e_CFDTXQCC0m_disabled = 0, /* 1'b0: DMA Transfer Request disabled for channel m */
    RSCFD_e_CFDTXQCC0m_enabled  = 1  /* 1'b1: DMA Transfer Request enabled for channel m */
}RSCFD_e_CFDTXQCC0m;

/* RSCFDnCFDTXQCC1m.QOWEIE: TXQ Message overwrite Error Interrupt Enable for FFI Mode */
typedef enum{
    RSCFD_e_CFDTXQCC1m_disabled = 0,    /* 1'b0: TXQ Message overwrite Error Interrupt Disabled */
    RSCFD_e_CFDTXQCC1m_enabled  = 1     /* 1'b1: TXQ Message overwrite Error Interrupt Enabled */
}RSCFD_e_CFDTXQCC1m;

/* RSCFDnCFDTXQCC2m */
typedef enum{
    RSCFD_e_CFDTXQCC2m_disabled = 0,    /* 1'b0: TXQ Message overwrite Error Interrupt Disabled */
    RSCFD_e_CFDTXQCC2m_enabled  = 1     /* 1'b1: TXQ Message overwrite Error Interrupt Enabled */
}RSCFD_e_CFDTXQCC2m;

/* RSCFDnCFDTXQCC2m.TXQIM: TX Queue Interrupt Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQCC2m_TXQIM_last_message_transmission = 0,    /* 0: when the last message is successfully transmitted */
    RSCFD_e_RSCFDnCFDTXQCC2m_TXQIM_every_transmission        = 1     /* 1: At every successful transmission */
}RSCFD_e_RSCFDnCFDTXQCC2m_TXQIM;

/* RSCFDnCFDTXQCC3m */
typedef enum{
    RSCFD_e_CFDTXQCC3m_disabled = 0,    /* disabled */
    RSCFD_e_CFDTXQCC3m_enabled  = 1     /* enabled */
}RSCFD_e_CFDTXQCC3m;

/* RSCFDnCFDTXQCC3m.TXQIM: TX Queue Interrupt Mode */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQCC3m_TXQIM_last_message_transmitted = 0, /* 0: when the last message is successfully transmitted */
    RSCFD_e_RSCFDnCFDTXQCC3m_TXQIM_every_transmission       = 1  /* 1: At every successful transmission */
}RSCFD_e_RSCFDnCFDTXQCC3m_TXQIM;

/* RSCFDnCFDTXQSTS0m.TXQDMASTS: DMA TX Transfer Status for TXQ0 */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQDMASTS_stopped = 0,  /* 1'b0: DMA transfer stopped */
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQDMASTS_enabled = 1   /* 1'b1: DMA transfer enable */
}RSCFD_e_RSCFDnCFDTXQSTS0m_TXQDMASTS;

/* RSCFDnCFDTXQSTS0m.TXQMOW: TXQ message overwrite */
typedef enum{
    RSCFD_e_TXQMOW_no_message_overwrite = 0,    /* 0: No Message overwrite in TXQ */
    RSCFD_e_TXQMOW_message_overwrite    = 1     /* 1: Message overwrite in TXQ */
}RSCFD_e_TXQMOW;

/* RSCFDnCFDTXQSTS0m.TXQMLT: TXQ Message Lost */
typedef enum{
    RSCFD_e_TXQMLT_no_message_lost = 0, /* no message lost */
    RSCFD_e_TXQMLT_message_lost    = 1  /* message lost */
}RSCFD_e_TXQMLT;

/* RSCFDnCFDTXQSTS0m.TXQTXIF: TX Queue TX Interrupt Flag */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQTXIF_interrupt_not_satisfied = 0,    /* 0: TX Queue TX interrupt condition not satisfied after Frame TX */
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQTXIF_interrupt_satisfied     = 1     /* 1: TX Queue TX interrupt condition satisfied after Frame TX */
}RSCFD_e_RSCFDnCFDTXQSTS0m_TXQTXIF;

/* RSCFDnCFDTXQSTS0m.TXQFLL: TX Queue Full */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQFLL_queue_not_full = 0,  /* 0: TX Queue Not Full */
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQFLL_queue_full     = 1   /* 1: TX Queue Full */
}RSCFD_e_RSCFDnCFDTXQSTS0m_TXQFLL;

/* RSCFDnCFDTXQSTS0m.TXQEMP: TX Queue Empty */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQEMP_queue_not_empty = 0, /* 0: TX Queue Not Empty */
    RSCFD_e_RSCFDnCFDTXQSTS0m_TXQEMP_queue_empty     = 1  /* 1: TX Queue Empty */
}RSCFD_e_RSCFDnCFDTXQSTS0m_TXQEMP;

/* RSCFDnCFDTXQSTS1m.TXQMOW: TXQ message overwrite */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQMOW_no_message_overwrite = 0,    /* 0: No Message overwrite in TXQ */
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQMOW_message_overwrite    = 1     /* 1: Message overwrite in TXQ */
}RSCFD_e_RSCFDnCFDTXQSTS1m_TXQMOW;

/* RSCFDnCFDTXQSTS1m.CFDTXQSTS1m: TXQ Message Lost */
typedef enum{
    RSCFD_e_CFDTXQSTS1m_no_message_lost = 0,    /* no message lost */
    RSCFD_e_CFDTXQSTS1m_message_lost    = 1     /* message lost */
}RSCFD_e_CFDTXQSTS1m;

/* RSCFDnCFDTXQSTS1m.TXQTXIF: TX Queue TX Interrupt Flag */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQTXIF_interrupt_not_satisfied = 0,    /* 0: TX Queue TX interrupt condition not satisfied after Frame TX */
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQTXIF_interrupt_satisfied     = 1     /* 1: TX Queue TX interrupt condition satisfied after Frame TX */
}RSCFD_e_RSCFDnCFDTXQSTS1m_TXQTXIF;

/* RSCFDnCFDTXQSTS1m.TXQFLL: TX Queue Full */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQFLL_queue_not_full = 0,  /* 0: TX Queue Not Full */
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQFLL_queue_full     = 1   /* 1: TX Queue Full */
}RSCFD_e_RSCFDnCFDTXQSTS1m_TXQFLL;

/* RSCFDnCFDTXQSTS1m.TXQEMP: TX Queue Empty */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQEMP_queue_not_empty = 0, /* 0: TX Queue Not Empty */
    RSCFD_e_RSCFDnCFDTXQSTS1m_TXQEMP_queue_empty     = 1  /* 1: TX Queue Empty */
}RSCFD_e_RSCFDnCFDTXQSTS1m_TXQEMP;

/* RSCFDnCFDTXQSTS2m.TXQMOW: TXQ message overwrite */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQMOW_no_message_overwrite = 0,    /* 0: No Message overwrite in TXQ */
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQMOW_message_overwrite    = 1     /* 1: Message overwrite in TXQ */
}RSCFD_e_RSCFDnCFDTXQSTS2m_TXQMOW;

/* RSCFDnCFDTXQSTS2m.CFDTXQSTS2m: TXQ Message Lost */
typedef enum{
    RSCFD_e_CFDTXQSTS2m_no_message_lost = 0,    /* no message lost */
    RSCFD_e_CFDTXQSTS2m_message_lost    = 1     /* message lost */
}RSCFD_e_CFDTXQSTS2m;

/* RSCFDnCFDTXQSTS2m.TXQTXIF: TX Queue TX Interrupt Flag */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQTXIF_interrupt_not_satisfied = 0,    /* 0: TX Queue TX interrupt condition not satisfied after Frame TX */
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQTXIF_interrupt_satisfied     = 1     /* 1: TX Queue TX interrupt condition satisfied after Frame TX */
}RSCFD_e_RSCFDnCFDTXQSTS2m_TXQTXIF;

/* RSCFDnCFDTXQSTS2m.TXQFLL: TX Queue Full */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQFLL_queue_not_full = 0,  /* 0: TX Queue Not Full */
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQFLL_queue_full     = 1   /* 1: TX Queue Full */
}RSCFD_e_RSCFDnCFDTXQSTS2m_TXQFLL;

/* RSCFDnCFDTXQSTS2m.TXQEMP: TX Queue Empty */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQEMP_queue_not_empty = 0, /* 0: TX Queue Not Empty */
    RSCFD_e_RSCFDnCFDTXQSTS2m_TXQEMP_queue_empty     = 1  /* 1: TX Queue Empty */
}RSCFD_e_RSCFDnCFDTXQSTS2m_TXQEMP;

/* RSCFDnCFDTXQSTS3m.TXQDMASTS: DMA TX Transfer Status for TXQ3 */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQDMASTS_stopped = 0,  /* 1'b0: DMA transfer stopped */
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQDMASTS_enable  = 1   /* 1'b1: DMA transfer enable */
}RSCFD_e_RSCFDnCFDTXQSTS3m_TXQDMASTS;

/* RSCFDnCFDTXQSTS3m.CFDTXQSTS3m: TXQ message overwrite */
typedef enum{
    RSCFD_e_CFDTXQSTS3m_no_message_overwrite = 0,   /* 0: No Message overwrite in TXQ */
    RSCFD_e_CFDTXQSTS3m_message_overwrite    = 1    /* 1: Message overwrite in TXQ */
}RSCFD_e_CFDTXQSTS3m;

/* RSCFDnCFDTXQSTS3m.TXQTXIF: TX Queue TX Interrupt Flag */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQTXIF_interrupt_not_satisfied = 0,    /* 0: TX Queue TX interrupt condition not satisfied after Frame TX */
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQTXIF_interrupt_satisfied     = 1     /* 1: TX Queue TX interrupt condition satisfied after Frame TX */
}RSCFD_e_RSCFDnCFDTXQSTS3m_TXQTXIF;

/* RSCFDnCFDTXQSTS3m.TXQFLL: TX Queue Full */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQFLL_queue_not_full = 0,   /* 0: TX Queue Not Full */
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQFLL_queue_full    = 1    /* 1: TX Queue Full */
}RSCFD_e_RSCFDnCFDTXQSTS3m_TXQFLL;

/* RSCFDnCFDTXQSTS3m.TXQEMP: TX Queue Empty */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQEMP_queue_not_empty = 0, /* 0: TX Queue Not Empty */
    RSCFD_e_RSCFDnCFDTXQSTS3m_TXQEMP_queue_empty     = 1  /* 1: TX Queue Empty */
}RSCFD_e_RSCFDnCFDTXQSTS3m_TXQEMP;

/* RSCFDnCFDTXQESTS.TXQxEMP: TXQ empty Status */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQESTS_TXQxEMP_queue_not_empty = 0,    /* queue not empty */
    RSCFD_e_RSCFDnCFDTXQESTS_TXQxEMP_queue_empty     = 1     /* queue empty */
}RSCFD_e_RSCFDnCFDTXQESTS_TXQxEMP;

/* RSCFDnCFDTXQFISTS.:  */
typedef enum{
    RSCFD_e_RSCFDnCFDTXQFISTS_TXQxEMP_interrupt_not_set = 0,  /* interrupt not set */
    RSCFD_e_RSCFDnCFDTXQFISTS_TXQxEMP_interrupt_set     = 1   /* interrupt set */
}RSCFD_e_RSCFDnCFDTXQFISTS_TXQxEMP;

/* RSCFDnCFDTXQMSTS.*/
typedef enum{
    RSCFD_e_TXQxML_message_flag_not_set = 0,    /* message flag not set */
    RSCFD_e_TXQxML_message_flag_set     = 1     /* message flag set */
}RSCFD_e_TXQxML;

/* RSCFDnCFDTXQOWSTS.*/
typedef enum{
    RSCFD_e_TXQxOW_message_write_not_set = 0,   /* message write not set */
    RSCFD_e_TXQxOW_message_write_set     = 1    /* message write set */
}RSCFD_e_TXQxOW;

/* RSCFDnCFDTXQISTS.*/
typedef enum{
    RSCFD_e_TXQxISF_interrupt_flag_not_set = 0, /* interrupt flag not set */
    RSCFD_e_TXQxISF_interrupt_flag_set     = 1  /* interrupt flag set */
}RSCFD_e_TXQxISF;

/* RSCFDnCFDTXQOFTISTS.*/
typedef enum{
    RSCFD_e_TXQxOFTISF_tx_interrupt_flag_not_set = 0,   /* tx interrupt flag not set */
    RSCFD_e_TXQxOFTISF_tx_interrupt_flag_set     = 1    /* tx interrupt flag set */
}RSCFD_e_TXQxOFTISF;

/* RSCFDnCFDTXQOFRISTS.*/
typedef enum{
    RSCFD_e_TXQxOFRISF_rx_interrupt_flag_not_set = 0,   /* rx interrupt flag not set */
    RSCFD_e_TXQxOFRISF_rx_interrupt_flag_set     = 1    /* rx interrupt flag set */
}RSCFD_e_TXQxOFRISF;

/* RSCFDnCFDTXQFSTS.*/
typedef enum{
    RSCFD_e_TXQxFSF_full_flag_not_set = 0,  /* full flag not set */
    RSCFD_e_TXQxFSF_full_flag_set     = 1   /* full flag set */
}RSCFD_e_TXQxFSF;

/* RSCFDnCFDTHLCCm.THLEIE: TX History List Entry Lost Interrupt Enable */
typedef enum{
    RSCFD_e_THLEIE_disabled = 0,    /* 1'b0: TX History List Entry Lost Interrupt Disabled. */
    RSCFD_e_THLEIE_enabled  = 1     /* 1'b1: TX History List Entry Lost Interrupt Enabled */
}RSCFD_e_THLEIE;

/* RSCFDnCFDTHLCCm.THLDGE: TX History List Dedicated GW Enable */
typedef enum{
    RSCFD_e_THLDGE_no_dedicate_gateway = 0, /* 0: Not dedicate Gateway FIFO + Gateway TX Queue. */
    RSCFD_e_THLDGE_dedicate_gateway    = 1  /* 1: Dedicate Gateway FIFO + Gateway TX Queue. */
}RSCFD_e_THLDGE;

/* RSCFDnCFDTHLCCm.THLDTE: TX History List Dedicated TX Enable */
typedef enum{
    RSCFD_e_THLDTE_tx_fifo_queue      = 0,  /* 0: TX FIFO + TX Queue. */
    RSCFD_e_THLDTE_flat_tx_fifo_queue = 1   /* 1: Flat TX MB + TX FIFO + TX Queue. */
}RSCFD_e_THLDTE;

/* RSCFDnCFDTHLCCm.THLIM: TX History List Interrupt Mode */
typedef enum{
    RSCFD_e_THLIM_int_gen_list_depth   = 0, /* 0: Interrupt generated if TX History List level reaches three-quarters of the TX History List depth. */
    RSCFD_e_THLIM_int_gen_stored_entry = 1  /* 1: Interrupt generated for every successfully stored entry. */
}RSCFD_e_THLIM;

/* RSCFDnCFDTHLCCm.THLIE: TX History List Interrupt Enable */
typedef enum{
    RSCFD_e_THLIE_disabled = 0, /* 0: TX History List Interrupt disabled. */
    RSCFD_e_THLIE_enabled  = 1  /* 1: TX History List Interrupt enabled. */
}RSCFD_e_THLIE;

/* RSCFDnCFDTHLCCm.THLE: TX History List Enable */
typedef enum{
    RSCFD_e_THLE_full_flag_not_set = 0, /* 0: TX History List disabled. */
    RSCFD_e_THLE_full_flag_set     = 1  /* 1: TX History List enabled. */
}RSCFD_e_THLE;

/* RSCFDnCFDTHLSTSm.THLIF: TX History List Interrupt Flag */
typedef enum{
    RSCFD_e_THLIF_not_satisfied = 0,    /* 0: TX History List Interrupt condition not satisfied. */
    RSCFD_e_THLIF_satisfied     = 1     /* 1: TX History List Interrupt condition satisfied. */
}RSCFD_e_THLIF;

/* RSCFDnCFDTHLSTSm.THLELT: TX History List Entry Lost */
typedef enum{
    RSCFD_e_THLELT_no_entry_lost = 0,   /* 0: No Entry Lost in TX History List. */
    RSCFD_e_THLELT_entry_lost    = 1    /* 1: TX History List Entry Lost. */
}RSCFD_e_THLELT;

/* RSCFDnCFDTHLSTSm.THLFLL: TX History List Full */
typedef enum{
    RSCFD_e_THLFLL_list_not_full = 0,   /* 0: TX History List Not Full. */
    RSCFD_e_THLFLL_list_full     = 1    /* 1: TX History List Full. */
}RSCFD_e_THLFLL;

/* RSCFDnCFDTHLSTSm.THLEMP: TX History List Empty */
typedef enum{
    RSCFD_e_THLEMP_not_empty = 0,   /* 0: TX History List Not Empty. */
    RSCFD_e_THLEMP_empty     = 1    /* 1: TX History List Empty. */
}RSCFD_e_THLEMP;

/* RSCFDnCFDTHLACC0m.TGW: Transmit Gateway Buffer indication */
typedef enum{
    RSCFD_e_TGW_not_transmission = 0,   /* 0: Not transmission from Gateway */
    RSCFD_e_TGW_transmission     = 1    /* 1: Transmission from Gateway. */
}RSCFD_e_TGW;

/* RSCFDnCFDCmCTR.BT: Buffer Type */
typedef enum{
    RSCFD_e_BT_message_buffer  = 1, /* 001: Flat TX Message Buffer */
    RSCFD_e_BT_tx_fifo_gw_fifo = 2, /* 010: TX FIFO MB Number and GW FIFO MB Number */
    RSCFD_e_BT_tx_queue        = 4  /* 100: TX Queue MB Number. */

}RSCFD_e_BT;

/* RSCFDnCFDGRSTC.SRST: Software reset */
typedef enum{
    RSCFD_e_SRST_normal         = 0,    /* 0: Normal state. */
    RSCFD_e_SRST_software_reset = 1     /* 1: Software reset state. */
}RSCFD_e_SRST;

/* RSCFDnCFDGFCMC.FLXCx: Flexible CAN mode between Channel 7 and Channel 6 */
typedef enum{
    RSCFD_e_FLXCx_normal_mode       = 0,    /* normal mode */
    RSCFD_e_FLXCx_flexible_can_mode = 1     /* flexible can mode */
}RSCFD_e_FLXCx;

/* RSCFDnCFDGTSTCFG.PNFS: Pretended Network Filter List RAM Select */
typedef enum{
    RSCFD_e_PNFS_aflram_mram_selected              = 0, /* 1'b0: AFL RAM, MRAM area is selected */
    RSCFD_e_PNFS_pretended_net_filter_ram_selected = 1  /* 1'b1: Pretended Network Filter RAM area is selected */
}RSCFD_e_PNFS;

/* .CmICBCE: Channel m Internal CAN Bus Communication Test Mode Enable */
typedef enum{
    RSCFD_e_CmICBCE_disabled = 0,   /* 0: Channel m internal CAN bus communication disabled. */
    RSCFD_e_CmICBCE_enebled  = 1    /* 1: Channel m internal CAN bus communication enabled. */
}RSCFD_e_CmICBCE;

/* RSCFDnCFDGTSTCTR */
typedef enum{
    RSCFD_e_CFDGTSTCTR_disabled = 0,    /* disabled */
    RSCFD_e_CFDGTSTCTR_enebled  = 1     /* enebled */
}RSCFD_e_CFDGTSTCTR;

/* RSCFDnCFDGFDCFG.TSCCFG: Timestamp capture configuration */
typedef enum{
    RSCFD_e_TSCCFG_sample_point_sof       = 0,  /* 00: Timestamp capture at the sample point of SOF (start of frame). */
    RSCFD_e_TSCCFG_frame_valid_indication = 1,  /* 01: Timestamp capture at frame valid indication. */
    RSCFD_e_TSCCFG_res_bit                = 2   /* 10: Timestamp capture at the sample point of RES bit */

}RSCFD_e_TSCCFG;

/* RSCFDnCFDGFDCFG.RPED: RES bit Protocol exception disable */
typedef enum{
    RSCFD_e_RPED_disabled = 0,  /* disabled */
    RSCFD_e_RPED_enebled  = 1   /* enebled */
}RSCFD_e_RPED;

/* RSCFDnCFDCmBLCT.BLCE: BUS Load counter Enable */
typedef enum{
    RSCFD_e_BLCE_disabled = 0,  /* 0: BUS Load counter disable. */
    RSCFD_e_BLCE_enebled  = 1   /* 1: BUS Load counter enable. */
}RSCFD_e_BLCE;

/* RSCFDnCFDGFFIMC.FFIEN: FFI Mode Enable */
typedef enum{
    RSCFD_e_FFIEN_disabled = 0, /* 1'b0: FFI Mode disabled. */
    RSCFD_e_FFIEN_enebled  = 1  /* 1'b1: FFI Mode enabled. */
}RSCFD_e_FFIEN;

/* RSCFDnCFDVMISTSm */
typedef enum{
    RSCFD_e_CFDVMISTSm_ERRORDETECTION_not_detected = 0, /* not detected */
    RSCFD_e_CFDVMISTSm_ERRORDETECTION_detected     = 1  /* detected */
}RSCFD_e_CFDVMISTSm_ERRORDETECTION;

/* RSCFDnCFDVMISTSm */
typedef enum{
    RSCFD_e_CFDVMISTSm_INTERRUPTSTATUS_flag_not_set = 0,    /* not set */
    RSCFD_e_CFDVMISTSm_INTERRUPTSTATUS_flag_set     = 1     /* set */
}RSCFD_e_CFDVMISTSm_INTERRUPTSTATUS;

/* RSCFDnCFDGPFLECTR.PFLDAE: Pretended Network Filter List Data Access Enable */
typedef enum{
    RSCFD_e_PFLDAE_disabled = 0,    /* 1'b0: Pretended Network Filter List Data access disabled */
    RSCFD_e_PFLDAE_enabled  = 1     /* 1'b1: Pretended Network Filter List Data access enabled */
}RSCFD_e_PFLDAE;

/* RSCFDnCFDGPFLIDs.GPFLIDE: Global Pretended Network Filter List IDE Field */
typedef enum{
    RSCFD_e_GPFLIDE_standard_identifier = 0,    /* 1'b0: Standard Identifier of Rule entry ID is valid for acceptance filtering */
    RSCFD_e_GPFLIDE_extended_identifier = 1     /* 1'b1: Extended Identifier of Rule entry ID is valid for acceptance filtering */
}RSCFD_e_GPFLIDE;

/* RSCFDnCFDGPFLIDs.GPFLRTR: Global Pretended Network Filter List Entry RTR Field */
typedef enum{
    RSCFD_e_GPFLRTR_date_frame   = 0,   /* 1'b0: Data Frame */
    RSCFD_e_GPFLRTR_remote_frame = 1    /* 1'b1: Remote Frame */
}RSCFD_e_GPFLRTR;

/* RSCFDnCFDGPFLIDs.GPFLLB: Global Pretended Network Filter List Entry Loopback Configuration */
typedef enum{
    RSCFD_e_GPFLLB_rx_attribute = 0,    /* 1'b0: Global Pretended Network Filter List entry ID for acceptance filtering has attribute 'RX' */
    RSCFD_e_GPFLLB_tx_attribute = 1     /* 1'b1: Global Pretended Network Filter List entry ID for acceptance filtering has attribute 'TX' */
}RSCFD_e_GPFLLB;

/*  RSCFDnCFDGPFLMs */
typedef enum{
    RSCFD_e_CFDGPFLMs_not_for_id_match = 0, /* not for id match */
    RSCFD_e_CFDGPFLMs_for_id_match     = 1  /* for id match */
}RSCFD_e_CFDGPFLMs;

/* RSCFDnCFDGPFLP0s.GPFLRMV: Global Pretended Network Filter List RX Message Buffer Valid */
typedef enum{
    RSCFD_e_GPFLRMV_invalid = 0,    /* 1'b0: Global Pretended Network Filter List Single Message Buffer Direction Pointer is invalid */
    RSCFD_e_GPFLRMV_ivalid  = 1     /* 1'b1: Global Pretended Network Filter List Single Message Buffer Direction Pointer is valid. */
}RSCFD_e_GPFLRMV;

/* RSCFDnCFDGPFLP0s.GPFLSRDx: Global Pretended Network Filter List Select Routing destination 2 */
typedef enum{
    RSCFD_e_GPFLSRDx_target_CFIFO2     = 0, /* target CFIFO2 */
    RSCFD_e_GPFLSRDx_target_TX_Queue_2 = 1  /* target TX Queue 2 */
}RSCFD_e_GPFLSRDx;

/*  RSCFDnCFDGPFLPTs.GPFLANDOR: Global Pretended Network filter conditions of the filters 0 and 1 */
typedef enum{
    RSCFD_e_GPFLANDOR_both_1_and_0  = 0,    /* 1'b0: Both of filters 0 and 1 are successful */
    RSCFD_e_GPFLANDOR_one_of_filter = 1     /* 1'b1: One of the filter 0 or 1 is successful */
}RSCFD_e_GPFLANDOR;

/*  RSCFDnCFDGPFLPTs */
typedef enum{
    RSCFD_e_CFDGPFLPTs_FILTER0_payload_data_match = 0,  /* payload data match */
    RSCFD_e_CFDGPFLPTs_FILTER0_upper_lower        = 1   /* upper lower */
}RSCFD_e_CFDGPFLPTs_FILTER0;

/*  RSCFDnCFDGPFLPTs.CFDGPFLPTs: Global Pretended Network filter conditions of upper / lower filter of the filter0 */
typedef enum{
    RSCFD_e_CFDGPFLPTs_FILTERCONDITION_with_in_range = 0,   /* 1'b0: Within the range of upper limit and lower limit */
    RSCFD_e_CFDGPFLPTs_FILTERCONDITION_outside_range = 1    /* 1'b1: Outside of the range of upper limit and lower limit */
}RSCFD_e_CFDGPFLPTs_FILTERCONDITION;

/* RSCFDnCFDRMID.RMIDE: RX Message Buffer IDE Bit */
typedef enum{
    RSCFD_e_RMIDE_STDID_is_stored = 0, /* 0B: STD-ID is stored */
    RSCFD_e_RMIDE_EXTID_is_stored = 1  /* 1B: EXT-ID is stored */
}RSCFD_e_RMIDE;

/* RSCFDnCFDRMID.RMRTR: RX Message Buffer RTR */
typedef enum{
    RSCFD_e_RMRTR_data_frame   = 0, /* 0: Data Frame */
    RSCFD_e_RMRTR_remote_frame = 1  /* 1: Remote Frame */
}RSCFD_e_RMRTR;

/* RSCFDnCFDRMFDSTS .RMFDF: CANFD Format bit */
typedef enum{
    RSCFD_e_RMFDF_non_canfd_frame = 0,  /* 0: Non CANFD frame received */
    RSCFD_e_RMFDF_canfd_frame     = 1   /* 1: CANFD frame received */
}RSCFD_e_RMFDF;

/* RSCFDnCFDRMFDSTS .RMBRS: Bit Rate Switch bit */
typedef enum{
    RSCFD_e_RMBRS_no_bitrate   = 0, /* 0: CANFD frame received with no bit rate switch */
    RSCFD_e_RMBRS_with_bitrate = 1  /* 1: CANFD frame received with bit rate switch */
}RSCFD_e_RMBRS;

/* RSCFDnCFDRMFDSTS .RMESI: Error State Indicator bit */
typedef enum{
    RSCFD_e_RMESI_active_node  = 0, /* 0: CANFD frame received from error active node */
    RSCFD_e_RMESI_passive_node = 1  /* 1: CANFD frame received from error passive node */
}RSCFD_e_RMESI;

/* RSCFDnCFDRFID .RFIDE: RX FIFO Buffer IDE Bit */
typedef enum{
    RSCFD_e_RFIDE_STD_ID = 0,   /* 0B: STD-ID has been received */
    RSCFD_e_RFIDE_EXT_ID = 1    /* 1B: EXT-ID has been received */
}RSCFD_e_RFIDE;

/* RSCFDnCFDRFID .RFRTR: RX FIFO Buffer RTR Bit */
typedef enum{
    RSCFD_e_RFRTR_data_frame   = 0, /* 0B: Data Frame */
    RSCFD_e_RFRTR_remote_frame = 1  /* 1B: Remote Frame */
}RSCFD_e_RFRTR;

/* RSCFDnCFDRFFDSTS .RFFDF: CANFD Format bit */
typedef enum{
    RSCFD_e_RFFDF_non_canfd_frame = 0,  /* 0B: Non CANFD frame received */
    RSCFD_e_RFFDF_canfd_frame     = 1   /* 1B: CANFD frame received */
}RSCFD_e_RFFDF;

/* RSCFDnCFDRFFDSTS .RFBRS: Bit Rate Switch bit */
typedef enum{
    RSCFD_e_RFBRS_no_bitrate   = 0, /* 0: CANFD frame received with no bit rate switch */
    RSCFD_e_RFBRS_with_bitrate = 1  /* 1: CANFD frame received with bit rate switch */
}RSCFD_e_RFBRS;

/* RSCFDnCFDRFFDSTS .RFESI: Error State Indicator bit */
typedef enum{
    RSCFD_e_RFESI_active_node  = 0, /* 0: CANFD frame received from error active node */
    RSCFD_e_RFESI_passive_node = 1  /* 1: CANFD frame received from error passive node */
}RSCFD_e_RFESI;

/* RSCFDnCFDCFID .CFIDE: Transmit/Receive FIFO Buffer IDE Bit */
typedef enum{
    RSCFD_e_CFIDE_STD_ID = 0,   /* 0B: STD-ID will be transmitted or has been received */
    RSCFD_e_CFIDE_EXT_ID = 1    /* 1B: EXT-ID will be transmitted or has been received */
}RSCFD_e_CFIDE;

/* RSCFDnCFDCFID .CFRTR: Transmit/Receive FIFO Buffer RTR Bit */
typedef enum{
    RSCFD_e_CFRTR_data_frame   = 0, /* 0B: Data Frame */
    RSCFD_e_CFRTR_remote_frame = 1  /* 1B: Remote Frame */
}RSCFD_e_CFRTR;

/* RSCFDnCFDCFID .THLEN: THL Entry enableTX FIFO Mode: */
typedef enum{
    RSCFD_e_RSCFDnCFDCFID_THLEN_entry_not_stored = 0, /* 0B: Entry will not be stored in THL after successful TX. */
    RSCFD_e_RSCFDnCFDCFID_THLEN_entry_stored     = 1  /* 1B: Entry will be stored in THL after successful TX.RX FIFO Mode:Reserved, this bit is read as 0 */
}RSCFD_e_RSCFDnCFDCFID_THLEN;

/* .CFFDF: CANFD Format bit */
typedef enum{
    RSCFD_e_CFFDF_non_canfd_frame = 0,  /* 0B: Non CANFD frame received or to transmit */
    RSCFD_e_CFFDF_canfd_frame     = 1   /* 1B: CANFD frame received or to transmit */
}RSCFD_e_CFFDF;

/* .CFBRS: Bit Rate Switch bit */
typedef enum{
    RSCFD_e_CFBRS_no_bitrate   = 0, /* 0B: CANFD frame received or to transmit with no bit rate switch */
    RSCFD_e_CFBRS_with_bitrate = 1  /* 1B: CANFD frame received or to transmit with bit rate switch */
}RSCFD_e_CFBRS;

/* .CFESI: Error State Indicator bit */
typedef enum{
    RSCFD_e_CFESI_active_node  = 0, /* 0B: CANFD frame received from or to transmit by error active node */
    RSCFD_e_CFESI_passive_node = 1    /* 1B: CANFD frame received from or to transmit by error passive node */
}RSCFD_e_CFESI;

/*  RSCFDnCFDTMID .TMIDE: TX Message Buffer IDE Bit */
typedef enum{
    RSCFD_e_TMIDE_STD_ID = 0,   /* 0B: STD-ID will be transmitted */
    RSCFD_e_TMIDE_EXT_ID = 1    /* 1B: EXT-ID will be transmitted */
}RSCFD_e_TMIDE;

/*  RSCFDnCFDTMID .TMRTR: TMRTR TX Message Buffer RTR Bit */
typedef enum{
    RSCFD_e_TMRTR_data_frame   = 0, /* 0B: Data Frame */
    RSCFD_e_TMRTR_remote_frame = 1  /* 1B: Remote Frame */
}RSCFD_e_TMRTR;

/*  RSCFDnCFDTMID .THLEN: Tx History List Entry */
typedef enum{
    RSCFD_e_RSCFDnCFDTMID_THLEN_entry_not_stored = 0, /* 0B: Entry not stored in THL after successful TX */
    RSCFD_e_RSCFDnCFDTMID_THLEN_entry_stored     = 1  /* 1B: Entry stored in THL after successful TX */
}RSCFD_e_RSCFDnCFDTMID_THLEN;

/* RSCFDnCFDTMFDCTR .TMFDF: CANFD Format bit */
typedef enum{
    RSCFD_e_TMFDF_non_canfd_frame = 0,  /* 0B: Non CANFD frame to transmit */
    RSCFD_e_TMFDF_canfd_frame     = 1   /* 1B: CANFD frame to transmit */
}RSCFD_e_TMFDF;

/* RSCFDnCFDTMFDCTR .TMBRS: Bit Rate Switch bit */
typedef enum{
    RSCFD_e_TMBRS_no_bitrate   = 0, /* 0B: CANFD frame to transmit with no bit rate switch */
    RSCFD_e_TMBRS_with_bitrate = 1  /* 1B: CANFD frame to transmit with bit rate switch */
}RSCFD_e_TMBRS;

/* RSCFDnCFDTMFDCTR .TMESI: Error State Indicator bit */
typedef enum{
    RSCFD_e_TMESI_active_node  = 0, /* 0B: CANFD frame to transmit by error active node */
    RSCFD_e_TMESI_passive_node = 1    /* 1B: CANFD frame to transmit by error passive node */
}RSCFD_e_TMESI;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* RSCFDnCFDC0NCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                NBRP            :10;
        uint32_t                NSJW            :7;
        uint32_t                NTSEG1          :8;
        RSCFD_e_NTSEG2          NTSEG2          :7;
    }BIT;
}RSCFD_s_RSCFDnCFDC0NCFG;

/* RSCFDnCFDC0CTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CHMDC           CHMDC           :2;
        RSCFD_e_CSLPR           CSLPR           :1;
        RSCFD_e_RTBO            RTBO            :1;
        uint32_t                Reserved_4      :4;
        RSCFD_e_BEIE            BEIE            :1;
        RSCFD_e_EWIE            EWIE            :1;
        RSCFD_e_EPIE            EPIE            :1;
        RSCFD_e_BOEIE           BOEIE           :1;
        RSCFD_e_BORIE           BORIE           :1;
        RSCFD_e_OLIE            OLIE            :1;
        RSCFD_e_BLIE            BLIE            :1;
        RSCFD_e_ALIE            ALIE            :1;
        RSCFD_e_EOCOIE          EOCOIE          :1;
        RSCFD_e_SOCOIE          SOCOIE          :1;
        RSCFD_e_TDCVFIE         TDCVFIE         :1;
        uint32_t                Reserved_20     :1;
        RSCFD_e_BOM             BOM             :2;
        RSCFD_e_ERRD            ERRD            :1;
        RSCFD_e_CTME            CTME            :1;
        RSCFD_e_CTMS            CTMS            :2;
        RSCFD_e_TRWE            TRWE            :1;
        RSCFD_e_TRH             TRH             :1;
        RSCFD_e_TRR             TRR             :1;
        RSCFD_e_CRCT            CRCT            :1;
        RSCFD_e_ROM             ROM             :1;
    }BIT;
}RSCFD_s_RSCFDnCFDC0CTR;

/* RSCFDnCFDC0STS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CRSTSTS         CRSTSTS         :1;
        RSCFD_e_CHLTSTS         CHLTSTS         :1;
        RSCFD_e_CSLPSTS         CSLPSTS         :1;
        RSCFD_e_EPSTS           EPSTS           :1;
        RSCFD_e_BOSTS           BOSTS           :1;
        RSCFD_e_TRMSTS          TRMSTS          :1;
        RSCFD_e_RECSTS          RECSTS          :1;
        RSCFD_e_COMSTS          COMSTS          :1;
        RSCFD_e_ESIF            ESIF            :1;
        uint32_t                Reserved_9      :7;
        uint32_t                REC             :8;
        uint32_t                TEC             :8;
    }BIT;
}RSCFD_s_RSCFDnCFDC0STS;

/* RSCFDnCFDC0ERFL register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_BEF             BEF             :1;
        RSCFD_e_EWF             EWF             :1;
        RSCFD_e_EPF             EPF             :1;
        RSCFD_e_BOEF            BOEF            :1;
        RSCFD_e_BORF            BORF            :1;
        RSCFD_e_OVLF            OVLF            :1;
        RSCFD_e_BLF             BLF             :1;
        RSCFD_e_ALF             ALF             :1;
        RSCFD_e_SERR            SERR            :1;
        RSCFD_e_FERR            FERR            :1;
        RSCFD_e_AERR            AERR            :1;
        RSCFD_e_CERR            CERR            :1;
        RSCFD_e_B1ERR           B1ERR           :1;
        RSCFD_e_B0ERR           B0ERR           :1;
        RSCFD_e_ADERR           ADERR           :1;
        uint32_t                Reserved_15     :1;
        uint32_t                CRCREG          :15;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDC0ERFL;

/* RSCFDnCFDC0DCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                DBRP            :8;
        uint32_t                DTSEG1          :5;
        uint32_t                Reserved_13     :3;
        uint32_t                DTSEG2          :4;
        uint32_t                Reserved_20     :4;
        uint32_t                DSJW            :4;
        uint32_t                Reserved_28     :4;
    }BIT;
}RSCFD_s_RSCFDnCFDC0DCFG;

/* RSCFDnCFDGFDCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RPED            RPED            :1;
        uint32_t                Reserved_1      :7;
        RSCFD_e_TSCCFG          TSCCFG          :2;
        uint32_t                Reserved_10     :22;
    }BIT;
}RSCFD_s_RSCFDnCFDGFDCFG;

/* RSCFDnCFDC0FDCTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_EOCCLR          EOCCLR          :1;
        RSCFD_e_SOCCLR          SOCCLR          :1;
        uint32_t                Reserved_2      :14;
        RSCFD_e_PNMDC           PNMDC           :2;
        uint32_t                Reserved_18     :6;
        RSCFD_e_KEY             KEY             :8;
    }BIT;
}RSCFD_s_RSCFDnCFDC0FDCTR;

/* RSCFDnCFDC0FDSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TDCR            :8;
        RSCFD_e_EOCO            EOCO            :1;
        RSCFD_e_SOCO            SOCO            :1;
        uint32_t                Reserved_10     :2;
        RSCFD_e_PNSTS           PNSTS           :2;
        uint32_t                Reserved_14     :1;
        RSCFD_e_TDCVF           TDCVF           :1;
        uint32_t                EOC             :8;
        uint32_t                SOC             :8;
    }BIT;
}RSCFD_s_RSCFDnCFDC0FDSTS;

/* RSCFDnCFDC0FDCRC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CRCREG          :21;
        uint32_t                Reserved_21     :3;
        uint32_t                SCNT            :4;
        uint32_t                Reserved_28     :4;
    }BIT;
}RSCFD_s_RSCFDnCFDC0FDCRC;

/* RSCFDnCFDGIPV register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_IPV             IPV             :8;
        RSCFD_e_IPT             IPT             :2;
        uint32_t                Reserved_10     :6;
        uint32_t                PSI             :14;
        uint32_t                Reserved_30     :2;
    }BIT;
}RSCFD_s_RSCFDnCFDGIPV;

/* RSCFDnCFDGCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_TPRI            TPRI            :1;
        RSCFD_e_DCE             DCE             :1;
        RSCFD_e_DRE             DRE             :1;
        RSCFD_e_MME             MME             :1;
        RSCFD_e_DCS             DCS             :1;
        uint32_t                CMPO            :1;
        uint32_t                Reserved_6      :2;
        uint32_t                TSP             :4;
        RSCFD_e_TSSS            TSSS            :1;
        RSCFD_e_TSBTCS          TSBTCS          :3;
        uint32_t                ITRCP           :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGCFG;

/* RSCFDnCFDGCTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_GMDC            GMDC            :2;
        uint32_t                GSLP            :1;
        uint32_t                Reserved_3      :5;
        uint32_t                DEIE            :1;
        uint32_t                MEIE            :1;
        RSCFD_e_THLEIE          THLEIE          :1;
        uint32_t                CMPOFIE         :1;
        uint32_t                QOWEIE          :1;
        uint32_t                Reserved_13     :1;
        uint32_t                QMEIE           :1;
        RSCFD_e_MOWEIE          MOWEIE          :1;
        RSCFD_e_TSRST           TSRST           :1;
        uint32_t                TSWR            :1;
        uint32_t                Reserved_18     :14;
    }BIT;
}RSCFD_s_RSCFDnCFDGCTR;

/* RSCFDnCFDGSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_GRSTSTS         GRSTSTS         :1;
        RSCFD_e_GHLTSTS         GHLTSTS         :1;
        RSCFD_e_GSLPSTS         GSLPSTS         :1;
        RSCFD_e_GRAMINIT        GRAMINIT        :1;
        uint32_t                Reserved_4      :28;
    }BIT;
}RSCFD_s_RSCFDnCFDGSTS;

/* RSCFDnCFDGERFL register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                DEF             :1;
        uint32_t                MES             :1;
        uint32_t                THLES           :1;
        uint32_t                CMPOF           :1;
        uint32_t                QOWES           :1;
        uint32_t                OTBMLTSTS       :1;
        uint32_t                QMES            :1;
        uint32_t                MOWES           :1;
        uint32_t                RXSFAIL0        :1;
        uint32_t                RXSFAIL1        :1;
        uint32_t                RXSFAIL2        :1;
        uint32_t                RXSFAIL3        :1;
        uint32_t                RXSFAIL4        :1;
        uint32_t                RXSFAIL5        :1;
        uint32_t                RXSFAIL6        :1;
        uint32_t                RXSFAIL7        :1;
        uint32_t                EEF0            :1;
        uint32_t                EEF1            :1;
        uint32_t                EEF2            :1;
        uint32_t                EEF3            :1;
        uint32_t                EEF4            :1;
        uint32_t                EEF5            :1;
        uint32_t                EEF6            :1;
        uint32_t                EEF7            :1;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDGERFL;

/* RSCFDnCFDGTINTSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TSIF0           :1;
        uint32_t                TAIF0           :1;
        uint32_t                TQIF0           :1;
        uint32_t                CFTIF0          :1;
        uint32_t                THIF0           :1;
        uint32_t                TQOFIF0         :1;
        uint32_t                CFOTIF0         :1;
        uint32_t                Reserved_7      :1;
        uint32_t                TSIF1           :1;
        uint32_t                TAIF1           :1;
        uint32_t                TQIF1           :1;
        uint32_t                CFTIF1          :1;
        uint32_t                THIF1           :1;
        uint32_t                TQOFIF1         :1;
        uint32_t                CFOTIF1         :1;
        uint32_t                Reserved_15     :1;
        uint32_t                TSIF2           :1;
        uint32_t                TAIF2           :1;
        uint32_t                TQIF2           :1;
        uint32_t                CFTIF2          :1;
        uint32_t                THIF2           :1;
        uint32_t                TQOFIF2         :1;
        uint32_t                CFOTIF2         :1;
        uint32_t                Reserved_23     :1;
        uint32_t                TSIF3           :1;
        uint32_t                TAIF3           :1;
        uint32_t                TQIF3           :1;
        uint32_t                CFTIF3          :1;
        uint32_t                THIF3           :1;
        uint32_t                TQOFIF3         :1;
        uint32_t                CFOTIF3         :1;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGTINTSTS0;

/* RSCFDnCFDGTSC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TS              :16;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGTSC;

/* RSCFDnCFDGAFLECTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                AFLPN           :7;
        uint32_t                Reserved_7      :1;
        RSCFD_e_AFLDAE          AFLDAE          :1;
        uint32_t                Reserved_9      :23;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLECTR;

/* RSCFDnCFDGAFLCFG0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RNC1            :9;
        uint32_t                Reserved_9      :7;
        uint32_t                RNC0            :9;
        uint32_t                Reserved_25     :7;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLCFG0;

/* RSCFDnCFDGAFLID0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GAFLID          :29;
        RSCFD_e_GAFLLB          GAFLLB          :1;
        RSCFD_e_GAFLRTR         GAFLRTR         :1;
        RSCFD_e_GAFLIDE         GAFLIDE         :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLID0;

/* RSCFDnCFDGAFLM0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GAFLIDM         :29;
        uint32_t                GAFLIFL1        :1;
        RSCFD_e_GAFLRTRM        GAFLRTRM        :1;
        RSCFD_e_GAFLIDEM        GAFLIDEM        :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLM0;

/* RSCFDnCFDGAFLP00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GAFLDLC         :4;
        RSCFD_e_GAFLSRD0        GAFLSRD0        :1;
        RSCFD_e_GAFLSRD1        GAFLSRD1        :1;
        RSCFD_e_GAFLSRD2        GAFLSRD2        :1;
        uint32_t                GAFLIFL0        :1;
        uint32_t                GAFLRMDP        :7;
        RSCFD_e_GAFLRMV         GAFLRMV         :1;
        uint32_t                GAFLPTR         :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLP00;

/* RSCFDnCFDGAFLP10 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GAFLFDP         :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGAFLP10;

/* RSCFDnCFDRMNB register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                NRXMB           :8;
        RSCFD_e_RMPLS           RMPLS           :3;
        uint32_t                Reserved_11     :21;
    }BIT;
}RSCFD_s_RSCFDnCFDRMNB;

/* RSCFDnCFDRMND0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RMNSu           RMNSu           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDRMND0;

/* RSCFDnCFDRFCC0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RFE             RFE             :1;
        RSCFD_e_RFIE            RFIE            :1;
        uint32_t                Reserved_2      :2;
        RSCFD_e_RFPLS           RFPLS           :3;
        uint32_t                Reserved_7      :1;
        RSCFD_e_RFDC            RFDC            :3;
        uint32_t                Reserved_11     :1;
        RSCFD_e_RFIM            RFIM            :1;
        RSCFD_e_RFIGCV          RFIGCV          :3;
        RSCFD_e_RFFIE           RFFIE           :1;
        uint32_t                Reserved_17     :7;
        uint32_t                MEIE            :1;
        uint32_t                Reserved_25     :3;
        uint32_t                DMAE            :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDRFCC0;

/* RSCFDnCFDRFSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RFEMP           RFEMP           :1;
        RSCFD_e_RFFLL           RFFLL           :1;
        RSCFD_e_RFMLT           RFMLT           :1;
        RSCFD_e_RFIF            RFIF            :1;
        uint32_t                Reserved_4      :4;
        uint32_t                RFMC            :8;
        uint32_t                RFFIF           :1;
        uint32_t                Reserved_17     :11;
        RSCFD_e_RFDMASTS        RFDMASTS        :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDRFSTS0;

/* RSCFDnCFDRFPCTR0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFPC            :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDRFPCTR0;

/* RSCFDnCFDCFCC0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CFE             CFE             :1;
        RSCFD_e_CFRXIE          CFRXIE          :1;
        RSCFD_e_CFTXIE          CFTXIE          :1;
        uint32_t                Reserved_3      :1;
        RSCFD_e_CFPLS           CFPLS           :3;
        uint32_t                Reserved_7      :1;
        RSCFD_e_CFM             CFM             :2;
        RSCFD_e_CFITSS          CFITSS          :1;
        RSCFD_e_CFITR           CFITR           :1;
        uint32_t                CFIM            :1;
        RSCFD_e_CFIGCV          CFIGCV          :3;
        uint32_t                CFTML           :5;
        RSCFD_e_CFDC            CFDC            :3;
        uint32_t                CFITT           :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFCC0;

/* RSCFDnCFDCFCCE0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CFFIE           CFFIE           :1;
        RSCFD_e_CFOFRXIE        CFOFRXIE        :1;
        RSCFD_e_CFOFTXIE        CFOFTXIE        :1;
        uint32_t                Reserved_3      :5;
        RSCFD_e_CFMOWM          CFMOWM          :1;
        uint32_t                Reserved_9      :7;
        RSCFD_e_CFBME           CFBME           :1;
        uint32_t                Reserved_17     :7;
        uint32_t                MEIE            :1;
        RSCFD_e_MOWEIE          MOWEIE          :1;
        uint32_t                Reserved_26     :2;
        uint32_t                DMAE            :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDCFCCE0;

/* RSCFDnCFDCFSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CFEMP           CFEMP           :1;
        RSCFD_e_CFFLL           CFFLL           :1;
        RSCFD_e_CFMLT           CFMLT           :1;
        uint32_t                CFRXIF          :1;
        uint32_t                CFTXIF          :1;
        uint32_t                Reserved_5      :3;
        uint32_t                CFMC            :8;
        RSCFD_e_CFFIF           CFFIF           :1;
        uint32_t                CFOFRXIF        :1;
        uint32_t                CFOFTXIF        :1;
        uint32_t                Reserved_19     :5;
        RSCFD_e_CFMOW           CFMOW           :1;
        uint32_t                Reserved_25     :3;
        RSCFD_e_CFDMASTS        CFDMASTS        :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDCFSTS0;

/* RSCFDnCFDCFPCTR0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFPC            :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDCFPCTR0;

/* RSCFDnCFDFFSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFxFLL          :8;
        uint32_t                CFkFLL          :24;
    }BIT;
}RSCFD_s_RSCFDnCFDFFSTS;

/* RSCFDnCFDFMSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFxMLT          :8;
        uint32_t                CFkMLT          :24;
    }BIT;
}RSCFD_s_RSCFDnCFDFMSTS;

/* RSCFDnCFDRFISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFxIF           :8;
        uint32_t                Reserved_8      :8;
        uint32_t                RFxFFLL         :8;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDRFISTS;

/* RSCFDnCFDCFRISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFkRXIF         :24;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFRISTS;

/* RSCFDnCFDCFTISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFkTXIF         :24;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFTISTS;

/* RSCFDnCFDFFFSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFxFFLL         :8;
        RSCFD_e_CFkFFLL         CFkFFLL         :24;
    }BIT;
}RSCFD_s_RSCFDnCFDFFFSTS;

/* RSCFDnCFDCFMOWSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFkMOW          :24;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFMOWSTS;

/* RSCFDnCFDCFOFRISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFkOFRXIF       :24;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFOFRISTS;

/* RSCFDnCFDCFOFTISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFkOFTXIF       :24;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFOFTISTS;

/* RSCFDnCFDCDTCT register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RFDMAE0         RFDMAE0         :1;
        RSCFD_e_RFDMAE1         RFDMAE1         :1;
        RSCFD_e_RFDMAE2         RFDMAE2         :1;
        RSCFD_e_RFDMAE3         RFDMAE3         :1;
        RSCFD_e_RFDMAE4         RFDMAE4         :1;
        RSCFD_e_RFDMAE5         RFDMAE5         :1;
        RSCFD_e_RFDMAE6         RFDMAE6         :1;
        RSCFD_e_RFDMAE7         RFDMAE7         :1;
        RSCFD_e_CFDMAE0         CFDMAE0         :1;
        RSCFD_e_CFDMAE1         CFDMAE1         :1;
        RSCFD_e_CFDMAE2         CFDMAE2         :1;
        RSCFD_e_CFDMAE3         CFDMAE3         :1;
        RSCFD_e_CFDMAE4         CFDMAE4         :1;
        RSCFD_e_CFDMAE5         CFDMAE5         :1;
        RSCFD_e_CFDMAE6         CFDMAE6         :1;
        uint32_t                CFDMAE7         :1;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDCDTCT;

/* RSCFDnCFDCDTSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFDMASTS0       :1;
        uint32_t                RFDMASTS1       :1;
        uint32_t                RFDMASTS2       :1;
        uint32_t                RFDMASTS3       :1;
        uint32_t                RFDMASTS4       :1;
        uint32_t                RFDMASTS5       :1;
        uint32_t                RFDMASTS6       :1;
        uint32_t                RFDMASTS7       :1;
        uint32_t                CFDMASTS0       :1;
        uint32_t                CFDMASTS1       :1;
        uint32_t                CFDMASTS2       :1;
        uint32_t                CFDMASTS3       :1;
        uint32_t                CFDMASTS4       :1;
        uint32_t                CFDMASTS5       :1;
        uint32_t                CFDMASTS6       :1;
        uint32_t                CFDMASTS7       :1;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDCDTSTS;

/* RSCFDnCFDCDTTCT register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TQ0DMAE0        :1;
        uint32_t                TQ0DMAE1        :1;
        uint32_t                TQ0DMAE2        :1;
        uint32_t                TQ0DMAE3        :1;
        uint32_t                TQ0DMAE4        :1;
        uint32_t                TQ0DMAE5        :1;
        uint32_t                TQ0DMAE6        :1;
        uint32_t                TQ0DMAE7        :1;
        uint32_t                TQ3DMAE0        :1;
        uint32_t                TQ3DMAE1        :1;
        uint32_t                TQ3DMAE2        :1;
        uint32_t                TQ3DMAE3        :1;
        uint32_t                TQ3DMAE4        :1;
        uint32_t                TQ3DMAE5        :1;
        uint32_t                TQ3DMAE6        :1;
        uint32_t                TQ3DMAE7        :1;
        RSCFD_e_CFDMAE0         CFDMAE0         :1;
        RSCFD_e_CFDMAE1         CFDMAE1         :1;
        RSCFD_e_CFDMAE2         CFDMAE2         :1;
        RSCFD_e_CFDMAE3         CFDMAE3         :1;
        RSCFD_e_CFDMAE4         CFDMAE4         :1;
        RSCFD_e_CFDMAE5         CFDMAE5         :1;
        RSCFD_e_CFDMAE6         CFDMAE6         :1;
        uint32_t                CFDMAE7         :1;
        uint32_t                Reserved_24     :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCDTTCT;

/* RSCFDnCFDCDTTSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TQ0DMASTS0       :1;
        uint32_t                TQ0DMASTS1       :1;
        uint32_t                TQ0DMASTS2       :1;
        uint32_t                TQ0DMASTS3       :1;
        uint32_t                TQ0DMASTS4       :1;
        uint32_t                TQ0DMASTS5       :1;
        uint32_t                TQ0DMASTS6       :1;
        uint32_t                TQ0DMASTS7       :1;
        uint32_t                TQ3DMASTS0       :1;
        uint32_t                TQ3DMASTS1       :1;
        uint32_t                TQ3DMASTS2       :1;
        uint32_t                TQ3DMASTS3       :1;
        uint32_t                TQ3DMASTS4       :1;
        uint32_t                TQ3DMASTS5       :1;
        uint32_t                TQ3DMASTS6       :1;
        uint32_t                TQ3DMASTS7       :1;
        uint32_t                CFDMASTS0        :1;
        uint32_t                CFDMASTS1        :1;
        uint32_t                CFDMASTS2        :1;
        uint32_t                CFDMASTS3        :1;
        uint32_t                CFDMASTS4        :1;
        uint32_t                CFDMASTS5        :1;
        uint32_t                CFDMASTS6        :1;
        uint32_t                CFDMASTS7        :1;
        uint32_t                Reserved_24      :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCDTTSTS;

/* RSCFDnCFDGRINTSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                QFIF            :3;
        uint32_t                Reserved_3      :1;
        uint32_t                BQFIF           :2;
        uint32_t                Reserved_6      :2;
        uint32_t                QOFRIF          :3;
        uint32_t                Reserved_11     :1;
        uint32_t                BQOFRIF         :2;
        uint32_t                Reserved_14     :2;
        uint32_t                CFRIF           :3;
        uint32_t                Reserved_19     :5;
        uint32_t                CFRFIF          :3;
        uint32_t                Reserved_27     :1;
        uint32_t                CFOFRIF         :3;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGRINTSTS0;

/* RSCFDnCFDTMC0 register */
typedef union{
        uint8_t                 UINT8;
    struct{
        RSCFD_e_TMTR            TMTR            :1;
        RSCFD_e_TMTAR           TMTAR           :1;
        RSCFD_e_TMOM            TMOM            :1;
        uint8_t                 Reserved_3      :5;
    }BIT;
}RSCFD_s_RSCFDnCFDTMC0;

/* RSCFDnCFDTMSTS0 register */
typedef union{
        uint8_t                 UINT8;
    struct{
        RSCFD_e_TMTSTS          TMTSTS          :1;
        RSCFD_e_TMTRF           TMTRF           :2;
        RSCFD_e_TMTRM           TMTRM           :1;
        RSCFD_e_TMTARM          TMTARM          :1;
        uint8_t                 Reserved_5      :3;
    }BIT;
}RSCFD_s_RSCFDnCFDTMSTS0;

/* RSCFDnCFDTMTRSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFDTMTRSTSp     :32;
    }BIT;
}RSCFD_s_RSCFDnCFDTMTRSTS0;

/* RSCFDnCFDTMTARSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFDTMTARSTSp    :32;
    }BIT;
}RSCFD_s_RSCFDnCFDTMTARSTS0;

/* RSCFDnCFDTMTCSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFDTMTCSTSp     :32;
    }BIT;
}RSCFD_s_RSCFDnCFDTMTCSTS0;

/* RSCFDnCFDTMTASTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFDTMTASTSp     :32;
    }BIT;
}RSCFD_s_RSCFDnCFDTMTASTS0;

/* RSCFDnCFDTMIEC0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TMIEp           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDTMIEC0;

/* RSCFDnCFDTXQCC00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQE            :1;
        uint32_t                TXQGWE          :1;
        uint32_t                TXQOWE          :1;
        uint32_t                Reserved_3      :2;
        uint32_t                TXQTXIE         :1;
        uint32_t                Reserved_6      :1;
        uint32_t                TXQIM           :1;
        uint32_t                TXQDC           :5;
        uint32_t                Reserved_13     :3;
        uint32_t                TXQFIE          :1;
        uint32_t                TXQOFRXIE       :1;
        uint32_t                TXQOFTXIE       :1;
        uint32_t                Reserved_19     :5;
        uint32_t                QMEIE           :1;
        uint32_t                QOWEIE          :1;
        uint32_t                Reserved_26     :2;
        uint32_t                DMAE            :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQCC00;

/* RSCFDnCFDTXQCC10 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQE            :1;
        uint32_t                TXQGWE          :1;
        uint32_t                TXQOWE          :1;
        uint32_t                Reserved_3      :2;
        uint32_t                TXQTXIE         :1;
        uint32_t                Reserved_6      :1;
        uint32_t                TXQIM           :1;
        uint32_t                TXQDC           :5;
        uint32_t                Reserved_13     :3;
        uint32_t                TXQFIE          :1;
        uint32_t                TXQOFRXIE       :1;
        uint32_t                TXQOFTXIE       :1;
        uint32_t                Reserved_19     :5;
        uint32_t                QMEIE           :1;
        uint32_t                QOWEIE          :1;
        uint32_t                Reserved_26     :6;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQCC10;

/* RSCFDnCFDTXQCC20 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQE            :1;
        uint32_t                TXQGWE          :1;
        uint32_t                TXQOWE          :1;
        uint32_t                Reserved_3      :2;
        uint32_t                TXQTXIE         :1;
        uint32_t                Reserved_6      :1;
        uint32_t                TXQIM           :1;
        uint32_t                TXQDC           :5;
        uint32_t                Reserved_13     :3;
        uint32_t                TXQFIE          :1;
        uint32_t                TXQOFRXIE       :1;
        uint32_t                TXQOFTXIE       :1;
        uint32_t                Reserved_19     :5;
        uint32_t                QMEIE           :1;
        uint32_t                QOWEIE          :1;
        uint32_t                Reserved_26     :6;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQCC20;

/* RSCFDnCFDTXQCC30 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQE            :1;
        uint32_t                Reserved_1      :1;
        uint32_t                TXQOWE          :1;
        uint32_t                Reserved_3      :2;
        uint32_t                TXQTXIE         :1;
        uint32_t                Reserved_6      :1;
        uint32_t                TXQIM           :1;
        uint32_t                TXQDC           :5;
        uint32_t                Reserved_13     :5;
        uint32_t                TXQOFTXIE       :1;
        uint32_t                Reserved_19     :6;
        uint32_t                QOWEIE          :1;
        uint32_t                Reserved_26     :2;
        uint32_t                DMAE            :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQCC30;

/* RSCFDnCFDTXQSTS00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQEMP          :1;
        uint32_t                TXQTXIF         :1;
        uint32_t                Reserved_3      :5;
        uint32_t                TXQMC           :6;
        uint32_t                Reserved_14     :2;
        uint32_t                TXQFIF          :1;
        uint32_t                TXQOFRXIF       :1;
        uint32_t                TXQOFTXIF       :1;
        RSCFD_e_TXQMLT          TXQMLT          :1;
        RSCFD_e_TXQMOW          TXQMOW          :1;
        uint32_t                Reserved_21     :7;
        uint32_t                TXQDMASTS       :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQSTS00;

/* RSCFDnCFDTXQSTS10 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQEMP          :1;
        uint32_t                TXQFLL          :1;
        uint32_t                TXQTXIF         :1;
        uint32_t                Reserved_3      :5;
        uint32_t                TXQMC           :6;
        uint32_t                Reserved_14     :2;
        uint32_t                TXQFIF          :1;
        uint32_t                TXQOFRXIF       :1;
        uint32_t                TXQOFTXIF       :1;
        RSCFD_e_TXQMLT          TXQMLT          :1;
        RSCFD_e_TXQMOW          TXQMOW          :1;
        uint32_t                Reserved_21     :11;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQSTS10;

/* RSCFDnCFDTXQSTS20 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQEMP          :1;
        uint32_t                TXQFLL          :1;
        uint32_t                TXQTXIF         :1;
        uint32_t                Reserved_3      :5;
        uint32_t                TXQMC           :6;
        uint32_t                Reserved_14     :2;
        uint32_t                TXQFIF          :1;
        uint32_t                TXQOFRXIF       :1;
        uint32_t                TXQOFTXIF       :1;
        RSCFD_e_TXQMLT          TXQMLT          :1;
        RSCFD_e_TXQMOW          TXQMOW          :1;
        uint32_t                Reserved_21     :11;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQSTS20;

/* RSCFDnCFDTXQSTS30 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQEMP          :1;
        uint32_t                TXQFLL          :1;
        uint32_t                TXQTXIF         :1;
        uint32_t                Reserved_3      :5;
        uint32_t                TXQMC           :6;
        uint32_t                Reserved_14     :4;
        uint32_t                TXQOFTXIF       :1;
        uint32_t                Reserved_19     :1;
        RSCFD_e_TXQMOW          TXQMOW          :1;
        uint32_t                Reserved_21     :7;
        uint32_t                TXQDMASTS       :1;
        uint32_t                Reserved_29     :3;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQSTS30;

/* RSCFDnCFDTXQPCTR00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQPC           :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQPCTR00;

/* RSCFDnCFDTXQPCTR10 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQPC           :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQPCTR10;

/* RSCFDnCFDTXQPCTR20 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQPC           :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQPCTR20;

/* RSCFDnCFDTXQPCTR30 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQPC           :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQPCTR30;

/* RSCFDnCFDTXQESTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0EMP         :1;
        uint32_t                TXQ1EMP         :1;
        uint32_t                TXQ2EMP         :1;
        uint32_t                TXQ3EMP         :1;
        uint32_t                TXQ4EMP         :1;
        uint32_t                TXQ5EMP         :1;
        uint32_t                TXQ6EMP         :1;
        uint32_t                TXQ7EMP         :1;
        uint32_t                TXQ8EMP         :1;
        uint32_t                TXQ9EMP         :1;
        uint32_t                TXQ10EMP        :1;
        uint32_t                TXQ11EMP        :1;
        uint32_t                TXQ12EMP        :1;
        uint32_t                TXQ13EMP        :1;
        uint32_t                TXQ14EMP        :1;
        uint32_t                TXQ15EMP        :1;
        uint32_t                TXQ16EMP        :1;
        uint32_t                TXQ17EMP        :1;
        uint32_t                TXQ18EMP        :1;
        uint32_t                TXQ19EMP        :1;
        uint32_t                TXQ20EMP        :1;
        uint32_t                TXQ21EMP        :1;
        uint32_t                TXQ22EMP        :1;
        uint32_t                TXQ23EMP        :1;
        uint32_t                TXQ24EMP        :1;
        uint32_t                TXQ25EMP        :1;
        uint32_t                TXQ26EMP        :1;
        uint32_t                TXQ27EMP        :1;
        uint32_t                TXQ28EMP        :1;
        uint32_t                TXQ29EMP        :1;
        uint32_t                TXQ30EMP        :1;
        uint32_t                TXQ31EMP        :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQESTS;

/* RSCFDnCFDTXQFISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0FULL        :1;
        uint32_t                TXQ1FULL        :1;
        uint32_t                TXQ2FULL        :1;
        uint32_t                Reserved_3      :1;
        uint32_t                TXQ4FULL        :1;
        uint32_t                TXQ5FULL        :1;
        uint32_t                TXQ6FULL        :1;
        uint32_t                Reserved_7      :1;
        uint32_t                TXQ8FULL        :1;
        uint32_t                TXQ9FULL        :1;
        uint32_t                TXQ10FULL       :1;
        uint32_t                Reserved_11     :1;
        uint32_t                TXQ12FULL       :1;
        uint32_t                TXQ13FULL       :1;
        uint32_t                TXQ14FULL       :1;
        uint32_t                Reserved_15     :1;
        uint32_t                TXQ16FULL       :1;
        uint32_t                TXQ17FULL       :1;
        uint32_t                TXQ18FULL       :1;
        uint32_t                Reserved_19     :1;
        uint32_t                TXQ20FULL       :1;
        uint32_t                TXQ21FULL       :1;
        uint32_t                TXQ22FULL       :1;
        uint32_t                Reserved_23     :1;
        uint32_t                TXQ24FULL       :1;
        uint32_t                TXQ25FULL       :1;
        uint32_t                TXQ26FULL       :1;
        uint32_t                Reserved_27     :1;
        uint32_t                TXQ28FULL       :1;
        uint32_t                TXQ29FULL       :1;
        uint32_t                TXQ30FULL       :1;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQFISTS;

/* RSCFDnCFDTXQMSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0ML          :1;
        uint32_t                TXQ1ML          :1;
        uint32_t                TXQ2ML          :1;
        uint32_t                Reserved_3      :1;
        uint32_t                TXQ4ML          :1;
        uint32_t                TXQ5ML          :1;
        uint32_t                TXQ6ML          :1;
        uint32_t                Reserved_7      :1;
        uint32_t                TXQ8ML          :1;
        uint32_t                TXQ9ML          :1;
        uint32_t                TXQ10ML         :1;
        uint32_t                Reserved_11     :1;
        uint32_t                TXQ12ML         :1;
        uint32_t                TXQ13ML         :1;
        uint32_t                TXQ14ML         :1;
        uint32_t                Reserved_15     :1;
        uint32_t                TXQ16ML         :1;
        uint32_t                TXQ17ML         :1;
        uint32_t                TXQ18ML         :1;
        uint32_t                Reserved_19     :1;
        uint32_t                TXQ20ML         :1;
        uint32_t                TXQ21ML         :1;
        uint32_t                TXQ22ML         :1;
        uint32_t                Reserved_23     :1;
        uint32_t                TXQ24ML         :1;
        uint32_t                TXQ25ML         :1;
        uint32_t                TXQ26ML         :1;
        uint32_t                Reserved_27     :1;
        uint32_t                TXQ28ML         :1;
        uint32_t                TXQ29ML         :1;
        uint32_t                TXQ30ML         :1;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQMSTS;

/* RSCFDnCFDTXQOWSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0OW          :1;
        uint32_t                TXQ1OW          :1;
        uint32_t                TXQ2OW          :1;
        uint32_t                TXQ3OW          :1;
        uint32_t                TXQ4OW          :1;
        uint32_t                TXQ5OW          :1;
        uint32_t                TXQ6OW          :1;
        uint32_t                TXQ7OW          :1;
        uint32_t                TXQ8OW          :1;
        uint32_t                TXQ9OW          :1;
        uint32_t                TXQ10OW         :1;
        uint32_t                TXQ11OW         :1;
        uint32_t                TXQ12OW         :1;
        uint32_t                TXQ13OW         :1;
        uint32_t                TXQ14OW         :1;
        uint32_t                TXQ15OW         :1;
        uint32_t                TXQ16OW         :1;
        uint32_t                TXQ17OW         :1;
        uint32_t                TXQ18OW         :1;
        uint32_t                TXQ19OW         :1;
        uint32_t                TXQ20OW         :1;
        uint32_t                TXQ21OW         :1;
        uint32_t                TXQ22OW         :1;
        uint32_t                TXQ23OW         :1;
        uint32_t                TXQ24OW         :1;
        uint32_t                TXQ25OW         :1;
        uint32_t                TXQ26OW         :1;
        uint32_t                TXQ27OW         :1;
        uint32_t                TXQ28OW         :1;
        uint32_t                TXQ29OW         :1;
        uint32_t                TXQ30OW         :1;
        uint32_t                TXQ31OW         :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQOWSTS;

/* RSCFDnCFDTXQISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0ISF         :1;
        uint32_t                TXQ1ISF         :1;
        uint32_t                TXQ2ISF         :1;
        uint32_t                TXQ3ISF         :1;
        uint32_t                TXQ4ISF         :1;
        uint32_t                TXQ5ISF         :1;
        uint32_t                TXQ6ISF         :1;
        uint32_t                TXQ7ISF         :1;
        uint32_t                TXQ8ISF         :1;
        uint32_t                TXQ9ISF         :1;
        uint32_t                TXQ10ISF        :1;
        uint32_t                TXQ11ISF        :1;
        uint32_t                TXQ12ISF        :1;
        uint32_t                TXQ13ISF        :1;
        uint32_t                TXQ14ISF        :1;
        uint32_t                TXQ15ISF        :1;
        uint32_t                TXQ16ISF        :1;
        uint32_t                TXQ17ISF        :1;
        uint32_t                TXQ18ISF        :1;
        uint32_t                TXQ19ISF        :1;
        uint32_t                TXQ20ISF        :1;
        uint32_t                TXQ21ISF        :1;
        uint32_t                TXQ22ISF        :1;
        uint32_t                TXQ23ISF        :1;
        uint32_t                TXQ24ISF        :1;
        uint32_t                TXQ25ISF        :1;
        uint32_t                TXQ26ISF        :1;
        uint32_t                TXQ27ISF        :1;
        uint32_t                TXQ28ISF        :1;
        uint32_t                TXQ29ISF        :1;
        uint32_t                TXQ30ISF        :1;
        uint32_t                TXQ31ISF        :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQISTS;

/* RSCFDnCFDTXQOFTISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0OFTISF      :1;
        uint32_t                TXQ1OFTISF      :1;
        uint32_t                TXQ2OFTISF      :1;
        uint32_t                TXQ3OFTISF      :1;
        uint32_t                TXQ4OFTISF      :1;
        uint32_t                TXQ5OFTISF      :1;
        uint32_t                TXQ6OFTISF      :1;
        uint32_t                TXQ7OFTISF      :1;
        uint32_t                TXQ8OFTISF      :1;
        uint32_t                TXQ9OFTISF      :1;
        uint32_t                TXQ10OFTISF     :1;
        uint32_t                TXQ11OFTISF     :1;
        uint32_t                TXQ12OFTISF     :1;
        uint32_t                TXQ13OFTISF     :1;
        uint32_t                TXQ14OFTISF     :1;
        uint32_t                TXQ15OFTISF     :1;
        uint32_t                TXQ16OFTISF     :1;
        uint32_t                TXQ17OFTISF     :1;
        uint32_t                TXQ18OFTISF     :1;
        uint32_t                TXQ19OFTISF     :1;
        uint32_t                TXQ20OFTISF     :1;
        uint32_t                TXQ21OFTISF     :1;
        uint32_t                TXQ22OFTISF     :1;
        uint32_t                TXQ23OFTISF     :1;
        uint32_t                TXQ24OFTISF     :1;
        uint32_t                TXQ25OFTISF     :1;
        uint32_t                TXQ26OFTISF     :1;
        uint32_t                TXQ27OFTISF     :1;
        uint32_t                TXQ28OFTISF     :1;
        uint32_t                TXQ29OFTISF     :1;
        uint32_t                TXQ30OFTISF     :1;
        uint32_t                TXQ31OFTISF     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQOFTISTS;

/* RSCFDnCFDTXQOFRISTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0OFRISF      :1;
        uint32_t                TXQ1OFRISF      :1;
        uint32_t                TXQ2OFRISF      :1;
        uint32_t                Reserved_3      :1;
        uint32_t                TXQ4OFRISF      :1;
        uint32_t                TXQ5OFRISF      :1;
        uint32_t                TXQ6OFRISF      :1;
        uint32_t                Reserved_7      :1;
        uint32_t                TXQ8OFRISF      :1;
        uint32_t                TXQ9OFRISF      :1;
        uint32_t                TXQ10OFRISF     :1;
        uint32_t                Reserved_11     :1;
        uint32_t                TXQ12OFRISF     :1;
        uint32_t                TXQ13OFRISF     :1;
        uint32_t                TXQ14OFRISF     :1;
        uint32_t                Reserved_15     :1;
        uint32_t                TXQ16OFRISF     :1;
        uint32_t                TXQ17OFRISF     :1;
        uint32_t                TXQ18OFRISF     :1;
        uint32_t                Reserved_19     :1;
        uint32_t                TXQ20OFRISF     :1;
        uint32_t                TXQ21OFRISF     :1;
        uint32_t                TXQ22OFRISF     :1;
        uint32_t                Reserved_23     :1;
        uint32_t                TXQ24OFRISF     :1;
        uint32_t                TXQ25OFRISF     :1;
        uint32_t                TXQ26OFRISF     :1;
        uint32_t                Reserved_27     :1;
        uint32_t                TXQ28OFRISF     :1;
        uint32_t                TXQ29OFRISF     :1;
        uint32_t                TXQ30OFRISF     :1;
        uint32_t                Reserved_31     :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQOFRISTS;

/* RSCFDnCFDTXQFSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0FSF         :1;
        uint32_t                TXQ1FSF         :1;
        uint32_t                TXQ2FSF         :1;
        uint32_t                TXQ3FSF         :1;
        uint32_t                TXQ4FSF         :1;
        uint32_t                TXQ5FSF         :1;
        uint32_t                TXQ6FSF         :1;
        uint32_t                TXQ7FSF         :1;
        uint32_t                TXQ8FSF         :1;
        uint32_t                TXQ9FSF         :1;
        uint32_t                TXQ10FSF        :1;
        uint32_t                TXQ11FSF        :1;
        uint32_t                TXQ12FSF        :1;
        uint32_t                TXQ13FSF        :1;
        uint32_t                TXQ14FSF        :1;
        uint32_t                TXQ15FSF        :1;
        uint32_t                TXQ16FSF        :1;
        uint32_t                TXQ17FSF        :1;
        uint32_t                TXQ18FSF        :1;
        uint32_t                TXQ19FSF        :1;
        uint32_t                TXQ20FSF        :1;
        uint32_t                TXQ21FSF        :1;
        uint32_t                TXQ22FSF        :1;
        uint32_t                TXQ23FSF        :1;
        uint32_t                TXQ24FSF        :1;
        uint32_t                TXQ25FSF        :1;
        uint32_t                TXQ26FSF        :1;
        uint32_t                TXQ27FSF        :1;
        uint32_t                TXQ28FSF        :1;
        uint32_t                TXQ29FSF        :1;
        uint32_t                TXQ30FSF        :1;
        uint32_t                TXQ31FSF        :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTXQFSTS;

/* RSCFDnCFDTHLCC0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_THLE            THLE            :1;
        uint32_t                Reserved_1      :7;
        RSCFD_e_THLIE           THLIE           :1;
        RSCFD_e_THLIM           THLIM           :1;
        RSCFD_e_THLDTE          THLDTE          :1;
        RSCFD_e_THLDGE          THLDGE          :1;
        uint32_t                Reserved_12     :12;
        RSCFD_e_THLEIE          THLEIE          :1;
        uint32_t                Reserved_25     :7;
    }BIT;
}RSCFD_s_RSCFDnCFDTHLCC0;

/* RSCFDnCFDTHLSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_THLEMP          THLEMP          :1;
        RSCFD_e_THLFLL          THLFLL          :1;
        RSCFD_e_THLELT          THLELT          :1;
        RSCFD_e_THLIF           THLIF           :1;
        uint32_t                Reserved_4      :4;
        uint32_t                THLMC           :6;
        uint32_t                Reserved_14     :18;
    }BIT;
}RSCFD_s_RSCFDnCFDTHLSTS0;

/* RSCFDnCFDTHLACC00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_BT              BT              :3;
        uint32_t                BN              :7;
        uint32_t                Reserved_10     :2;
        uint32_t                CH              :3;
        RSCFD_e_TGW             TGW             :1;
        uint32_t                TMTS            :16;
    }BIT;
}RSCFD_s_RSCFDnCFDTHLACC00;

/* RSCFDnCFDTHLACC10 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TID             :16;
        uint32_t                TIFL            :2;
        uint32_t                Reserved_18     :14;
    }BIT;
}RSCFD_s_RSCFDnCFDTHLACC10;

/* RSCFDnCFDTHLPCTR0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                THLPC           :8;
        uint32_t                Reserved_8      :24;
    }BIT;
}RSCFD_s_RSCFDnCFDTHLPCTR0;

/* RSCFDnCFDGRSTC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_SRST            SRST            :1;
        uint32_t                Reserved_1      :7;
        uint32_t                KEY             :8;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGRSTC;

/* RSCFDnCFDGFCMC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FLXC0           :1;
        uint32_t                FLXC1           :1;
        uint32_t                FLXC2           :1;
        uint32_t                FLXC3           :1;
        uint32_t                Reserved_4      :28;
    }BIT;
}RSCFD_s_RSCFDnCFDGFCMC;

/* RSCFDnCFDGFTBAC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FLXMB0          :4;
        uint32_t                Reserved_4      :4;
        uint32_t                FLXMB1          :4;
        uint32_t                Reserved_12     :4;
        uint32_t                FLXMB2          :4;
        uint32_t                Reserved_20     :4;
        uint32_t                FLXMB3          :4;
        uint32_t                Reserved_28     :4;
    }BIT;
}RSCFD_s_RSCFDnCFDGFTBAC;

/* RSCFDnCFDGTSTCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CmICBCE         CmICBCE         :8;
        uint32_t                Reserved_8      :8;
        uint32_t                RTMPS           :10;
        uint32_t                Reserved_26     :5;
        RSCFD_e_PNFS            PNFS            :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGTSTCFG;

/* RSCFDnCFDGTSTCTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                ICBCTME         :1;
        uint32_t                Reserved_1      :1;
        uint32_t                RTME            :1;
        uint32_t                Reserved_3      :29;
    }BIT;
}RSCFD_s_RSCFDnCFDGTSTCTR;

/* RSCFDnCFDC0FDCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_EOCCFG          EOCCFG          :3;
        uint32_t                Reserved_3      :5;
        RSCFD_e_TDCOC           TDCOC           :1;
        RSCFD_e_TDCE            TDCE            :1;
        RSCFD_e_ESIC            ESIC            :1;
        uint32_t                Reserved_11     :1;
        RSCFD_e_RPNMD           RPNMD           :2;
        uint32_t                Reserved_14     :2;
        uint32_t                TDCO            :8;
        RSCFD_e_GWEN            GWEN            :1;
        RSCFD_e_GWFDF           GWFDF           :1;
        RSCFD_e_GWBRS           GWBRS           :1;
        uint32_t                Reserved_27     :1;
        RSCFD_e_FDOE            FDOE            :1;
        RSCFD_e_REFE            REFE            :1;
        RSCFD_e_CLOE            CLOE            :1;
        RSCFD_e_CFDTE           CFDTE           :1;
    }BIT;
}RSCFD_s_RSCFDnCFDC0FDCFG;

/* RSCFDnCFDGLOCKK register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                LOCK            :16;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGLOCKK;

/* RSCFDnCFDRPGACC0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RDTA            :32;
    }BIT;
}RSCFD_s_RSCFDnCFDRPGACC0;

/* RSCFDnCFDC0BLCT register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_BLCE            BLCE            :1;
        uint32_t                Reserved_1      :7;
        uint32_t                BLCLD           :1;
        uint32_t                Reserved_9      :23;
    }BIT;
}RSCFD_s_RSCFDnCFDC0BLCT;

/* RSCFDnCFDC0BLSTS register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                Reserved_0      :3;
        uint32_t                BLC             :29;
    }BIT;
}RSCFD_s_RSCFDnCFDC0BLSTS;

/* RSCFDnCFDGFFIMC register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_FFIEN           FFIEN           :1;
        uint32_t                Reserved_1      :7;
        RSCFD_e_KEY             KEY             :8;
        uint32_t                Reserved_16     :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGFFIMC;

/* RSCFDnCFDVMCFG0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TXQ0VMN         :4;
        uint32_t                TXQ1VMN         :4;
        uint32_t                TXQ2VMN         :4;
        uint32_t                TXQ3VMN         :4;
        uint32_t                CF0VMN          :4;
        uint32_t                CF1VMN          :4;
        uint32_t                CF2VMN          :4;
        uint32_t                Reserved_28     :4;
    }BIT;
}RSCFD_s_RSCFDnCFDVMCFG0;

/* RSCFDnCFDVMRFCFG register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                VMN0            :4;
        uint32_t                VMN1            :4;
        uint32_t                VMN2            :4;
        uint32_t                VMN3            :4;
        uint32_t                VMN4            :4;
        uint32_t                VMN5            :4;
        uint32_t                VMN6            :4;
        uint32_t                VMN7            :4;
    }BIT;
}RSCFD_s_RSCFDnCFDVMRFCFG;

/* RSCFDnCFDVMISTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFTXINT         :1;
        uint32_t                CFOFTXINT       :1;
        uint32_t                TXQTXIF         :1;
        uint32_t                TXQOFTXIF       :1;
        RSCFD_e_THLIF           THLIF           :1;
        uint32_t                Reserved_5      :3;
        RSCFD_e_RFIF            RFIF            :1;
        uint32_t                RFFIF           :1;
        uint32_t                CFRXINT         :1;
        uint32_t                CFOFRXINT       :1;
        RSCFD_e_CFFIF           CFFIF           :1;
        uint32_t                TXQOFRXIF       :1;
        uint32_t                TXQFIF          :1;
        uint32_t                Reserved_15     :1;
        RSCFD_e_RFMLT           RFMLT           :1;
        RSCFD_e_CFMLT           CFMLT           :1;
        RSCFD_e_CFMOW           CFMOW           :1;
        RSCFD_e_TXQMLT          TXQMLT          :1;
        RSCFD_e_TXQMOW          TXQMOW          :1;
        RSCFD_e_THLELT          THLELT          :1;
        uint32_t                Reserved_22     :10;
    }BIT;
}RSCFD_s_RSCFDnCFDVMISTS0;

/* RSCFDnCFDGPFLECTR register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                PFLPN           :6;
        uint32_t                Reserved_6      :2;
        RSCFD_e_PFLDAE          PFLDAE          :1;
        uint32_t                Reserved_9      :23;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLECTR;

/* RSCFDnCFDGPFLCFG0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RNC3            :6;
        uint32_t                Reserved_6      :2;
        uint32_t                RNC2            :6;
        uint32_t                Reserved_14     :2;
        uint32_t                RNC1            :6;
        uint32_t                Reserved_22     :2;
        uint32_t                RNC0            :6;
        uint32_t                Reserved_30     :2;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLCFG0;

/* RSCFDnCFDRMID00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RMID            :29;
        uint32_t                Reserved_29     :1;
        RSCFD_e_RMRTR           RMRTR           :1;
        RSCFD_e_RMIDE           RMIDE           :1;
    }BIT;
}RSCFD_s_RSCFDnCFDRMID00;

/* RSCFDnCFDCFPTR00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFTS            :16;
        uint32_t                Reserved_16     :12;
        uint32_t                CFDLC           :4;
    }BIT;
}RSCFD_s_RSCFDnCFDCFPTR00;

/* RSCFDnCFDGPFLID1 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GPFLID          :29;
        RSCFD_e_GPFLLB          GPFLLB          :1;
        RSCFD_e_GPFLRTR         GPFLRTR         :1;
        RSCFD_e_GPFLIDE         GPFLIDE         :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLID1;

/* RSCFDnCFDGPFLM1 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GPFLIDM         :29;
        uint32_t                GPFLIFL1        :1;
        uint32_t                GPFLRTRM        :1;
        uint32_t                GPFLIDEM        :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLM1;

/* RSCFDnCFDGPFLP01 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GPFLDLC         :4;
        uint32_t                GPFLSRD0        :1;
        uint32_t                GPFLSRD1        :1;
        uint32_t                GPFLSRD2        :1;
        uint32_t                GPFLIFL0        :1;
        uint32_t                GPFLRMDP        :7;
        RSCFD_e_GPFLRMV         GPFLRMV         :1;
        uint32_t                GPFLPTR         :16;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLP01;

/* RSCFDnCFDGPFLP11 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GPFLFDP         :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLP11;

/* RSCFDnCFDGPFLPT1 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                GPFLOFFSET1     :4;
        uint32_t                Reserved_4      :9;
        uint32_t                GPFLOUT1        :1;
        uint32_t                GPFLRANG1       :1;
        uint32_t                Reserved_15     :1;
        uint32_t                GPFLOFFSET0     :4;
        uint32_t                Reserved_20     :9;
        uint32_t                GPFLOUT0        :1;
        uint32_t                GPFLRANG0       :1;
        RSCFD_e_GPFLANDOR       GPFLANDOR       :1;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLPT1;

/* RSCFDnCFDGPFLPD01 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FDATA           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLPD01;

/* RSCFDnCFDGPFLPM01 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FMASK           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLPM01;

/* RSCFDnCFDGPFLPD11 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FDATA           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLPD11;

/* RSCFDnCFDGPFLPM11 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                FMASK           :32;
    }BIT;
}RSCFD_s_RSCFDnCFDGPFLPM11;

/* RSCFDnCFDRMPTR00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RMTS            :16;
        uint32_t                Reserved_16     :12;
        uint32_t                RMDLC           :4;
    }BIT;
}RSCFD_s_RSCFDnCFDRMPTR00;

/* RSCFDnCFDRMFDSTS00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RMESI           RMESI           :1;
        RSCFD_e_RMBRS           RMBRS           :1;
        RSCFD_e_RMFDF           RMFDF           :1;
        uint32_t                Reserved_3      :5;
        uint32_t                RMIFL           :2;
        uint32_t                Reserved_10     :6;
        uint32_t                RMPTR           :16;
    }BIT;
}RSCFD_s_RSCFDnCFDRMFDSTS00;

/* RSCFDnCFDRMDF000 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RMDB0           :8;
        uint32_t                RMDB1           :8;
        uint32_t                RMDB2           :8;
        uint32_t                RMDB3           :8;
    }BIT;
}RSCFD_s_RSCFDnCFDRMDF000;

/* RSCFDnCFDRFID0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFID            :29;
        uint32_t                Reserved_29     :1;
        RSCFD_e_RFRTR           RFRTR           :1;
        RSCFD_e_RFIDE           RFIDE           :1;
    }BIT;
}RSCFD_s_RSCFDnCFDRFID0;

/* RSCFDnCFDRFPTR0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFTS            :16;
        uint32_t                Reserved_16     :12;
        uint32_t                RFDLC           :4;
    }BIT;
}RSCFD_s_RSCFDnCFDRFPTR0;

/* RSCFDnCFDRFFDSTS0 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_RFESI           RFESI           :1;
        RSCFD_e_RFBRS           RFBRS           :1;
        RSCFD_e_RFFDF           RFFDF           :1;
        uint32_t                Reserved_3      :5;
        uint32_t                RFIFL           :2;
        uint32_t                Reserved_10     :6;
        uint32_t                CFDRFPTR        :16;
    }BIT;
}RSCFD_s_RSCFDnCFDRFFDSTS0;

/* RSCFDnCFDRFDF00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                RFDB0           :8;
        uint32_t                RFDB1           :8;
        uint32_t                RFDB2           :8;
        uint32_t                RFDB3           :8;
    }BIT;
}RSCFD_s_RSCFDnCFDRFDF00;

/* RSCFDnCFDCFID00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFID            :29;
        uint32_t                THLEN           :1;
        RSCFD_e_CFRTR           CFRTR           :1;
        RSCFD_e_CFIDE           CFIDE           :1;
    }BIT;
}RSCFD_s_RSCFDnCFDCFID00;

/* RSCFDnCFDCFFDCSTS00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_CFESI           CFESI           :1;
        RSCFD_e_CFBRS           CFBRS           :1;
        RSCFD_e_CFFDF           CFFDF           :1;
        uint32_t                Reserved_3      :5;
        uint32_t                CFIFL           :2;
        uint32_t                Reserved_10     :6;
        uint32_t                CFPTR           :16;
    }BIT;
}RSCFD_s_RSCFDnCFDCFFDCSTS00;

/* RSCFDnCFDCFDF100 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                CFDB4           :8;
        uint32_t                CFDB5           :8;
        uint32_t                CFDB6           :8;
        uint32_t                CFDB7           :8;
    }BIT;
}RSCFD_s_RSCFDnCFDCFDF100;

/* RSCFDnCFDTMID00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TMID            :29;
        uint32_t                THLEN           :1;
        RSCFD_e_TMRTR           TMRTR           :1;
        RSCFD_e_TMIDE           TMIDE           :1;
    }BIT;
}RSCFD_s_RSCFDnCFDTMID00;

/* RSCFDnCFDTMPTR00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                Reserved_0      :28;
        uint32_t                TMDLC           :4;
    }BIT;
}RSCFD_s_RSCFDnCFDTMPTR00;

/* RSCFDnCFDTMFDCTR00 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        RSCFD_e_TMESI           TMESI           :1;
        RSCFD_e_TMBRS           TMBRS           :1;
        RSCFD_e_TMFDF           TMFDF           :1;
        uint32_t                Reserved_3      :5;
        uint32_t                TMIFL           :2;
        uint32_t                Reserved_10     :6;
        uint32_t                TMPTR           :16;
    }BIT;
}RSCFD_s_RSCFDnCFDTMFDCTR00;

/* RSCFDnCFDTMDF000 register */
typedef union{
    uint32_t                    UINT32;
    struct{
        uint32_t                TMDB0           :8;
        uint32_t                TMDB1           :8;
        uint32_t                TMDB2           :8;
        uint32_t                TMDB3           :8;
    }BIT;
}RSCFD_s_RSCFDnCFDTMDF000;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_RSCANFD_reg_H__ */

