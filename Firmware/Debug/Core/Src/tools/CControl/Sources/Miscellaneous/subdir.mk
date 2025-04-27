################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/Miscellaneous/cut.c \
../Core/Src/tools/CControl/Sources/Miscellaneous/insert.c \
../Core/Src/tools/CControl/Sources/Miscellaneous/scalar.c \
../Core/Src/tools/CControl/Sources/Miscellaneous/sign.c \
../Core/Src/tools/CControl/Sources/Miscellaneous/vmax.c \
../Core/Src/tools/CControl/Sources/Miscellaneous/vmin.c 

OBJS += \
./Core/Src/tools/CControl/Sources/Miscellaneous/cut.o \
./Core/Src/tools/CControl/Sources/Miscellaneous/insert.o \
./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.o \
./Core/Src/tools/CControl/Sources/Miscellaneous/sign.o \
./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.o \
./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/Miscellaneous/cut.d \
./Core/Src/tools/CControl/Sources/Miscellaneous/insert.d \
./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.d \
./Core/Src/tools/CControl/Sources/Miscellaneous/sign.d \
./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.d \
./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/Miscellaneous/%.o Core/Src/tools/CControl/Sources/Miscellaneous/%.su Core/Src/tools/CControl/Sources/Miscellaneous/%.cyclo: ../Core/Src/tools/CControl/Sources/Miscellaneous/%.c Core/Src/tools/CControl/Sources/Miscellaneous/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Miscellaneous

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Miscellaneous:
	-$(RM) ./Core/Src/tools/CControl/Sources/Miscellaneous/cut.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/cut.d ./Core/Src/tools/CControl/Sources/Miscellaneous/cut.o ./Core/Src/tools/CControl/Sources/Miscellaneous/cut.su ./Core/Src/tools/CControl/Sources/Miscellaneous/insert.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/insert.d ./Core/Src/tools/CControl/Sources/Miscellaneous/insert.o ./Core/Src/tools/CControl/Sources/Miscellaneous/insert.su ./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.d ./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.o ./Core/Src/tools/CControl/Sources/Miscellaneous/scalar.su ./Core/Src/tools/CControl/Sources/Miscellaneous/sign.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/sign.d ./Core/Src/tools/CControl/Sources/Miscellaneous/sign.o ./Core/Src/tools/CControl/Sources/Miscellaneous/sign.su ./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.d ./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.o ./Core/Src/tools/CControl/Sources/Miscellaneous/vmax.su ./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.cyclo ./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.d ./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.o ./Core/Src/tools/CControl/Sources/Miscellaneous/vmin.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Miscellaneous

