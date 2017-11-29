# PATHS - to search for the headers and source files
HEADERS_1 = ../../
HEADERS_2 =
HEADERS_3 = 

SOURCE_1 = ../../
SOURCE_2 = 
SOURCE_3 = 

INCLUDES = $(HEADERS_1) $(HEADERS_2) $(HEADERS_3)
SOURCE = $(SOURCE_1) $(SOURCE_2) $(SOURCE_3)

vpath %.h $(INCLUDES)
vpath %.c $(SOURCE)

# COMPILER - with flags and libraries to link
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror $(foreach dir, $(INCLUDES), -I$(dir))
LDLIBS = 

# EXECUTABLE - the final binary file
BUILD_DIR = ./build
BIN = base_convertor
TARGET = $(BUILD_DIR)/$(BIN)

# FILES
PWD_HEADERS := $(wildcard *.h)
PWD_SOURCES := $(wildcard *.c)
HEADERS = $(PWD_HEADERS) data_structures/linked_list.h tools/convertors.h tools/printing.h
SOURCES = $(PWD_SOURCES) data_structures/linked_list.c tools/convertors.c tools/printing.c
OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)
DEPENDS = $(OBJECTS:%.o=%.d)

# TARGETS
.PHONY: all clean rebuild test

all: $(TARGET)

$(TARGET): $(OBJECTS) $(HEADERS) Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(TARGET)

-include $(DEPENDS)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)

rebuild: clean $(TARGET)

test:
	@echo "EXECUTABLES = ${TARGET}"
	@echo "OBJECTS = ${OBJECTS}"
