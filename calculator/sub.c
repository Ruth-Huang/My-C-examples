#include <stdio.h>
#include <stdlib.h>

int sub(int x, int y){
	return x - y; 
}

int main(int argc, char *argv[]){

	int x, y, r;

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	r= sub(x, y);

	printf("The subtraction result is %d\n", r);
}
