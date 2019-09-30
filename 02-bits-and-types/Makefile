CC=gcc
CXX=g++
PROGRAMS=01-show-bytes 02-bit-shift-and-overflow 03-constant-shift-length

all: $(PROGRAMS)

01-show-bytes: 01-show-bytes.cc
	$(CXX) $^ -o $@ $(CFLAGS)

02-bit-shift-and-overflow: 02-bit-shift-and-overflow.cc
	$(CXX) $^ -o $@ $(CFLAGS)

03-constant-shift-length: 03-constant-shift-length.cc
	$(CXX) $^ -o $@ $(CFLAGS)

clean:
	rm $(PROGRAMS)
