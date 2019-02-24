#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/io.h>
#include "gpio.h"

int main(int argc, char **argv) {
  int n;

  if(argc != 2) {
        printf("Usage: setgpio <numbers either 0 or 1>\n");
        exit(0);
  }

  setup_io();
  setgpiofunc(8, 1);

  n = atoi(argv[1]);
  if(n < 0 || n > 1) {
        printf("The number is invalid\n");
        exit(0);
  }

    write_to_gpio(n, 8);
//for(i=0;i<10;i++) do_sth();
/*
i=0;
while(i<10) {
do_sth();
i++; // i = i + 1;
}
*/
while(1){
write_to_gpio(0, 8);
usleep(1000000);
write_to_gpio(1, 8);
usleep(1000000);
}


  return EXIT_SUCCESS;
}


