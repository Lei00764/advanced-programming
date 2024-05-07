/* 2053932 ��� ���� */
/* 2150858 ������ 2151474 ����͢ 2154275 ���� 1850511 �Ž��� 2152118 ʷ���� 2150806 ����Դ 1952099 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
 * @return (i, j) ��Χ�׵ĸ���
 */
int Find(char arr[12][28], int i, int j)
{
	int count = 0;  // ͳ����Χ����
	
	if (arr[i - 1][j - 1] == '*')  // ����
		count++;
	if (arr[i][j - 1] == '*')      // ��
		count++;
	if (arr[i + 1][j - 1] == '*')  // ����
		count++;
	if (arr[i - 1][j] == '*')      // ��
		count++;
	if (arr[i + 1][j] == '*')      // ��
		count++;
	if (arr[i - 1][j + 1] == '*')  // ����
		count++;
	if (arr[i][j + 1] == '*')      // ��
		count++;
	if (arr[i + 1][j + 1] == '*')  // ����
		count++;
	
	return count;
}

int main()
{	
	char arr[12][28];
	int all_count = 0;  // ͳ���׵ĸ���
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
			scanf("%c", &w);  // ���ո�
			if (j == 26)
				scanf("%c", &w);  // ���س�
			if (arr[i][j] == '*')
				all_count++;
		}
	}

	if (all_count != 50)
	{
		printf("����1\n");
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
				int count = Find(arr, m, n);  // (m, n)�����׵�����
				if (count + '0' != arr[m][n])
				{
					printf("����2\n");
					return 0;
				}
			}
		}
	}
	printf("��ȷ\n");

	return 0;
}
