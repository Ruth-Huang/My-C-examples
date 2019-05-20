#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "i2c_api.h"
#include "Grove_DLS.h"
#include "time.h"
#include "morse.h"

#define LT 100

unsigned short getLight(int fd)
{
        u8 byte1 = read_byte(fd, DEVICE_ADDRESS, DATA0HIGH);
        u8 byte2 = read_byte(fd, DEVICE_ADDRESS, DATA0LOW);

        if(byte1 < 0 || byte2 < 0)
        {
                printf("error reading light sensor.\n");
                exit(1);
        }

        unsigned short result = (byte1 << 8) | byte2;

        return result;
}

void powerUp(int fd)
{
	write_byte(fd, DEVICE_ADDRESS, CONTROL, 0x3);
}

int search_code(int a[]){
	int done = 0;
	int j,i;
	for(j=0; j<37; j++){
	  for(i=0; i<5; i++){
	    if(a[i] != morsecode[j][i])
	      break;
	    if(a[i] == -1) { done = 1; break;}
	  }
	  if(done == 1 || i==5) return j;
	}
	return -1;
}

int main(int argc, char** argv)
{
	int fd, mc[6], ai, index, i, ft;
	unsigned short light;
	unsigned long t1, t2, t;

	fd = open_i2c();
	powerUp(fd);

	t1 = t2 = ai = 0;
	ft = 1;
	for(i=0;i<5;i++) mc[i] = -1;
	while(1){	
	  light = getLight(fd);
	  if(light > LT) {
	    t1 = ustime();
	    while (light > LT) light = getLight(fd);
	    t2 = ustime();
	    t = t2 - t1;
	    //printf("The reading from the light sensor is %u. and over threshold time is %lu\n", light, t);
	    if(t > 1000000){ 
		mc[ai] = 1; ai++;
		//printf("long\n");
	    } else { 
		//printf("short\n");
	  	mc[ai] = 0; ai++;
	   }
	  }  else {
	    t1 = ustime();
	    while(light <= LT) light = getLight(fd);
	    t2 = ustime();
	    t = t2 - t1;
	    //printf("The gap time is %lu\n", t);
	    if(t > 2000000 && t <= 3000000) {
		//printf("letter finished: ");
		mc[ai] = -1;
		ai = 0;
		index = search_code(mc);
		if(index < 0 && ft == 1) {ft = 0;} 
		else if (index < 0 && ft == 0) printf("Wrong letter\n");
		else if(index == 36) printf("\n");
		else{
		  if(index >= 26) 
		    printf("%c\n",(index - 26) + '0');
	    	  else
		    printf("%c\n",index + 'a');
	       } 
	   }
	    else if(t > 3000000){ 
                mc[ai] = -1;
                ai = 0;
                index = search_code(mc);
                if(index < 0) {if(ft==1) {ft = 0;} else printf("Wrong letter\n");}
		else if(index == 36) printf("\n");
                else{
                  if(index >= 26) 
                    printf("%c\n",(index - 26) + '0');
                  else
                    printf("%c\n",index + 'a');
                }
		printf(" \n");
	    }

	  }
	//usleep(50000);
	}
}

