################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
PDE_SRCS += \
../libraries/Time/examples/TimeRTCLog/TimeRTCLog.pde 

PDE_DEPS += \
./libraries/Time/examples/TimeRTCLog/TimeRTCLog.pde.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Time/examples/TimeRTCLog/TimeRTCLog.o: ../libraries/Time/examples/TimeRTCLog/TimeRTCLog.pde
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


