#include <sys/time.h>

unsigned long ustime(void)
{
    struct timeval t;
    int ret;

    while ((ret = gettimeofday(&t, 0)) < 0);
    return t.tv_sec*1000000+t.tv_usec;
}
