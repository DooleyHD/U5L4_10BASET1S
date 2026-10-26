/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_mpu.h"

/***********************************************************************************************************************
 * Variables and functions
 **********************************************************************************************************************/
static void r_mpu_region_init(const uint32_t r_index, const bsp_mpu_region_t * region_conf);

/*******************************************************************************************************************//**
 * MAIR (Memory Attribute Indirection Register) attribute table.
 *
 * This array defines up to eight memory attributes used by the MPU.
 * Each entry corresponds to an index used in region configuration (via mair_idx).
 *
 * Maximum of eight attributes.
 **********************************************************************************************************************/
const uint8_t g_bsp_mpu_mair_attributes[] =
{
#if (BSP_MPU_CONFIG_ENABLE)
    BSP_MPU_ATTRn_CONFIG(0)
    BSP_MPU_ATTRn_CONFIG(1)
    BSP_MPU_ATTRn_CONFIG(2)
    BSP_MPU_ATTRn_CONFIG(3)
    BSP_MPU_ATTRn_CONFIG(4)
    BSP_MPU_ATTRn_CONFIG(5)
    BSP_MPU_ATTRn_CONFIG(6)
    BSP_MPU_ATTRn_CONFIG(7)
#endif
};

/*******************************************************************************************************************//**
 * MPU region configuration table.
 *
 * Each entry in this array defines a memory region with a name, base address, and attributes.
 *
 * Maximum of 16 regions.
 **********************************************************************************************************************/
static const bsp_mpu_region_t mpu_regions[] =
{
#if (BSP_MPU_CONFIG_ENABLE)
    BSP_MPU_REGIONn_CONFIG(00)
    BSP_MPU_REGIONn_CONFIG(01)
    BSP_MPU_REGIONn_CONFIG(02)
    BSP_MPU_REGIONn_CONFIG(03)
    BSP_MPU_REGIONn_CONFIG(04)
    BSP_MPU_REGIONn_CONFIG(05)
    BSP_MPU_REGIONn_CONFIG(06)
    BSP_MPU_REGIONn_CONFIG(07)
    BSP_MPU_REGIONn_CONFIG(08)
    BSP_MPU_REGIONn_CONFIG(09)
    BSP_MPU_REGIONn_CONFIG(10)
    BSP_MPU_REGIONn_CONFIG(11)
    BSP_MPU_REGIONn_CONFIG(12)
    BSP_MPU_REGIONn_CONFIG(13)
    BSP_MPU_REGIONn_CONFIG(14)
    BSP_MPU_REGIONn_CONFIG(15)
#endif
};

const bsp_mpu_config_t g_bsp_mpu_config =
{
#if (BSP_MPU_CONFIG_ENABLE)
    .num_regions = BSP_MPU_NUMBER_OF_REGIONS_ENBALED,
#else
    .num_regions = 0U,
#endif
    .mpu_regions = mpu_regions,
};

/*******************************************************************************************************************//**
 * This function sets up the MPU by clearing non-configured regions and initializing all configured regions.
 * It prepares the MPU for enforcing memory access permissions based on predefined region settings.
 *
 * @param[in]  p_cfg                 Pointer to MPU specific configuration structure.
 *
 * @retval  FSP_SUCCESS              MPU was enabled successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPUEnable (const bsp_mpu_config_t * const p_cfg)
{
    uint8_t   r_index;
    fsp_err_t err = FSP_SUCCESS;

    FSP_ASSERT(p_cfg->num_regions < BSP_MPU_DEVICE_MAX_REGION_NUMBER);

    /* Disable the MPU */
    ARM_MPU_Disable();

    /* Clear all regions */
    for (r_index = 0; r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER; r_index++)
    {
        ARM_MPU_ClrRegion(r_index);
    }

    /* Initialize MPU_MAIR0 and MPU_MAIR1 from attributes table. */
    for (uint8_t i = 0; i < BSP_MPU_DEVICE_MAX_ATTRUBUTE_NUMBER; i++)
    {
        ARM_MPU_SetMemAttr(i, g_bsp_mpu_mair_attributes[i]);
    }

    /* Initialize all configured regions */
    for (r_index = 0U; r_index < p_cfg->num_regions; r_index++)
    {
        FSP_ASSERT(p_cfg->mpu_regions[r_index].r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER);
        r_mpu_region_init(p_cfg->mpu_regions[r_index].r_index, &(p_cfg->mpu_regions[r_index]));
    }

    /* Enable the MPU */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    return err;
}

/*******************************************************************************************************************//**
 * This function disable the MPU by clearing all the regions.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_MPUDisable (void)
{
    uint8_t r_index;

    /* Disable the MPU */
    ARM_MPU_Disable();

    /* Clear all regions */
    for (r_index = 0U; r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER; r_index++)
    {
        ARM_MPU_ClrRegion(r_index);
    }
}

/*******************************************************************************************************************//**
 * This function return the number of regions enabled
 *
 * @retval Number of regions enabled
 **********************************************************************************************************************/
uint8_t R_BSP_MPURegionCountGet (void)
{
    uint8_t count   = 0;
    uint8_t r_index = 0;
    for (r_index = 0; r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER; r_index++)
    {
        MPU->RNR = r_index;
        if ((MPU->RLAR & MPU_RLAR_EN_Msk) == MPU_RLAR_EN_Msk)
        {
            count++;
        }
    }

    return count;
}

