################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/Statistics/amax.c \
../Core/Src/tools/CControl/Sources/Statistics/amin.c \
../Core/Src/tools/CControl/Sources/Statistics/area.c \
../Core/Src/tools/CControl/Sources/Statistics/center.c \
../Core/Src/tools/CControl/Sources/Statistics/centroid.c \
../Core/Src/tools/CControl/Sources/Statistics/clusterratio.c \
../Core/Src/tools/CControl/Sources/Statistics/clustersdistance.c \
../Core/Src/tools/CControl/Sources/Statistics/cov.c \
../Core/Src/tools/CControl/Sources/Statistics/covm.c \
../Core/Src/tools/CControl/Sources/Statistics/giniimpurity.c \
../Core/Src/tools/CControl/Sources/Statistics/lda.c \
../Core/Src/tools/CControl/Sources/Statistics/mean.c \
../Core/Src/tools/CControl/Sources/Statistics/normpdf.c \
../Core/Src/tools/CControl/Sources/Statistics/opa.c \
../Core/Src/tools/CControl/Sources/Statistics/pca.c \
../Core/Src/tools/CControl/Sources/Statistics/randi.c \
../Core/Src/tools/CControl/Sources/Statistics/randn.c \
../Core/Src/tools/CControl/Sources/Statistics/randperm.c \
../Core/Src/tools/CControl/Sources/Statistics/stddev.c \
../Core/Src/tools/CControl/Sources/Statistics/var.c 

