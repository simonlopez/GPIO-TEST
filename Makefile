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

# Force user to supply target
ifdef TARGET
TARGET	=	$(TARGET)
else
$(error No target is defined)
endif

ifdef CC
COMPILER = $(CC)
else
COMPILER = gcc
endif

CFLAGS	=	-Wall -std=c99 -I./inc/
LINKER	=	$(COMPILER) -o
LFLAGS	=	-Wall -I./inc/

SRCDIR	=	src
INCDIR	=	inc
OBJDIR	=	obj
BINDIR	=	bin

SOURCES		:=	$(wildcard $(SRCDIR)/*.c)
INCLUDES	:=	$(wildcard $(INCDIR)/*.h)
OBJECTS		:=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm			=	rm -f

	 

all: $(OBJECTS) $(BINDIR)/$(TARGET)
	

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully"

$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
		@echo "Linking complete!"
		
	
	
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"
	
.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Exacutable removed!"

