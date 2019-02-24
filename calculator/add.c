#include <stdio.h>
#include <stdlib.h>

int add(int x, int y){
	return x + y; 
}

int main(int argc, char *argv[]){

	int x, y, r;

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	r = add(x, y);

	printf("The addition result is %d\n", r);
}
