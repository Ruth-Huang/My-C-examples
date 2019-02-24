all: get_temp

i2c_temp.o: i2c_temp.c i2c_api.h MPU9255.h
	gcc -c i2c_temp.c -O2

i2c_api.o: i2c_api.c i2c_api.h MPU9255.h
	gcc -c i2c_api.c -O2

get_temp: i2c_temp.o i2c_api.o
	gcc -o get_temp i2c_temp.o i2c_api.o

clean:
	rm -rf *.o get_temp
