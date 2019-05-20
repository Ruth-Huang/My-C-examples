all: light

light.o: light.c i2c_api.h Grove_DLS.h
	gcc -c light.c -O2

i2c_api.o: i2c_api.c i2c_api.h
	gcc -c i2c_api.c -O2

light: light.o i2c_api.o
	gcc -o light light.o i2c_api.o

clean:
	rm -rf *.o light
