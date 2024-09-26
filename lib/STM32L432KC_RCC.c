// STM32L432KC_RCC.c
// Source code for RCC functions

#include "STM32L432KC_RCC.h"

void configurePLL() {
    // Set clock to 80 MHz
    // Output freq = (src_clk) * (N/M) / R
    // (4 MHz) * (80/1) / 4 = 80 MHz
    // M: 1, N: 80, R: 4
    // Use MSI as PLLSRC

    // Turn off PLL
    RCC->CR &= ~(1 << 24);
    
    // Wait till PLL is unlocked (e.g., off)
    while ((RCC->CR >> 25 & 1) != 0);

    // Load configuration
    // Set PLL SRC to MSI
    RCC->PLLCFGR |= (1 << 0);
    RCC->PLLCFGR &= ~(1 << 1);

    // Set PLLN
    RCC->PLLCFGR &= ~(0b11111111 << 8); // Clear all bits of PLLN
    RCC->PLLCFGR |= (0b1010000 << 8); // |= 80
    
    // Set PLLM
    RCC->PLLCFGR &= ~(0b111 << 4);  // Clear all bits
    
    // Set PLLR
    RCC->PLLCFGR &= ~(1 << 26);
    RCC->PLLCFGR |= (1 << 25);
    
    // Enable PLLR output
    RCC->PLLCFGR |= (1 << 24);

    // Enable PLL
    RCC->CR |= (1 << 24);
    
    // Wait until PLL is locked
    while ((RCC->CR >> 25 & 1) != 1);
}

void configureClock(){
    // Configure and turn on PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR |= (0b11 << 0);
    while(!((RCC->CFGR >> 2) & 0b11));

    // Configure clk for TIM6/7
    //(pg 198) set to MCO to divide 
    //RCC->CFGR |= (1<<25); //When MCOSEL[3:0] = 0010 then MSI clock selected (pg 198)
    // ^ alr done in configurePLL()?

    //clock source control
    RCC->CFGR |= (1<<10); //bits 10:8 (PPRE1) where 0xx is HCLK not divided
    RCC->CFGR |= (1<<7) ; // AHB Prescaler, (HPRE[3:0] = 0xxx)

    // disable slave mode (pg927), SMCR
    // SMCR |= (1<< (pg 927)

    //enable timer (pg 245)
    RCC->APB2ENR |= (1<<16); //enable timer 15
    RCC->APB2ENR |= (1<<17); //enable timer 16

    //turn on MSI timer 



}