/*******************************************************************************************************************//**
 * This function enables a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was enabled successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionEnable (const bsp_mpu_region_t * const p_region)
{
    uint32_t          rnr  = 0;
    volatile uint32_t rlar = 0;
    fsp_err_t         err  = FSP_SUCCESS;

    FSP_ASSERT(p_region->r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER);

    /* RNR */
    rnr = p_region->r_index;

    /* RLAR */
    MPU->RNR = rnr;
    rlar     = MPU->RLAR;
    rlar    |= MPU_RLAR_EN_Msk;

    MPU->RLAR = rlar;

    return err;
}

/*******************************************************************************************************************//**
 * This function disables a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was disabled successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionDisable (const bsp_mpu_region_t * const p_region)
{
    uint32_t          rnr  = 0;
    volatile uint32_t rlar = 0;
    fsp_err_t         err  = FSP_SUCCESS;

    FSP_ASSERT(p_region->r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER);

    /* RNR */
    rnr = p_region->r_index;

    /* RLAR */
    MPU->RNR = rnr;
    rlar     = MPU->RLAR;
    rlar    &= ~(MPU_RLAR_EN_Msk);

    MPU->RLAR = rlar;

    return err;
}

/*******************************************************************************************************************//**
 * This function sets up the access rules for a specific region.
 *
 * @param[in]  p_region                Pointer to specific region configuration structure.
 *
 * @retval  FSP_SUCCESS              Region was configured successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionSet (bsp_mpu_region_t * const p_region)
{
    uint32_t  rnr  = 0;
    uint32_t  rbar = 0;
    uint32_t  rlar = 0;
    fsp_err_t err  = FSP_SUCCESS;

    FSP_ASSERT(p_region->r_index < BSP_MPU_DEVICE_MAX_REGION_NUMBER);

    /* Disable the MPU */
    ARM_MPU_Disable();

    /* Clear the region */
    ARM_MPU_ClrRegion(p_region->r_index);

    /* RNR */
    rnr = p_region->r_index;

    /* RBAR */
    rbar = (p_region->base & MPU_RBAR_BASE_Msk) | \
           (p_region->attr.rbar & (MPU_RBAR_XN_Msk | MPU_RBAR_AP_Msk | MPU_RBAR_SH_Msk));

    /* RLAR */
    rlar = (p_region->attr.r_limit & MPU_RLAR_LIMIT_Msk) |                                           \
           ((uint32_t) (p_region->attr.mair_idx << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) | \
           (p_region->r_enable);

    /* Set MPU region with specified number, base, and limit */
    ARM_MPU_SetRegion(rnr, rbar, rlar);

    /* Enable the MPU */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    return err;
}

/*******************************************************************************************************************//**
 * This function gets the current settings for a specific region and store it in the passing argument.
 *
 * @param[in]  p_region_data           Pointer to specific region configuration structure.
 * @param[in]  r_index                 Index of specific region that user want to get setting.
 *
 * @retval  FSP_SUCCESS              Get specific region successfully.
 * @retval  FSP_ERR_ASSERTION        r_index exceeded max region supported.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MPURegionGet (bsp_mpu_region_t * const p_region_data, uint8_t r_index)
{
    fsp_err_t         err  = FSP_SUCCESS;
    uint32_t          rnr  = r_index;
    volatile uint32_t rbar = 0;
    volatile uint32_t rlar = 0;

    FSP_ASSERT(rnr < BSP_MPU_DEVICE_MAX_REGION_NUMBER);

    MPU->RNR = rnr;
    rbar     = MPU->RBAR;
    rlar     = MPU->RLAR;

    p_region_data->base      = (rbar & MPU_RBAR_BASE_Msk);
    p_region_data->attr.rbar = (rbar & (MPU_RBAR_XN_Msk | MPU_RBAR_AP_Msk | MPU_RBAR_SH_Msk));
    p_region_data->r_index   = r_index;
    p_region_data->r_enable  = (rlar & MPU_RLAR_EN_Msk);

    p_region_data->attr.r_limit  = (rlar & MPU_RLAR_LIMIT_Msk);
    p_region_data->attr.mair_idx = ((rlar & MPU_RLAR_AttrIndx_Msk) >> MPU_RLAR_AttrIndx_Pos);

    return err;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * This function sets up the MPU region specified by the index using the provided configuration structure.
 * It is used to apply access permissions, base address, size, and other attributes for memory protection.
 *
 * @param[in]  r_index       Index of the MPU region to configure.
 * @param[in]  region_conf   Pointer to the configuration structure for the region.
 **********************************************************************************************************************/
static void r_mpu_region_init (const uint32_t r_index, const bsp_mpu_region_t * region_conf)
{
    uint32_t rnr  = 0;
    uint32_t rbar = 0;
    uint32_t rlar = 0;

    /* RNR */
    rnr = r_index;

    /* RBAR */
    rbar = (region_conf->base & MPU_RBAR_BASE_Msk) | \
           (region_conf->attr.rbar & (MPU_RBAR_XN_Msk | MPU_RBAR_AP_Msk | MPU_RBAR_SH_Msk));

    /* RLAR */
    rlar = (region_conf->attr.r_limit & MPU_RLAR_LIMIT_Msk) |                                           \
           ((uint32_t) (region_conf->attr.mair_idx << MPU_RLAR_AttrIndx_Pos) & MPU_RLAR_AttrIndx_Msk) | \
           (region_conf->r_enable);

    /* Set MPU region with specified number, base, and limit */
    ARM_MPU_SetRegion(rnr, rbar, rlar);
}
