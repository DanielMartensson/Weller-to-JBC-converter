################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/modbus/nanomodbus/nanomodbus.c 

OBJS += \
./Core/Src/tools/modbus/nanomodbus/nanomodbus.o 

C_DEPS += \
./Core/Src/tools/modbus/nanomodbus/nanomodbus.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/modbus/nanomodbus/%.o Core/Src/tools/modbus/nanomodbus/%.su Core/Src/tools/modbus/nanomodbus/%.cyclo: ../Core/Src/tools/modbus/nanomodbus/%.c Core/Src/tools/modbus/nanomodbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-modbus-2f-nanomodbus

clean-Core-2f-Src-2f-tools-2f-modbus-2f-nanomodbus:
	-$(RM) ./Core/Src/tools/modbus/nanomodbus/nanomodbus.cyclo ./Core/Src/tools/modbus/nanomodbus/nanomodbus.d ./Core/Src/tools/modbus/nanomodbus/nanomodbus.o ./Core/Src/tools/modbus/nanomodbus/nanomodbus.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-modbus-2f-nanomodbus

