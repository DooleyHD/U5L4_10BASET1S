/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Defines function pointers to be used with vector table. */
typedef void (* exc_ptr_t)(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void);
void RAM_Init(void);

extern const uint32_t RAM_START;
extern const uint32_t RAM_LENGTH;
extern const uint32_t GRAM_START;
extern const uint32_t GRAM_LENGTH;
int32_t main(void);

BSP_ATTRIBUTE_STACKLESS void RAM_Init ()
{
    __ASM volatile (
        "mov r5, lr                 \n" /* Save the LR register from caller Reset_Handler */
        "mov r4, #0xaaaaaaaa        \n" /* Initialize default value */

        "ldr r1, = RAM_START        \n" /* Load RAM base address to r1 */
        "ldr r2, = RAM_LENGTH       \n" /* Load RAM length to r2 */
        "add r2, r1, r2             \n"

        "bl FillDefaultValue        \n"

#if defined(__ICCARM__)
        "ldr r3, = R_BSP_CheckChipStandByMode\n" /* Load address of CheckChipStandByMode */
        "blx r3                              \n" /* Call function to check chip standby mode */

        "ldr r3, = R_BSP_GetChipStandByMode  \n" /* Load address of GetChipStandByMode */
        "blx r3                              \n" /* Get the current chip standby mode */
#else
        "bl R_BSP_CheckChipStandByMode \n"       /* Calling the function to check the current chip standby mode */
        "bl R_BSP_GetChipStandByMode   \n"       /* Get the current chip standby mode */
#endif
        "mov r1, #1                    \n"       /* Load BSP_CYCLICRUN_MODE after the BL calls. r1 is caller-saved and is not preserved across function calls. */
        "mov r2, r0                    \n"
        "cmp r1, r2                    \n"       /* Compare the result of the function call (r2) with BSP_CYCLICRUN_MODE (r1) */
        "beq skip_init_gram            \n"       /* Skip initialization if modes are equal */

#ifndef BSP_MCU_GROUP_RCARU5X_MULTICORE
        "ldr r1, = GRAM_START       \n"          /* Load GRAM base address to r1 */
        "ldr r2, = GRAM_LENGTH      \n"          /* Load GRAM length to r2 */
        "add r2, r1, r2             \n"

        "bl FillDefaultValue        \n"
#endif  /* #ifndef BSP_MCU_GROUP_RCARU5X_MULTICORE */

        "bx r5                      \n" /* Return to caller (Reset_Handler) */

        /*******************************************************************************
         * Initialize the RAM space via 4 bytes write accesses
         *******************************************************************************/

        "FillDefaultValue:          \n"
        "   str  r4, [r1]           \n"
        "   add r1, r1, #4          \n"
        "LoopFillDefaultValue:      \n"
        "   cmp r1, r2              \n"
        "   blo FillDefaultValue    \n"
        "   bx lr                   \n" /* Return to initialization process */
        "skip_init_gram:            \n"
        "   bx r5                   \n" /* Return to caller (Reset_Handler) */
        );
}

/*******************************************************************************************************************//**
 * SOC starts executing here out of reset. Main stack pointer is set up already.
 **********************************************************************************************************************/
void Reset_Handler (void)
{
    /* Restrict execution to CPU0 only, as multicore operation is not supported yet.
     * In the VLAB environment, only CORE0 is allowed to run.
     * Other cores enter a low-power wait state (WFI) indefinitely.
     */
#if  BSP_VLAB_HARDWARE_BASED_USED && BSP_FEATURE_COREID_AVAILABLE
    if (0U != R_CPUCTL0->COREID)
    {
        while (1)
        {
            __WFI();
        }
    }
#endif

    /* RAM initialization */
    RAM_Init();

    /* Initialize system using BSP. */
    SystemInit();

    /* Call user application. */
    main();

    while (1)
    {
        /* Infinite Loop. */
    }
}

/*******************************************************************************************************************//**
 * Default exception handler.
 **********************************************************************************************************************/
void Default_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/* Main stack */
static uint8_t g_main_stack[BSP_CFG_STACK_MAIN_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_STACK);

/* Heap */
#if (BSP_CFG_HEAP_SIZE_BYTES > 0)

BSP_DONT_REMOVE uint8_t g_heap[BSP_CFG_HEAP_SIZE_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT) \
    BSP_PLACE_IN_SECTION(BSP_SECTION_HEAP);
#endif

/* All system exceptions in the vector table are weak references to Default_Handler. If the user wishes to handle
 * these exceptions in their code they should define their own function with the same name.
 */

#define WEAK_REF_ATTRIBUTE    __attribute__((weak, alias("Default_Handler")))

void HardFault_Handler(void) WEAK_REF_ATTRIBUTE;
void MemManage_Handler(void) WEAK_REF_ATTRIBUTE;
void BusFault_Handler(void) WEAK_REF_ATTRIBUTE;
void UsageFault_Handler(void) WEAK_REF_ATTRIBUTE;
void SecureFault_Handler(void) WEAK_REF_ATTRIBUTE;
void SVC_Handler(void) WEAK_REF_ATTRIBUTE;
void DebugMon_Handler(void) WEAK_REF_ATTRIBUTE;
void PendSV_Handler(void) WEAK_REF_ATTRIBUTE;
void SysTick_Handler(void) WEAK_REF_ATTRIBUTE;

/* Vector table. */
BSP_DONT_REMOVE const exc_ptr_t __Vectors[BSP_CORTEX_VECTOR_TABLE_ENTRIES] BSP_PLACE_IN_SECTION(
    BSP_SECTION_FIXED_VECTORS) =
{
    (exc_ptr_t) (&g_main_stack[0] + BSP_CFG_STACK_MAIN_BYTES), /*      Initial Stack Pointer     */
    Reset_Handler,                                             /*      Reset Handler             */
    NMI_Handler,                                               /*      NMI Handler               */
    HardFault_Handler,                                         /*      Hard Fault Handler        */
    MemManage_Handler,                                         /*      MPU Fault Handler         */
    BusFault_Handler,                                          /*      Bus Fault Handler         */
    UsageFault_Handler,                                        /*      Usage Fault Handler       */
    SecureFault_Handler,                                       /*      Secure Fault Handler      */
    0,                                                         /*      Reserved                  */
    0,                                                         /*      Reserved                  */
    0,                                                         /*      Reserved                  */
    SVC_Handler,                                               /*      SVCall Handler            */
    DebugMon_Handler,                                          /*      Debug Monitor Handler     */
    0,                                                         /*      Reserved                  */
    PendSV_Handler,                                            /*      PendSV Handler            */
    SysTick_Handler,                                           /*      SysTick Handler           */
};

/** @} (end addtogroup BSP_MCU) */
