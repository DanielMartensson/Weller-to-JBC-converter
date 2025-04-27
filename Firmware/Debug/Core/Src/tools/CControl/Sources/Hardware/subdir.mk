################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.c \
../Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.c \
../Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.c \
../Core/Src/tools/CControl/Sources/Hardware/saveload.c \
../Core/Src/tools/CControl/Sources/Hardware/scan_file_names.c \
../Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.c 

OBJS += \
./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.o \
./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.o \
./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.o \
./Core/Src/tools/CControl/Sources/Hardware/saveload.o \
./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.o \
./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.o 

C_DEPS += \
./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.d \
./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.d \
./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.d \
./Core/Src/tools/CControl/Sources/Hardware/saveload.d \
./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.d \
./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tools/CControl/Sources/Hardware/%.o Core/Src/tools/CControl/Sources/Hardware/%.su Core/Src/tools/CControl/Sources/Hardware/%.cyclo: ../Core/Src/tools/CControl/Sources/Hardware/%.c Core/Src/tools/CControl/Sources/Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Hardware

clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Hardware:
	-$(RM) ./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.cyclo ./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.d ./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.o ./Core/Src/tools/CControl/Sources/Hardware/concatenate_paths.su ./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.cyclo ./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.d ./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.o ./Core/Src/tools/CControl/Sources/Hardware/count_sub_folders.su ./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.cyclo ./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.d ./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.o ./Core/Src/tools/CControl/Sources/Hardware/detectmemoryleak.su ./Core/Src/tools/CControl/Sources/Hardware/saveload.cyclo ./Core/Src/tools/CControl/Sources/Hardware/saveload.d ./Core/Src/tools/CControl/Sources/Hardware/saveload.o ./Core/Src/tools/CControl/Sources/Hardware/saveload.su ./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.cyclo ./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.d ./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.o ./Core/Src/tools/CControl/Sources/Hardware/scan_file_names.su ./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.cyclo ./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.d ./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.o ./Core/Src/tools/CControl/Sources/Hardware/scan_sub_folder_names.su

.PHONY: clean-Core-2f-Src-2f-tools-2f-CControl-2f-Sources-2f-Hardware

