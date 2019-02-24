#ifndef MPU9255_H
#define MPU9255_H

#define 	DEVICE_ADDRESS    		0x68
#define         MAG_ADDRESS       		0x0C

#define    	GYRO_FULL_SCALE_250_DPS    	0x00
#define    	GYRO_FULL_SCALE_500_DPS    	0x08
#define    	GYRO_FULL_SCALE_1000_DPS   	0x10
#define    	GYRO_FULL_SCALE_2000_DPS   	0x18

#define    	ACC_FULL_SCALE_2_G       	0x00
#define    	ACC_FULL_SCALE_4_G        	0x08
#define    	ACC_FULL_SCALE_8_G        	0x10
#define    	ACC_FULL_SCALE_16_G       	0x18

#define         CONFIG         			0x1A
#define         GYRO_CONFIG     		0x1B
#define         ACC_CONFIG      		0x1C
#define         INT_PIN_CFG     		0x37
#define         PWR_MGMT_1      		0x6B
#define         PWR_MGMT_2      		0x6C
#define         MAG_CNTL1       		0x0A
#define         MAG_ST1         		0x02
#define         MAG_ST2         		0x09

// Data registers to access
#define		TEMPERATURE_DATA_REG		0x41
#define    	ACC_DATA_REG          		0x3B
#define         GYRO_DATA_REG         		0x43
#define         MAG_DATA_REG          		0x03

#define    	FIFO_ENABLE       		0x23

// Resolution for GYRO_FULL_SCALE_2000_DPS
#define 	GYRO_RESOLUTION         	0.0610351

// Resolution for ACC_FULL_SCALE_2_G
#define 	ACC_RESOLUTION          	0.0000610351

// Resolution for MAGNETOMETER (-4800, 4800) microT
#define 	MAG_RESOLUTION          	1.4994


#endif
