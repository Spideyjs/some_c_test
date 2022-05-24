#include <stdio.h>
#include <stdlib.h>

#  define GT_L3_CACHE  768*1024	/* some number > last level cache */
#  define TEST_LEN(m)  ((GT_L3_CACHE / m) & ~(64-1))  // intel定义单个数据块大小的方式
#  define TEST_LENN(m)  (GT_L3_CACHE / m)  // 在如上的方式去掉后面的一部分

int main()
{
    int m = 12;
    printf("intel的定义方式: %d\n", TEST_LEN(m)/(1024));
    printf("不考虑后面的与操作和取反操作: %d", TEST_LENN(m)/(1024));  // 对比得到的结果
    return 0;
}