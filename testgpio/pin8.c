#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "gpio.h"

int main()
{
	setup_io();

	while(1)
	{
	  write_to_gpio(1, 8);
	  usleep(1000000);
	  write_to_gpio(0, 8);
	  usleep(1000000);
	}

}
