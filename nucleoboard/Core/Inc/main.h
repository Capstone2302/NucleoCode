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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "encoder_handler.h"
#include "stepper_motor.h"
#include <stdio.h>
#include <stdlib.h>
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EncoderIn_Pin GPIO_PIN_0
#define EncoderIn_GPIO_Port GPIOA
#define EncoderInB_Pin GPIO_PIN_1
#define EncoderInB_GPIO_Port GPIOA
#define Stepper2Step_Pin GPIO_PIN_4
#define Stepper2Step_GPIO_Port GPIOA
#define MotoDir_Pin GPIO_PIN_5
#define MotoDir_GPIO_Port GPIOA
#define PWMOut_Pin GPIO_PIN_6
#define PWMOut_GPIO_Port GPIOA
#define Stepper1Step_Pin GPIO_PIN_6
#define Stepper1Step_GPIO_Port GPIOC
#define Stepper2Dir_Pin GPIO_PIN_8
#define Stepper2Dir_GPIO_Port GPIOC
#define Stepper1Dir_Pin GPIO_PIN_9
#define Stepper1Dir_GPIO_Port GPIOC
#define ServoPWM_Pin GPIO_PIN_8
#define ServoPWM_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define DATA_LENGTH 7
#define UART_TIMEOUT 100
#define DUTYCYCLE_MAX 1000
#define DUTYCYCLE_SCALER UINT16_MAX/1000
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
