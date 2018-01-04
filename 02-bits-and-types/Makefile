CC=gcc
CXX=g++
PROGRAMS=01-show-bytes 02-bit-shift-and-overflow

all: $(PROGRAMS)

01-show-bytes: 01-show-bytes.cpp
	$(CXX) $^ -o $@ $(CFLAGS)

02-bit-shift-and-overflow: 02-bit-shift-and-overflow.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm $(PROGRAMS)
