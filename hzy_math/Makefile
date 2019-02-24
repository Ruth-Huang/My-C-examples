all: stat

stat: stat.o mean.o sd.o mm.o
	gcc -o stat stat.o mean.o sd.o mm.o

stat.o: stat.c stat.h
	gcc -c stat.c

mean.o: mean.c
	gcc -c mean.c

sd.o: sd.c
	gcc -c sd.c

mm.o: mm.c
	gcc -c mm.c

clean:
	rm *.o stat
