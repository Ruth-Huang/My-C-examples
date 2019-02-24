#include <stdio.h>
#include <stdlib.h>
#include "stat.h"

int main()
{
int i;
float num[100], avg, sdv, max, min;

for(i=0; i<100; i++) num[i] = (float)rand()/RAND_MAX;

avg = mean(num, 100);
sdv = sd(num, 100, avg);
max = mm_max(num, 100);
min = mm_min(num, 100);

for(i=0; i<100; i++) printf("%f ", num[i]);
printf("\n");
printf("The mean is %f and the sd is %f the max is %f and the min is %f\n", avg, sdv, max, min);

}
