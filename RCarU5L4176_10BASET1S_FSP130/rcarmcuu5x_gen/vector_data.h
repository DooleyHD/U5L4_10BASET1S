/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (0)
#endif

#define R_BSP_ISR_SLOT_TEMPLATE(slot, group, type)                        \
        void r_bsp_irq_slot_##slot##_isr(void)                                    \
        {                                                                         \
            uint32_t imfu_f   = R_IMFU0->IMFU ## type[group].IMFU ## type ## F;   \
            uint32_t imfu_msk = R_IMFU0->IMFU ## type[group].IMFU ## type ## MSK; \
            uint8_t bit_pos  = (uint8_t)(__CLZ(__RBIT(imfu_f & (~imfu_msk))));\
            irq_slot_##slot##_function[bit_pos]();                                \
        }

/* Function define */

/* ISR prototypes */

#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
