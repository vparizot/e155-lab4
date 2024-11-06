/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
// main.c
// E155 Lab4
// Victoria Parizot
// vparizot@g.hmc.edu

// Includes for libraries
#include "lib/STM32L432KC_RCC.h"
#include "lib/STM32L432KC_GPIO.h"
#include "lib/STM32L432KC_FLASH.h"
#include "lib/STM32L432KC_TIM.h"

// Define macros for constants
#define SOUND_PIN           6
#define DELAY_DURATION_MS    500


// Function for dummy delay by executing nops
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

//3
const int B = 246; //b3

//4
const int Fs = 370; //f4s
const int D = 293;
const int E = 329;
const int A = 440; 
const int q = 200;
const int h = 400;
const int B1 = 493; //4
//5
const int D1 = 587;
const int A1 = 880;
const int Cs = 554;
const int G1 = 784;
const int Fs1 = 740;
const int third =300 ;
const int G = 392; //4
const int Cs1 = 554;


// Pitch in Hz, duration in ms
const int halway [][2] = {
{B, q}, //3
{B, q }, //3
{Fs,q }, //4
{Fs,q },//4
{E,q },//4
{D,q },//4
{D,q },//4
{B,h },//4
{0, q },//4
{E, q},//4
{Fs, q },//4
{E, q },//4
{D, q },//4
{D, q },//4
{B, q },//3
{D, q },//4
{D, q },//4
{E, q },//4
{Fs, q },//4
{E, q },//4
{D, q },//4//4
{D, q },//4
{B, q },//3
{B, q },//3
{0, h},
{0, q},
{Fs, q},//4
{E,q},//4

{E ,q},//4
{0 ,q},
{0 ,q},
{0 ,q},
{E ,q},//4
{Fs ,q},//4
{E ,q},//4
{D ,h},//4
{D ,h},//4
{B ,h},//3
{B ,h},//3
{B ,q},//3
{0 ,q},//3
{0 ,q},
{A ,q}, //4
{Fs ,q},//4
{A ,q},//4
{E ,q},//4
{Fs ,h},//4
{Fs ,h},//4
{0 ,h},
{0 ,h},
{E ,q},//4
{D ,q},//4
{E ,h},//4
{E ,q},//4
{D ,q},//4
{E ,q},//4
{D ,h},//4
{D ,q},//4
{E ,q},//4
{Fs ,q},//4
{E ,q},//4
{D ,h},//4
{D ,q},//4
{D,h}, //4
{B ,h}, //3
{B, h}, //3
{0 ,q},

{Cs ,q}, //5
{D1 ,q}, //5
{B1 ,h}, //6
{B1 ,h}, //6
{B1, h}, //6
{A1 ,h},//5
{A1 ,h},//5
{A1, h}, //5
{Cs ,q},//5
{D1 , q},//5
{A1 ,h}, //5
{A1 ,h}, //5
{A1 ,h}, //5

{G1 ,q}, //5
{Fs1 ,q}, //5
{A ,third},//4
{G ,third}, //4
{Fs ,h}, //4
{E ,h}, //4
{D ,q}, //4
{E ,h}, //4
{Fs ,third}, //4
{Fs ,h}, //4
{ Fs,q}, //4
{E ,h}, //4
{E, h}, //4
{0, h},
{Cs1 ,q}, //5
{D1 ,q}, //5
{B1 ,h}, //6
{B1 ,h}, //6
{B1, q}, //6
{A1 ,h}, //5
{A1, h}, //5
{A1 ,q},
{Cs1 ,q}, //5
{D1 ,q}, //5
{A1 ,h}, //5
{A1 ,h}, //5
{A ,h}, //4
{A ,h}, //4
{A ,h}, //4
{A ,h}, //4

{G, third}, //4
{Fs , third}, //4
{Fs , h}, //4
{E , h}, //4
{D , h}, //4
{D , h}, //4
{E , q}, //4
{Fs , h},
{Fs,q}};


const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};




int main(void) {

    // Configure flash to add waitstates to avoid timing errors
    //configureFlash();

    // CONFIGURE CLOCKS IN RCC: (do we still have to Setup the PLL and switch clock source to the PLL)
    //configureClock();
 
/////////////////////////
    //clock source control
    //RCC->CFGR |= (1<<10); //bits 10:8 (PPRE1) where 0xx is HCLK not divided
    //RCC->CFGR |= (1<<7) ; // AHB Prescaler, (HPRE[3:0] = 0xxx)

    //enable timer (pg 245)
    RCC->APB2ENR |= (1<<16); //enable timer 15
    RCC->APB2ENR |= (1<<17); //enable timer 16

    //RCC->CFGR |= (0b1 << 13);
    //RCC->CFGR |= (0b1 << 7);

    //SYSCFGEN
    //RCC->APB2ENR |= (1<<0);
////////////////////////////////
  
    // Turn on clock to GPIOA
    RCC->AHB2ENR |= (1 << 0);

    //SELECT CORRECT CLK SRC IN TIM CONTROL
    initTIMpwm(TIM16);
    initTIMdelay(TIM15);

    // set output pin as an alternate function (TIM16 has PA6)
    pinMode(6, GPIO_ALT);     // set up alternate function
    GPIO->AFRL &= ~(0b1111 <<24);                                  
    GPIO->AFRL |= (0b1110 << 24);    //Set AF14 to be output
    // datasheet pg. 57
  
   // cycle thru entry
   while(1) {
    int i = 0;
    while (notes[i][1] != 0){ // exit loop at duration = 0
      pitch(TIM16, notes[i][0]);
      delay_millis(TIM15, notes[i][1]);
      i++;
 
     }
   }
}

/*************************** End of file ****************************/
