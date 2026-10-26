/* generated configuration header file - do not edit */
#ifndef BSP_MCU_CPU_MEMORY_CFG_H_
#define BSP_MCU_CPU_MEMORY_CFG_H_
#ifndef BSP_MPU_ATTR0_CONFIG
#define BSP_MPU_ATTR0_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WT_RA, MPU_ATTR_NORMAL_INNER_WT_RA),
#endif
#ifndef BSP_MPU_ATTR1_CONFIG
#define BSP_MPU_ATTR1_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WB_RA_WA, MPU_ATTR_NORMAL_INNER_WB_RA_WA),
#endif
#ifndef BSP_MPU_ATTR2_CONFIG
#define BSP_MPU_ATTR2_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_NON_CACHEABLE, MPU_ATTR_NORMAL_INNER_NON_CACHEABLE),
#endif
#ifndef BSP_MPU_ATTR3_CONFIG
#define BSP_MPU_ATTR3_CONFIG                    ARM_MPU_ATTR(ARM_MPU_ATTR_DEVICE_nGnRnE, ARM_MPU_ATTR_DEVICE_nGnRnE),
#endif
#ifndef BSP_MPU_ATTR4_CONFIG
#define BSP_MPU_ATTR4_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WB_RA_WA, MPU_ATTR_NORMAL_INNER_WB_RA_WA),
#endif
#ifndef BSP_MPU_ATTR5_CONFIG
#define BSP_MPU_ATTR5_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WB_RA_WA, MPU_ATTR_NORMAL_INNER_WB_RA_WA),
#endif
#ifndef BSP_MPU_ATTR6_CONFIG
#define BSP_MPU_ATTR6_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WB_RA_WA, MPU_ATTR_NORMAL_INNER_WB_RA_WA),
#endif
#ifndef BSP_MPU_ATTR7_CONFIG
#define BSP_MPU_ATTR7_CONFIG                    ARM_MPU_ATTR(MPU_ATTR_NORMAL_OUTER_WB_RA_WA, MPU_ATTR_NORMAL_INNER_WB_RA_WA),
#endif

#ifndef BSP_REGION00_ENABLE
#define BSP_REGION00_ENABLE     1U
#endif
#ifndef BSP_REGION01_ENABLE
#define BSP_REGION01_ENABLE     1U
#endif
#ifndef BSP_REGION02_ENABLE
#define BSP_REGION02_ENABLE     1U
#endif
#ifndef BSP_REGION03_ENABLE
#define BSP_REGION03_ENABLE     1U
#endif
#ifndef BSP_REGION04_ENABLE
#define BSP_REGION04_ENABLE     1U
#endif
#ifndef BSP_REGION05_ENABLE
#define BSP_REGION05_ENABLE     1U
#endif
#ifndef BSP_REGION06_ENABLE
#define BSP_REGION06_ENABLE     1U
#endif
#ifndef BSP_REGION07_ENABLE
#define BSP_REGION07_ENABLE     0U
#endif
#ifndef BSP_REGION08_ENABLE
#define BSP_REGION08_ENABLE     0U
#endif
#ifndef BSP_REGION09_ENABLE
#define BSP_REGION09_ENABLE     0U
#endif
#ifndef BSP_REGION10_ENABLE
#define BSP_REGION10_ENABLE     0U
#endif
#ifndef BSP_REGION11_ENABLE
#define BSP_REGION11_ENABLE     0U
#endif
#ifndef BSP_REGION12_ENABLE
#define BSP_REGION12_ENABLE     0U
#endif
#ifndef BSP_REGION13_ENABLE
#define BSP_REGION13_ENABLE     0U
#endif
#ifndef BSP_REGION14_ENABLE
#define BSP_REGION14_ENABLE     0U
#endif
#ifndef BSP_REGION15_ENABLE
#define BSP_REGION15_ENABLE     0U
#endif

#ifndef BSP_REGION00_CONFIG
#if (BSP_REGION00_ENABLE == 0U)
      #define BSP_REGION00_CONFIG
      #else
#define BSP_REGION00_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 0u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "CODE_FLASH_0",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RO * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00200000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION01_CONFIG
#if (BSP_REGION01_ENABLE == 0U)
      #define BSP_REGION01_CONFIG
      #else
#define BSP_REGION01_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 1u,                                                                      \
          .base = 0x00400000,                                  \
          .name = "CODE_FLASH_1",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RO * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00400000, 0x00200000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION02_CONFIG
#if (BSP_REGION02_ENABLE == 0U)
      #define BSP_REGION02_CONFIG
      #else
