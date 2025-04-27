################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/SystemIdentification/era.c \
../Core/Src/tools/CControl/Sources/SystemIdentification/okid.c \
../Core/Src/tools/CControl/Sources/SystemIdentification/rls.c \
../Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.c \
../Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.c 

OBJS += \
./Core/Src/tools/CControl/Sources/SystemIdentification/era.o \
./Core/Src/tools/CControl/Sources/SystemIdentification/okid.o \
./Core/Src/tools/CControl/Sources/SystemIdentification/rls.o \
./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.o \
./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/SystemIdentification/era.d \
./Core/Src/tools/CControl/Sources/SystemIdentification/okid.d \
./Core/Src/tools/CControl/Sources/SystemIdentification/rls.d \
./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.d \
./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/SystemIdentification/%.o Core/Src/tools/CControl/Sources/SystemIdentification/%.su Core/Src/tools/CControl/Sources/SystemIdentification/%.cyclo: ../Core/Src/tools/CControl/Sources/SystemIdentification/%.c Core/Src/tools/CControl/Sources/SystemIdentification/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SystemIdentification

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SystemIdentification:
	-$(RM) ./Core/Src/tools/CControl/Sources/SystemIdentification/era.cyclo ./Core/Src/tools/CControl/Sources/SystemIdentification/era.d ./Core/Src/tools/CControl/Sources/SystemIdentification/era.o ./Core/Src/tools/CControl/Sources/SystemIdentification/era.su ./Core/Src/tools/CControl/Sources/SystemIdentification/okid.cyclo ./Core/Src/tools/CControl/Sources/SystemIdentification/okid.d ./Core/Src/tools/CControl/Sources/SystemIdentification/okid.o ./Core/Src/tools/CControl/Sources/SystemIdentification/okid.su ./Core/Src/tools/CControl/Sources/SystemIdentification/rls.cyclo ./Core/Src/tools/CControl/Sources/SystemIdentification/rls.d ./Core/Src/tools/CControl/Sources/SystemIdentification/rls.o ./Core/Src/tools/CControl/Sources/SystemIdentification/rls.su ./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.cyclo ./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.d ./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.o ./Core/Src/tools/CControl/Sources/SystemIdentification/sr_ukf_parameter_estimation.su ./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.cyclo ./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.d ./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.o ./Core/Src/tools/CControl/Sources/SystemIdentification/theta2ss.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-SystemIdentification

