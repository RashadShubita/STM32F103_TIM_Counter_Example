/*******************************************************************************
 * @file    timer.h
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

/* Define to prevent recursive inclusion */
#ifndef __INC_TIMER_H_
#define __INC_TIMER_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f10x.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup timer
 * @{
 */

/**
 * @defgroup timer_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_functions
 * @{
 */
/**
 * @brief   Timer6 as up counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM2_UpCount_Config(void);

/**
 * @brief   Timer3 as down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM3_DownCount_Config(void);

/**
 * @brief   Timer4 as up down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM4_UpDownCount_Config(void);

/**
 * @brief   Timer4 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM4_IRQ_Callback(void);

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_TIMER_H_ */
