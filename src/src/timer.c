/*******************************************************************************
 * @file    timer.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    04.05.2019
 *
 * @brief   Timer examples
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

/* Includes */
#include "timer.h"
#include "gpio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief   Timer2 as up counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM2_UpCount_Config(void)
{
  /* Enable TIM2 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

  /* Set counter direction as up-counter */
  TIM2->CR1 &= ~TIM_CR1_DIR;

  /* Set timer Prescaler, bus clock = 36 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 36000000 / (35999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM2->PSC = 35999;

  /* Set timer reload value */
  TIM2->ARR = 5000;

  /* Enable TIM2 counter */
  TIM2->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer3 as down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM3_DownCount_Config(void)
{
  /* Enable TIM3 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

  /* Set counter direction as down-counter */
  TIM3->CR1 |= TIM_CR1_DIR;

  /* Set timer Prescaler, bus clock = 36 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 36000000 / (35999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM3->PSC = 35999;

  /* Set timer reload value */
  TIM3->ARR = 5000;

  /* Enable TIM3 counter */
  TIM3->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer4 as up down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM4_UpDownCount_Config(void)
{
  /* Enable TIM4 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

  /* Set counter direction as up-down-counter */
  TIM4->CR1 |= TIM_CR1_CMS;

  /* Set timer Prescaler, bus clock = 36 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 36000000 / (35999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM4->PSC = 35999;

  /* Set timer reload value */
  TIM4->ARR = 5000;

  /* Enable update event interrupt */
  TIM4->DIER |= TIM_DIER_UIE;

  /* Enable TIM4 counter */
  TIM4->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer4 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM4_IRQ_Callback(void)
{
  /* Clear update interrupt flag */
  TIM4->SR &= ~TIM_SR_UIF;

  /* Toggle green LED */
  GPIO_Pin_Toggle(GPIOC,13);
}


