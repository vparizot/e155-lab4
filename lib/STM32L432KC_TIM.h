// STM32L432KC_TIM.h
// Header for TIM functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Base addresses
#define RCC_TIM16 (0x40001000UL) // base address of TIM6
#define RCC_TIM17 (0x40001400UL) // base address of TIM7

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for TIM
///////////////////////////////////////////////////////////////////////////////
// TIM register structs here
typedef struct { //pg 967
    volatile uint32_t CR1;      // memory offset 0x00
    volatile uint32_t CR1;      // memory offset 0x04
    volatile uint32_t FILL1;     // memory offset 0x08
    volatile uint32_t DIER;      // memory offset 0x0C
    volatile uint32_t SR;      // memory offset 0x10
    volatile uint32_t EGR;      // memory offset 0x14
    volatile uint32_t CCMR1;      // memory offset 0x18
    volatile uint32_t FILL2;     // memory offset 0x1C
    volatile uint32_t CCER;      // memory offset 0x20
    volatile uint32_t CNT;      // memory offset 0x24
    volatile uint32_t PSC;      // memory offset 0x28
    volatile uint32_t ARR;      // memory offset 0x2C
    volatile uint32_t RCR;      // memory offset 0x30
    volatile uint32_t CCR1;      // memory offset 0x34
    volatile uint32_t FILL3;      // memory offset 0x38
    volatile uint32_t FILL4;      // memory offset 0x3c
    volatile uint32_t FILL5;      // memory offset 0x40
    volatile uint32_t BDTR;      // memory offset 0x44
    volatile uint32_t DCR;      // memory offset 0x48
    volatile uint32_t DMAR;      // memory offset 0x4C
    volatile uint32_t OR1;      // memory offset 0x50
    volatile uint32_t FILL6;      // memory offset 0x54
    volatile uint32_t FILL7;      // memory offset 0x58
    volatile uint32_t FILL8;      // memory offset 0x5C
    volatile uint32_t OR2;      // memory offset 0x60

} TIM; 

// Pointers to GPIO-sized chunks of memory for each peripheral
#define TIM6 ((TIM_TypeDef *) TIM_BASE6)
#define TIM7 ((TIM_TypeDef *) TIM_BASE7)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initTIM(TIM_TypeDef * TIMx);
void delay_millis(TIM_TypeDef * TIMx, uint32_t ms);

#endif