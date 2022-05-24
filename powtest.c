#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i = 0;
    for(i = 1; i <= 7; i++)
        printf("%d ", (int)pow(2, i));
    return 0;
}