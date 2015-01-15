#-----------------------------------------------------------
#Generic Makefile
#
# Author: Stefan Mavrodiev @ Olimex LTD
# Date	: 2013-06-27
#
# Changelog:
# 2013-06-27	-	Initial release
# 15 OCT 2014	-	Modified for RK3188
# 13 NOV 2014	-	Made general version
#
#-----------------------------------------------------------

ifndef BOARD	
$(error No board defined)
endif

ifeq ($(BOARD),AM3352_SOM)
	CHIP = AM3352
else ifeq ($(BOARD),RK3188_SOM)
	CHIP = RK3188
else
$(error No matching board)
endif

ifdef CC
COMPILER = $(CC)
else
COMPILER = gcc
endif

ifdef CROSS_COMPILE
COMPILER = $(CROSS_COMPILE)
endif


SRCDIR = source
INCDIR = include
OBJDIR = obj
BINDIR = bin
BRDDIR = boards

CFLAGS = -Wall -std=c99 -D $(CHIP) -D $(BOARD) -D _DEBUG -I./$(INCDIR)/ -I./$(BRDDIR)
LINKER = $(COMPILER) -o
LFLAGS = -Wall -I./$(INCDIR)/ -I./$(BRDDIR)

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm = rm -f


all: $(OBJECTS) $(BINDIR)/$(BOARD)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully"
		
$(BINDIR)/$(BOARD): $(OBJECTS)
		@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
		@echo "Linking complete!"

	
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"
	
.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(BOARD)
	@echo "Exacutable removed!"
