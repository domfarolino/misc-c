CC=gcc
CXX=g++
PROGRAMS=01-array-by-reference 02-function-pointers 03-array-of-fp-by-reference

all: $(PROGRAMS)

01-array-by-reference: 01-array-by-reference.cpp
	$(CXX) $^ -o $@ $(CFLAGS)

02-function-pointers: 02-function-pointers.c
	$(CC) $^ -o $@ $(CFLAGS)

03-array-of-fp-by-reference: 03-array-of-fp-by-reference.cpp
	$(CXX) $^ -o $@ $(CFLAGS)

clean:
	rm $(PROGRAMS)
