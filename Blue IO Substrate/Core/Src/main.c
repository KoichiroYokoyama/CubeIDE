/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "adc.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */





int overflow0 = 0;
int overflow1 = 0;
int overflow2 = 0;
int overflow3 = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
	if(htim->Instance == TIM5){
		__HAL_TIM_CLEAR_FLAG(&htim5, TIM_IT_UPDATE);
		if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim5)){//0->65535
			overflow0 --;
		}else{//65535->0
			overflow0 ++;
		}
	}
	if(htim->Instance == TIM3){
		__HAL_TIM_CLEAR_FLAG(&htim3, TIM_IT_UPDATE);
		if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3)){
			overflow1 --;
		}else{
			overflow1 ++;
		}
	}
	if(htim->Instance == TIM2){
		__HAL_TIM_CLEAR_FLAG(&htim2, TIM_IT_UPDATE);
		if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2)){
			overflow2 --;
		}else{
			overflow2 ++;
		}
	}
	if(htim->Instance == TIM4){
		__HAL_TIM_CLEAR_FLAG(&htim4, TIM_IT_UPDATE);
		if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4)){
			overflow3 --;
		}else{
			overflow3 ++;
		}
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN2_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);//エンコー�?読み取りスター�?
  HAL_TIM_Base_Start_IT(&htim5);//割り込み有効�?
  HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim4);

  HAL_CAN_Start(&hcan2);

  uint32_t cnt0_f;
  uint32_t cnt1_f;
  uint32_t cnt2_f;
  uint32_t cnt3_f;
  char scnt0[100];
  char scnt1[100];
  char scnt2[100];
  char scnt3[100];
  overflow0 = 0;
  overflow1 = 0;
  overflow2 = 0;
  overflow3 = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //ENC
	  cnt0_f = (long)(overflow0)*0x10000 + (long)TIM5 ->CNT;//TIMx->CNTとすることで随時値を読�?ことが可能
	  cnt1_f = (long)(overflow1)*0x10000 + (long)TIM3 ->CNT;
	  cnt2_f = (long)(overflow2)*0x10000 + (long)TIM2 ->CNT;
	  cnt3_f = (long)(overflow3)*0x10000 + (long)TIM4 ->CNT;
	  sprintf(scnt0, "ENC0:%d ", cnt0_f);
	  sprintf(scnt1, "ENC1:%d ", cnt1_f);
	  sprintf(scnt2, "ENC2:%d ", cnt2_f);
	  sprintf(scnt3, "ENC3:%d\r\n", cnt3_f);
	  HAL_UART_Transmit(&huart3, scnt0, strlen(scnt0) + 1, 0xFFFF);
	  HAL_UART_Transmit(&huart3, scnt1, strlen(scnt1) + 1, 0xFFFF);
	  HAL_UART_Transmit(&huart3, scnt2, strlen(scnt2) + 1, 0xFFFF);
	  HAL_UART_Transmit(&huart3, scnt3, strlen(scnt3) + 1, 0xFFFF);

	  //LED
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	  HAL_Delay(100);

	  //Photo
	  uint8_t p0 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_3);
	  uint8_t p1 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4);
	  uint8_t p2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	  uint8_t p3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	  uint8_t p4 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	  uint8_t p5 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	  uint8_t p6 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0);
	  uint8_t p7 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1);
	  char ph0[10];
	  char ph1[10];
	  char ph2[10];
	  char ph3[10];
	  char ph4[10];
	  char ph5[10];
	  char ph6[10];
	  char ph7[10];
	  sprintf(ph0, "PHOTO0:%d ",p0);
	  sprintf(ph1, "PHOTO1:%d ",p1);
	  sprintf(ph2, "PHOTO2:%d ",p2);
	  sprintf(ph3, "PHOTO3:%d ",p3);
	  sprintf(ph4, "PHOTO4:%d ",p4);
	  sprintf(ph5, "PHOTO5:%d ",p5);
	  sprintf(ph6, "PHOTO6:%d ",p6);
	  sprintf(ph7, "PHOTO7:%d\r\n ",p7);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph0, strlen(ph0), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph1, strlen(ph1), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph2, strlen(ph2), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph3, strlen(ph3), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph4, strlen(ph4), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph5, strlen(ph5), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph6, strlen(ph6), 0xFFFF);
	  HAL_UART_Transmit(&huart3, (uint8_t*)ph7, strlen(ph7), 0xFFFF);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */