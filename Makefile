# the compiler
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -Wextra   'extra' warnings
#  -Werror   treat errors as warnings, and refuse to compile
CFLAGS  = -g -Wall -Wextra -Werror -I${PWD}/linked_list

# Library linking
LDLIBS = 

# base_convertor
BASE_HEADERS = linked-list/node.h linked-list/utilities.h linked-list/list_funcs.h
BASE_SOURCES = base_convertor.c linked-list/utilities.c linked-list/list_funcs.c
BASE_OBJECTS := $(BASE_SOURCES:%.c=%.o)

# the build target executable:
EXECUTABLES = base_convertor

all: $(EXECUTABLES)

base_convertor: $(BASE_OBJECTS) $(BASE_HEADERS) Makefile
	$(CC) $(CFLAGS) $(BASE_OBJECTS) -o base_convertor

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
$(OBJECTS): $(HEADERS) Makefile

clean:
	$(RM) $(EXECUTABLES) *.o linked-list/*.o

test:
	@echo "EXECUTABLES = ${EXECUTABLES}"
	@echo "OBJECTS = ${BASE_OBJECTS}"
