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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */
uint8_t rxData[2];
uint8_t rxData2[2];
uint8_t rxData3[2];
uint8_t rxData4[2];
uint8_t rxData5[2];

uint8_t ID = 0x87; // register addr
uint8_t ID1 = 0xFF; // register addr
uint8_t ID2 = 0xFE; // register addr
uint8_t ID3 = 0x00; // register addr
uint8_t ID4 = 0x85; // register addr
uint16_t rawValue;

#define U4_ADDRESS 0x41 // INA3221
#define U2_ADDRESS 0x44 // INA219BID
#define U1_ADDRESS 0x40 // INA3221
#define U3_ADDRESS 0x45 // ISL28022
#define ADDRESS 0x29 // LTR

uint8_t ina_u4_config[3];
uint8_t ina_u4_shunt_reg = 0x01;
uint8_t ina_u4_bus_reg = 0x02;
uint8_t ina_u1_config[3];
uint8_t ina219_config[3];
uint8_t ina_u1_shunt_reg = 0x01;
uint8_t ina_u1_bus_reg = 0x02;
uint8_t isl_config[3];
uint8_t isl_shunt_reg = 0x01;
uint8_t isl_bus_reg = 0x02;
uint8_t config = 0x00; // register addr
uint8_t shunt = 0x06; // register addr
uint8_t shunt_ina219 = 0x01;
uint8_t bus_ina219 = 0x02;
uint8_t power_ina219 = 0x03;
uint8_t current_ina219 = 0x04;
uint8_t current_fs;
uint8_t current_lsb;
uint8_t power_lsb;
uint8_t r_shunt = 0.1;
int cal;

uint16_t raw_shunt_Value;
uint16_t raw_bus_Value;
uint16_t ina_u4_raw_shunt_Value;
uint16_t ina_u4_raw_bus_Value;
uint16_t ina_u1_raw_shunt_Value;
uint16_t ina_u1_raw_bus_Value;
uint16_t ina219_raw_shunt;
uint16_t ina219_shunt_value;
uint16_t ina219_raw_bus;
uint16_t ina219_bus_value;
uint16_t ina219_raw_power;
uint16_t ina219_power_value;
uint16_t ina219_raw_current;
uint16_t ina219_current_value;
uint16_t ina219_currentDivider_mA = 33;    // Current LSB = 30uA per bit
uint16_t ina219_powerMultiplier_mW = 0.66f; // Power LSB = 666uW per bit
int max_expected_current = 1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void ina219_calibration()
{
	// adjusting configuration pin
	ina219_config[0] = 0x00;
	ina219_config[1] = 0x39;
	ina219_config[2] = 0x9F;
	HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, ina219_config, 3, HAL_MAX_DELAY);
	current_lsb = max_expected_current / 32767; // max_expected / 2^15.
	power_lsb = current_lsb * 20;
	cal = 0.04096 / (current_lsb * r_shunt); // 13430
	HAL_I2C_Mem_Write(&hi2c2, U1_ADDRESS, 0x05, 2, cal, 2, HAL_MAX_DELAY); // write to calibration register to operate current and power registers.
}

void ina219_reading()
{
	//reading shunt voltage
	HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, &shunt_ina219, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(&hi2c2, U1_ADDRESS << 1, &ina219_raw_shunt, 2, HAL_MAX_DELAY);
	ina219_shunt_value = 0.01 * ina219_raw_shunt; // mV.

	// reading bus voltage
	HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, &bus_ina219, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(&hi2c2, U1_ADDRESS << 1, &ina219_raw_bus, 2, HAL_MAX_DELAY);
	ina219_bus_value = (ina219_raw_bus >> 3) * 4;
	ina219_bus_value = ina219_bus_value * 0.001; // V.

	// reading power
	HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, &power_ina219, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(&hi2c2, U1_ADDRESS << 1, &ina219_raw_power, 2, HAL_MAX_DELAY);
	ina219_power_value = ina219_powerMultiplier_mW * ina219_raw_power; //mW.

	// reading current
	HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, &current_ina219, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(&hi2c2, U1_ADDRESS << 1, &ina219_raw_current, 2, HAL_MAX_DELAY);
	ina219_current_value =  ina219_raw_power / ina219_currentDivider_mA; // mA.
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
  MX_I2C2_Init();
  ina219_calibration();
  ina219_reading();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  	  ina219_calibration();
	  	  ina219_reading();
	  	  // LTR
		  HAL_I2C_Master_Transmit(&hi2c2, ADDRESS << 1, &ID4, 1, HAL_MAX_DELAY);
		  HAL_I2C_Master_Receive(&hi2c2, ADDRESS << 1, rxData, 2, HAL_MAX_DELAY);
		  // U4
		  HAL_I2C_Master_Transmit(&hi2c2, U4_ADDRESS << 1, &ID1, 1, HAL_MAX_DELAY);
		  HAL_I2C_Master_Receive(&hi2c2, U4_ADDRESS << 1, rxData2, 2, HAL_MAX_DELAY);

		  // U1
		  HAL_I2C_Master_Transmit(&hi2c2, U1_ADDRESS << 1, &ID2, 1, HAL_MAX_DELAY);
		  HAL_I2C_Master_Receive(&hi2c2, U1_ADDRESS << 1, rxData3, 2, HAL_MAX_DELAY);

		  // U2
		  HAL_I2C_Master_Transmit(&hi2c2, U2_ADDRESS << 1, &ID3, 1, HAL_MAX_DELAY);
		  HAL_I2C_Master_Receive(&hi2c2, U2_ADDRESS << 1, rxData4, 2, HAL_MAX_DELAY);

		  // U3
		  HAL_I2C_Master_Transmit(&hi2c2, U3_ADDRESS << 1, &ID3, 1, HAL_MAX_DELAY);
		  HAL_I2C_Master_Receive(&hi2c2, U3_ADDRESS << 1, rxData5, 2, HAL_MAX_DELAY);


	//	  rawValue = (rxData[0] << 8) | rxData[1];
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00303D5B;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
