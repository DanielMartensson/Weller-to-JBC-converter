################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/LinearAlgebra/chol.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/dot.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/expm.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/eye.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/inv.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/lup.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/mul.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/norm.c \
../Core/Src/tools/CControl/Sources/LinearAlgebra/tran.c 

OBJS += \
./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.o \
./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.d \
./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/LinearAlgebra/%.o Core/Src/tools/CControl/Sources/LinearAlgebra/%.su Core/Src/tools/CControl/Sources/LinearAlgebra/%.cyclo: ../Core/Src/tools/CControl/Sources/LinearAlgebra/%.c Core/Src/tools/CControl/Sources/LinearAlgebra/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-LinearAlgebra

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-LinearAlgebra:
	-$(RM) ./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/chol.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/dot.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/expm.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/eye.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/inv.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_chol.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_lower_triangular.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/linsolve_upper_triangular.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/lup.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/mul.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/norm.su ./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.cyclo ./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.d ./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.o ./Core/Src/tools/CControl/Sources/LinearAlgebra/tran.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-LinearAlgebra

