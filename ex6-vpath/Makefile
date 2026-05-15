##############################################################################
# Project: GPIO bare-metal STM32
# Toolchain: ARM GCC
# Output: ELF -> HEX -> Flash
##############################################################################

# Toolchain
GCC_DIR := E:/GNU-toolchain/
CC=$(GCC_DIR)/bin/arm-none-eabi-gcc
PROGRAMMER := E:/STM32CubeProgrammer/bin/STM32_Programmer_CLI.exe
CHIP = cortex-m3

# Linker file
LD_FILE := Linker/stm_ls.ld


# Include header files
INC_DIRS += Driver/GPIO/inc	\
			Driver/UART/inc 

INC_FILES = $(foreach dir, $(INC_DIRS), $(wildcard $(dir)/*))

# Source files
SRC_DIRS += Driver/GPIO/src \
			Driver/UART/src \
			User/src		\
			Startup

SRC_FILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*))

# Foreach for -I$() in compiler options
INC_DIR_OPT = $(foreach dir, $(INC_DIRS), -I$(dir))


# Flags: compiler & linker options
CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 $(INC_DIR_OPT)
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=Output/GPIO.map 

.PHONY: build
build: Output/GPIO.hex

# Compile object file
vpath %.c $(SRC_DIRS)

Output/main.o: main.c
	$(CC) $(CCFLAGS) -o $@ $^
Output/GPIO.o: GPIO.c
	$(CC) $(CCFLAGS) -o $@ $^
Output/stm32_startup.o: stm32_startup.c
	$(CC) $(CCFLAGS) -o $@ $^
	
# Build excutable file
Output/GPIO.elf: Output/main.o Output/GPIO.o Output/stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

# Build .hex file
Output/GPIO.hex: Output/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

# Flash firmware into chip
.PHONY: flash
flash: 
	$(PROGRAMMER) -c port=SWD -e all
	$(PROGRAMMER) -c port=SWD -w "Output/GPIO.hex" 0x08000000 -rst


# Clear all output file
.PHONY: clean
clean:
	rm -rf ./Output/*
	
# Print
print-%:
	@echo $($(subst print-,,$@))