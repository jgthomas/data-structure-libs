# MY LIBRARIES
LLIST = linked-list


# HEADER FILES
INCLUDES = ${PWD}/${LLIST}


# COMPILER
CC = gcc


# FLAGS
CFLAGS = -g -Wall -Wextra -Werror $(foreach dir, $(INCLUDES), -I$(dir))


# LIBRARY LINKING
LDLIBS = 


# EXECUTABLES
BCONV = base_convertor
BCONV_HEADERS = ${LLIST}/node.h ${LLIST}/utilities.h ${LLIST}/list_funcs.h
BCONV_SOURCES = base_convertor.c ${LLIST}/utilities.c ${LLIST}/list_funcs.c
BCONV_OBJECTS := $(BCONV_SOURCES:%.c=%.o)

EXECUTABLES = $(BCONV)


# TARGETS
.PHONY: all clean test

all: $(EXECUTABLES)

$(BCONV): $(BCONV_OBJECTS) $(BCONV_HEADERS) Makefile
	$(CC) $(CFLAGS) $(BCONV_OBJECTS) -o $(BCONV)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(EXECUTABLES) *.o ${LLIST}/*.o

test:
	@echo "EXECUTABLES = ${EXECUTABLES}"
	@echo "OBJECTS = ${BCONV_OBJECTS}"


# DEPENDENCIES
$(BCONV_OBJECTS): $(BCONV_HEADERS) Makefile
