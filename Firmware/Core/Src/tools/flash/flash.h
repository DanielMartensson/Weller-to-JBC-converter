/*
 * flash.h
 *
 *  Created on: Jan 1, 2025
 *      Author: Daniel
 */

#ifndef SRC_TOOLS_FLASH_FLASH_H_
#define SRC_TOOLS_FLASH_FLASH_H_

#include <stdint.h>

int Flash_Write_Data(uint16_t data[], uint16_t length);
void Flash_Read_Data(uint16_t data[], uint16_t length);

#endif /* SRC_TOOLS_FLASH_FLASH_H_ */
