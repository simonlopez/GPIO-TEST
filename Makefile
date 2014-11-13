#-----------------------------------------------------------
#Generic Makefile
#
# Author: Stefan Mavrodiev @ Olimex LTD
# Date	: 2013-06-27
#
# Changelog:
# 2013-06-27	-	Initial release
# 15 OCT 2014	-	Modified for RK3188
#
#-----------------------------------------------------------

TARGET	=	RK3188-SOM-GPIO
CC		=	gcc
CFLAGS	=	-Wall -std=c99 -I./inc/
LINKER	=	$(CC) -o
LFLAGS	=	-Wall -I./inc/

SRCDIR	=	src
INCDIR	=	inc
OBJDIR	=	obj
BINDIR	=	bin

SOURCES		:=	$(wildcard $(SRCDIR)/*.c)
INCLUDES	:=	$(wildcard $(INCDIR)/*.h)
OBJECTS		:=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm			=	rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
		@echo "Linking complete!"
		
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully"
	
		
	
	
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"
	
.PHONE: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Exacutable removed!"

