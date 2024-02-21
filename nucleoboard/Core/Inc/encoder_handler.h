/*
 * encoder_handler.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Ashli Forbes
 */
#pragma once

#ifndef INC_ENCODER_HANDLER_H_
#define INC_ENCODER_HANDLER_H_
#include "stdint.h"
#include "main.h"

typedef struct
{
	int8_t first_time;
	int16_t delta_position;
	int64_t position;
	uint32_t last_counter_value;
}encoder_instance;

/**
 * Update the encoder instance with the change in between ticks
 * @param encoder_value The instance of the specific encoder
 * @param htim Pointer to the relevant timer
 */
void update_encoder(encoder_instance *encoder_value, TIM_HandleTypeDef *htim);

/**
 * Reset the encoder instance to default values
 * @param encoder_value The instance of the specific encoder
 */
void reset_encoder(encoder_instance *encoder_value);

#endif /* INC_ENCODER_HANDLER_H_ */
