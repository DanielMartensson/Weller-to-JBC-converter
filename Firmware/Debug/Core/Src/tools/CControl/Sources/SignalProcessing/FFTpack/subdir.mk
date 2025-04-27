################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.c 

OBJS += \
./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/%.o Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/%.su Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/%.cyclo: ../Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/%.c Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SignalProcessing-2f-FFTpack

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SignalProcessing-2f-FFTpack:
	-$(RM) ./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.cyclo ./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.d ./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.o ./Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/fftpack.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SignalProcessing-2f-FFTpack

