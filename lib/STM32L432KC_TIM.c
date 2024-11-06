// STM32L432KC_TIM.c
// Source code for TIM functions
// E155 Lab4
// Victoria Parizot
// vparizot@g.hmc.edu
#include "STM32L432KC_TIM.h"
#include "STM32L432KC_GPIO.h"


void initTIMdelay(TIM_TypeDef15 * TIMx){
    //CONFIGURE COUNTER
    //prescaler register: TIMX_PSC counter to prescale input clk signal
    TIMx->PSC =39; //|= (0b1111<<0) ; //(pg. 959 for TIM16)
    TIMx->ARR= 0xffff;//; // set ARR

    // pg. 950 enable CEN (counter enable)
    TIMx->CR1 |= (1<<0); //PRESCALE REGISTER, AUTOLOAD-REGISTER, ENABLE COUNTER

    //TIMx->CR1 |= (1<<7); //autoreload reg en
    //Auto-reload register: TIMX_ARR
    TIMx->CNT = 0;
}

void initTIMpwm(TIM_TypeDef16 * TIMx){

    TIMx->PSC = 39;  // Set Prescaler register to 39 to scale down clock to 100 kHz
    
    TIMx->CR1 |= (1<<7); // set ARPE bit in TIMx_CR1 register for mode (upcounting, pg 893)

    TIMx->ARR = 50000; // set ARR, will update based on pitch later
    
    // select PWM by writing 110 to OCxM bits of TIMx_CCMRx register
    TIMx->CCMR1 &= ~(0b11<<0); 

  // se;ect PWM mode
    TIMx->CCMR1 |= (1<<6);
    TIMx->CCMR1 |= (1<<5);
    TIMx->CCMR1 |= (1<<3);

    //50% duty cycle
    TIMx->CCR1 = TIMx->ARR / 2;

    TIMx->CCER |= (1 << 0); 

    TIMx->BDTR |= (1<<15); //turn on MOE (main outpit enable)

    // initialize registers by setting UG bit in TIMx_EGR register
    TIMx->EGR |= (1<<0); 
    TIMx->CR1 |= (1<<0); //CEN, ENABLE COUNTER
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/// delay_millis - delays a timer for a set amount of milliseconds
///   sets max value for counterbased on ms
///   Set counter to 0
///   have while loop wait until max value is reached
///      check if flag of max value is hit
///////////////////////////////////////////////////////////////////   
void delay_millis(TIM_TypeDef15 * TIMx, uint32_t ms){
  // define max value based on time for delay
  TIMx->ARR = 100*ms;
  TIMx->CNT = 0;

  TIMx->SR &= (0b00<<0);

  while((TIMx->SR & 0b1)!=1){
    __asm("nop");
  }
}

void pitch(TIM_TypeDef16 * TIMx, uint32_t hz){
// pwm mode pg. 906 for tim15
// freq determined by TIMx_ARR and duty cycle TIMx_CCRx

// calc psc
//int pscval = (16000000-pitch)/pitch;

//TIMx->ARR &= (0b0000000000000000); //clear ARR
TIMx->ARR = 100000/hz; //pitch/1000;
TIMx->CCR1 = TIMx->ARR / 2; //50% duty cycle
TIMx->EGR |= (1<<0);//set egr

    
//TIMx->PSC &= ~(1111<<0); //clear pscval
//TIMx->PSC |= (pscval); //set to get desired freq

//TIMx->CCR1 |= (11) ;


}