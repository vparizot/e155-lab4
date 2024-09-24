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

// Define macros for constants
#define LED_PIN           3
#define DELAY_DURATION_MS    200
#define speakerPin

// Function for dummy delay by executing nops
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {

    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // CONFIGURE CLOCKS IN RCC: (do we still have to Setup the PLL and switch clock source to the PLL)
    configureClock();
 
    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    //SELECT CORRECT CLK SRC IN TIM CONTROL
    initTIM(TIM16);
    initTIM(TIM17);

    //CONFIGURE COUNTER


    //PRESCALE REGISTER, AUTOLOAD-REGISTER, ENABLE COUNTER



   //Set LED_PIN as output
    pinMode(LED_PIN, GPIO_OUTPUT);

    // Blink LED
    while(1) {
        ms_delay(DELAY_DURATION_MS);
        togglePin(LED_PIN);
    }
    return 0; 
    

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
