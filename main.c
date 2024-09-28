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
// GPIO blink LED with clock configuration
// Josh Brake
// jbrake@hmc.edu
// 9/16/24

// Includes for libraries
#include "lib/STM32L432KC_RCC.h"
#include "lib/STM32L432KC_GPIO.h"
#include "lib/STM32L432KC_FLASH.h"
#include "lib/STM32L432KC_TIM.h"

// Define macros for constants
#define SOUND_PIN           6
#define DELAY_DURATION_MS    200


// Function for dummy delay by executing nops
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

// Pitch in Hz, duration in ms
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
    configureFlash();

    // CONFIGURE CLOCKS IN RCC: (do we still have to Setup the PLL and switch clock source to the PLL)
    configureClock();
 
    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    

    //SELECT CORRECT CLK SRC IN TIM CONTROL
    initTIMpwm(TIM16);
    initTIMdelay(TIM15);

   // size of array
   int size = sizeof(notes)/sizeof(notes[0]);
   
   // cycle thru entry
   for (int i = 0; i < size; i++) {
      pitch(TIM16, notes[i][0]);
      ms_delay(notes[i][1]);
      //delay_millis(TIM15, notes[i][1]);
      // exit loop at duration = 0
      if (notes[i][1] == 0) {
        break;
      }
   }





   //Set LED_PIN as output
    //pinMode(LED_PIN, GPIO_OUTPUT);

    // Blink LED
    //while(1) {
    //    ms_delay(DELAY_DURATION_MS);
   //     togglePin(LED_PIN);
    //}
    //return 0; 
    

  // set up peripherals
      //clk
      //timer - use tm2/3 - registers are the similair
        // 1 timer for pwm, 1 timer for note duration

        // three all purpose times: TIM2, TIM15, TIM16
      //pwm

    // call while loop
    // go thru each pitch and duration


}

/*************************** End of file ****************************/
