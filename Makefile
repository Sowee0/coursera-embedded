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

# linker file
LINKER_FILE = ../msp432p401r.lds
# plattform specific files
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=mapfile.map
CFLAGS = -Wall\
        -Werror\
         -g\
         -O0\
         -std=c99

OBJS = $(SOURCES:.c=.o)
# output file name
TARGET = m1c2.out
# choose compiler based on provided information
ifeq ($(PLATFORM),HOST)
    CC = gcc
else
    CC = arm-none-eabi-gcc
	CFLAGS := $(CFLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
    LD = arm-none-eabi-ld
endif

# make object file target
%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -C $< -o $@
#make all target
.PHONY: all
all: $(TARGET)
$(TARGET) : $(OBJS)
	@echo "Buildig with" $(CC) "compiler"
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
#removes all generated files such as object/map/assembly/output	
.PHONY: clean
clean:
	@printf "clean project directory"
	@rm -f *.o
	@printf "."
	@rm -f *.i
	@printf "."
	@rm -f *.map
	@printf "."
	@rm -f *.out
	@printf "."
	@rm -f *.asm
	@printf ".\n"
	@echo "cleaning complete"

#debug target for printing variables
.PHONY: printinfo
printinfo:
	@echo "SOURCES" $(SOURCES)
	@echo "OBJECTS" $(OBJS)