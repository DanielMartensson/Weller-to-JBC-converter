/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tools/tools.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum{
	PARAMETER_ESTIMATION,
	STATE_ESTIMATION,
	CONTROL_FEEDBACK,
	STATE_ESTIMATION_AND_CONTROL_FEEDBACK,
	RECOMPUTE_MODEL,
	SAVE_REGISTER_TO_MEMORY
}OPERATION;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define row_a 2
#define column_b 1
#define row_c 1
#define row_ai (row_a + column_b)
#define column_bi column_b
#define row_ci row_c
#define N 10
#define SAMPLE_TIME 0.5f
#define SETPOINT 6.0f
#define LAMBDA 0.2f
#define MAX_U 0.4f
#define INTEGRATION_CONSTANT 0.2f
#define HAS_INTEGRATION_ACTION true
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;
DMA_HandleTypeDef hdma_adc;

COMP_HandleTypeDef hcomp2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
volatile uint32_t ADC_DATA[3];
const uint8_t ADC_DATA_SIZE =  sizeof(ADC_DATA) / sizeof(ADC_DATA[0]);
float what[3] = { 0, 0, 0 }; 		/* Estimated parameter vector */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC_Init(void);
static void MX_COMP2_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

int32_t UART_read(const char port[], uint8_t* buf, uint16_t count, int32_t byte_timeout_ms) {
	const bool read = HAL_UART_Receive(&huart1, buf, count, byte_timeout_ms) == HAL_OK;
	if(read){
		return count; /* Assuming that we wrote count bytes */
	}else{
		return 0;
	}
}

int32_t UART_write(const char port[], const uint8_t* buf, uint16_t count, int32_t byte_timeout_ms) {
	const bool wrote = HAL_UART_Transmit(&huart1, buf, count, byte_timeout_ms) == HAL_OK;
    if(wrote){
    	return count; /* Assuming that we wrote count bytes */
    }else{
    	return 0;
    }
}

const char* UART_port(){
	return "PORT";
}

void parameter_estimation_transition_function(float dw[], const float x[], const float w[]) {
	dw[0] = 1.0f * x[1];
	dw[1] = -w[0]*x[0] - w[1]*x[1] + w[2]*x[2];
}

