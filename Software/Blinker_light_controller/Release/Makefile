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
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../button_handler.c \
../main.c \
../output_control.c \
../Ws2812.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
button_handler.o \
main.o \
output_control.o \
Ws2812.o

OBJS_AS_ARGS +=  \
button_handler.o \
main.o \
output_control.o \
Ws2812.o

C_DEPS +=  \
button_handler.d \
main.d \
output_control.d \
Ws2812.d

C_DEPS_AS_ARGS +=  \
button_handler.d \
main.d \
output_control.d \
Ws2812.d

OUTPUT_FILE_PATH +=Blinker_light_controller.elf

OUTPUT_FILE_PATH_AS_ARGS +=Blinker_light_controller.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./button_handler.o: .././button_handler.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATtiny814  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.10.348\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATtiny814__ -DNDEBUG  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATtiny814  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.10.348\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATtiny814__ -DNDEBUG  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./output_control.o: .././output_control.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATtiny814  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.10.348\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATtiny814__ -DNDEBUG  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./Ws2812.o: .././Ws2812.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATtiny814  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.10.348\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATtiny814__ -DNDEBUG  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking:  XC8 C Linker : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mcpu=ATtiny814  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.10.348\xc8"  -Wl,-Map="Blinker_light_controller.map" -funsigned-char -funsigned-bitfields -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,-L"C:\Users\Justus\OneDrive - TUNI.fi\Omat projektit\etuvalo\Blinker_light_controller"  -Wl,--gc-sections -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax --memorysummary,memoryfile.xml  
	@echo Finished building target: $@
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Blinker_light_controller.elf" "Blinker_light_controller.hex"
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "Blinker_light_controller.elf" "Blinker_light_controller.eep" || exit 0
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objdump.exe" -h -S "Blinker_light_controller.elf" > "Blinker_light_controller.lss"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Blinker_light_controller.elf" "Blinker_light_controller.hex" "Blinker_light_controller.eep" "Blinker_light_controller.map" "Blinker_light_controller.usersignatures" "Blinker_light_controller.a"  "Blinker_light_controller.lss"
	