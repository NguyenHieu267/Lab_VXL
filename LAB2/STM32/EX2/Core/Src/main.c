/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "timer.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/// BEGIN EX9
const int MAX_LED_MATRIX = 8;
 int index_led_matrix = 0;
 uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};

 uint8_t letterA[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};

 GPIO_TypeDef* ROW_GPIO[8] = {ROW0_GPIO_Port,ROW1_GPIO_Port,
 		  ROW2_GPIO_Port,ROW3_GPIO_Port,ROW4_GPIO_Port,
 		  ROW5_GPIO_Port,ROW6_GPIO_Port,ROW7_GPIO_Port};

  int ROW_pin[8] = {ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin,
 		  ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};

  GPIO_TypeDef* COL_GPIO[8] = {ENM0_GPIO_Port,ENM1_GPIO_Port,
  		  ENM2_GPIO_Port,ENM3_GPIO_Port,ENM4_GPIO_Port,
  		  ENM5_GPIO_Port,ENM6_GPIO_Port,ENM7_GPIO_Port};

   int COL_pin[8] = {ENM0_Pin,ENM1_Pin,ENM2_Pin,ENM3_Pin,
  		  ENM4_Pin,ENM5_Pin,ENM6_Pin,ENM7_Pin};
void turnoffall()
{
	for(int i=0;i<8;i++)
	{
		HAL_GPIO_WritePin(ROW_GPIO[i], ROW_pin[i], SET);
		HAL_GPIO_WritePin(COL_GPIO[i], COL_pin[i], SET);
	}
}
void turnon(uint8_t num, int row)
{
	if(row!=0)
	{
		HAL_GPIO_WritePin(ROW_GPIO[row-1], ROW_pin[row-1], SET);
	}
	else
	{
		HAL_GPIO_WritePin(ROW_GPIO[7], ROW_pin[7], SET);
	}
	for(int i=0;i<8;i++)
	{
		int bit_value = (num>>i) & 1;
		if(bit_value==1)
		{
			HAL_GPIO_WritePin(COL_GPIO[i], COL_pin[i], RESET);
		}
		else
		{
			HAL_GPIO_WritePin(COL_GPIO[i], COL_pin[i], SET);
		}
	}
	HAL_GPIO_WritePin(ROW_GPIO[row], ROW_pin[row], RESET);
}

				void turnleft(int stage,int shift)
				{
					if(stage == 0)
					{
						for(int i=0;i<8;i++)
						{
							matrix_buffer[i] = matrix_buffer[i]>>1;
						}
					}
					else if(stage == 1)
					{
						for(int i=0;i<8;i++)
						{
							matrix_buffer[i] = letterA[i] << shift;
						}
					}
				}

 void updateLEDMatrix(int index){
	 switch (index){
	 case 0:
		 turnon(matrix_buffer[0], 0);
	 break;
	 case 1:
		 turnon(matrix_buffer[1], 1);
	 break;
	 case 2:
		 turnon(matrix_buffer[2], 2);
	 break;
	 case 3:
		 turnon(matrix_buffer[3], 3);
	 break;
	 case 4:
		 turnon(matrix_buffer[4], 4);
	 break;
	 case 5:
		 turnon(matrix_buffer[5], 5);
	 break;
	 case 6:
		 turnon(matrix_buffer[6], 6);
	 break;
	 case 7:
		 turnon(matrix_buffer[7], 7);
	 break;
	 default:
		 turnoffall();
	 break;
	 }
 }

/// END EX9
GPIO_TypeDef* SEG_GPIO[7] = {pin_a_GPIO_Port,pin_b_GPIO_Port,
		  pin_c_GPIO_Port,pin_d_GPIO_Port,pin_e_GPIO_Port,
		  pin_f_GPIO_Port,pin_g_GPIO_Port};

 int SEG_pin[7] = {pin_a_Pin,pin_b_Pin,pin_c_Pin,
		  pin_d_Pin,pin_e_Pin,pin_f_Pin,pin_g_Pin};
 int stage=0; // EX 4
 //int cycle = 100; // EX2 & 3
