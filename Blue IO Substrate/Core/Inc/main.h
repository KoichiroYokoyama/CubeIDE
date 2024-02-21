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
#define Enc0_TX_Pin GPIO_PIN_0
#define Enc0_TX_GPIO_Port GPIOA
#define Enc0_RX_Pin GPIO_PIN_1
#define Enc0_RX_GPIO_Port GPIOA
#define ADC1_Pin GPIO_PIN_2
#define ADC1_GPIO_Port GPIOA
#define ADC0_Pin GPIO_PIN_3
#define ADC0_GPIO_Port GPIOA
#define Enc1_TX_Pin GPIO_PIN_6
#define Enc1_TX_GPIO_Port GPIOA
#define Enc1_RX_Pin GPIO_PIN_7
#define Enc1_RX_GPIO_Port GPIOA
#define ADC2_Pin GPIO_PIN_0
#define ADC2_GPIO_Port GPIOB
#define ADC3_Pin GPIO_PIN_1
#define ADC3_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_2
#define LED0_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOE
#define LED3_Pin GPIO_PIN_9
#define LED3_GPIO_Port GPIOE
#define SW0_Pin GPIO_PIN_10
#define SW0_GPIO_Port GPIOE
#define SW1_Pin GPIO_PIN_11
#define SW1_GPIO_Port GPIOE
#define SW2_Pin GPIO_PIN_12
#define SW2_GPIO_Port GPIOE
#define SW3_Pin GPIO_PIN_13
#define SW3_GPIO_Port GPIOE
#define Can0_RX_Pin GPIO_PIN_12
#define Can0_RX_GPIO_Port GPIOB
#define Can0_TX_Pin GPIO_PIN_13
#define Can0_TX_GPIO_Port GPIOB
#define sw0_Pin GPIO_PIN_8
#define sw0_GPIO_Port GPIOD
#define sw1_Pin GPIO_PIN_9
#define sw1_GPIO_Port GPIOD
#define Enc3_TX_Pin GPIO_PIN_12
#define Enc3_TX_GPIO_Port GPIOD
#define Enc3_RX_Pin GPIO_PIN_13
#define Enc3_RX_GPIO_Port GPIOD
#define Cycle_LED_Pin GPIO_PIN_14
#define Cycle_LED_GPIO_Port GPIOD
#define Valve0_Pin GPIO_PIN_6
#define Valve0_GPIO_Port GPIOC
#define Valve1_Pin GPIO_PIN_7
#define Valve1_GPIO_Port GPIOC
#define Valve2_Pin GPIO_PIN_8
#define Valve2_GPIO_Port GPIOC
#define Valve3_Pin GPIO_PIN_9
#define Valve3_GPIO_Port GPIOC
#define Valve4_Pin GPIO_PIN_8
#define Valve4_GPIO_Port GPIOA
#define Valve5_Pin GPIO_PIN_9
#define Valve5_GPIO_Port GPIOA
#define Valve6_Pin GPIO_PIN_10
#define Valve6_GPIO_Port GPIOA
#define Valve7_Pin GPIO_PIN_11
#define Valve7_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define Enc2_TX_Pin GPIO_PIN_15
#define Enc2_TX_GPIO_Port GPIOA
#define Serial0_TX_Pin GPIO_PIN_10
#define Serial0_TX_GPIO_Port GPIOC
#define Serial0_RX_Pin GPIO_PIN_11
#define Serial0_RX_GPIO_Port GPIOC
#define Photo0_Pin GPIO_PIN_3
#define Photo0_GPIO_Port GPIOD
#define Photo1_Pin GPIO_PIN_4
#define Photo1_GPIO_Port GPIOD
#define Serial1_TX_Pin GPIO_PIN_5
#define Serial1_TX_GPIO_Port GPIOD
#define Serial1_RX_Pin GPIO_PIN_6
#define Serial1_RX_GPIO_Port GPIOD
#define Enc2_RX_Pin GPIO_PIN_3
#define Enc2_RX_GPIO_Port GPIOB
#define Photo2_Pin GPIO_PIN_4
#define Photo2_GPIO_Port GPIOB
#define Photo3_Pin GPIO_PIN_5
#define Photo3_GPIO_Port GPIOB
#define Photo4_Pin GPIO_PIN_8
#define Photo4_GPIO_Port GPIOB
#define Photo5_Pin GPIO_PIN_9
#define Photo5_GPIO_Port GPIOB
#define Photo6_Pin GPIO_PIN_0
#define Photo6_GPIO_Port GPIOE
#define Photo7_Pin GPIO_PIN_1
#define Photo7_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
