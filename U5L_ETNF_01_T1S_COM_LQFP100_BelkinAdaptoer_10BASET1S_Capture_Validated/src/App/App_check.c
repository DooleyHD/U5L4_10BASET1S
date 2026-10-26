
/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_check.h"


/*******************************************************************************
* Definition
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/
char	*Indent = "      ";


/*******************************************************************************
* Description  : output register value set in the function
*                App_InitSetting_EMAC
*                   - R_ETNF_ConfigEMAC
*                   - R_ETNF_Config_T1SPHY
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_EMAC( char *title, uint8_t n ){
	
	R_COM_printf( "%s\n", title );
	
	R_COM_printf( "%sETNF%dMAHR    = 0x%8x\n", Indent, n, rETNFnMAHR(n) );
	R_COM_printf( "%sETNF%dMALR    = 0x%8x\n", Indent, n, rETNFnMALR(n) );
	R_COM_printf( "%sETNF%dECMR    = 0x%8x\n", Indent, n, rETNFnECMR(n) );
	R_COM_printf( "%sETNF%dRFLR    = 0x%8x\n", Indent, n, rETNFnRFLR(n) );
	R_COM_printf( "%sETNF%dECSIPR  = 0x%8x\n", Indent, n, rETNFnECSIPR(n) );
	R_COM_printf( "%sETNF%dT1SCTL0 = 0x%8x\n", Indent, n, rETNFnT1SCTL0(n) );
	
	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output register value set in the function
*                App_InitSetting_AVBDMAC_Common
*                   - R_ETNF_Set_gPTPClockSource
*                   - R_ETNF_SetDescBaseAddrTable
*                   - R_ETNF_EnableInternalLB
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_DMAC_common( char *title, uint8_t n ){
	
	R_COM_printf( "%s\n", title );
	
	R_COM_printf( "%sETNF%dCCC     = 0x%8x\n", Indent, n, rETNFnCCC(n) );
	R_COM_printf( "%sETNF%dDBAT    = 0x%8x\n", Indent, n, rETNFnDBAT(n) );
	
	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_ConfigRxInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_Receive( char *title, uint8_t n ){
	
	R_COM_printf( "%s\n", title );
	
	R_COM_printf( "%sETNF%dRIC0  = 0x%8x\n", Indent, n, rETNFnRIC0(n) );
	R_COM_printf( "%sETNF%dRCR   = 0x%8x\n", Indent, n, rETNFnRCR(n) );
	for( int i = 0; i < ETH_NUM_OF_RQC_REG; i++){
		R_COM_printf( "%sETNF%dRQC%d  = 0x%8x\n", Indent, n, i, rETNFnRQCi(n, i) );
	}
	R_COM_printf( "%sETNF%dRPC   = 0x%8x\n", Indent, n, rETNFnRPC(n) );
	
	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_SetsFilterOffset
*                R_ETNF_Config_sFilterPattern
*                R_ETNF_Config_sFilterMask
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_sFilter( char *title, uint8_t n, uint8_t i_num ){
	
	R_COM_printf( "%s\n", title );
	
	R_COM_printf( "%sETNF%dSFO   = 0x%8x\n", Indent, n, rETNFnSFO(n) );
	for( int i = 0; i < APP_NUM_SFL*2; i++ ){
	R_COM_printf( "%sETNF%dSFP%d  = 0x%8x\n", Indent, n, i, rETNFnSFPi(n,i) );
	}
	R_COM_printf( "%sETNF%dSFM0  = 0x%8x\n", Indent, n, rETNFnSFMi(n,0) );
	R_COM_printf( "%sETNF%dSFM1  = 0x%8x\n", Indent, n, rETNFnSFMi(n,1) );
	
	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_transmit( char *title, uint8_t n ){
	
	R_COM_printf( "%s\n", title );
	
	R_COM_printf( "%sETNF%dDIC   = 0x%8x\n", Indent, n, rETNFnDIC(n) );
	R_COM_printf( "%sETNF%dTGC   = 0x%8x\n", Indent, n, rETNFnTGC(n) );
	R_COM_printf( "%sETNF%dTCCR  = 0x%8x\n", Indent, n, rETNFnTCCR(n) );
	
	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_PLCA( char *title, uint8_t n ){

	char	*Indent = "      ";
	uint16_t	value;
	R_COM_printf( "%s\n", title );

	R_ETNF_KeepLevel_MDC();
	R_COM_printf( "%sPLCA_CONTROL = 0x%4x\n", Indent, R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_CONTROL_REG ) );
	R_ETNF_KeepLevel_MDC();
	R_COM_printf( "%sPLCA_STATUS  = 0x%4x\n", Indent, R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG ) );

	R_COM_printf( "%sT1STWEAKS    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STWEAKS ) );
	R_COM_printf( "%sT1SPLCAEXT   = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPLCAEXT ) );
	R_COM_printf( "%sT1SPMACTRL   = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPMACTRL ) );
	R_COM_printf( "%sPLCACTRL0    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL0 ) );
	R_COM_printf( "%sPLCACTRL1    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL1 ) );
	R_COM_printf( "%sT1STXCCTL    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STXCCTL ) );
	R_COM_printf( "%sT1SPCSDIAG1    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPCSDIAG1 ) );
	R_COM_printf( "%sT1SPCSDIAG2    = 0x%4x\n", Indent, R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPCSDIAG2 ) );

	R_COM_printf( "\n" );
}


/*******************************************************************************
* Description  : output specified TX frame or RX buffer
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_1frame( uint8_t *frame ){
	
	uint8_t 	i;
	
	
	/* SA */
	R_COM_printf( "%s      SA  : 0x" , Indent );
	for( i = ETNF_e_frameindex_SA1; i <= ETNF_e_frameindex_SA6; i++ ){
		R_COM_printf( "%2x:", frame[i] );
	}
	R_COM_printf( "\n" );
	
	/* DA */
	R_COM_printf( "%s      DA  : 0x" , Indent );
	for( i = ETNF_e_frameindex_DA1; i <= ETNF_e_frameindex_DA6; i++ ){
		R_COM_printf( "%2x:", frame[i] );
	}
	R_COM_printf( "\n" );
	
	/* ET */
	R_COM_printf( "%s      ET  : 0x" , Indent );
	R_COM_printf( "%2x", App_TxFrame[0][ETNF_e_frameindex_ET1] );
	R_COM_printf( "%2x", App_TxFrame[0][ETNF_e_frameindex_ET2] );
	R_COM_printf( "\n" );
	
	/* Data */
	R_COM_printf( "%s      Data: 0x" , Indent );
	for( i = 0; i < 16; i++ ){
		R_COM_printf( "%2x ", frame[i+ETNF_e_frameindex_Data] );
	}
	R_COM_printf( "... \n" );
	
}


/*******************************************************************************
* Description  : output transmitted and received frame
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_frame( char *title, uint8_t n ){
	
	R_COM_printf( "%s\n", title );
	
	
	for( int i = 0; i < 4; i++ ){
		R_COM_printf( "%s- Queue %d: \n", Indent, i );
		
		/* transmitted frame */
		R_COM_printf( "%s  transmitted frame: \n", Indent );
		App_Output_1frame( &App_TxFrame[i][0] );
		
		/* received frame */
		R_COM_printf( "%s  received frame   : \n", Indent );
		App_Output_1frame( &App_RxBuffer_ST[i][0] );
		
		R_COM_printf( "\n" );
	}
	
}
	
