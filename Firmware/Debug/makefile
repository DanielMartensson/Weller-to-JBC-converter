################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/tools/modbus/nanomodbus/subdir.mk
-include Core/Src/tools/modbus/subdir.mk
-include Core/Src/tools/conversions/subdir.mk
-include Core/Src/tools/CControl/Sources/SystemIdentification/subdir.mk
-include Core/Src/tools/CControl/Sources/Statistics/subdir.mk
-include Core/Src/tools/CControl/Sources/SignalProcessing/FFTpack/subdir.mk
-include Core/Src/tools/CControl/Sources/SignalProcessing/subdir.mk
-include Core/Src/tools/CControl/Sources/Optimization/subdir.mk
-include Core/Src/tools/CControl/Sources/Miscellaneous/subdir.mk
-include Core/Src/tools/CControl/Sources/MachineLearning/subdir.mk
-include Core/Src/tools/CControl/Sources/LinearAlgebra/CLapack/Tools/subdir.mk
-include Core/Src/tools/CControl/Sources/LinearAlgebra/CLapack/Routines/subdir.mk
-include Core/Src/tools/CControl/Sources/LinearAlgebra/subdir.mk
-include Core/Src/tools/CControl/Sources/ImageProcessing/subdir.mk
-include Core/Src/tools/CControl/Sources/Hardware/subdir.mk
-include Core/Src/tools/CControl/Sources/ControlEngineering/subdir.mk
-include Core/Src/tools/CControl/Sources/ComputerVision/subdir.mk
-include Core/Src/tools/CControl/Sources/ArtificialIntelligence/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Firmware
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Firmware.elf \

MAP_FILES += \
Firmware.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Firmware.list \


# All Target
all: main-build

# Main-build Target
main-build: Firmware.elf secondary-outputs

# Tool invocations
Firmware.elf Firmware.map: $(OBJS) $(USER_OBJS) C:\Users\danie\Documents\GitHub\Weller-to-JBC-converter\Firmware\STM32F051R8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Firmware.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\danie\Documents\GitHub\Weller-to-JBC-converter\Firmware\STM32F051R8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Firmware.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Firmware.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Firmware.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Firmware.elf Firmware.list Firmware.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
