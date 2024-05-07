/* 2053932 软件 雷翔 */
/* 2150858 蔡明辉 2151474 刘奕廷 2154275 颜炜骞 1850511 张江丽 2152118 史君宝 2150806 刘广源 1952099 穆祖磊 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
 * @return (i, j) 周围雷的个数
 */
int Find(char arr[12][28], int i, int j)
{
	int count = 0;  // 统计周围雷数
	
	if (arr[i - 1][j - 1] == '*')  // 左上
		count++;
	if (arr[i][j - 1] == '*')      // 上
		count++;
	if (arr[i + 1][j - 1] == '*')  // 右上
		count++;
	if (arr[i - 1][j] == '*')      // 左
		count++;
	if (arr[i + 1][j] == '*')      // 右
		count++;
	if (arr[i - 1][j + 1] == '*')  // 左下
		count++;
	if (arr[i][j + 1] == '*')      // 下
		count++;
	if (arr[i + 1][j + 1] == '*')  // 右下
		count++;
	
	return count;
}

int main()
{	
	char arr[12][28];
	int all_count = 0;  // 统计雷的个数
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 27)
			{
				arr[i][j] = '0';
				continue;
			}
			scanf("%c", &arr[i][j]);
			char w;
			scanf("%c", &w);  // 读空格
			if (j == 26)
				scanf("%c", &w);  // 读回车
			if (arr[i][j] == '*')
				all_count++;
		}
	}

	if (all_count != 50)
	{
		printf("错误1\n");
		return 0;
	}

	for (int m = 1; m < 11; m++)
	{
		for (int n = 1; n < 27; n++)
		{
			if (arr[m][n] == '*')
				continue;
			else
			{
				int count = Find(arr, m, n);  // (m, n)四周雷的数量
				if (count + '0' != arr[m][n])
				{
					printf("错误2\n");
					return 0;
				}
			}
		}
	}
	printf("正确\n");

	return 0;
}
