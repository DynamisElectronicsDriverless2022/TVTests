/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "TVModel.h"
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
#define INVERTER_BA3_2_Pin GPIO_PIN_3
#define INVERTER_BA3_2_GPIO_Port GPIOE
#define INVERTER_BA3_4_Pin GPIO_PIN_0
#define INVERTER_BA3_4_GPIO_Port GPIOF
#define INVERTER_BA3_3_Pin GPIO_PIN_1
#define INVERTER_BA3_3_GPIO_Port GPIOF
#define INVERTER_EF_X_Pin GPIO_PIN_6
#define INVERTER_EF_X_GPIO_Port GPIOF
#define INVERTER_BE1_1_Pin GPIO_PIN_7
#define INVERTER_BE1_1_GPIO_Port GPIOF
#define AD7616_RST_Pin GPIO_PIN_2
#define AD7616_RST_GPIO_Port GPIOA
#define APPS1_IN_Pin GPIO_PIN_3
#define APPS1_IN_GPIO_Port GPIOA
#define DEBUG_LED_1_Pin GPIO_PIN_12
#define DEBUG_LED_1_GPIO_Port GPIOF
#define PRECHG_Pin GPIO_PIN_0
#define PRECHG_GPIO_Port GPIOG
#define RedLed_Pin GPIO_PIN_14
#define RedLed_GPIO_Port GPIOB
#define DEBUG_LED_2_Pin GPIO_PIN_10
#define DEBUG_LED_2_GPIO_Port GPIOD
#define DEBUG_LED_3_Pin GPIO_PIN_4
#define DEBUG_LED_3_GPIO_Port GPIOG
#define AD7616_BUSY_Pin GPIO_PIN_10
#define AD7616_BUSY_GPIO_Port GPIOA
#define INVERTER_BE1_3_Pin GPIO_PIN_4
#define INVERTER_BE1_3_GPIO_Port GPIOD
#define INVERTER_BE1_4_Pin GPIO_PIN_5
#define INVERTER_BE1_4_GPIO_Port GPIOD
#define INVERTER_BE2_X_Pin GPIO_PIN_6
#define INVERTER_BE2_X_GPIO_Port GPIOD
#define INVERTER_BA3_1_Pin GPIO_PIN_7
#define INVERTER_BA3_1_GPIO_Port GPIOD
#define AD7616_CONVST_Pin GPIO_PIN_3
#define AD7616_CONVST_GPIO_Port GPIOB
#define INVERTER_BE1_2_Pin GPIO_PIN_7
#define INVERTER_BE1_2_GPIO_Port GPIOB
#define ADS8688_RST_Pin GPIO_PIN_8
#define ADS8688_RST_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
