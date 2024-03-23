/*
 * stepper_motor.h
 *
 *  Created on: Mar 03, 2024
 *      Author: Ashli Forbes
 */
#pragma once

#include "stdint.h"
#include "main.h"

typedef struct
{
	GPIO_TypeDef * DIR_PIN ;
	GPIO_TypeDef * PWM_PIN ;
	TIM_HandleTypeDef *htim;
}stepper_motor_instance;

/**
 * Init the stepper motor with the correct in pin values
 * @param GPIO_TypeDef * pointer to the dir pin
 * @param GPIO_TypeDef * pointer to the dir pin
 * @param htim Pointer to the relevant timer
 */
stepper_motor_instance * init_stepper_motor(GPIO_TypeDef * DIR_PIN, GPIO_TypeDef * PWM_PIN ,TIM_HandleTypeDef *htim);

/**
 * Update the encoder instance with the change in between ticks
 * @param pwm_value The instance of the specific encoder
 * @param htim Pointer to the relevant timer
 */
void move_stepper_motor(stepper_motor_instance *stepper_motor, );

/**
 * Reset the stepper_motor_instance to home position
 * @param stepper_motor The instance of the specific motor
 */
void reset_stepper_motor(stepper_motor_instance *stepper_motor);

#endif /* INC_ENCODER_HANDLER_H_ */
