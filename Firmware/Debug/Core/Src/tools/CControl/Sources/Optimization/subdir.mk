################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/Optimization/linprog.c \
../Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.c \
../Core/Src/tools/CControl/Sources/Optimization/quadprog.c 

OBJS += \
./Core/Src/tools/CControl/Sources/Optimization/linprog.o \
./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.o \
./Core/Src/tools/CControl/Sources/Optimization/quadprog.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/Optimization/linprog.d \
./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.d \
./Core/Src/tools/CControl/Sources/Optimization/quadprog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/Optimization/%.o Core/Src/tools/CControl/Sources/Optimization/%.su Core/Src/tools/CControl/Sources/Optimization/%.cyclo: ../Core/Src/tools/CControl/Sources/Optimization/%.c Core/Src/tools/CControl/Sources/Optimization/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Optimization

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Optimization:
	-$(RM) ./Core/Src/tools/CControl/Sources/Optimization/linprog.cyclo ./Core/Src/tools/CControl/Sources/Optimization/linprog.d ./Core/Src/tools/CControl/Sources/Optimization/linprog.o ./Core/Src/tools/CControl/Sources/Optimization/linprog.su ./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.cyclo ./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.d ./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.o ./Core/Src/tools/CControl/Sources/Optimization/lsqnonneg.su ./Core/Src/tools/CControl/Sources/Optimization/quadprog.cyclo ./Core/Src/tools/CControl/Sources/Optimization/quadprog.d ./Core/Src/tools/CControl/Sources/Optimization/quadprog.o ./Core/Src/tools/CControl/Sources/Optimization/quadprog.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Optimization
