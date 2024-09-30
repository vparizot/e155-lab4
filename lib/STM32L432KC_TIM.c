// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"
#include "STM32L432KC_GPIO.h"

void initTIMdelay(TIM_TypeDef15 * TIMx){
    //CONFIGURE COUNTER
    //prescaler register: TIMX_PSC counter to prescale input clk signal
    TIMx->PSC |= (0b1111<<0) ; //(pg. 959 for TIM16)
   
    // pg. 950 enable CEN (counter enable)
    TIMx->CR1 |= (1<<0); //PRESCALE REGISTER, AUTOLOAD-REGISTER, ENABLE COUNTER

    TIMx->CR1 |= (1<<7); //autoreload reg en
    //Auto-reload register: TIMX_ARR
    TIMx->ARR &= (0b0000000000000000); //clear ARR
    TIMx->ARR |= (1<<15); // set ARR


}

void initTIMpwm(TIM_TypeDef16 * TIMx){
   
    // CONFIGURE COUNTER
    TIMx->PSC |= (0b1111<<0); // Set Prescaler register to 15
    
    TIMx->CR1 |= (1<<7); // set ARPE bit in TIMx_CR1 register for mode (upcounting, pg 893)

    //TIMx->ARR &= (0b0000000000000000); //clear ARR
    TIMx->ARR = 50000; //(1<<15); 
    
    // select PWM by writing 110 to OCxM bits of TIMx_CCMRx register
    TIMx->CCMR1 &= ~(0b11<<0); //~(0b111<<5);
    //TIMx->CCMR1 |= (0b110<<4); 
 // enable preload register by setting OCxPE bit in TIMx_CCMRx registers
    //TIMx->CCMR1 &= ~(0b11 <<0);
    TIMx->CCMR1 |= (1<<6);
    TIMx->CCMR1 |= (1<<5);
    TIMx->CCMR1 |= (0b1<<3);
    //50% duty cycle
    TIMx->CCR1 |= TIMx->ARR / 2;

    TIMx->CCER |= (0b1 <<0); 

    


   

    TIMx->BDTR |= (1<<15); //turn on MOE

 

    // initialize registers by setting UG bit in TIMx_EGR register
    TIMx->EGR |= (0b1<<0);
    TIMx->CR1 |= (1<<0); //CEN, ENABLE COUNTER
   
    
  
}

void delay_millis(TIM_TypeDef15 * TIMx, uint32_t ms){
//set max value for counterbased on ms
//have while loop wait until max value is reacher
    //check if flag of max value is hit
    // reset counter to zero

}

void pitch(TIM_TypeDef16 * TIMx, uint32_t pitch){
// pwm mode pg. 906 for tim15
// freq determined by TIMx_ARR and duty cycle TIMx_CCRx

// calc psc
//int pscval = (16000000-pitch)/pitch;

//TIMx->ARR &= (0b0000000000000000); //clear ARR
TIMx->ARR = pitch/1000;
TIMx->CCR1 |= TIMx->ARR / 2; //50% duty cycle
TIMx->EGR |= (0b1<<0);//set egr

    
//TIMx->PSC &= ~(1111<<0); //clear pscval
//TIMx->PSC |= (pscval); //set to get desired freq

//TIMx->CCR1 |= (11) ;


}