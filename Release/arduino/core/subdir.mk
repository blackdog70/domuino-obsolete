################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/CDC.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HID.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/IPAddress.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Print.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Stream.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Tone.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/USBCore.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WMath.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WString.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/abi.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/main.cpp \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/new.cpp 

C_SRCS += \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WInterrupts.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/hooks.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_analog.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_digital.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_pulse.c \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_shift.c 

S_UPPER_SRCS += \
/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_pulse.S 

C_DEPS += \
./arduino/WInterrupts.c.d \
./arduino/hooks.c.d \
./arduino/wiring.c.d \
./arduino/wiring_analog.c.d \
./arduino/wiring_digital.c.d \
./arduino/wiring_pulse.c.d \
./arduino/wiring_shift.c.d 

S_UPPER_DEPS += \
./arduino/wiring_pulse.S.d 

AR_OBJ += \
./arduino/CDC.cpp.o \
./arduino/HID.cpp.o \
./arduino/HardwareSerial.cpp.o \
./arduino/HardwareSerial0.cpp.o \
./arduino/HardwareSerial1.cpp.o \
./arduino/HardwareSerial2.cpp.o \
./arduino/HardwareSerial3.cpp.o \
./arduino/IPAddress.cpp.o \
./arduino/Print.cpp.o \
./arduino/Stream.cpp.o \
./arduino/Tone.cpp.o \
./arduino/USBCore.cpp.o \
./arduino/WInterrupts.c.o \
./arduino/WMath.cpp.o \
./arduino/WString.cpp.o \
./arduino/abi.cpp.o \
./arduino/hooks.c.o \
./arduino/main.cpp.o \
./arduino/new.cpp.o \
./arduino/wiring.c.o \
./arduino/wiring_analog.c.o \
./arduino/wiring_digital.c.o \
./arduino/wiring_pulse.S.o \
./arduino/wiring_pulse.c.o \
./arduino/wiring_shift.c.o 

CPP_DEPS += \
./arduino/CDC.cpp.d \
./arduino/HID.cpp.d \
./arduino/HardwareSerial.cpp.d \
./arduino/HardwareSerial0.cpp.d \
./arduino/HardwareSerial1.cpp.d \
./arduino/HardwareSerial2.cpp.d \
./arduino/HardwareSerial3.cpp.d \
./arduino/IPAddress.cpp.d \
./arduino/Print.cpp.d \
./arduino/Stream.cpp.d \
./arduino/Tone.cpp.d \
./arduino/USBCore.cpp.d \
./arduino/WMath.cpp.d \
./arduino/WString.cpp.d \
./arduino/abi.cpp.d \
./arduino/main.cpp.d \
./arduino/new.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/CDC.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HID.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HID.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial0.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial1.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial2.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial3.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/IPAddress.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Print.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Stream.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Tone.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/USBCore.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WInterrupts.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WMath.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WString.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/abi.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/abi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/hooks.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/hooks.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/main.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/new.cpp.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_analog.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_digital.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.S.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -x assembler-with-cpp -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_shift.c.o: /home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/FreeMemory" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/AES-library" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/crc" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/Time" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/animation" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/TimerOne/config" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/home/sebastiano/Documents/arduino/domino/workspace/domino-0.2/libraries/EmonLib" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/home/sebastiano/Programs/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


