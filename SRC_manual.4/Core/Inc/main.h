/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define PHOTO0_Pin GPIO_PIN_0
#define PHOTO0_GPIO_Port GPIOC
#define PHOTO1_Pin GPIO_PIN_1
#define PHOTO1_GPIO_Port GPIOC
#define PHOTO2_Pin GPIO_PIN_2
#define PHOTO2_GPIO_Port GPIOC
#define VALVE0_Pin GPIO_PIN_3
#define VALVE0_GPIO_Port GPIOC
#define ENC0_T_Pin GPIO_PIN_0
#define ENC0_T_GPIO_Port GPIOA
#define ENC0_R_Pin GPIO_PIN_1
#define ENC0_R_GPIO_Port GPIOA
#define MOTOR5_T_Pin GPIO_PIN_2
#define MOTOR5_T_GPIO_Port GPIOA
#define MOTOR5_R_Pin GPIO_PIN_3
#define MOTOR5_R_GPIO_Port GPIOA
#define PHOTO3_Pin GPIO_PIN_4
#define PHOTO3_GPIO_Port GPIOA
#define ENC3_T_Pin GPIO_PIN_5
#define ENC3_T_GPIO_Port GPIOA
#define ENC1_T_Pin GPIO_PIN_6
#define ENC1_T_GPIO_Port GPIOA
#define ENC1_R_Pin GPIO_PIN_7
#define ENC1_R_GPIO_Port GPIOA
#define VALVE1_Pin GPIO_PIN_4
#define VALVE1_GPIO_Port GPIOC
#define VALVE2_Pin GPIO_PIN_5
#define VALVE2_GPIO_Port GPIOC
#define SERIAL1_T_Pin GPIO_PIN_10
#define SERIAL1_T_GPIO_Port GPIOB
#define SERIAL1_R_Pin GPIO_PIN_11
#define SERIAL1_R_GPIO_Port GPIOB
#define MOTOR4_T_Pin GPIO_PIN_14
#define MOTOR4_T_GPIO_Port GPIOB
#define MOTOR4_R_Pin GPIO_PIN_15
#define MOTOR4_R_GPIO_Port GPIOB
#define ENC2_T_Pin GPIO_PIN_12
#define ENC2_T_GPIO_Port GPIOD
#define ENC2_R_Pin GPIO_PIN_13
#define ENC2_R_GPIO_Port GPIOD
#define MOTOR3_T_Pin GPIO_PIN_6
#define MOTOR3_T_GPIO_Port GPIOC
#define MOTOR3_R_Pin GPIO_PIN_7
#define MOTOR3_R_GPIO_Port GPIOC
#define MOTOR2_T_Pin GPIO_PIN_8
#define MOTOR2_T_GPIO_Port GPIOC
#define MOTOR2_R_Pin GPIO_PIN_9
#define MOTOR2_R_GPIO_Port GPIOC
#define MOTOR1_T_Pin GPIO_PIN_8
#define MOTOR1_T_GPIO_Port GPIOA
#define MOTOR1_R_Pin GPIO_PIN_9
#define MOTOR1_R_GPIO_Port GPIOA
#define MOTOR0_T_Pin GPIO_PIN_10
#define MOTOR0_T_GPIO_Port GPIOA
#define MOTOR0_R_Pin GPIO_PIN_11
#define MOTOR0_R_GPIO_Port GPIOA
#define SERIAL0_T_Pin GPIO_PIN_10
#define SERIAL0_T_GPIO_Port GPIOC
#define SERIAL0_R_Pin GPIO_PIN_11
#define SERIAL0_R_GPIO_Port GPIOC
#define SERIAL2_T_Pin GPIO_PIN_12
#define SERIAL2_T_GPIO_Port GPIOC
#define SERIAL2_R_Pin GPIO_PIN_2
#define SERIAL2_R_GPIO_Port GPIOD
#define LED5_Pin GPIO_PIN_3
#define LED5_GPIO_Port GPIOD
#define LED4_Pin GPIO_PIN_4
#define LED4_GPIO_Port GPIOD
#define ENC3_R_Pin GPIO_PIN_3
#define ENC3_R_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_4
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_5
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_7
#define LED0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
