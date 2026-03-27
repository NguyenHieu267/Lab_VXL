/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define RED_UP_DOWN_Pin GPIO_PIN_0
#define RED_UP_DOWN_GPIO_Port GPIOA
#define GREEN_UP_DOWN_Pin GPIO_PIN_1
#define GREEN_UP_DOWN_GPIO_Port GPIOA
#define YELLOW_UP_DOWN_Pin GPIO_PIN_2
#define YELLOW_UP_DOWN_GPIO_Port GPIOA
#define RED_LEFT_RIGHT_Pin GPIO_PIN_3
#define RED_LEFT_RIGHT_GPIO_Port GPIOA
#define GREEN_LEFT_RIGHT_Pin GPIO_PIN_4
#define GREEN_LEFT_RIGHT_GPIO_Port GPIOA
#define YELLOW_LEFT_RIGHT_Pin GPIO_PIN_5
#define YELLOW_LEFT_RIGHT_GPIO_Port GPIOA
#define a_UP_DOWN_Pin GPIO_PIN_0
#define a_UP_DOWN_GPIO_Port GPIOB
#define b_UP_DOWN_Pin GPIO_PIN_1
#define b_UP_DOWN_GPIO_Port GPIOB
#define c_UP_DOWN_Pin GPIO_PIN_2
#define c_UP_DOWN_GPIO_Port GPIOB
#define d_LEFT_RIGHT_Pin GPIO_PIN_10
#define d_LEFT_RIGHT_GPIO_Port GPIOB
#define e_LEFT_RIGHT_Pin GPIO_PIN_11
#define e_LEFT_RIGHT_GPIO_Port GPIOB
#define f_LEFT_RIGHT_Pin GPIO_PIN_12
#define f_LEFT_RIGHT_GPIO_Port GPIOB
#define g_LEFT_RIGHT_Pin GPIO_PIN_13
#define g_LEFT_RIGHT_GPIO_Port GPIOB
#define d_UP_DOWN_Pin GPIO_PIN_3
#define d_UP_DOWN_GPIO_Port GPIOB
#define e_UP_DOWN_Pin GPIO_PIN_4
#define e_UP_DOWN_GPIO_Port GPIOB
#define f_UP_DOWN_Pin GPIO_PIN_5
#define f_UP_DOWN_GPIO_Port GPIOB
#define g_UP_DOWN_Pin GPIO_PIN_6
#define g_UP_DOWN_GPIO_Port GPIOB
#define a_LEFT_RIGHT_Pin GPIO_PIN_7
#define a_LEFT_RIGHT_GPIO_Port GPIOB
#define b_LEFT_RIGHT_Pin GPIO_PIN_8
#define b_LEFT_RIGHT_GPIO_Port GPIOB
#define c_LEFT_RIGHT_Pin GPIO_PIN_9
#define c_LEFT_RIGHT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
