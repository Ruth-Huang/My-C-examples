# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -O2  level 2 compilation optimizations
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -O2 -Wall

# the build target executable:
TARGET = pin8

all: $(TARGET)

$(TARGET): pin8.o gpio.o
	$(CC) $(CFLAGS) -o $(TARGET) pin8.o gpio.o

pin8.o: pin8.c gpio.h
	$(CC) $(CFLAGS) -c pin8.c

gpio.o: gpio.c
	$(CC) $(CFLAGS) -c gpio.c

clean:
	rm $(TARGET) *.o
