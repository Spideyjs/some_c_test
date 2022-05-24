#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 255

int table[256];  //正表数组，下标就是生成元g的指数，取值范围为 [0, 254]。下标对应元素就是g^k得到的多项式值。取值范围为[1, 255]。
int arc_table[256]; //反表数组 下标就是g^k得到的多项式值，取值范围为 [1, 255]。下标对应的元素就是生成元g 的指数，取值范围为 [0, 254]。
int inverse_table[256]; //逆表数组 下标值和下标对应元素的值互为逆元，取值范围都是 [1, 255]。

void juzhen1(int n); //生成信息位矩阵数组
void juzhen2(int m); //生成范德蒙德矩阵数组，固定3列

int a[max][max];
int b[1][max];
int c[1][max];

int mul(int x, int y); //相乘函数
void juzhencheng(int k);  //生成冗余位函数




void main()
{
	int i;

	table[0] = 1;//g^0
	for (i = 1; i < 255; ++i)//生成元为x，对应本原多项式x^8 + x^4 + x^3 + x^2 + 1。
	{
		//下面是table[i] = table[i-1] * x
		table[i] = table[i - 1] << 1;

		//最高指数已经到了8，需要模上m(x)
		if (table[i] & 0x100)
		{
			table[i] ^= 0x11D;//x11D 就是 2^8 + 2^4 + 2^3 + 2^2 + 1 
		}
	}

	for (i = 0; i < 255; ++i)
		arc_table[table[i]] = i;
	/*printf("  ***");
	for (int j = 1; j < 255; j++)
	{

		printf(" %4d", arc_table[j]);
		if (j%15==0)
			printf("\n");
	}*/

	for (i = 1; i < 256; ++i)//0没有逆元，所以从1开始
	{
		int k = arc_table[i];
		k = 255 - k;
		k %= 255;//table的取值范围为 [0, 254]
		inverse_table[i] = table[k];
	}


	juzhen1(3);
	juzhen2(3);
	juzhencheng(3);
	printf("%d %d %d", c[0][0], c[0][1], c[0][2]);


}



int mul(int x, int y)
{
	if (!x || !y)
		return 0;

	return table[(arc_table[x] + arc_table[y]) % 255];
}

void juzhencheng(int k)
{
	for (int i = 0; i < k; i++)
	{
		int sum = 0;
		for (int j = 0; j < k; j++)
		{
			sum += mul(b[0][j], a[j][i]);
			
		}
		c[0][i] = sum;
	}
}

void juzhen1(int n)
{
	int m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		b[0][i] = m;
	}
}






void juzhen2(int m)
{
	int i, j;
	int d[3];

	d[0] = 1; d[1] = 2; d[2] = 4;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = pow(d[j], i);
		}
	}

	//将矩阵输出 
	//for (i = 0; i < m; i++)
	//{
	//	for (j = 0; j < 3; j++)
	//	{
	//		printf(" %d", a[i][j]);

	//	}
	//	printf("\n");
	//}
}