################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/harris.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imfree.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imread.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imresize.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imshow.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/lbp.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/pooling.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/rpca.c \
../Core/Src/tools/CControl/Sources/ImageProcessing/sobel.c 

OBJS += \
./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/harris.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imread.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.o \
./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/harris.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imread.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.d \
./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/ImageProcessing/%.o Core/Src/tools/CControl/Sources/ImageProcessing/%.su Core/Src/tools/CControl/Sources/ImageProcessing/%.cyclo: ../Core/Src/tools/CControl/Sources/ImageProcessing/%.c Core/Src/tools/CControl/Sources/ImageProcessing/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ImageProcessing

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ImageProcessing:
	-$(RM) ./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.d ./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.o ./Core/Src/tools/CControl/Sources/ImageProcessing/fspecial.su ./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.d ./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.o ./Core/Src/tools/CControl/Sources/ImageProcessing/haarlike.su ./Core/Src/tools/CControl/Sources/ImageProcessing/harris.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/harris.d ./Core/Src/tools/CControl/Sources/ImageProcessing/harris.o ./Core/Src/tools/CControl/Sources/ImageProcessing/harris.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imcollect.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imfree.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imgaussfilt.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imread.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imread.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imread.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imread.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imresize.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imshow.su ./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.d ./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.o ./Core/Src/tools/CControl/Sources/ImageProcessing/imwrite.su ./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.d ./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.o ./Core/Src/tools/CControl/Sources/ImageProcessing/integralimage.su ./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.d ./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.o ./Core/Src/tools/CControl/Sources/ImageProcessing/intensitycentroid.su ./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.d ./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.o ./Core/Src/tools/CControl/Sources/ImageProcessing/lbp.su ./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.d ./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.o ./Core/Src/tools/CControl/Sources/ImageProcessing/pooling.su ./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.d ./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.o ./Core/Src/tools/CControl/Sources/ImageProcessing/rpca.su ./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.cyclo ./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.d ./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.o ./Core/Src/tools/CControl/Sources/ImageProcessing/sobel.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-ImageProcessing

