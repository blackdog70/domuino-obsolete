################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../libraries/EmonLib/EmonLib.cpp 

CPP_DEPS += \
./libraries/EmonLib/EmonLib.cpp.d 

LINK_OBJ += \
./libraries/EmonLib/EmonLib.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/EmonLib/EmonLib.cpp.o: ../libraries/EmonLib/EmonLib.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