OBJS += \
./Core/Src/tools/CControl/Sources/Statistics/amax.o \
./Core/Src/tools/CControl/Sources/Statistics/amin.o \
./Core/Src/tools/CControl/Sources/Statistics/area.o \
./Core/Src/tools/CControl/Sources/Statistics/center.o \
./Core/Src/tools/CControl/Sources/Statistics/centroid.o \
./Core/Src/tools/CControl/Sources/Statistics/clusterratio.o \
./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.o \
./Core/Src/tools/CControl/Sources/Statistics/cov.o \
./Core/Src/tools/CControl/Sources/Statistics/covm.o \
./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.o \
./Core/Src/tools/CControl/Sources/Statistics/lda.o \
./Core/Src/tools/CControl/Sources/Statistics/mean.o \
./Core/Src/tools/CControl/Sources/Statistics/normpdf.o \
./Core/Src/tools/CControl/Sources/Statistics/opa.o \
./Core/Src/tools/CControl/Sources/Statistics/pca.o \
./Core/Src/tools/CControl/Sources/Statistics/randi.o \
./Core/Src/tools/CControl/Sources/Statistics/randn.o \
./Core/Src/tools/CControl/Sources/Statistics/randperm.o \
./Core/Src/tools/CControl/Sources/Statistics/stddev.o \
./Core/Src/tools/CControl/Sources/Statistics/var.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/Statistics/amax.d \
./Core/Src/tools/CControl/Sources/Statistics/amin.d \
./Core/Src/tools/CControl/Sources/Statistics/area.d \
./Core/Src/tools/CControl/Sources/Statistics/center.d \
./Core/Src/tools/CControl/Sources/Statistics/centroid.d \
./Core/Src/tools/CControl/Sources/Statistics/clusterratio.d \
./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.d \
./Core/Src/tools/CControl/Sources/Statistics/cov.d \
./Core/Src/tools/CControl/Sources/Statistics/covm.d \
./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.d \
./Core/Src/tools/CControl/Sources/Statistics/lda.d \
./Core/Src/tools/CControl/Sources/Statistics/mean.d \
./Core/Src/tools/CControl/Sources/Statistics/normpdf.d \
./Core/Src/tools/CControl/Sources/Statistics/opa.d \
./Core/Src/tools/CControl/Sources/Statistics/pca.d \
./Core/Src/tools/CControl/Sources/Statistics/randi.d \
./Core/Src/tools/CControl/Sources/Statistics/randn.d \
./Core/Src/tools/CControl/Sources/Statistics/randperm.d \
./Core/Src/tools/CControl/Sources/Statistics/stddev.d \
./Core/Src/tools/CControl/Sources/Statistics/var.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/Statistics/%.o Core/Src/tools/CControl/Sources/Statistics/%.su Core/Src/tools/CControl/Sources/Statistics/%.cyclo: ../Core/Src/tools/CControl/Sources/Statistics/%.c Core/Src/tools/CControl/Sources/Statistics/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Statistics

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Statistics:
	-$(RM) ./Core/Src/tools/CControl/Sources/Statistics/amax.cyclo ./Core/Src/tools/CControl/Sources/Statistics/amax.d ./Core/Src/tools/CControl/Sources/Statistics/amax.o ./Core/Src/tools/CControl/Sources/Statistics/amax.su ./Core/Src/tools/CControl/Sources/Statistics/amin.cyclo ./Core/Src/tools/CControl/Sources/Statistics/amin.d ./Core/Src/tools/CControl/Sources/Statistics/amin.o ./Core/Src/tools/CControl/Sources/Statistics/amin.su ./Core/Src/tools/CControl/Sources/Statistics/area.cyclo ./Core/Src/tools/CControl/Sources/Statistics/area.d ./Core/Src/tools/CControl/Sources/Statistics/area.o ./Core/Src/tools/CControl/Sources/Statistics/area.su ./Core/Src/tools/CControl/Sources/Statistics/center.cyclo ./Core/Src/tools/CControl/Sources/Statistics/center.d ./Core/Src/tools/CControl/Sources/Statistics/center.o ./Core/Src/tools/CControl/Sources/Statistics/center.su ./Core/Src/tools/CControl/Sources/Statistics/centroid.cyclo ./Core/Src/tools/CControl/Sources/Statistics/centroid.d ./Core/Src/tools/CControl/Sources/Statistics/centroid.o ./Core/Src/tools/CControl/Sources/Statistics/centroid.su ./Core/Src/tools/CControl/Sources/Statistics/clusterratio.cyclo ./Core/Src/tools/CControl/Sources/Statistics/clusterratio.d ./Core/Src/tools/CControl/Sources/Statistics/clusterratio.o ./Core/Src/tools/CControl/Sources/Statistics/clusterratio.su ./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.cyclo ./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.d ./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.o ./Core/Src/tools/CControl/Sources/Statistics/clustersdistance.su ./Core/Src/tools/CControl/Sources/Statistics/cov.cyclo ./Core/Src/tools/CControl/Sources/Statistics/cov.d ./Core/Src/tools/CControl/Sources/Statistics/cov.o ./Core/Src/tools/CControl/Sources/Statistics/cov.su ./Core/Src/tools/CControl/Sources/Statistics/covm.cyclo ./Core/Src/tools/CControl/Sources/Statistics/covm.d ./Core/Src/tools/CControl/Sources/Statistics/covm.o ./Core/Src/tools/CControl/Sources/Statistics/covm.su ./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.cyclo ./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.d ./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.o ./Core/Src/tools/CControl/Sources/Statistics/giniimpurity.su ./Core/Src/tools/CControl/Sources/Statistics/lda.cyclo ./Core/Src/tools/CControl/Sources/Statistics/lda.d ./Core/Src/tools/CControl/Sources/Statistics/lda.o ./Core/Src/tools/CControl/Sources/Statistics/lda.su ./Core/Src/tools/CControl/Sources/Statistics/mean.cyclo ./Core/Src/tools/CControl/Sources/Statistics/mean.d ./Core/Src/tools/CControl/Sources/Statistics/mean.o ./Core/Src/tools/CControl/Sources/Statistics/mean.su ./Core/Src/tools/CControl/Sources/Statistics/normpdf.cyclo ./Core/Src/tools/CControl/Sources/Statistics/normpdf.d ./Core/Src/tools/CControl/Sources/Statistics/normpdf.o ./Core/Src/tools/CControl/Sources/Statistics/normpdf.su ./Core/Src/tools/CControl/Sources/Statistics/opa.cyclo ./Core/Src/tools/CControl/Sources/Statistics/opa.d ./Core/Src/tools/CControl/Sources/Statistics/opa.o ./Core/Src/tools/CControl/Sources/Statistics/opa.su ./Core/Src/tools/CControl/Sources/Statistics/pca.cyclo ./Core/Src/tools/CControl/Sources/Statistics/pca.d ./Core/Src/tools/CControl/Sources/Statistics/pca.o ./Core/Src/tools/CControl/Sources/Statistics/pca.su ./Core/Src/tools/CControl/Sources/Statistics/randi.cyclo ./Core/Src/tools/CControl/Sources/Statistics/randi.d ./Core/Src/tools/CControl/Sources/Statistics/randi.o ./Core/Src/tools/CControl/Sources/Statistics/randi.su ./Core/Src/tools/CControl/Sources/Statistics/randn.cyclo ./Core/Src/tools/CControl/Sources/Statistics/randn.d ./Core/Src/tools/CControl/Sources/Statistics/randn.o ./Core/Src/tools/CControl/Sources/Statistics/randn.su ./Core/Src/tools/CControl/Sources/Statistics/randperm.cyclo ./Core/Src/tools/CControl/Sources/Statistics/randperm.d ./Core/Src/tools/CControl/Sources/Statistics/randperm.o ./Core/Src/tools/CControl/Sources/Statistics/randperm.su ./Core/Src/tools/CControl/Sources/Statistics/stddev.cyclo ./Core/Src/tools/CControl/Sources/Statistics/stddev.d ./Core/Src/tools/CControl/Sources/Statistics/stddev.o ./Core/Src/tools/CControl/Sources/Statistics/stddev.su ./Core/Src/tools/CControl/Sources/Statistics/var.cyclo ./Core/Src/tools/CControl/Sources/Statistics/var.d ./Core/Src/tools/CControl/Sources/Statistics/var.o ./Core/Src/tools/CControl/Sources/Statistics/var.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Statistics

