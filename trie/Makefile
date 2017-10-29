# MY HEADERS - paths to search for includes
HEADERS_1 = 
HEADERS_2 = 
HEADERS_3 = 

# MY SOURCES - paths to search for source files
SOURCE_1 = 
SOURCE_2 = 
SOURCE_3 = 

# HEADER FILES
INCLUDES = $(HEADERS_1) $(HEADERS_2) $(HEADERS_3)

# SOURCE FILES
SOURCE = $(SOURCE_1) $(SOURCE_2) $(SOURCE_3)

# PATHS
vpath %.h $(INCLUDES)
vpath %.c $(SOURCE)

# COMPILER
CC = gcc

# FLAGS
CFLAGS = -g -Wall -Wextra -Werror $(foreach dir, $(INCLUDES), -I$(dir))

# LIBRARY LINKING
LDLIBS = 

# EXECUTABLE
TARGET = trie_demo

# FILES
HEADERS = trienode.h trie_funcs.h
SOURCES = trie_funcs.c
OBJECTS := $(SOURCES:%.c=%.o)

# TARGETS
.PHONY: all clean rebuild test

all: $(TARGET)

$(TARGET): $(OBJECTS) $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)

rebuild: clean $(TARGET)

test:
	@echo "EXECUTABLES = ${TARGET}"
	@echo "OBJECTS = ${OBJECTS}"
