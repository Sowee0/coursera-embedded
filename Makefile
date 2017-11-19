#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

DFLAGS = -D$(PLATFORM)
ifdef COURSE1
    DFLAGS := $(DFLAGS) -DCOURSE1
endif

ifdef VERBOSE
    DFLAGS := $(DFLAGS) -DVERBOSE
endif

# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds

CPU = cortex-m4
THUMB = thumb
ARCH = armv7e-m
SPECS = nosys.specs
FLOAT = hard
FPU = fpv4-sp-d16

# Compiler Flags and Defines
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=c1m2.map

#general compiler flags for both platforms
CFLAGS = -Wall\
        -Werror\
         -g\
         -O0\
         -std=c99 $(DFLAGS)
#object files		 
OBJS = $(SOURCES:.c=.o)
#output file name
TARGET = c1final.out
#platform dependent changes
ifeq ($(PLATFORM),HOST)
    CC = gcc
else
    CC = arm-none-eabi-gcc
	CFLAGS := $(CFLAGS) -mcpu=$(CPU) -m$(THUMB) --specs=$(SPECS) -mfloat-abi=$(FLOAT) -mfpu=$(FPU) -march=$(ARCH)
    LD = arm-none-eabi-ld
	LDFLAGS := $(LDFLAGS) -T $(LINKER_FILE)
endif

#make build target
.PHONY: build
build: $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@

#building object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  
#building assembly files
%.asm: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@
#create preprocessed files
%.i: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -E $< -o $@
#create dep files
%.d: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -M -MP $< -o $@
#compile all sources
.PHONY: compile-all
compile-all: $(TARGET)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -c -o $@
#make clean target, removes all generated files
.PHONY: clean
clean:
	@printf "clean project directory"
	@rm -f ./src/*.o
	@printf ".."
	@rm -f ./src/*.i
	@printf ".."
	@rm -f ./src/*.map
	@printf ".."
	@rm -f ./*.map
	@printf ".."
	@rm -f ./src/*.out
	@printf ".."
	@rm -f ./*.out
	@printf ".."
	@rm -f ./src/*.asm
	@printf ".."
	@rm -f ./src/*.d
	@printf "....\n"
	@echo "cleaning complete"
#debug target for printing variables
.PHONY: printinfo
printinfo:
	@echo "SOURCES" $(SOURCES)
	@echo "OBJECTS" $(OBJS)
	@echo "COMPILER (CC)" $(CC)
	@echo "CFLAGS" $(CFLAGS)
	@echo "LDFLAGS" $(LDFLAGS)
	@echo "DFLAGS" $(DFLAGS)