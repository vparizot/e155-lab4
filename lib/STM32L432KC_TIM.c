// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"
#include "STM32L432KC_GPIO.h"

void initTIMdelay(TIM_TypeDef * TIMx){
    //CONFIGURE COUNTER
    //prescaler register: TIMX_PSC counter to prescale input clk signal
    TIMx->PSC ; //(pg. 959 for TIM16)

    //counter register: TIMX_CNT
    // i dont think i do anything with this rn

    //Auto-reload register: TIMX_ARR
//    TIMx->ARR |= ; // pg. 959 for TIM16

    // pg. 950 enable CEN (counter enable)
//    TIMx->  CR1 |= (1<<0); //PRESCALE REGISTER, AUTOLOAD-REGISTER, ENABLE COUNTER

}

void initTIMpwm(TIM_TypeDef * TIMx){
    // CONFIGURE COUNTER
//    TIMx->PSC |= (110) ; // Prescaler register
//    TIMx->ARR |= ; //Auto-reload register: TIMX_ARR
    TIMx->CR1 |= (1<<0); //CEN, ENABLE COUNTER

    // select PWM by writing 110 to OCxM bits of TIMx_CCMRx register
    TIMx->CCMR1 |= (110<<4); 

    // enable preload register by setting OCxPE bit in TIMx_CCMRx registers
    TIMx->CCMR1 |= (1<<3);

    // set ARPE bit in TIMx_CR1 register for mode (upcounting, pg 893)
    TIMx->CR1 |= (1<<7);

    // initialize registers by setting UG bit in TIMx_EGR register
    TIMx->EGR |= (1);

    // set output pin as an alternate function (TIM16 has PA6)
    pinMode(6, GPIO_ALT);     // set up alternate function
    GPIO->AFRL |= (1110 << 24);    //Set AF14 to be output
    // datasheet pg. 57
}


void delay_millis(TIM_TypeDef * TIMx, uint32_t ms){
//set max value for counterbased on ms
//have while loop wait until max value is reacher
    //check if flag of max value is hit
    // reset counter to zero

}

void pitch(TIM_TypeDef * TIMx, uint32_t pitch){
// pwm mode pg. 906 for tim15
// freq determined by TIMx_ARR and duty cycle TIMx_CCRx

TIMx->ARR |= (1000);
TIMx->CCR1 |= (10) ;





// 




}