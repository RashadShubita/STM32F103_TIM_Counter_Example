/*******************************************************************************
 * @file    rcc.h
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    11.04.2019
 *
 * @brief   RCC configuration header file
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
#ifndef __INC_RCC_H_
#define __INC_RCC_H_

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
 * @addtogroup rcc
 * @{
 */

/**
 * @defgroup rcc_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_functions
 * @{
 */
void RCC_SystemReset(void);
void RCC_DetectResetSource(void);
void RCC_ProcessReset(void);
void RCC_ClockOut_Setup(void);

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

#endif /*__INC_RCC_H_ */
