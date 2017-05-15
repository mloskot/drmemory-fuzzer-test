# Builds DrFuzzTest
# Flags after http://drmemory.org/docs/page_prep.html
CC=g++
CXXFLAGS=-m32 -g -Wall

all: fuzz_me

fuzz_me: fuzz_me.o
	$(CC) $(CXXFLAGS) fuzz_me.o -o fuzz_me

fuzz_me.o: fuzz_me.cpp
	$(CC) $(CXXFLAGS) -c fuzz_me.cpp

clean:
	-rm -f fuzz_me *.o *~ core