void state_estimation_transition_function(float dx[], const float x[], const float u[]) {
	dx[0] = 1.0f * x[1];
	dx[1] = -what[0]*x[0] - what[1]*x[1] + what[2]*u[0];
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
  MX_DMA_Init();
  MX_ADC_Init();
  MX_COMP2_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  /* Start nanoMODBUS with address 1 */
  modbus_set_serial_read(UART_read);
  modbus_set_serial_write(UART_write);
  modbus_set_serial_port(UART_port);
  modbus_server_create_RTU(1);

  /* Start PWM */
  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);

  /* Start timer */
  HAL_TIM_Base_Start(&htim1);

  /* Start ADC */
  HAL_ADC_Start_DMA(&hadc, (uint32_t*)ADC_DATA, ADC_DATA_SIZE);

  /* Square Root Parameter Estimation */
  const float alpha = 0.1f; 												/* Alpha value - A small number like 0.01 -> 1.0 */
  const float beta = 2.0f; 													/* Beta value - Normally 2 for gaussian noise */
  const uint8_t L_parameter_estimation = 3; 								/* How many parameters we have */
  const float e = 0.1f;														/* Tuning factor for noise */
  const float Re[3 * 3] = { e, 0, 0, 0, e, 0, 0, 0, e }; 					/* Initial noise covariance matrix - Recommended to use identity matrix */
  float Sw[3 * 3] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 }; 							/* Initial covariance matrix - Recommended to use identity matrix */
  float d_parameter_estimation[3] = { 0, 0, 0 };							/* This is our measurement */
  float x_parameter_estimation[3] = { 4.4f, 6.2f, 1.0f }; 					/* State vector */
  const float lambda_rls = 0.99f;											/* RLS forgetting parameter between 0.0 and 1.0, but very close to 1.0 */

  const uint8_t L_state_estimation = 2; 									/* How many states we have */
  const float r = 1.5f;														/* Tuning factor for noise */
  const float q = 0.2f;														/* Tuning factor for disturbance */
  const float Rv[2 * 2] = {q, 0, 0, q }; 									/* Initial disturbance covariance matrix - Recommended to use identity matrix */
  const float Rn[2 * 2] = { r, 0, 0, r }; 									/* Initial noise covariance matrix - Recommended to use identity matrix */
  float S[2 * 2] = {1, 0, 0, 1 }; 											/* Initial covariance matrix - Recommended to use identity matrix */
  float xhat[2] = { 0, 0 }; 												/* Estimated state vector */
  float y_state_estimation[2] = { 0, 0 };									/* This is our measurement */
  float u_state_estimation[2] = { 0, 0 }; 													/* u is not used in this example due to the transition function not using an input signal */

  /* Create A matrix */
  float A[row_a * row_a] = { 0, 1, -what[0], -what[1] };

  /* Create B matrix */
  float B[row_a * column_b] = { 0, what[2] };

  /* Create C matrix */
  float C[row_c * row_a] = { 1, 0 };

  /* Turn the SS model into a discrete SS model */
  c2d(A, B, row_a, column_b, SAMPLE_TIME);

  /* Create Ai matrix */
  float Ai[row_ai * row_ai];

  /* Create Bi matrix */
  float Bi[row_ai * column_bi];

  /* Create Ci matrix */
  float Ci[row_ci * row_ai];

  /* Add integral action */
  ssint(A, B, C, Ai, Bi, Ci, row_a, column_b, row_c);

  /* Create PHI matrix */
  float PHI[(N * row_ci) * row_ai];
  obsv(PHI, Ai, Ci, row_ai, row_ci, N);

  /* Create GAMMA matrix */
  float GAMMA[(N * row_ci) * (N * column_bi)];
  cab(GAMMA, PHI, Bi, Ci, row_ai, row_ci, column_bi, N);

  /* Create vectors: state vector x, input signal u, reference vector r, maximum output signal Umax, slack variable values S */
  float x_qmpc[row_ai], u_qmpc[column_bi], r_qmpc[row_ci], Umax[column_bi], S_qmpc[row_ci];

  /* Set constraints */
  Umax[0] = 65535.0f;

  /* Integral constant */
  const float I_qmpc = 0.2f;
  float past_u_qmpc = 0.0f;

  /* Slack variable */
  S_qmpc[0] = 2.0f;

  /* Remember the last operation */
  uint16_t last_operation = STATE_ESTIMATION;

  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  /* Polling */
	  modbus_server_polling();

	  /* Read digital outputs */
	  const bool led_green = HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	  const bool leakage_active = HAL_GPIO_ReadPin(LEAKAGE_ACTIVE_GPIO_Port, LEAKAGE_ACTIVE_Pin);

	  /* Set digital outputs */
	  const uint8_t digital_outputs = (led_green << 1) | leakage_active;
	  modbus_server_set_digital_outputs(&digital_outputs, 0, 2);

	  /* Read digital inputs */
	  const bool n_sleep = HAL_GPIO_ReadPin(N_SLEEP_GPIO_Port, N_SLEEP_Pin);

	  /* Set digital inputs */
	  const uint8_t digital_inputs = n_sleep;
	  modbus_server_set_digital_inputs(&digital_inputs, 0, 1);

	  /* Read registers */
	  uint16_t parameters[31];
	  modbus_server_get_parameters(parameters, 0, 25);
	  const uint16_t minSetpointRaw_LSB = parameters[0];
	  const uint16_t minSetpointRaw_MSB = parameters[1];
	  const uint16_t maxSetpointRaw_LSB = parameters[2];
	  const uint16_t maxSetpointRaw_MSB = parameters[3];
	  const uint16_t minSetpointReal_LSB = parameters[4];
	  const uint16_t minSetpointReal_MSB = parameters[5];
	  const uint16_t maxSetpointReal_LSB = parameters[6];
	  const uint16_t maxSetpointReal_MSB = parameters[7];
	  const uint16_t minTemperatureRaw_LSB = parameters[8];
	  const uint16_t minTemperatureRaw_MSB = parameters[9];
	  const uint16_t maxTemperatureRaw_LSB = parameters[10];
	  const uint16_t maxTemperatureRaw_MSB = parameters[11];
	  const uint16_t minTemperatureReal_LSB = parameters[12];
	  const uint16_t minTemperatureReal_MSB = parameters[13];
	  const uint16_t maxTemperatureReal_LSB = parameters[14];
	  const uint16_t maxTemperatureReal_MSB = parameters[15];
	  const uint16_t minCurrentRaw_LSB = parameters[16];
	  const uint16_t minCurrentRaw_MSB = parameters[17];
	  const uint16_t maxCurrentRaw_LSB = parameters[18];
	  const uint16_t maxCurrentRaw_MSB = parameters[19];
	  const uint16_t minCurrentReal_LSB = parameters[20];
	  const uint16_t minCurrentReal_MSB = parameters[21];
	  const uint16_t maxCurrentReal_LSB = parameters[22];
	  const uint16_t maxCurrentReal_MSB = parameters[23];
	  const uint16_t operation = parameters[24];

	  /* Read ADC inputs */
	  const uint16_t temperature_raw = ADC_DATA[0];
	  const uint16_t setpoint_raw = ADC_DATA[1];
	  const uint16_t current_raw = ADC_DATA[2];

	  /* Convert to real value */
	  const float temperature = calibrate_value(temperature_raw, minTemperatureRaw_LSB, minTemperatureRaw_MSB, maxTemperatureRaw_LSB, maxTemperatureRaw_MSB,
			  minTemperatureReal_LSB, minTemperatureReal_MSB, maxTemperatureReal_LSB, maxTemperatureReal_MSB);
	  const float current = calibrate_value(current_raw, minCurrentRaw_LSB, minCurrentRaw_MSB, maxCurrentRaw_LSB, maxCurrentRaw_MSB,
			  minCurrentReal_LSB, minCurrentReal_MSB, maxCurrentReal_LSB, maxCurrentReal_MSB);
	  const float setpoint = calibrate_value(setpoint_raw, minSetpointRaw_LSB, minSetpointRaw_MSB, maxSetpointRaw_LSB, maxSetpointRaw_MSB,
			  minSetpointReal_LSB, minSetpointReal_MSB, maxSetpointReal_LSB, maxSetpointReal_MSB);

	  /* Do operation */
	  switch(operation){
	  case PARAMETER_ESTIMATION:
		  last_operation = PARAMETER_ESTIMATION;
		  /* Parameter estimation - SISO model with state dimension 3 */
		  x_parameter_estimation[0] = 1.0f;                /* This is the A[1,0] value */
		  x_parameter_estimation[1] = 1.0f;                /* This is the A[1,1] value */
		  x_parameter_estimation[2] = (float)setpoint_raw; /* This is the u[0] */
		  d_parameter_estimation[0] = temperature;
		  d_parameter_estimation[1] = temperature;
		  d_parameter_estimation[2] = temperature;
		  sr_ukf_parameter_estimation(d_parameter_estimation, what, Re, x_parameter_estimation, parameter_estimation_transition_function, lambda_rls, Sw, alpha, beta, L_parameter_estimation);
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, setpoint_raw);

		  break;
	  case STATE_ESTIMATION:
		  last_operation = STATE_ESTIMATION;
		  /* State estimation - SISO model with state dimension 2 */
		  u_state_estimation[0] = (float)setpoint_raw;     /* This is the u[0] */
		  u_state_estimation[1] = 0;                       /* Not used */
		  y_state_estimation[0] = temperature;
		  y_state_estimation[1] = temperature;
		  sr_ukf_state_estimation(y_state_estimation, xhat, Rn, Rv, u_state_estimation, state_estimation_transition_function, S, alpha, beta, L_state_estimation);
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, setpoint_raw);

		  break;
	  case CONTROL_FEEDBACK:
		  last_operation = CONTROL_FEEDBACK;
		  u_state_estimation[0] = (float)setpoint_raw;     /* This is the u[0] */
		  u_state_estimation[1] = 0;                       /* Not used */
		  state_estimation_transition_function(y_state_estimation, x_qmpc, u_state_estimation);
		  x_qmpc[0] = y_state_estimation[0];
		  x_qmpc[1] = y_state_estimation[1];

		  /* Quadratic Model Predictive Control - SISO model with state dimension 2 */
		  r_qmpc[0] = (float)setpoint_raw;
		  qmpc(GAMMA, PHI, x_qmpc, u_qmpc, Umax, S_qmpc, r_qmpc, row_ai, row_ci, column_bi, N, LAMBDA, HAS_INTEGRATION_ACTION, INTEGRATION_CONSTANT);

		  /* Compute delta for integral action */
		  delta = u_qmpc[0] - I_qmpc*past_u_qmpc;
		  past_u_qmpc = u_qmpc[0];
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, (uint16_t)delta);

		  break;
	  case STATE_ESTIMATION_AND_CONTROL_FEEDBACK:
		  last_operation = STATE_ESTIMATION_AND_CONTROL_FEEDBACK;
		  /* State estimation - SISO model with state dimension 2 */
		  u_state_estimation[0] = (float)setpoint_raw;     /* This is the u[0] */
		  u_state_estimation[1] = 0;                       /* Not used */
		  y_state_estimation[0] = temperature;
		  y_state_estimation[1] = temperature;
		  sr_ukf_state_estimation(y_state_estimation, xhat, Rn, Rv, u_state_estimation, state_estimation_transition_function, S, alpha, beta, L_state_estimation);

		  /* Quadratic Model Predictive Control - SISO model with state dimension 2 */
		  x_qmpc[0] = xhat[0];
		  x_qmpc[1] = xhat[1];
		  /* x_qmpc[2];  Let this tune in itself */
		  r_qmpc[0] = (float)setpoint_raw;
		  qmpc(GAMMA, PHI, x_qmpc, u_qmpc, Umax, S_qmpc, r_qmpc, row_ai, row_ci, column_bi, N, LAMBDA, HAS_INTEGRATION_ACTION, INTEGRATION_CONSTANT);

		  /* Compute delta for integral action */
		  delta = u_qmpc[0] - I_qmpc*past_u_qmpc;
		  past_u_qmpc = u_qmpc[0];
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, (uint16_t)delta);
		  break;
	  case RECOMPUTE_MODEL:
		  last_operation = RECOMPUTE_MODEL;
		  A[2] = -what[0];
		  A[3] = -what[1];
		  B[1] = what[2];
		  c2d(A, B, row_a, column_b, SAMPLE_TIME);
		  ssint(A, B, C, Ai, Bi, Ci, row_a, column_b, row_c);
		  obsv(PHI, Ai, Ci, row_ai, row_ci, N);
		  cab(GAMMA, PHI, Bi, Ci, row_ai, row_ci, column_bi, N);
		  break;
	  case SAVE_REGISTER_TO_MEMORY:

		  break;
	  default:
		  break;
	  }

	  /* Set analog inputs */
	  uint16_t analog_inputs[13];
	  analog_inputs[0] = temperature_raw;
	  analog_inputs[1] = setpoint_raw;
	  analog_inputs[2] = current_raw;
	  float_to_uint16(temperature, &analog_inputs[4], &analog_inputs[3]);
	  float_to_uint16(setpoint, &analog_inputs[6], &analog_inputs[5]);
	  float_to_uint16(current, &analog_inputs[8], &analog_inputs[7]);
	  float_to_uint16(xhat[0], &analog_inputs[10], &analog_inputs[9]);
	  float_to_uint16(xhat[1], &analog_inputs[12], &analog_inputs[11]);
	  modbus_server_set_analog_inputs(analog_inputs, 0, 13);

	  /* Set parameters */
	  float_to_uint16(what[0], &parameters[26], &parameters[25]);
	  float_to_uint16(what[1], &parameters[28], &parameters[27]);
	  float_to_uint16(what[2], &parameters[30], &parameters[29]);
	  modbus_server_set_parameters(parameters, 25, 31);


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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_TRGO;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc.Init.DMAContinuousRequests = ENABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief COMP2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_COMP2_Init(void)
{

  /* USER CODE BEGIN COMP2_Init 0 */

  /* USER CODE END COMP2_Init 0 */

  /* USER CODE BEGIN COMP2_Init 1 */

  /* USER CODE END COMP2_Init 1 */
  hcomp2.Instance = COMP2;
  hcomp2.Init.InvertingInput = COMP_INVERTINGINPUT_DAC1;
  hcomp2.Init.NonInvertingInput = COMP_NONINVERTINGINPUT_IO1;
  hcomp2.Init.Output = COMP_OUTPUT_NONE;
  hcomp2.Init.OutputPol = COMP_OUTPUTPOL_NONINVERTED;
  hcomp2.Init.Hysteresis = COMP_HYSTERESIS_NONE;
  hcomp2.Init.Mode = COMP_MODE_HIGHSPEED;
  hcomp2.Init.WindowMode = COMP_WINDOWMODE_DISABLE;
  hcomp2.Init.TriggerMode = COMP_TRIGGERMODE_NONE;
  if (HAL_COMP_Init(&hcomp2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN COMP2_Init 2 */

  /* USER CODE END COMP2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 15;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 49999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_ENABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 120;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4095;
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
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_ENABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_GREEN_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GREEN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : N_SLEEP_Pin */
  GPIO_InitStruct.Pin = N_SLEEP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(N_SLEEP_GPIO_Port, &GPIO_InitStruct);

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
