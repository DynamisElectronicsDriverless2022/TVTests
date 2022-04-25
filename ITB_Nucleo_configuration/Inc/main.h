/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_CONVST_Pin GPIO_PIN_8
#define ADC_CONVST_GPIO_Port GPIOI
#define ADC_RESET_Pin GPIO_PIN_13
#define ADC_RESET_GPIO_Port GPIOC
#define ADC_BUSY_Pin GPIO_PIN_14
#define ADC_BUSY_GPIO_Port GPIOC
#define AUX_12V_BATT_Pin GPIO_PIN_6
#define AUX_12V_BATT_GPIO_Port GPIOH
#define AUX_12V_DCDC_Pin GPIO_PIN_7
#define AUX_12V_DCDC_GPIO_Port GPIOH
#define FLASH_RESET_Pin GPIO_PIN_11
#define FLASH_RESET_GPIO_Port GPIOD
#define COOLING2_BATT_Pin GPIO_PIN_6
#define COOLING2_BATT_GPIO_Port GPIOJ
#define COOLING2_DCDC_Pin GPIO_PIN_7
#define COOLING2_DCDC_GPIO_Port GPIOJ
#define COOLING1_BATT_Pin GPIO_PIN_8
#define COOLING1_BATT_GPIO_Port GPIOJ
#define COOLING1_DCDC_Pin GPIO_PIN_9
#define COOLING1_DCDC_GPIO_Port GPIOJ
#define EXT_INTERRUPT_AUX_Pin GPIO_PIN_10
#define EXT_INTERRUPT_AUX_GPIO_Port GPIOJ
#define EXT_INTERRUPT_AUX_EXTI_IRQn EXTI15_10_IRQn
#define STEP_UP_ENABLE_Pin GPIO_PIN_11
#define STEP_UP_ENABLE_GPIO_Port GPIOJ
#define DIGITAL_IN_AUX_Pin GPIO_PIN_0
#define DIGITAL_IN_AUX_GPIO_Port GPIOK
#define DIGITAL_OUT_AUX_Pin GPIO_PIN_1
#define DIGITAL_OUT_AUX_GPIO_Port GPIOK
#define LED_DEBUG_5_Pin GPIO_PIN_2
#define LED_DEBUG_5_GPIO_Port GPIOK
#define LED_DEBUG_4_Pin GPIO_PIN_2
#define LED_DEBUG_4_GPIO_Port GPIOG
#define LED_DEBUG_3_Pin GPIO_PIN_3
#define LED_DEBUG_3_GPIO_Port GPIOG
#define LED_DEBUG_2_Pin GPIO_PIN_6
#define LED_DEBUG_2_GPIO_Port GPIOG
#define LED_DEBUG_1_Pin GPIO_PIN_7
#define LED_DEBUG_1_GPIO_Port GPIOG
#define PUMP_PWM_Pin GPIO_PIN_7
#define PUMP_PWM_GPIO_Port GPIOC
#define FAN_5_PWM_Pin GPIO_PIN_8
#define FAN_5_PWM_GPIO_Port GPIOC
#define FAN_4_PWM_Pin GPIO_PIN_9
#define FAN_4_PWM_GPIO_Port GPIOC
#define FAN_1_PWM_Pin GPIO_PIN_9
#define FAN_1_PWM_GPIO_Port GPIOA
#define FAN_2_PWM_Pin GPIO_PIN_10
#define FAN_2_PWM_GPIO_Port GPIOA
#define FAN_3_PWM_Pin GPIO_PIN_11
#define FAN_3_PWM_GPIO_Port GPIOA
#define AMP_MUTE_Pin GPIO_PIN_13
#define AMP_MUTE_GPIO_Port GPIOJ
#define AMP_STBY_Pin GPIO_PIN_14
#define AMP_STBY_GPIO_Port GPIOJ
#define AMP_FAULT_Pin GPIO_PIN_15
#define AMP_FAULT_GPIO_Port GPIOJ
#define AMP_WARN_Pin GPIO_PIN_9
#define AMP_WARN_GPIO_Port GPIOG
#define KEY_SWITCH_IT_Pin GPIO_PIN_12
#define KEY_SWITCH_IT_GPIO_Port GPIOG
#define KEY_SWITCH_IT_EXTI_IRQn EXTI15_10_IRQn
#define INVERTER_X_BE2_Pin GPIO_PIN_13
#define INVERTER_X_BE2_GPIO_Port GPIOG
#define INVERTER_X_EF_Pin GPIO_PIN_3
#define INVERTER_X_EF_GPIO_Port GPIOK
#define INVERTER_1_BE1_Pin GPIO_PIN_4
#define INVERTER_1_BE1_GPIO_Port GPIOK
#define INVERTER_2_BE1_Pin GPIO_PIN_5
#define INVERTER_2_BE1_GPIO_Port GPIOK
#define INVERTER_3_BE1_Pin GPIO_PIN_6
#define INVERTER_3_BE1_GPIO_Port GPIOK
#define INVERTER_4_BE1_Pin GPIO_PIN_7
#define INVERTER_4_BE1_GPIO_Port GPIOK
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
