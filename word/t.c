#include <stdio.h>

int main()
{
    FILE *f;
    char x[1024];
    f = fopen("h.txt", "r");


    /* assumes no word exceeds length of 1023 */
    while (fscanf(f, " %20s", x) == 1) {
        puts(x);
    }


}


