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

ifeq ($(BOARD),AM3352-SOM)
	CHIP = AM3352
endif

ifeq ($(BOARD),RK3188-SOM)
	CHIP = RK3188
endif


ifdef CC
COMPILER = $(CC)
else
COMPILER = gcc
endif

ifdef CROSS_COMPILE
COMPILER = $(CROSS_COMPILE)
endif


CFLAGS = -Wall -std=c99 -D $(BOARD) -D $(CHIP) -I./inc/
LINKER = $(COMPILER) -o
LFLAGS = -Wall -I./inc/

SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm = rm -f



all:
	@echo "asddd"
#	ifndef BOARD
	#$(error There is no BOARD defined. Run "make help" for available platforms)	
	#endif
	#make_target	

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully"
		
$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
		@echo "Linking complete!"
		
	
make_target: $(OBJECTS) $(BINDIR)/$(BOARD)

	
.PHONY: help
help:
	@echo "Available boards:"
	@echo "=================="
	@echo "AM3352-SOM"
	@echo "RK3188-SOM"
	@echo ""	
	
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"
	
.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Exacutable removed!"
