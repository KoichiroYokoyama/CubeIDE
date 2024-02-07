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
#include "../Inc/main.h"

#include <stdio.h>
#include <string.h>
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
int overflowcnt0 = 0;
int overflowcnt1 = 0;
int overflowcnt2 = 0;
int overflowcnt3 = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM5){
		__HAL_TIM_CLEAR_FLAG(&htim5,TIM_IT_UPDATE);
		if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim5)){
			overflowcnt0 --;
		}
		else{
			overflowcnt0 ++;
		}
	}
	if(htim->Instance == TIM3){
			__HAL_TIM_CLEAR_FLAG(&htim3,TIM_IT_UPDATE);
			if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3)){
				overflowcnt1 --;
			}
			else{
				overflowcnt1 ++;
			}
		}
	if(htim->Instance == TIM4){
			__HAL_TIM_CLEAR_FLAG(&htim4,TIM_IT_UPDATE);
			if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4)){
				overflowcnt2 --;
			}
			else{
				overflowcnt2 ++;
			}
		}
	if(htim->Instance == TIM2){
			__HAL_TIM_CLEAR_FLAG(&htim2,TIM_IT_UPDATE);
			if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2)){
				overflowcnt3 --;
			}
			else{
				overflowcnt3 ++;
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
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_TIM9_Init();
  MX_TIM12_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim5);
  HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim4);
  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
  //変数
  uint32_t cnt0;
  uint32_t cnt1;
  uint32_t cnt2;
  uint32_t cnt3;
  char scnt0[100];
  char scnt1[100];
  char scnt2[100];
  char scnt3[100];
  overflowcnt0 = 0;
  overflowcnt1 = 0;
  overflowcnt2 = 0;
  overflowcnt3 = 0;
  uint8_t Photo0 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0);
  uint8_t Photo1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
  uint8_t Photo2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
  uint8_t Photo3 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
  char buffer0[10];
  char buffer1[10];
  char buffer2[10];
  char buffer3[10];





  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while(1){
    	cnt0 = (long)(overflowcnt0) * 0x10000 + (long)TIM5 ->CNT;
    	cnt1 = (long)(overflowcnt1) * 0x10000 + (long)TIM3 ->CNT;
    	cnt2 = (long)(overflowcnt2) * 0x10000 + (long)TIM4 ->CNT;
    	cnt3 = (long)(overflowcnt3) * 0x10000 + (long)TIM2 ->CNT;
    	sprintf(scnt0,"ENC0:%d ",cnt0);
    	sprintf(scnt1,"ENC1:%d ",cnt1);
    	sprintf(scnt2,"ENC2:%d ",cnt2);
    	sprintf(scnt3,"ENC3:%d\r\n ",cnt3);
    	HAL_UART_Transmit(&huart4, scnt0, strlen(scnt0)+1,0xFFFF);
    	HAL_UART_Transmit(&huart4, scnt1, strlen(scnt1)+1,0xFFFF);
    	HAL_UART_Transmit(&huart4, scnt2, strlen(scnt2)+1,0xFFFF);
    	HAL_UART_Transmit(&huart4, scnt3, strlen(scnt3)+1,0xFFFF);
    	///ENC

    	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,200);
    	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,200);
    	__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,200);
    	__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,200);
    	__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,200);
    	__HAL_TIM_SET_COMPARE(&htim9,TIM_CHANNEL_2,200);
    	///MD

    	sprintf(buffer0, "Photo0:%d ", Photo0);
    	sprintf(buffer1, "Photo1:%d ", Photo1);
    	sprintf(buffer2, "Photo2:%d ", Photo2);
    	sprintf(buffer3, "Photo3:%d\r\n", Photo3);
    	HAL_UART_Transmit(&huart4, (uint8_t*)buffer0, strlen(buffer0),0xFFFF);
    	HAL_UART_Transmit(&huart4, (uint8_t*)buffer1, strlen(buffer1),0xFFFF);
    	HAL_UART_Transmit(&huart4, (uint8_t*)buffer2, strlen(buffer2),0xFFFF);
    	HAL_UART_Transmit(&huart4, (uint8_t*)buffer3, strlen(buffer3),0xFFFF);
    	///Photo
	    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_3,GPIO_PIN_SET);
	    HAL_Delay(100);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
	    HAL_Delay(100);
	    ///Cycle LED

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
  RCC_OscInitStruct.PLL.PLLN = 168;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
