/*
 * flash.c
 *
 *  Created on: Jan 1, 2025
 *      Author: Daniel
 */

#include "flash.h"
#include "main.h"

#define ADDR_FLASH_PAGE (uint32_t)0x0800FC00 /* Sector 15 */

int Flash_Write_Data(uint16_t data[], uint16_t length) {

	/* Unlock */
	HAL_FLASH_Unlock();

	/* Erase */
	FLASH_EraseInitTypeDef eraseInitStruct;
	eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	eraseInitStruct.PageAddress = ADDR_FLASH_PAGE;
	eraseInitStruct.NbPages = 1;
	uint32_t PageError = 0;
	if (HAL_FLASHEx_Erase(&eraseInitStruct, &PageError) != HAL_OK) {
		return HAL_ERROR;
	}

	/* Write data */
	uint16_t index = 0;
	for (uint16_t i = 0; i < length; i++) {
		uint32_t value = data[i];
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, ADDR_FLASH_PAGE + index, value) != HAL_OK) {
			return HAL_ERROR;
		}
		index += 2;
	}

	/* Lock */
	HAL_FLASH_Lock();

	return 0;
}

void Flash_Read_Data(uint16_t data[], uint16_t length) {
	uint32_t address = ADDR_FLASH_PAGE;
	for (uint16_t i = 0; i < length; i++) {
		data[i] = *(__IO uint16_t*) address;
		address += 2;
	}
}
