/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{	
	printf("请输入成绩（最多1000个），以-1结束\n");
	int a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == -1)
			break;
		a[i] = num;
	}
	int n = i; // 数组真实长度 不包括 -1

	// 打印输入的数组
	printf("输入的数组为:\n");
	for (int j = 0; j < n; j++)
	{ 
		if (j > 0 && j % 10 == 0)
			printf("\n");
		printf("%d ", a[j]);
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");
	int sum[101] = {0};  // 下标表示分数 存的值表示该分数的个数
	for (int k = 0; k < n; k++)
	{
		sum[a[k]]++; 
	}

	for (int w = 100; w >= 0; w--)
	{
		if (sum[w] > 0)
			printf("%d %d\n", w, sum[w]);
	}

	return 0;
}