#
# Compile ALL source files in the directory 
# into ONE executable via creating object files 
# for each of those source files.
#
# Only those source files that have been changed 
# are re-compiled, as the object files for other
# source files already exist.
#
# EXAMPLE:
#
# sources: one.c, two.c, three.c
# command: make
# output: one.o, two.o, three.o, executable
#

#--------------COMPILER--------------#

# The compiler to use
CC = gcc

# Compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -Wextra  'extra' warnings
#  -Werror   treat errors as warnings, and refuse to compile
CFLAGS  = -g -Wall -Wextra -Werror

# Library linking
LDLIBS = 


#--------------FILES--------------#

# The name of the final executable
TARGET = demo

# Get all c files in the dir and their names as
# objects files
HEADERS := $(wildcard *.h)
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:%.c=%.o)


#--------------TARGETS--------------#

# Phony are targets that are not associated with filenames.
#
# Normally, make only runs if the file targets have 
# changed. Phony targets are always out-of-date and
# so always run when called. Often 'all' would also be
# a phony target, but this makefile is designed to combine 
# all files, so we don't want it to run if no changes have 
# occurred.
.PHONY: clean test

# make
#
# 1. Build all the individual object files from source
# 2. Combine those object files into the final executable
all: $(TARGET)

$(TARGET): $(OBJECTS) $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
#
# Files on which the object files depend: typically header
# files and makefiles. This ensures that object files are
# re-compiled when any of these dependencies are changed.
$(OBJECTS): $(HEADERS) Makefile

# make clean
#
# delete all object files and executables
clean:
	$(RM) $(TARGET) $(OBJECTS)

# make test
#
# list all source and object files
test:
	@echo "SOURCES = ${SOURCES}"
	@echo "OBJECTS = ${OBJECTS}"
