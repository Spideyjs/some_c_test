#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 255

int table[256];  //�������飬�±��������Ԫg��ָ����ȡֵ��ΧΪ [0, 254]���±��ӦԪ�ؾ���g^k�õ��Ķ���ʽֵ��ȡֵ��ΧΪ[1, 255]��
int arc_table[256]; //�������� �±����g^k�õ��Ķ���ʽֵ��ȡֵ��ΧΪ [1, 255]���±��Ӧ��Ԫ�ؾ�������Ԫg ��ָ����ȡֵ��ΧΪ [0, 254]��
int inverse_table[256]; //������� �±�ֵ���±��ӦԪ�ص�ֵ��Ϊ��Ԫ��ȡֵ��Χ���� [1, 255]��

void juzhen1(int n); //������Ϣλ��������
void juzhen2(int m); //���ɷ����ɵ¾������飬�̶�3��

int a[max][max];
int b[1][max];
int c[1][max];

int mul(int x, int y); //��˺���
void juzhencheng(int k);  //��������λ����




void main()
{
	int i;

	table[0] = 1;//g^0
	for (i = 1; i < 255; ++i)//����ԪΪx����Ӧ��ԭ����ʽx^8 + x^4 + x^3 + x^2 + 1��
	{
		//������table[i] = table[i-1] * x
		table[i] = table[i - 1] << 1;

		//���ָ���Ѿ�����8����Ҫģ��m(x)
		if (table[i] & 0x100)
		{
			table[i] ^= 0x11D;//x11D ���� 2^8 + 2^4 + 2^3 + 2^2 + 1 
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

	for (i = 1; i < 256; ++i)//0û����Ԫ�����Դ�1��ʼ
	{
		int k = arc_table[i];
		k = 255 - k;
		k %= 255;//table��ȡֵ��ΧΪ [0, 254]
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

	//��������� 
	//for (i = 0; i < m; i++)
	//{
	//	for (j = 0; j < 3; j++)
	//	{
	//		printf(" %d", a[i][j]);

	//	}
	//	printf("\n");
	//}
}