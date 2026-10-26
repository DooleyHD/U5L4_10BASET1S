/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_module_standby_driver.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** Array contains all Module standby informations */
const bsp_module_standby_info_t g_msr_info_table[] =
{
    [BSP_MODULE_STANDBY_ADC_AWO] = {.msr_reg_address   = (uint32_t *) &(R_SYS0_A_STBC->MSR_ADCK_AWO),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_ADC_ENABLE},
    [BSP_MODULE_STANDBY_ADC_ISO] = {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_ADCK_ISO),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_ADC_ENABLE},
    [BSP_MODULE_STANDBY_CANFD] =   {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_RSCFD),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_CANFD_ENABLE},
#if (BSP_FEATURE_CANXL_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_CANXL] =   {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_CANXL),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_CANXL_ENABLE},
#endif
    [BSP_MODULE_STANDBY_CSIH] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_CSIH),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_CSIH_ENABLE},
    [BSP_MODULE_STANDBY_CXPI] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_CXPI),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_CXPI_ENABLE},
    [BSP_MODULE_STANDBY_ENCA] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_ENCA),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_ENCA_ENABLE},
#if (BSP_FEATURE_ETHTSN_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_ETHTSN] =  {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_ETND),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_ETHTSN_ENABLE},
#endif                                 /* #if (BSP_FEATURE_ETHTSN_IS_AVAILABLE) */
#if (BSP_FEATURE_T1S_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_ETHT1S] =  {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_ETNF),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_ETHT1S_ENABLE},
#endif
    [BSP_MODULE_STANDBY_I2C] =     {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_RIIC),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_I2C_ENABLE},
    [BSP_MODULE_STANDBY_I3C] =     {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_RI3C),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_I3C_ENABLE},
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_MMCA] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_MMCA),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_MMCA_ENABLE},
#endif                                 /* #if (BSP_FEATURE_MMCA_IS_AVAILABLE) */
    [BSP_MODULE_STANDBY_OSTM] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_OSTM),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_OSTM_ENABLE},
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_PSI5] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_PSI5),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_PSI5_ENABLE},
#endif                                 /* #if (BSP_FEATURE_PSI5_IS_AVAILABLE) */
    [BSP_MODULE_STANDBY_PWMDIAG] = {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_PWMD),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_PWMDIAG_ENABLE},
    [BSP_MODULE_STANDBY_RSENT] =   {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_RSENT),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_RSENT_ENABLE},
    [BSP_MODULE_STANDBY_RLIN] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_RLIN3),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_RLIN_ENABLE},
    [BSP_MODULE_STANDBY_RTCA] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_A_STBC->MSR_RTCA),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_RTCA_ENABLE},
#if (BSP_FEATURE_SFMA_IS_AVAILABLE)
    [BSP_MODULE_STANDBY_SFMA] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_SFMA),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_SFMA_ENABLE},
#endif                                 /* #if (BSP_FEATURE_SFMA_IS_AVAILABLE) */
    [BSP_MODULE_STANDBY_SSIF] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_SSIF),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_SSIF_ENABLE},
    [BSP_MODULE_STANDBY_TAPA] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_TAPA),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_TAPA_ENABLE},
    [BSP_MODULE_STANDBY_TAUD] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_TAUD),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_TAUD_ENABLE},
    [BSP_MODULE_STANDBY_TAUJ] =    {.msr_reg_address   = (uint32_t *) &(R_SYS0_STBC->MSR_TAUJ_ISO),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_TAUJ_ENABLE},
    [BSP_MODULE_STANDBY_WDT] =     {.msr_reg_address   = (uint32_t *) &(R_SYS0_A_STBC->MSR_WDTB_AWO),
                                    .initial_cfg_value = BSP_MODULE_STANDBY_WDT_ENABLE}
};
