################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/conversions/conversions.c 

OBJS += \
./Core/Src/tools/conversions/conversions.o 

C_DEPS += \
./Core/Src/tools/conversions/conversions.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/conversions/%.o Core/Src/tools/conversions/%.su Core/Src/tools/conversions/%.cyclo: ../Core/Src/tools/conversions/%.c Core/Src/tools/conversions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-conversions

clean-Core-2f-Src-2f-tools-2f-conversions:
	-$(RM) ./Core/Src/tools/conversions/conversions.cyclo ./Core/Src/tools/conversions/conversions.d ./Core/Src/tools/conversions/conversions.o ./Core/Src/tools/conversions/conversions.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-conversions

