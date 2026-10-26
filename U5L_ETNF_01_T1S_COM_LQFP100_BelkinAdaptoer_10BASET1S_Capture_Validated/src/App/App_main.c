
/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_main.h"
#include "App_sub.h"


/*******************************************************************************
* Definition
*******************************************************************************/

// Add the codes for App_CheckETNF_LinkStatus by Heedong Lee on Sep 28, 2026
/*****************************************************************
* Description : Check T1S PHY Link Status (STATUS reg bit2 = LKST)
* Arguments   : uint8_t n : ETNF unit number
* Return Value: uint8_t   : RET_OK if link is up, RET_NG otherwise
*****************************************************************/
uint8_t App_CheckETNF_LinkStatus( uint8_t n )
{
    uint16_t status_reg;
    uint8_t  ret = RET_ERR_STATE;

    /* STATUS(000001H) is RO-LL (Latch-Low): the first read can still
       hold a stale 1->0 transition from before link-up, so read it
       twice and trust the second value for the real-time state. */
    status_reg = R_ETNF_ReadPhyReg( n, APP_T1STANS_DADDR, ETH_PHY_CONTROL_REG_ID + 1 ); /* dummy read, clears latch */
    status_reg = R_ETNF_ReadPhyReg( n, APP_T1STANS_DADDR, ETH_PHY_CONTROL_REG_ID + 1 ); /* real read */

    R_COM_printf( "[ETNF%d] PHY STATUS = 0x%04X\n", n, status_reg );

    if ( ( status_reg & PHY_LINKUP ) == PHY_LINKUP )
    {
        R_COM_printf( "[ETNF%d] Link Status : UP\n", n );
        ret = RET_OK;
    }
    else
    {
        R_COM_printf( "[ETNF%d] Link Status : DOWN\n", n );
        ret = RET_ERR_STATE;
    }

    return ret;
}

/*******************************************************************************
* Description  : The sample for transmit and receive in non-AVB mode of ETNF
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_main( void ){
	
	uint8_t 	n = APP_UNIT;	/* unit number of ETNF to use */
	uint8_t 	ret = RET_OK;
	uint8_t 	value;
	
	/* Prepare for execution
	****************************************************************************/
	/* Output title */
	App_OutputTitle();
	
	/* Global variable Initialization */
	App_Init_GlobalVariable();
	
	/* Configuration of ETNF
	****************************************************************************/
	App_Init_ETNF();

	// Add the codes for App_CheckETNF_LinkStatus by Heedong Lee on Sep 28, 2026
	/* --- Check Link Status (added) --- */
//	if ( App_CheckETNF_LinkStatus( n ) != RET_OK )
//	{
//	    R_COM_printf( "[Warning] Link is not established. Communication may fail.\n" );
//	    /* Optionally add a wait loop here, e.g.: while(!App_CheckETNF_LinkStatus(n)); */
//	}
	
	if(APP_COM_TEST == APP_ETNF_TxRx){
		/* Start transmission and wait until complete
		****************************************************************************/	
#if ( (APP_COM_MODE == APP_ETNF_NORMAL) && (APP_COM_IF == APP_ETNF_T1S) )
		if (APP_COM_TYPE == APP_COM_MASTER){
			R_PORT_ReleaseWriteProtect( 13, 0 );
			R_PORT_SetInputMode_Pnm(13,7);

			do{
			value = R_PORT_GetPortInput(13, 7);
			}while( value != 1);

		}else if (APP_COM_TYPE == APP_COM_SLAVE){
			// initialize flag port output
			R_PORT_ReleaseWriteProtect( 13, 0 );
			R_PORT_InitPort_nm( 13 , 7, 0 );
			R_PORT_ChangeIOmode_P(13,0xFF7F) ;
			R_PORT_OutputHigh_Pnm( 13, 7 );

		}else{
		}
#endif

		/* Start transmission */
		R_ETNF_RequestFrameTransmission( n, APP_USE_TXQ_B );
		R_COM_printf( "[Start transmission...]\n" );
		
		/* Wait until transmission compete */
		R_COM_printf( "Wait until all data received ... " );
		
		R_ETNF_WaitTransmissionComplete( n );

		while( 4 > App_RxCount ){	/* App_RxCount will be updated in interrupt handler */
	}
			
		R_COM_printf( "Done\n\n" );
	}else if (APP_COM_TEST == APP_ETNF_RxTx){	
		/* Start rececive and wait until complete
		****************************************************************************/
		if (APP_COM_TYPE == APP_COM_MASTER){
			R_PORT_ReleaseWriteProtect( 13, 0 );
			R_PORT_SetInputMode_Pnm(13,7);

			do{
			value = R_PORT_GetPortInput(13, 7);
			}while( value != 1);

		}else if (APP_COM_TYPE == APP_COM_SLAVE){
			// initialize flag port output
			R_PORT_ReleaseWriteProtect( 13, 0 );
			R_PORT_InitPort_nm( 13 , 7, 0 );
			R_PORT_ChangeIOmode_P(13,0xFF7F) ;
			// set flag
			R_PORT_OutputHigh_Pnm( 13, 7 );

		}else{
		}

		while( 4 > App_RxCount ){	/* App_RxCount will be updated in interrupt handler */
	}
		
		/* Start transmission and wait until complete
		****************************************************************************/	
		R_COM_printf( "[Start transmission]\n" );
		
		/* Start transmission */
		R_ETNF_RequestFrameTransmission( n, APP_USE_TXQ_B );
		
		/* Wait until transmission compete */
		R_COM_printf( "Wait until all data received ... " );
		
		R_ETNF_WaitTransmissionComplete( n );
			
		R_COM_printf( "Done\n\n" );	
		
	}else{
	}
	
	
	/* Stop transmission and reception
	****************************************************************************/	
	R_COM_printf( "[Stop and reset transmission and reception]\n" );
	
	R_ETNF_StopAndReset( n );
	
	R_COM_printf( "\n" );
	

	/* Check received frames and output result
	****************************************************************************/	
	/* Output transmitted and received frame */
#ifdef APP_REG_OUTPUT	
	App_Output_frame( "[After communication complete]", n );
#endif

	/* check received frame */
	ret = App_Check_Rxframe( n );
	
	/* output result */
	R_COM_printf( "Transmission and reception were " );
	
	if ( ret == RET_OK ){
		R_COM_printf( "successful.\n" );
	}else{
		R_COM_printf( "failed.\n" );
	}
	
	while( 1 )
		;
		

}

