################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.c \
../Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.c \
../Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.c \
../Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.c \
../Core/Src/tools/CControl/Sources/ComputerVision/hough.c \
../Core/Src/tools/CControl/Sources/ComputerVision/violajones.c 

OBJS += \
./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.o \
./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.o \
./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.o \
./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.o \
./Core/Src/tools/CControl/Sources/ComputerVision/hough.o \
./Core/Src/tools/CControl/Sources/ComputerVision/violajones.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.d \
./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.d \
./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.d \
./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.d \
./Core/Src/tools/CControl/Sources/ComputerVision/hough.d \
./Core/Src/tools/CControl/Sources/ComputerVision/violajones.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/ComputerVision/%.o Core/Src/tools/CControl/Sources/ComputerVision/%.su Core/Src/tools/CControl/Sources/ComputerVision/%.cyclo: ../Core/Src/tools/CControl/Sources/ComputerVision/%.c Core/Src/tools/CControl/Sources/ComputerVision/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ComputerVision

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ComputerVision:
	-$(RM) ./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.d ./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.o ./Core/Src/tools/CControl/Sources/ComputerVision/cornerdetection.su ./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.d ./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.o ./Core/Src/tools/CControl/Sources/ComputerVision/featuredetection.su ./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.d ./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.o ./Core/Src/tools/CControl/Sources/ComputerVision/fisherfaces.su ./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.d ./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.o ./Core/Src/tools/CControl/Sources/ComputerVision/generalizedhough.su ./Core/Src/tools/CControl/Sources/ComputerVision/hough.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/hough.d ./Core/Src/tools/CControl/Sources/ComputerVision/hough.o ./Core/Src/tools/CControl/Sources/ComputerVision/hough.su ./Core/Src/tools/CControl/Sources/ComputerVision/violajones.cyclo ./Core/Src/tools/CControl/Sources/ComputerVision/violajones.d ./Core/Src/tools/CControl/Sources/ComputerVision/violajones.o ./Core/Src/tools/CControl/Sources/ComputerVision/violajones.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ComputerVision

