CC=g++
CFLAGS= -c -std=c++17 -Wall
LFLAGS= -g
OFILES=   mainStdStack.o readin_return_int_stack.o prefix_sum.o
#All the .o's file that are going to be created ADD in all the .o's that are needed to

OMAIN_FILES = mainStdStack.o	readin_return_int_stack.o	prefix_sum.o
all: main

OUNIT_TEST_FILES = unit_tests.o readin_return_int_stack.o	prefix_sum.o
all: unit_test_me

main: $(OMAIN_FILES) # the main final executable  which takes all the ofiles and build the executable to run
	$(CC) $(LFLAGS) $(OMAIN_FILES) -o myMain

unit_test_me: $(OUNIT_TEST_FILES) # the main final executable  which takes all the ofiles and build the executable to run
	$(CC) $(LFLAGS) $(OUNIT_TEST_FILES) -o unit_test_all_of_me

mainStdStack.o : mainStdStack.cpp readin_return_int_stack.cpp	prefix_sum.cpp

unit_tests.o:  unit_tests.cpp readin_return_int_stack.cpp	prefix_sum.cpp

# hardcode the final executable name which is given in the `all` above
clean: 
	rm -rf *.o  a.out