//int cycle = 50; // EX4
int cycle = 5; //EX5  (for fast, 1 second = 500ms -> cycle = 25 (5*25 = 125 (=1/4 seond) ) )

 void display7SEG(int counter, GPIO_TypeDef* pin[7], int p[7])
 {
 	  switch (counter){
 	  case 0:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 1:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 2:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], SET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 3:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 4:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 5:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 6:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 7:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 8:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 9:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  default:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], SET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  }
 }

 int led_buffer[4] = {1,2,3,0};

 void update7SEG(int index)
 {
	 display7SEG(10, SEG_GPIO, SEG_pin);
	  switch(index) {
	  		  case 0:
	  			  HAL_GPIO_WritePin(Active_seg_1_GPIO_Port, Active_seg_1_Pin, RESET);
	  			  HAL_GPIO_WritePin(Active_seg_2_GPIO_Port, Active_seg_2_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_3_GPIO_Port, Active_seg_3_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_4_GPIO_Port, Active_seg_4_Pin, SET);
	  			  break;
	  		  case 1:
	  			  HAL_GPIO_WritePin(Active_seg_1_GPIO_Port, Active_seg_1_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_2_GPIO_Port, Active_seg_2_Pin, RESET);
	  			  HAL_GPIO_WritePin(Active_seg_3_GPIO_Port, Active_seg_3_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_4_GPIO_Port, Active_seg_4_Pin, SET);
	  			  break;
	  		  case 2:
	  			  HAL_GPIO_WritePin(Active_seg_1_GPIO_Port, Active_seg_1_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_2_GPIO_Port, Active_seg_2_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_3_GPIO_Port, Active_seg_3_Pin, RESET);
	  			  HAL_GPIO_WritePin(Active_seg_4_GPIO_Port, Active_seg_4_Pin, SET);
	  			  break;
	  		  case 3:
	  			  HAL_GPIO_WritePin(Active_seg_1_GPIO_Port, Active_seg_1_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_2_GPIO_Port, Active_seg_2_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_3_GPIO_Port, Active_seg_3_Pin, SET);
	  			  HAL_GPIO_WritePin(Active_seg_4_GPIO_Port, Active_seg_4_Pin, RESET);
	  			  break;
	  		  default:
	  			  break;
	  		  }
	  display7SEG(led_buffer[index], SEG_GPIO, SEG_pin);
 }


 // BEGIN EX6 ----------
  int timer0_counter = 0;
  int timer0_flag = 0;
  int TIMER_CYCLE = 10;
  void setTimer0(int duration){
  timer0_counter = duration /TIMER_CYCLE;
  timer0_flag = 0;
  }
  void timer_run(){
  if(timer0_counter > 0){
  timer0_counter--;
  if(timer0_counter <= 0) timer0_flag = 1;
  }
  }
 // END EX6 ------------
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int hour = 15 , minute = 8 , second = 55;

  //begin setup EX9
  int count=0;
  turnoffall();
  int counttime = 16;
  int s=0;
  //end setup EX9

  void updateClockBuffer()
  {
	  led_buffer[0] = hour/10;
	  led_buffer[1] = hour%10;
	  led_buffer[2] = minute/10;
	  led_buffer[3] = minute%10;
  }
  //settimer(cycle);
  //setTimer0(cycle*10); //EX6
  setTimer0(cycle*10);
  int counterflag = 0;
  updateClockBuffer();
  while (1)
  {
	  if(timer0_flag == 1)
	  {
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  counterflag++;
		  setTimer0(cycle*10);
		  //setTimer0(cycle);
		update7SEG(stage);
		stage+=1;
		if(stage > 3) stage = 0;
		//begin ex9
		  //setTimer0(cycle);
		  updateLEDMatrix(count);
		  count++;
		  if(count>=8) count=0;
		  counttime--;
		//end ex9
	  }
	  if(counterflag == 1000/(10*cycle))
	  {
		  counterflag = 0;
		  second++;
		  if(second>=60)
		  {
			  second=0;
			  minute++;
		  }
		  if(minute>=60)
		  {
			  minute=0;
			  hour++;
		  }
		  if(hour>=24)
		  {
			  hour=0;
		  }
		  updateClockBuffer();
	  }

	  //begin EX10
	  if(counttime<=0)
	  	  {
	  		  counttime = 16;
	  		  if(s<=7) {turnleft(0,0);s++;}
	  		  else
	  		  {
	  			  turnleft(1,15-s);
	  			  s++;
	  			  if(s==16) s = 0;
	  		  }
	  	  }
	  //end EX10
	  // BEGIN EX5-----

//	  second++;
//	  if(second>=60)
//	  {
//		  second=0;
//		  minute++;
//	  }
//	  if(minute>=60)
//	  {
//		  minute=0;
//		  hour++;
//	  }
//	  if(hour>=24)
//	  {
//		  hour=0;
//	  }
//
//	  updateClockBuffer();
	  //HAL_Delay(1000);//EX5

	  // END EX5--------


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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin
                          |ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|Active_seg_1_Pin|Active_seg_2_Pin|Active_seg_3_Pin
                          |Active_seg_4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, pin_a_Pin|pin_b_Pin|pin_c_Pin|pin_d_Pin
                          |pin_e_Pin|pin_f_Pin|pin_g_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin
                          |ROW6_Pin|ROW7_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin Active_seg_1_Pin
                           Active_seg_2_Pin Active_seg_3_Pin Active_seg_4_Pin ENM2_Pin
                           ENM3_Pin ENM4_Pin ENM5_Pin ENM6_Pin
                           ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|Active_seg_1_Pin
                          |Active_seg_2_Pin|Active_seg_3_Pin|Active_seg_4_Pin|ENM2_Pin
                          |ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin
                          |ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : pin_a_Pin pin_b_Pin pin_c_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin pin_d_Pin pin_e_Pin pin_f_Pin
                           pin_g_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = pin_a_Pin|pin_b_Pin|pin_c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|pin_d_Pin|pin_e_Pin|pin_f_Pin
                          |pin_g_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
// int counter = 50;  //EX2
// int index = 0; //EX2
int counterdot = 25;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	// BEGIN EX7---------
	timer_run();
	// END EX7-----------



	/*// BEGIN EX5
	runtime();
	counterdot--;
	if(counterdot<=0)
	{
		counterdot = cycle*4;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}

	  //-----BEGIN EX2,3,4-------

	  if(time_flag == 1)
	  {
		  settimer(cycle);
		  update7SEG(stage);
		  stage+=1;
		  if(stage>3) stage = 0;
	  }

	  //-----END EX2,3,4----
	  // END EX5
	  */
	// BEGIN EX6---------
	// EX6 use the function affect similarly to EX5
//	timer_run();
//	counterdot--;
//	if(counterdot<=0)
//	{
//		counterdot = cycle*4;
//		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
//	}
//
//	if(timer0_flag == 1)
//	{
//		setTimer0(250);
//		update7SEG(stage);
//		stage+=1;
//		if(stage > 3) stage = 0;
//	}
	// END EX6----------
	/*
	 counter--;
	 if(counter<=0)
	 {
	 	 counter = 50;
	 	 update7SEG(index);
	 	 index+=1;
	 	 if(index>3) index=0;
	 }
	 */
}
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
