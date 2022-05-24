#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>

typedef unsigned char u8;

void random_arr(u8 **a, int k, int n, u8 min_num, u8 max_num);  // 生成单个随机数据，a为待生成数据数组，k为行大小，n为行数组大小，后两个为上下限


int main()
{
    int row = 8;
    int col = 36;
    u8 min_num = 0;
    u8 max_num = 255;

    u8 **data = (u8**)malloc(sizeof(u8*) * row);
    for(int i = 0; i < row; i++)
    {
        data[i] = (u8*)malloc(sizeof(u8) * col);
    }
    random_arr(data, row, col, min_num, max_num);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", data[i][j]);
        printf("\n");
    }
    for(int i = 0; i < row; i++)
        free(data[i]);
    free(data);
    return 0;
}


void random_arr(u8 **a, int k, int n, u8 min_num, u8 max_num) 
{
    int i = 0;
    int j = 0;
    srand(time(0));  //设置时间种子
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < n; j++)
        {
            *(*(a+i) + j) = rand() % (max_num - min_num + 1) + min_num;
        }
    }
}