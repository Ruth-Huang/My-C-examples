#include <stdio.h>
#include <stdlib.h>
#include "i2c_api.h"
#include "MPU9255.h"

float getTemperature(int fd)
{
        u8 byte1 = read_byte(fd, DEVICE_ADDRESS, TEMPERATURE_DATA_REG);
        u8 byte2 = read_byte(fd, DEVICE_ADDRESS, TEMPERATURE_DATA_REG + 1);

        if(byte1 < 0 || byte2 < 0)
        {
                printf("error reading temperature.\n");
                exit(1);
        }

        short result = (byte1 << 8) | byte2;

        return ((float) result - 21.0) / 333.87 + 21.0;
}


int main(int argc, char** argv)
{
	int fd, serversocket, clientsocket, n;
	float temperature;

	fd = open_i2c();

while(1){
	temperature = getTemperature(fd);

	printf("The temperature is %f degrees.\n", temperature);
	usleep(50000);
	}
}

