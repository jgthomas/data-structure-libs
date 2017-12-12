#
# Compile MULTIPLE source files together. 
#
# Especially useful when multiple, separate source files
# all draw on a shared file of, say, utility functions
#
# EXAMPLE:
#
# shared set of functions: utils.c
# two source files: one.c, two.c
# 
# command: make one 
# output: an executable built with one.c and utils.c, and
# one.o and utils.o
#
# command: make
# output: two executables (one.c + utils.c) and (two.c with utils.c), 
# plus one.o two.o and utils.o
#
# If utils.c remains unchanged, then it does not need to be
# recompiled for each project or source file that uses it.
#


#--------------COMPILER--------------#

# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g        adds debugging information to the executable file
#  -Wall     turns on most, but not all, compiler warnings
#  -Wextra 
#  -Werror   treat errors as warnings, and refuse to compile
CFLAGS  = -g -Wall -Wextra -Werror


#--------------FILES--------------#

EXECUTABLES = demo_linear_binary_search \
			  demo_bubble_sort \
			  demo_selection_sort \
			  demo_insertion_sort \
			  demo_counting_sort \
			  demo_radix_sort \
			  demo_bucket_sort

SHARED = demo_algorithms_shared.o


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
# Build all targets with their shared files
# or build any individually
all: $(EXECUTABLES)

demo_linear_binary_search: demo_linear_binary_search.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_linear_binary_search.o -o demo_linear_binary_search

demo_bubble_sort: demo_bubble_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_bubble_sort.o -o demo_bubble_sort

demo_selection_sort: demo_selection_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_selection_sort.o -o demo_selection_sort

demo_insertion_sort: demo_insertion_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_insertion_sort.o -o demo_insertion_sort

demo_counting_sort: demo_counting_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_counting_sort.o -o demo_counting_sort

demo_radix_sort: demo_radix_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_radix_sort.o -o demo_radix_sort

demo_bucket_sort: demo_bucket_sort.o $(SHARED)
	$(CC) $(CFLAGS) $(SHARED) demo_bucket_sort.o -o demo_bucket_sort

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# make clean
#
# delete all object files and executables
clean:
	$(RM) $(EXECUTABLES) *.o


# make test
#
# list all executables build with targets set up and 
# the source files they share 
test:
	@echo "EXECUTABLES = ${EXECUTABLES}"
	@echo "SHARED = ${SHARED}"
