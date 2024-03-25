/*
 * stepper_motor.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Ashli Forbes
 */

#include "stepper_motor.h"

void init_stepper_motor(stepper_motor_instance *stepper_motor, GPIO_TypeDef * dir_port_pin, uint16_t dir_num_pin ,GPIO_TypeDef * step_port_pin, uint16_t step_num_pin ){
	   stepper_motor->dir_port_pin = dir_port_pin ;
	   stepper_motor->dir_num_pin = dir_num_pin ;
	   stepper_motor->step_port_pin = step_port_pin ;
	   stepper_motor->step_num_pin = step_num_pin ;
}

void move_stepper_motor(stepper_motor_instance *stepper_motor, int32_t step_val){
	if (step_val < 0){
		HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_SET);
	}
	for(uint8_t i = 0; i < abs(step_val); i++){
		HAL_GPIO_WritePin(stepper_motor->step_port_pin , stepper_motor->step_num_pin, GPIO_PIN_SET);
		HAL_Delay(20);
		HAL_GPIO_WritePin(stepper_motor->step_port_pin , stepper_motor->step_num_pin, GPIO_PIN_RESET);
		HAL_Delay(20);
	}
}

void reset_stepper_motor(stepper_motor_instance *stepper_motor){
	HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_SET);
}
