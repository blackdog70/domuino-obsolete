################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../animation.cpp \
../automatic.cpp \
../communication.cpp \
../crypto.cpp \
../domino.cpp \
../input.cpp \
../output.cpp 

CPP_DEPS += \
./animation.cpp.d \
./automatic.cpp.d \
./communication.cpp.d \
./crypto.cpp.d \
./domino.cpp.d \
./input.cpp.d \
./output.cpp.d 

LINK_OBJ += \
./animation.cpp.o \
./automatic.cpp.o \
./communication.cpp.o \
./crypto.cpp.o \
./domino.cpp.o \
./input.cpp.o \
./output.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
animation.cpp.o: ../animation.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

automatic.cpp.o: ../automatic.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

communication.cpp.o: ../communication.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

crypto.cpp.o: ../crypto.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

domino.cpp.o: ../domino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

input.cpp.o: ../input.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

output.cpp.o: ../output.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


