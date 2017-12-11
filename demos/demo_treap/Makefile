# MY HEADERS - paths to search for includes
HEADERS_1 = ../../
HEADERS_2 = 
HEADERS_3 = 

# MY SOURCES - paths to search for source files
SOURCE_1 = ../../
SOURCE_2 = 
SOURCE_3 = 

# HEADER FILES
INCLUDES = $(HEADERS_1) $(HEADERS_2) $(HEADERS_3)

# SOURCE FILES
SOURCE = $(SOURCE_1) $(SOURCE_2) $(SOURCE_3)

# PATHS - to search for the wildcarded filetypes
vpath %.h $(INCLUDES)
vpath %.c $(SOURCE)

# DIRECTORIES
BUILD_DIR = ./build

# COMPILER
CC = gcc

# FLAGS
CFLAGS = -g -Wall -Wextra -Werror $(foreach dir, $(INCLUDES), -I$(dir))

# LIBRARY LINKING
LDLIBS = 

# EXECUTABLE
BIN = demo_treap

TARGET = $(BUILD_DIR)/$(BIN)

# FILES
PWD_HEADERS := $(wildcard *.h)
PWD_SOURCES := $(wildcard *.c)
HEADERS = $(PWD_HEADERS) tools/comparison.h tools/printing.h tools/get_input.h data_structures/treap.h
SOURCES = $(PWD_SOURCES) tools/comparison.c tools/printing.c tools/get_input.c data_structures/treap.c
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
