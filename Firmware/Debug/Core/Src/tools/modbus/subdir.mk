################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/modbus/modbus.c \
../Core/Src/tools/modbus/modbusclient.c \
../Core/Src/tools/modbus/modbusserver.c 

OBJS += \
./Core/Src/tools/modbus/modbus.o \
./Core/Src/tools/modbus/modbusclient.o \
./Core/Src/tools/modbus/modbusserver.o 

C_DEPS += \
./Core/Src/tools/modbus/modbus.d \
./Core/Src/tools/modbus/modbusclient.d \
./Core/Src/tools/modbus/modbusserver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/modbus/%.o Core/Src/tools/modbus/%.su Core/Src/tools/modbus/%.cyclo: ../Core/Src/tools/modbus/%.c Core/Src/tools/modbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-modbus

clean-Core-2f-Src-2f-tools-2f-modbus:
	-$(RM) ./Core/Src/tools/modbus/modbus.cyclo ./Core/Src/tools/modbus/modbus.d ./Core/Src/tools/modbus/modbus.o ./Core/Src/tools/modbus/modbus.su ./Core/Src/tools/modbus/modbusclient.cyclo ./Core/Src/tools/modbus/modbusclient.d ./Core/Src/tools/modbus/modbusclient.o ./Core/Src/tools/modbus/modbusclient.su ./Core/Src/tools/modbus/modbusserver.cyclo ./Core/Src/tools/modbus/modbusserver.d ./Core/Src/tools/modbus/modbusserver.o ./Core/Src/tools/modbus/modbusserver.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-modbus

