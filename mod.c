#include <stdio.h>

int main()
{
    int ec_col = 8;
    int L = 16;
    int h = 15;
    int y;
    int y1;
    y = L - 3*(h - ec_col/3);
    y1 = L - 3*h + ec_col;
    printf("%d\n, %d\n", y, y1);
    return 0;
}