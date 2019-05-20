all: decode

decode.o: decode.c i2c_api.h Grove_DLS.h
	gcc -c decode.c -O2

i2c_api.o: i2c_api.c i2c_api.h
	gcc -c i2c_api.c -O2

time.o: time.c time.h
	gcc -c time.c -O2

decode: decode.o i2c_api.o time.o
	gcc -o decode decode.o i2c_api.o time.o

clean:
	rm -rf *.o decode
