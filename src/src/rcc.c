/*******************************************************************************
 * @file    rcc.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    11.04.2019
 *
 * @brief   RCC configuration source file
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
#include "rcc.h"
#include "SysTick.h"
#include "gpio.h"

/* Private typedef -----------------------------------------------------------*/

/**
 * @brief   Reset sources
 */
typedef enum
{
  RESET_SOURCE_UNKNOWN,
  POWER_ON_POWER_DOWN,
  SOFTWARE_RESET,
  LOW_LEVEL_ON_NRST
} ResetSource_Type;

/**
 * @}
 */

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/**
 * @brief   Reset source
 */
static ResetSource_Type resetSource = RESET_SOURCE_UNKNOWN;

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/


/**
 * @brief   Perform system reset
 * @note
 * @param   None
 * @retval  None
 */
void RCC_SystemReset(void)
{
  /* Perform system reset */
  NVIC_SystemReset();
}

/**
 * @brief   Detect system reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_DetectResetSource(void)
{
  uint32_t tmp;

  /* Read RCC clock control & status register (RCC_CSR)
   * to detect reset source */
  tmp = RCC->CSR;

  /* Detect reset source */
  if(RCC_CSR_SFTRSTF == (tmp & RCC_CSR_SFTRSTF))
  {
    /* Reset source is software request */
    resetSource = SOFTWARE_RESET;

    /* Clear reset flag */
    RCC->CSR |= RCC_CSR_RMVF;
  }
  else if(RCC_CSR_PORRSTF == (tmp & RCC_CSR_PORRSTF))
  {
    /* Reset source is power on/down */
    resetSource = POWER_ON_POWER_DOWN;
  }
  else if(RCC_CSR_PINRSTF == (tmp & RCC_CSR_PINRSTF))
  {
    /* Reset source is low level on NRST pin */
    resetSource = LOW_LEVEL_ON_NRST;

    /* Clear reset flag */
    RCC->CSR |= RCC_CSR_RMVF;
  }
  else
  {
    /* Reset source unknown */
    resetSource = RESET_SOURCE_UNKNOWN;
  }
}

/**
 * @brief   Turn on LEDs based on reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_ProcessReset(void)
{
  /* Check reset source */
  switch (resetSource)
  {
    case SOFTWARE_RESET:
      /* Blink Yellow LED */
      Yellow_LED_BITBAND =0;
      SysTick_Delay(500);
      Yellow_LED_BITBAND =1;
      SysTick_Delay(500);
      break;

    case LOW_LEVEL_ON_NRST:
      /* Blink red LED */
      GPIO_BITBAND(GPIOB_BASE, ODR, 0) = 1;
      SysTick_Delay(500);
      GPIO_BITBAND(GPIOB_BASE, ODR, 0) = 0;
      SysTick_Delay(500);
      break;

    case POWER_ON_POWER_DOWN:
      /* Blink both LEDs */
      Yellow_LED_BITBAND =0;
      SysTick_Delay(500);
      Yellow_LED_BITBAND =1;
      GPIO_BITBAND(GPIOB_BASE, ODR, 0) = 1;
      SysTick_Delay(500);
      GPIO_BITBAND(GPIOB_BASE, ODR, 0) = 0;
      SysTick_Delay(500);
      break;

    default:
      break;
  }
}

/**
 * @brief   Setup clock output
 * @note    HSE (8MHz)  -> MCO(PA8)
 *          GPIO configuration based on "Table 33" RM0008
 * @param   None
 * @retval  None
 */
void RCC_ClockOut_Setup(void)
{
  /* Enable port A clock */
  RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN;

  /* Select Output mode, max speed 50 MHz */
  GPIOA->CRH |= GPIO_CRH_MODE8;

  /* Select Alternate function output Push-pull*/
  GPIOA->CRH &= ~GPIO_CRH_CNF8;
  GPIOA->CRH |= GPIO_CRH_CNF8_1;


  /* Select HSE as clock source for MCO */
  RCC->CFGR &= ~RCC_CFGR_MCO;
  RCC->CFGR |= (RCC_CFGR_MCO_1 | RCC_CFGR_MCO_2);

}


