#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/io.h>
#include "gpio.h"

int main(int argc, char **argv) {
  int n, on, pressed;

  if(argc != 1) {
        printf("Usage: getgpio \n");
        exit(0);
  }

  setup_io();
  setgpiofunc(7, 0);
  setgpiofunc(8, 1);
  on = 0;
  pressed = 0;

while(1)
{
  n = read_from_gpio(7);
  //printf("The pin value is %d\n", n);
  if(n == 0) {
	pressed = 1;
  }
  if(n == 1 && pressed == 1){
	if(on == 1) on = 0;
	else on = 1;
  }


if(on == 1){
    write_to_gpio(1, 8);
   } else {
    write_to_gpio(0, 8);
    }
}
  return EXIT_SUCCESS;
}


