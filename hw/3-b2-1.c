/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n");
	int num;
	scanf("%d", &num);
	int gewei = num % 10;
	int shiwei = (num / 10) % 10;
	int baiwei = (num / 100) % 10;
	int qianwei = (num / 1000) % 10;
	int wanwei = (num / 10000) % 10;
	printf("��λ : %d\n", wanwei);
	printf("ǧλ : %d\n", qianwei);
	printf("��λ : %d\n", baiwei);
	printf("ʮλ : %d\n", shiwei);
	printf("��λ : %d\n", gewei);
	return 0;
}
