################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.c 

OBJS += \
./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/DifferentialEquation/%.o Core/Src/tools/CControl/Sources/DifferentialEquation/%.su Core/Src/tools/CControl/Sources/DifferentialEquation/%.cyclo: ../Core/Src/tools/CControl/Sources/DifferentialEquation/%.c Core/Src/tools/CControl/Sources/DifferentialEquation/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-DifferentialEquation

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-DifferentialEquation:
	-$(RM) ./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.cyclo ./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.d ./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.o ./Core/Src/tools/CControl/Sources/DifferentialEquation/rk4args.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-DifferentialEquation

