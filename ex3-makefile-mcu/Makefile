GCC_DIR := E:/GNU-toolchain/
CC=$(GCC_DIR)/bin/arm-none-eabi-gcc
LD_FILE := Linker/stm_ls.ld
INC_DIR := Driver/GPIO/inc

PROGRAMMER := E:/STM32CubeProgrammer/bin/STM32_Programmer_CLI.exe

CHIP = cortex-m3

# Compiler Options: gọi tắt là comile flags
CCFLAGS= -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
# -c để cho compile
# O0 không dùng Optimize

# Linker flags
LDFLAGS= -nostdlib -T $(LD_FILE) -Wl,-Map=Output/GPIO.map 

.PHONY: build
build: Output/GPIO.hex

#main.o
Output/main.o: User/src/main.c
	$(CC) $(CCFLAGS) -o $@ $^
#GPIO.o
Output/GPIO.o: Driver/GPIO/src/GPIO.c
	$(CC) $(CCFLAGS) -o $@ $^ 
#startup.o
Output/stm32_startup.o: Startup/stm32_startup.c
	$(CC) $(CCFLAGS) -o $@ $^
	
#GPIO.elf
Output/GPIO.elf: Output/main.o Output/GPIO.o Output/stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

#GPIO.hex
Output/GPIO.hex: Output/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

.PHONY: flash
flash: 
	$(PROGRAMMER) -c port=SWD -e all
	$(PROGRAMMER) -c port=SWD -w "Output/GPIO.hex" 0x08000000 -rst

.PHONY: clean
clean:
	rm -rf ./Output/*
	