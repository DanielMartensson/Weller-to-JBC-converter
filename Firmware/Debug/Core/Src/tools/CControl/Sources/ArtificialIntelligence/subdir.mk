################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.c \
../Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.c 

OBJS += \
./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.o \
./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.d \
./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/ArtificialIntelligence/%.o Core/Src/tools/CControl/Sources/ArtificialIntelligence/%.su Core/Src/tools/CControl/Sources/ArtificialIntelligence/%.cyclo: ../Core/Src/tools/CControl/Sources/ArtificialIntelligence/%.c Core/Src/tools/CControl/Sources/ArtificialIntelligence/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ArtificialIntelligence

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ArtificialIntelligence:
	-$(RM) ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.cyclo ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.d ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.o ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/Astar.su ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.cyclo ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.d ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.o ./Core/Src/tools/CControl/Sources/ArtificialIntelligence/inpolygon.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ArtificialIntelligence

