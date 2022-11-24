# makefile for testing shared object file
CC = gcc
CFLAG = -Wall -o
PATH_INCLUDE = rtklib_src_test/src
PATH_SHARE_LIBRARY = -Lrtklib_src_test
FLAG_SHARE_LIBRARY = -lrtklib_test_without_java -lm -lpthread
OBJECT = main_implement.o

#test_implementation: main_implement.c \
		$(PATH_INCLUDE)/share_object_function.h
#	$(CC) $(CFLAG) test_implementation main_implement.c \
		$(FLAG_SHARE_LIBRARY) \
		$(PATH_SHARE_LIBRARY)

test_implementation: $(OBJECT)
	$(CC) $(CFLAG) test_implementation $(OBJECT) \
		$(PATH_SHARE_LIBRARY) $(FLAG_SHARE_LIBRARY)

main_implement.o: main_implement.c \
	$(PATH_INCLUDE)/rtklib.h
	$(CC) -c main_implement.c	

clean:
	rm test_implementation $(OBJECT)