#define BSP_REGION02_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 2u,                                                                      \
          .base = 0x204E0000,                                  \
          .name = "RAM_CPU0",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 1U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x204E0000, 0x00020000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION03_CONFIG
#if (BSP_REGION03_ENABLE == 0U)
      #define BSP_REGION03_CONFIG
      #else
#define BSP_REGION03_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 3u,                                                                      \
          .base = 0x28000000,                                  \
          .name = "GLOBAL_RAM",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 1U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x28000000, 0x000B0000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION04_CONFIG
#if (BSP_REGION04_ENABLE == 0U)
      #define BSP_REGION04_CONFIG
      #else
#define BSP_REGION04_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 4u,                                                                      \
          .base = 0x2C000000,                                  \
          .name = "RETENTION_RAM",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 1U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x2C000000, 0x00008000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION05_CONFIG
#if (BSP_REGION05_ENABLE == 0U)
      #define BSP_REGION05_CONFIG
      #else
#define BSP_REGION05_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 5u,                                                                      \
          .base = 0x40400000,                                  \
          .name = "PERIPHERAL",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_PO)) << 1U) | (ARM_MPU_XN),                                 \
            .mair_idx = 3U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x40400000, 0x1EC00000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION06_CONFIG
#if (BSP_REGION06_ENABLE == 0U)
      #define BSP_REGION06_CONFIG
      #else
#define BSP_REGION06_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 1U,                            \
          .r_index = 6u,                                                                      \
          .base = 0x0C000000,                                  \
          .name = "CODE_FLASH_BLANK_CHECK_AREA",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_NON) << 3U) | ((((ARM_MPU_AP_RO * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_XN),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x0C000000, 0x00600000),\
          }                                                                                   \
      },
#endif
#endif

#ifndef BSP_REGION07_CONFIG
#if (BSP_REGION07_ENABLE == 0U)
#define BSP_REGION07_CONFIG
#else
      #define BSP_REGION07_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 7u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION08_CONFIG
#if (BSP_REGION08_ENABLE == 0U)
#define BSP_REGION08_CONFIG
#else
      #define BSP_REGION08_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 8u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION09_CONFIG
#if (BSP_REGION09_ENABLE == 0U)
#define BSP_REGION09_CONFIG
#else
      #define BSP_REGION09_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 9u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION10_CONFIG
#if (BSP_REGION10_ENABLE == 0U)
#define BSP_REGION10_CONFIG
#else
      #define BSP_REGION10_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 10u,                                                                     \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION11_CONFIG
#if (BSP_REGION11_ENABLE == 0U)
#define BSP_REGION11_CONFIG
#else
      #define BSP_REGION11_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 11u,                                                                     \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION12_CONFIG
#if (BSP_REGION12_ENABLE == 0U)
#define BSP_REGION12_CONFIG
#else
      #define BSP_REGION12_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 12u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION13_CONFIG
#if (BSP_REGION13_ENABLE == 0U)
#define BSP_REGION13_CONFIG
#else
      #define BSP_REGION13_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 13u,                                                                     \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION14_CONFIG
#if (BSP_REGION14_ENABLE == 0U)
#define BSP_REGION14_CONFIG
#else
      #define BSP_REGION14_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 14u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_REGION15_CONFIG
#if (BSP_REGION15_ENABLE == 0U)
#define BSP_REGION15_CONFIG
#else
      #define BSP_REGION15_CONFIG                                                             \
      {                                                                                       \
          .r_enable = 0U,                            \
          .r_index = 15u,                                                                      \
          .base = 0x00000000,                                  \
          .name = "Not Used",                                \
          .attr =                                                                             \
          {                                                                                   \
            .rbar = ((ARM_MPU_SH_OUTER) << 3U) | ((((ARM_MPU_AP_RW * 2U) | ARM_MPU_AP_NP)) << 1U) | (ARM_MPU_EX),                                 \
            .mair_idx = 0U,                            \
            .r_limit = BSP_MPU_REGION_LIMIT_ADDR(0x00000000, 0x00000000),\
          }                                                                                   \
      },
      #endif
#endif

#ifndef BSP_MPU_NUMBER_OF_REGIONS_ENBALED
#define BSP_MPU_NUMBER_OF_REGIONS_ENBALED             0x7U
#endif

#ifndef BSP_MPU_CONFIG_ENABLE
#define BSP_MPU_CONFIG_ENABLE                         1U
#endif
#endif /* BSP_MCU_CPU_MEMORY_CFG_H_ */
