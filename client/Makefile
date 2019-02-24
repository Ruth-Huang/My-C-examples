# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -O2  level 2 compilation optimizations
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -O2 -Wall

# the build target executable:
TARGET = client

all: $(TARGET)

$(TARGET): client.o client_api.o gpio.o
	$(CC) $(CFLAGS) -o $(TARGET) client.o client_api.o gpio.o

client.o: client.c client_api.h
	$(CC) $(CFLAGS) -c client.c

client_api.o: client_api.c
	$(CC) $(CFLAGS) -c client_api.c

gpio.o: gpio.c gpio.h
	$(CC) $(CFLAGS) -c gpio.c

clean:
	rm $(TARGET) *.o
