/*******************************************************************************
 * @file    main.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    04.05.2019
 *
 * @brief   main application called after startup
 * @note
 *
@verbatim
Copyright (C) 2019, Rashad Shubita

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "nvic.h"
#include "SysTick.h"
#include "timer.h"
#include "gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/**
 * @brief   Variable for storing the up counter
 */
static uint16_t UpCounter = 0;

/**
 * @brief   Variable for storing the down counter
 */
static uint16_t DownCounter = 0;

/**
 * @brief   Variable for storing the up down counter
 */
static uint16_t UpDownCounter = 0;

/* Private constants ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{

	SysTick_Init();
	NVIC_Init();
    GPIO_OnBoard_Init_LED();

    /* Clear PRIMASK, enable IRQs */
    __enable_irq();

    /* Configure Counters */
    TIM2_UpCount_Config();
    TIM3_DownCount_Config();
    TIM4_UpDownCount_Config();

 /* Infinite loop */
 while(1)
 {
	    /* Read periodically counter registers */
	    UpCounter = TIM2->CNT;
	    DownCounter = TIM3->CNT;
	    UpDownCounter = TIM4->CNT;
 }

}


