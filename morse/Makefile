# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -O2  level 2 compilation optimizations
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -O2 -Wall

# the build target executable:
TARGET = morse

all: $(TARGET)

$(TARGET): morse.o gpio.o
	$(CC) $(CFLAGS) -o $(TARGET) morse.o gpio.o

morse.o: morse.c gpio.h
	$(CC) $(CFLAGS) -c morse.c

gpio.o: gpio.c
	$(CC) $(CFLAGS) -c gpio.c

clean:
	rm $(TARGET) *.o
