/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MPU_H_
#define BSP_MPU_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#if defined(BSP_MCU_GROUP_RCARU5LX)
 #include "bsp_mcu_cpu_memory_cfg.h"
#endif

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MPU BSP MPU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Helper define to initialize the attribute structure. */
#define BSP_MPU_ATTRn_CONFIG(n)                  BSP_MPU_ATTR ## n ## _CONFIG

/** Helper define to initialize the region structure. */
#define BSP_MPU_REGIONn_CONFIG(n)                BSP_REGION ## n ## _CONFIG

/* Helper define to calculate the region limit address. */
#define BSP_MPU_REGION_LIMIT_ADDR(base, size)    (((base & MPU_RBAR_BASE_Msk) + size - 1) & MPU_RLAR_LIMIT_Msk)

/**  Reference: Hardware's User Manual U5Lx device
 *   Non-secure MPU (MPU_NS): 16 regions
 */
#define BSP_MPU_DEVICE_MAX_REGION_NUMBER       0x10U
#define BSP_MPU_DEVICE_MAX_ATTRUBUTE_NUMBER    0x08U

#define BSP_MPU_STORE_EXCLUSIVE_SUCCESS        0x00U
#define BSP_MPU_STORE_EXCLUSIVE_FAILED         0x01U

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** MPU Attribute configuration structure */
typedef struct st_bsp_mpu_region_attr
{
    /* Attributes belonging to RBAR */
    uint8_t rbar : 5;

    /* MAIR index for attribute indirection */
    uint8_t mair_idx : 3;

    /* Region Limit Address value to be written to the RLAR register. */
    uint32_t r_limit;
} bsp_mpu_region_attr_t;

/** Region definition data structure */
typedef struct st_bsp_mpu_region
{
    /* Region enable status */
    uint8_t r_enable;

    /* Region index */
    uint8_t r_index;

    /* Region Base Address */
    uint32_t base;

    /* Region Name */
    const char * name;

    /* Region Attributes */
    bsp_mpu_region_attr_t attr;
} bsp_mpu_region_t;

/* MPU configuration data structure */
typedef struct st_bsp_mpu_config
{
    /* Number of regions */
    uint8_t num_regions;

    /* Regions */
    const bsp_mpu_region_t * mpu_regions;
} bsp_mpu_config_t;

/***********************************************************************************************************************
 * Exported global variable (to be accessed by other files)
 **********************************************************************************************************************/
extern const uint8_t          g_bsp_mpu_mair_attributes[BSP_MPU_DEVICE_MAX_ATTRUBUTE_NUMBER];
extern const bsp_mpu_config_t g_bsp_mpu_config;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      LDR Exclusive (8 bit). Executes a exclusive LDR instruction for 8 bit value.
 *
 * @param[in]  p_addr  Pointer to data
 *
 * @retval  Value of type uint8_t at (*ptr)
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint8_t R_BSP_LDREXB (volatile uint8_t * p_addr)
{
    return __LDREXB(p_addr);
}

