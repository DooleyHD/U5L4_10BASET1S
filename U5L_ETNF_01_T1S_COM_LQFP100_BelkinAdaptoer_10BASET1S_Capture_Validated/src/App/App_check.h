#ifndef	__App_check_H__
#define	__App_check_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_main.h"
#include "App_sub.h"

/* target module */
#include "App_ETNF_cfg.h"
#include "R_driver_ETNF.h"


/*******************************************************************************
* Definition
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Description  : output register value set in the function
*                App_InitSetting_EMAC
*                   - R_ETNF_ConfigEMAC
*                   - R_ETNF_Config_T1SPHY
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_EMAC( char *title, uint8_t n );

/*******************************************************************************
* Description  : output register value set in the function
*                App_InitSetting_AVBDMAC_Common
*                   - R_ETNF_Set_gPTPClockSource
*                   - R_ETNF_SetDescBaseAddrTable
*                   - R_ETNF_EnableInternalLB
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_DMAC_common( char *title, uint8_t n );

/*******************************************************************************
* Description  : output register value
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_Receive( char *title, uint8_t n );

/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_SetsFilterOffset
*                R_ETNF_Config_sFilterPattern
*                R_ETNF_Config_sFilterMask
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_sFilter( char *title, uint8_t n, uint8_t i_num );

/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_transmit( char *title, uint8_t n );

/*******************************************************************************
* Description  : output register value set in the function
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_Config_PLCA( char *title, uint8_t n );

/*******************************************************************************
* Description  : output transmitted and received frame
*                R_ETNF_ConfigDescInt
*                R_ETNF_Config_AVBDMAC_Rx
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Output_frame( char *title, uint8_t n );


#endif /* __App_check_H__ */


