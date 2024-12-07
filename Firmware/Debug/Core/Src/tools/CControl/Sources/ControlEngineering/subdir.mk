################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/ControlEngineering/c2d.c \
../Core/Src/tools/CControl/Sources/ControlEngineering/cab.c \
../Core/Src/tools/CControl/Sources/ControlEngineering/obsv.c \
../Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.c \
../Core/Src/tools/CControl/Sources/ControlEngineering/ssint.c \
../Core/Src/tools/CControl/Sources/ControlEngineering/stability.c 

OBJS += \
./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.o \
./Core/Src/tools/CControl/Sources/ControlEngineering/cab.o \
./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.o \
./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.o \
./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.o \
./Core/Src/tools/CControl/Sources/ControlEngineering/stability.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.d \
./Core/Src/tools/CControl/Sources/ControlEngineering/cab.d \
./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.d \
./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.d \
./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.d \
./Core/Src/tools/CControl/Sources/ControlEngineering/stability.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/ControlEngineering/%.o Core/Src/tools/CControl/Sources/ControlEngineering/%.su Core/Src/tools/CControl/Sources/ControlEngineering/%.cyclo: ../Core/Src/tools/CControl/Sources/ControlEngineering/%.c Core/Src/tools/CControl/Sources/ControlEngineering/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ControlEngineering

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ControlEngineering:
	-$(RM) ./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.d ./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.o ./Core/Src/tools/CControl/Sources/ControlEngineering/c2d.su ./Core/Src/tools/CControl/Sources/ControlEngineering/cab.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/cab.d ./Core/Src/tools/CControl/Sources/ControlEngineering/cab.o ./Core/Src/tools/CControl/Sources/ControlEngineering/cab.su ./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.d ./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.o ./Core/Src/tools/CControl/Sources/ControlEngineering/obsv.su ./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.d ./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.o ./Core/Src/tools/CControl/Sources/ControlEngineering/qmpc.su ./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.d ./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.o ./Core/Src/tools/CControl/Sources/ControlEngineering/ssint.su ./Core/Src/tools/CControl/Sources/ControlEngineering/stability.cyclo ./Core/Src/tools/CControl/Sources/ControlEngineering/stability.d ./Core/Src/tools/CControl/Sources/ControlEngineering/stability.o ./Core/Src/tools/CControl/Sources/ControlEngineering/stability.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ControlEngineering

