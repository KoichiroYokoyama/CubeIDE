/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define Photo0_Pin GPIO_PIN_0
#define Photo0_GPIO_Port GPIOC
#define Photo1_Pin GPIO_PIN_1
#define Photo1_GPIO_Port GPIOC
#define Photo2_Pin GPIO_PIN_2
#define Photo2_GPIO_Port GPIOC
#define Valve0_Pin GPIO_PIN_3
#define Valve0_GPIO_Port GPIOC
#define Enc0_T_Pin GPIO_PIN_0
#define Enc0_T_GPIO_Port GPIOA
#define Enc0_R_Pin GPIO_PIN_1
#define Enc0_R_GPIO_Port GPIOA
#define Motor5_1_Pin GPIO_PIN_2
#define Motor5_1_GPIO_Port GPIOA
#define Motor5_2_Pin GPIO_PIN_3
#define Motor5_2_GPIO_Port GPIOA
#define Enc3_T_Pin GPIO_PIN_5
#define Enc3_T_GPIO_Port GPIOA
#define Enc1_T_Pin GPIO_PIN_6
#define Enc1_T_GPIO_Port GPIOA
#define Enc1_R_Pin GPIO_PIN_7
#define Enc1_R_GPIO_Port GPIOA
#define Valve1_Pin GPIO_PIN_4
#define Valve1_GPIO_Port GPIOC
#define Valve2_Pin GPIO_PIN_5
#define Valve2_GPIO_Port GPIOC
#define Serial1_T_Pin GPIO_PIN_10
#define Serial1_T_GPIO_Port GPIOB
#define Serial1_R_Pin GPIO_PIN_11
#define Serial1_R_GPIO_Port GPIOB
#define Motor4_1_Pin GPIO_PIN_14
#define Motor4_1_GPIO_Port GPIOB
#define Motor4_2_Pin GPIO_PIN_15
#define Motor4_2_GPIO_Port GPIOB
#define Enc2_T_Pin GPIO_PIN_12
#define Enc2_T_GPIO_Port GPIOD
#define Enc2_R_Pin GPIO_PIN_13
#define Enc2_R_GPIO_Port GPIOD
#define Motor3_1_Pin GPIO_PIN_6
#define Motor3_1_GPIO_Port GPIOC
#define Motor3_2_Pin GPIO_PIN_7
#define Motor3_2_GPIO_Port GPIOC
#define Motor2_1_Pin GPIO_PIN_8
#define Motor2_1_GPIO_Port GPIOC
#define Motor2_2_Pin GPIO_PIN_9
#define Motor2_2_GPIO_Port GPIOC
#define Motor1_1_Pin GPIO_PIN_8
#define Motor1_1_GPIO_Port GPIOA
#define Motor1_2_Pin GPIO_PIN_9
#define Motor1_2_GPIO_Port GPIOA
#define Motor0_1_Pin GPIO_PIN_10
#define Motor0_1_GPIO_Port GPIOA
#define Motor0_2_Pin GPIO_PIN_11
#define Motor0_2_GPIO_Port GPIOA
#define Serial0_T_Pin GPIO_PIN_10
#define Serial0_T_GPIO_Port GPIOC
#define Serial0_R_Pin GPIO_PIN_11
#define Serial0_R_GPIO_Port GPIOC
#define Serial2_T_Pin GPIO_PIN_12
#define Serial2_T_GPIO_Port GPIOC
#define Serial2_R_Pin GPIO_PIN_2
#define Serial2_R_GPIO_Port GPIOD
#define Enc3_R_Pin GPIO_PIN_3
#define Enc3_R_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
