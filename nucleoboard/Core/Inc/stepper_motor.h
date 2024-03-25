/*
 * stepper_motor.h
 *
 *  Created on: Mar 03, 2024
 *      Author: Ashli Forbes
 */
#pragma once

#ifndef INC_STEPPER_MOTOR_H_
#define INC_STEPPER_MOTOR_H_
#include "stdint.h"
#include "main.h"

typedef struct
{
	GPIO_TypeDef *dir_port_pin ;
	uint16_t dir_num_pin ;
	TIM_TypeDef * tim;
}stepper_motor_instance;

/**
 * Init the stepper motor with the correct in pin values
 * @param GPIO_TypeDef * pointer to the dir pin
 * @param GPIO_TypeDef * pointer to the dir pin
 * @param htim Pointer to the relevant timer
 */
void init_stepper_motor(stepper_motor_instance *stepper_motor, GPIO_TypeDef * dir_port_pin, uint16_t dir_num_pin , TIM_TypeDef * TIM);

/**
 * Update the encoder instance with the change in between ticks
 * @param pwm_value The instance of the specific encoder
 * @param htim Pointer to the relevant timer
 */
void move_stepper_motor(stepper_motor_instance *stepper_motor, int32_t pwm_val);

/**
 * Reset the stepper_motor_instance to home position
 * @param stepper_motor The instance of the specific motor
 */
void reset_stepper_motor(stepper_motor_instance *stepper_motor);

#endif /* INC_STEPPER_MOTOR_H_ */
