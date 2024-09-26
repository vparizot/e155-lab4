// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"


void initTIM(TIM_TypeDef * TIMx){
    //CONFIGURE COUNTER
    //prescaler register: TIMX_PSC counter to prescale input clk signal
    TIMx->PSC ; //(pg. 959 for TIM16)

    //counter register: TIMX_CNT
    // i dont think i do anything with this rn

    //Auto-reload register: TIMX_ARR
    TIMx->ARR |= ; // pg. 959 for TIM16

    // pg. 950 enable CEN (counter enable)
    TIMx->CR1 |= (1<<0); //PRESCALE REGISTER, AUTOLOAD-REGISTER, ENABLE COUNTER

    
}

void delay_millis(TIM_TypeDef * TIMx, uint32_t ms){



}