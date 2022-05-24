#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int m = 4;
    int n = 4;
    int find_err = 0;
    unsigned int failcode = 15;
    // unsigned int test_num = 1;
    unsigned int test_num = pow(2, m + n - 1);
    int *err_list = (int *)malloc(sizeof(int) * n);
    // int *bit = (int*)malloc(sizeof(int)*(n + m));
    // memset(bit, 0, sizeof(int)*(n + m));

    // for (int i = 0; i < n + m; i++)
    // {
    //     if((test_num & failcode) && (find_err < 2))
    //     {
    //         err_list[find_err] = i;
    //         find_err++;
    //     }
    //     failcode <<= 1;
    // }
    for (int i = 0; i < m; i++)
    {
        if((test_num & failcode) && (find_err < 2))
        {
            err_list[find_err] = i;
            find_err++;
        }
        failcode <<= 1;
    }
    // if(find_err > 2)
    //     printf("error");
    // 方法2：转二进制
    // failcode = 10;
    // for (int i = 0; failcode > 0; i++)
    // {
    //     bit[n + m - 1 - i] = failcode % 2;
    //     failcode = failcode / 2;
    // }
    // for (int i = 0; i < n + m; i++)
    // {
    //     printf("%d ", bit[i]);
    // }

    for(int i = 0; i < find_err; i++)
        printf("%d ", err_list[i]);
    free(err_list);
    return 0;
}