#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/io.h>
#include "morse.h"
#include "gpio.h"


void long_code()
{
    write_to_gpio(1, 8);
    usleep(1500000);
    write_to_gpio(0, 8);
    usleep(1500000);
}

void short_code()
{
    write_to_gpio(1, 8);
    usleep(500000);
    write_to_gpio(0, 8);
    usleep(1500000);
}

void gap()
{
    usleep(1500000);
}

void long_gap()
{
    usleep(2500000);
}

int main(int argc, char *argv[])
{
int i, j, k;
char c;

  if(argc != 2) {
    printf("Usage: %s <message>\n", argv[0]);
    exit(0);
  }

  setup_io();
  setgpiofunc(8, 1);

  c = argv[1][0];
  k = 0;
  while(c!=0){
    if(c==' ') { long_gap(); k++; c = argv[1][k]; continue; }
    if(c >= 48 && c <= 57)
       j = (c - 48) + 26;
    else if(c >= 65 && c <= 90)
       j = c - 65;
    else if(c >= 97 && c <= 122)
       j = c - 97;
    else {
	printf("Wrong character: %c\n", c);
	exit(0);
    }
    printf("The morse code for letter %c is:\n", c);
    for(i=0;i<5;i++){
       if(morsecode[j][i] == 1) {printf("long \n"); long_code();}
       if(morsecode[j][i] == 0) {printf("short \n"); short_code();}
       if(morsecode[j][i] == -1) {break;}
    }
    gap();
    k++;
    c = argv[1][k];
  }
  long_code();
  short_code();
  long_code();
  short_code();
  long_code();
return 0;
}
