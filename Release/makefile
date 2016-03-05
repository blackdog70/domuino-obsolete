################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/crc/subdir.mk
-include libraries/TimerOne/subdir.mk
-include libraries/Time/examples/TimeTeensy3/subdir.mk
-include libraries/Time/examples/TimeSerialDateStrings/subdir.mk
-include libraries/Time/examples/TimeSerial/subdir.mk
-include libraries/Time/examples/TimeRTCSet/subdir.mk
-include libraries/Time/examples/TimeNTP/subdir.mk
-include libraries/Time/examples/TimeGPS/subdir.mk
-include libraries/Time/examples/TimeArduinoDue/subdir.mk
-include libraries/Time/subdir.mk
-include libraries/FreeMemory/subdir.mk
-include libraries/EmonLib/examples/voltage_and_current/subdir.mk
-include libraries/EmonLib/examples/current_only/subdir.mk
-include libraries/EmonLib/subdir.mk
-include libraries/AES-library/subdir.mk
-include animation/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
domino-0.2.elf \

EEP += \
domino-0.2.eep \

FLASH_IMAGE += \
domino-0.2.hex \


# All Target
all: domino-0.2

# Tool invocations
domino-0.2: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-size" -A "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-ar" rcs  "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

domino-0.2.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.elf"   $(LINK_OBJ) $(AR)  "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/arduino.ar" "-L/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

domino-0.2.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.elf" "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.eep"
	@echo 'Finished building: $@'
	@echo ' '

domino-0.2.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.elf" "/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/Release/domino-0.2.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) domino-0.2
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
