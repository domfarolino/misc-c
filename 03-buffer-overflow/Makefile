CXX=gcc
PROGRAMS=01-buffer-layout 02-buffer-overflow
CFLAGS=-g -m32 -fno-stack-protector

all: $(PROGRAMS)

01-buffer-layout: 01-buffer-layout.c
	$(CXX) $^ -o $@ $(CFLAGS)

02-buffer-overflow: 02-buffer-overflow.c
	$(CXX) $^ -o $@ $(CFLAGS)

clean:
	rm -r $(PROGRAMS) *.dSYM
