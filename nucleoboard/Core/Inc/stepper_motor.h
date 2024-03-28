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
	GPIO_TypeDef *step_port_pin ;
	uint16_t step_num_pin ;
}stepper_motor_instance;

/**
 * Init the stepper motor with the correct in pin values
 * @param stepper_motor The instance of the specific motor
 * @param dir_port_pin Pointer to the direction pin
 * @param dir_num_pin The number of the direction pin
 * @param step_port_pin Pointer to the step port pin
 * @param step_num_pin The number of the step pin
 */
void init_stepper_motor(stepper_motor_instance *stepper_motor, GPIO_TypeDef * dir_port_pin, uint16_t dir_num_pin ,GPIO_TypeDef * step_port_pin, uint16_t step_num_pin );

/**
 * Update the encoder instance with the change in between ticks
 * @param stepper_motor The instance of the specific stepper motor
 * @param step_val The number of steps the motor is to take
 */
void move_stepper_motor(stepper_motor_instance *stepper_motor, int32_t step_val);

/**
 * Reset the stepper_motor_instance to home position
 * @param stepper_motor The instance of the specific motor
 */
void reset_stepper_motor(stepper_motor_instance *stepper_motor);

#endif /* INC_STEPPER_MOTOR_H_ */
