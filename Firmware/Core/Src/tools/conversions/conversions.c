/*
 * conversions.c
 *
 *  Created on: Nov 28, 2024
 *      Author: Daniel Mårtensson
 */

#include "conversions.h"

union {
	uint32_t i;
    float f;
} data;

float uint16_to_float(const uint16_t msb, const uint16_t lsb) {
    data.i = (((uint32_t)msb) << 16) | lsb;
    return data.f;
}

void float_to_uint16(const float value, uint16_t* msb, uint16_t* lsb) {
    data.f = value;
    *msb = (data.i >> 16) & 0xFFFF;
    *lsb = data.i & 0xFFFF;
}

float calibrate_value(const uint16_t raw, const uint16_t slope_msb, const uint16_t slope_lsb, const uint16_t bias_msb, const uint16_t bias_lsb){
	  const float slope = uint16_to_float(slope_msb, slope_lsb);
	  const float bias = uint16_to_float(bias_msb, bias_lsb);
	  const float value = slope*((float)raw) + bias;
	  return value;
}
