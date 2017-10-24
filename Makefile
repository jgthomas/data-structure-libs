# MY LIBRARIES
# re-useable code
LLIST = linked-list

# HEADER FILES
# where to search
INCLUDES = ${PWD}/${LLIST}

# COMPILER
CC = gcc

# FLAGS
CFLAGS = -g -Wall -Wextra -Werror $(foreach dir, $(INCLUDES), -I$(dir))

# LIBRARY LINKING
LDLIBS = 

# TARGETS
EXECUTABLES = base_convertor

all: $(EXECUTABLES)

BASE_HEADERS = ${LLIST}/node.h ${LLIST}/utilities.h ${LLIST}/list_funcs.h
BASE_SOURCES = base_convertor.c ${LLIST}/utilities.c ${LLIST}/list_funcs.c
BASE_OBJECTS := $(BASE_SOURCES:%.c=%.o)

base_convertor: $(BASE_OBJECTS) $(BASE_HEADERS) Makefile
	$(CC) $(CFLAGS) $(BASE_OBJECTS) -o base_convertor

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
$(BASE_OBJECTS): $(BASE_HEADERS) Makefile

clean:
	$(RM) $(EXECUTABLES) *.o linked-list/*.o

test:
	@echo "EXECUTABLES = ${EXECUTABLES}"
	@echo "OBJECTS = ${BASE_OBJECTS}"
