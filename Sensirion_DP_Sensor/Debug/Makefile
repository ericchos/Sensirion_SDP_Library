################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Visual\ Micro/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../sensirion.cpp \
../twi.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
sensirion.o \
twi.o

OBJS_AS_ARGS +=  \
sensirion.o \
twi.o

C_DEPS +=  \
sensirion.d \
twi.d

C_DEPS_AS_ARGS +=  \
sensirion.d \
twi.d

OUTPUT_FILE_PATH +=SensirionSDP600.elf

OUTPUT_FILE_PATH_AS_ARGS +=SensirionSDP600.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler





./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega328p__ -D__AVR_ATmega328P__ -DARDUINO=101 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__ -D__cplusplus  -I"C:\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"C:\arduino-1.5.6-r2\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\arduino-1.5.6-r2\libraries" -I"C:\arduino-1.5.6-r2\hardware\arduino\avr\libraries" -I"C:\Program Files (x86)\Visual Micro\Visual Micro for Arduino\Micro Platforms\default\debuggers" -I"C:\Users\Eric\Dropbox\WorkSpaces\Arduino\libraries" -I"c:\arduino-1.5.6-r2\hardware\tools\avr\avr\include" -I"c:\arduino-1.5.6-r2\hardware\tools\avr\avr\include\avr" -I"c:\arduino-1.5.6-r2\hardware\tools\avr\avr" -I"c:\arduino-1.5.6-r2\hardware\tools\avr\lib\gcc\avr\4.3.2\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -c -include=arduino.h -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SensirionSDP600.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p 
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "SensirionSDP600.elf" "SensirionSDP600.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SensirionSDP600.elf" "SensirionSDP600.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SensirionSDP600.elf" > "SensirionSDP600.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "SensirionSDP600.elf" "SensirionSDP600.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-size.exe" "SensirionSDP600.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SensirionSDP600.elf" "SensirionSDP600.a" "SensirionSDP600.hex" "SensirionSDP600.lss" "SensirionSDP600.eep" "SensirionSDP600.map" "SensirionSDP600.srec"
	