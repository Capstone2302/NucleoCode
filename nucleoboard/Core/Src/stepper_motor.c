/*
 * stepper_motor.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Ashli Forbes
 */

#include "stepper_motor.h"

void init_stepper_motor(stepper_motor_instance *stepper_motor, GPIO_TypeDef * dir_port_pin,uint16_t dir_num_pin , TIM_TypeDef * TIM){
	   stepper_motor->dir_port_pin = dir_port_pin ;
	   stepper_motor->dir_num_pin = dir_num_pin ;
	   stepper_motor->tim = TIM;
}

void move_stepper_motor(stepper_motor_instance *stepper_motor, int32_t pwm_val){
	stepper_motor->tim->CCR1 = abs(pwm_val);
	if (pwm_val < 0){
		HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_SET);
	}
}

void reset_stepper_motor(stepper_motor_instance *stepper_motor){
	stepper_motor->tim->CCR1 = 0;
	HAL_GPIO_WritePin(stepper_motor->dir_port_pin , stepper_motor->dir_num_pin, GPIO_PIN_SET);
}