/*******************************************************************************************************************//**
 * @brief      STR Exclusive (8 bit). Executes a exclusive STR instruction for 8 bit values.
 *
 * @param[in]  value  Value to store
 * @param[in]  p_addr Pointer to location
 *
 * @retval  BSP_MPU_STORE_EXCLUSIVE_SUCCESS           Function succeeded
 * @retval  BSP_MPU_STORE_EXCLUSIVE_FAILED            Function failed
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t R_BSP_STREXB (uint8_t value, volatile uint8_t * p_addr)
{
    return __STREXB(value, p_addr);
}

/*******************************************************************************************************************//**
 * @brief      LDR Exclusive (16 bit). Executes a exclusive LDR instruction for 16 bit value.
 *
 * @param[in]  p_addr  Pointer to data
 *
 * @retval  Value of type uint16_t at (*ptr)
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint16_t R_BSP_LDREXH (volatile uint16_t * p_addr)
{
    return __LDREXH(p_addr);
}

/*******************************************************************************************************************//**
 * @brief      STR Exclusive (16 bit). Executes a exclusive STR instruction for 16 bit values.
 *
 * @param[in]  value  Value to store
 * @param[in]  p_addr Pointer to location
 *
 * @retval  BSP_MPU_STORE_EXCLUSIVE_SUCCESS           Function succeeded
 * @retval  BSP_MPU_STORE_EXCLUSIVE_FAILED            Function failed
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t R_BSP_STREXH (uint16_t value, volatile uint16_t * p_addr)
{
    return __STREXH(value, p_addr);
}

/*******************************************************************************************************************//**
 * @brief      LDR Exclusive (32 bit). Executes a exclusive LDR instruction for 32 bit value.
 *
 * @param[in]  p_addr  Pointer to data
 *
 * @retval  Value of type uint32_t at (*ptr)
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t R_BSP_LDREXW (volatile uint32_t * p_addr)
{
    return __LDREXW(p_addr);
}

/*******************************************************************************************************************//**
 * @brief      STR Exclusive (32 bit). Executes a exclusive STR instruction for 32 bit values.
 *
 * @param[in]  value  Value to store
 * @param[in]  p_addr Pointer to location
 *
 * @retval  BSP_MPU_STORE_EXCLUSIVE_SUCCESS           Function succeeded
 * @retval  BSP_MPU_STORE_EXCLUSIVE_FAILED            Function failed
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t R_BSP_STREXW (uint32_t value, volatile uint32_t * p_addr)
{
    return __STREXW(value, p_addr);
}

/*******************************************************************************************************************//**
 * @brief      Removes the exclusive lock which is created by LDREX.
 *
 * @retval     None
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void R_BSP_CLREX (void)
{
    __CLREX();
}

/*******************************************************************************************************************//**
 * @brief      Disables writes to registers that are associated with the Non-secure MPU region
 *             from software or from a debug agent connected to the processor
 *
 * @retval     None
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void R_BSP_LockNonSecureMPU (void)
{
    R_CPUCTL0->CPU0LOCKCRNS_b.LCKNSMPU = 1U;
}

/*******************************************************************************************************************//**
 * @brief      Enables writes to registers that are associated with the Non-secure MPU region
 *             from software or from a debug agent connected to the processor
 *
 * @retval     None
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void R_BSP_UnlockNonSecureMPU (void)
{
    R_CPUCTL0->CPU0LOCKCRNS_b.LCKNSMPU = 0U;
}

/*******************************************************************************************************************//**
 * @brief      Disables writes to the VTOR_NS register
 *
 * @retval     None
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void R_BSP_LockNonSecureVTOR (void)
{
    R_CPUCTL0->CPU0LOCKCRNS_b.LCKNSVTOR = 1U;
}

/*******************************************************************************************************************//**
 * @brief      Enables writes to the VTOR_NS register
 *
 * @retval     None
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void R_BSP_UnlockNonSecureVTOR (void)
{
    R_CPUCTL0->CPU0LOCKCRNS_b.LCKNSVTOR = 0U;
}

fsp_err_t R_BSP_MPUEnable(const bsp_mpu_config_t * const p_cfg);
void      R_BSP_MPUDisable(void);
uint8_t   R_BSP_MPURegionCountGet(void);
fsp_err_t R_BSP_MPURegionEnable(const bsp_mpu_region_t * const p_region);
fsp_err_t R_BSP_MPURegionDisable(const bsp_mpu_region_t * const p_region);
fsp_err_t R_BSP_MPURegionSet(bsp_mpu_region_t * const p_region);
fsp_err_t R_BSP_MPURegionGet(bsp_mpu_region_t * const p_region_data, uint8_t r_index);

/** @} (end defgroup BSP_MPU) */

#endif                                 /* BSP_MPU_H_ */
