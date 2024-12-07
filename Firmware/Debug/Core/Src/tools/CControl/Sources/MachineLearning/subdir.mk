################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/MachineLearning/adaboost.c \
../Core/Src/tools/CControl/Sources/MachineLearning/dbscan.c \
../Core/Src/tools/CControl/Sources/MachineLearning/kernel.c \
../Core/Src/tools/CControl/Sources/MachineLearning/kmeans.c \
../Core/Src/tools/CControl/Sources/MachineLearning/kpca.c \
../Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.c \
../Core/Src/tools/CControl/Sources/MachineLearning/nn.c \
../Core/Src/tools/CControl/Sources/MachineLearning/svm.c 

OBJS += \
./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.o \
./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.o \
./Core/Src/tools/CControl/Sources/MachineLearning/kernel.o \
./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.o \
./Core/Src/tools/CControl/Sources/MachineLearning/kpca.o \
./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.o \
./Core/Src/tools/CControl/Sources/MachineLearning/nn.o \
./Core/Src/tools/CControl/Sources/MachineLearning/svm.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.d \
./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.d \
./Core/Src/tools/CControl/Sources/MachineLearning/kernel.d \
./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.d \
./Core/Src/tools/CControl/Sources/MachineLearning/kpca.d \
./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.d \
./Core/Src/tools/CControl/Sources/MachineLearning/nn.d \
./Core/Src/tools/CControl/Sources/MachineLearning/svm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/MachineLearning/%.o Core/Src/tools/CControl/Sources/MachineLearning/%.su Core/Src/tools/CControl/Sources/MachineLearning/%.cyclo: ../Core/Src/tools/CControl/Sources/MachineLearning/%.c Core/Src/tools/CControl/Sources/MachineLearning/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-MachineLearning

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-MachineLearning:
	-$(RM) ./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.d ./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.o ./Core/Src/tools/CControl/Sources/MachineLearning/adaboost.su ./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.d ./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.o ./Core/Src/tools/CControl/Sources/MachineLearning/dbscan.su ./Core/Src/tools/CControl/Sources/MachineLearning/kernel.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/kernel.d ./Core/Src/tools/CControl/Sources/MachineLearning/kernel.o ./Core/Src/tools/CControl/Sources/MachineLearning/kernel.su ./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.d ./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.o ./Core/Src/tools/CControl/Sources/MachineLearning/kmeans.su ./Core/Src/tools/CControl/Sources/MachineLearning/kpca.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/kpca.d ./Core/Src/tools/CControl/Sources/MachineLearning/kpca.o ./Core/Src/tools/CControl/Sources/MachineLearning/kpca.su ./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.d ./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.o ./Core/Src/tools/CControl/Sources/MachineLearning/kpca_lda_nn.su ./Core/Src/tools/CControl/Sources/MachineLearning/nn.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/nn.d ./Core/Src/tools/CControl/Sources/MachineLearning/nn.o ./Core/Src/tools/CControl/Sources/MachineLearning/nn.su ./Core/Src/tools/CControl/Sources/MachineLearning/svm.cyclo ./Core/Src/tools/CControl/Sources/MachineLearning/svm.d ./Core/Src/tools/CControl/Sources/MachineLearning/svm.o ./Core/Src/tools/CControl/Sources/MachineLearning/svm.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-MachineLearning

