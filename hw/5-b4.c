/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{	
	printf("������ɼ������1000��������-1����\n");
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
	int n = i; // ������ʵ���� ������ -1

	// ��ӡ���������
	printf("���������Ϊ:\n");
	for (int j = 0; j < n; j++)
	{ 
		if (j > 0 && j % 10 == 0)
			printf("\n");
		printf("%d ", a[j]);
	}
	printf("\n");

	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	int sum[101] = {0};  // �±��ʾ���� ���ֵ��ʾ�÷����ĸ���
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