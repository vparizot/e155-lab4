// STM32L432KC_TIM.h
// Header for TIM functions
// E155 Lab4
// Victoria Parizot
// vparizot@g.hmc.edu
#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

// Base addresses
#define TIM_BASE16 (0x40014400UL) // base address of TIM16 (pg. 69)
#define TIM_BASE15 (0x40014000UL) // base address of TIM15

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for TIM
///////////////////////////////////////////////////////////////////////////////
// TIM register structs here
typedef struct { //pg 967 is TIM16
    volatile uint32_t CR1;      // memory offset 0x00
    volatile uint32_t CR2;      // memory offset 0x04
    volatile uint32_t FILL1;     // memory offset 0x08
    volatile uint32_t DIER;      // memory offset 0x0C
    volatile uint32_t SR;      // memory offset 0x10
    volatile uint32_t EGR;      // memory offset 0x14
    volatile uint32_t CCMR1;      // memory offset 0x18
    volatile uint32_t CCMR1a;     // memory offset 0x1C
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

} TIM_TypeDef16; 

// TIM register structs here
typedef struct { //pg 946 is TIM15
    volatile uint32_t CR1;      // memory offset 0x00
    volatile uint32_t CR2;      // memory offset 0x04
    volatile uint32_t SMCR;     // memory offset 0x08
    volatile uint32_t DIER;      // memory offset 0x0C
    volatile uint32_t SR;      // memory offset 0x10
    volatile uint32_t EGR;      // memory offset 0x14
    volatile uint32_t CCMR1;      // memory offset 0x18
    volatile uint32_t CCMR1a;     // memory offset 0x1C
    volatile uint32_t CCER;      // memory offset 0x20
    volatile uint32_t CNT;      // memory offset 0x24
    volatile uint32_t PSC;      // memory offset 0x28
    volatile uint32_t ARR;      // memory offset 0x2C
    volatile uint32_t RCR;      // memory offset 0x30
    volatile uint32_t CCR1;      // memory offset 0x34
    volatile uint32_t CCR2;      // memory offset 0x38
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

} TIM_TypeDef15; 

// Pointers to GPIO-sized chunks of memory for each peripheral
#define TIM16 ((TIM_TypeDef16 *) TIM_BASE16)
#define TIM15 ((TIM_TypeDef15 *) TIM_BASE15)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initTIMpwm(TIM_TypeDef16 * TIMx);
void initTIMdelay(TIM_TypeDef15 * TIMx);

void delay_millis(TIM_TypeDef15 * TIMx, uint32_t ms);
void pitch(TIM_TypeDef16 * TIMx, uint32_t hz);

#endif