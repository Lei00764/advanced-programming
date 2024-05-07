/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int num;
	scanf("%d", &num);
	int gewei = num % 10;
	int shiwei = (num / 10) % 10;
	int baiwei = (num / 100) % 10;
	int qianwei = (num / 1000) % 10;
	int wanwei = (num / 10000) % 10;
	printf("万位 : %d\n", wanwei);
	printf("千位 : %d\n", qianwei);
	printf("百位 : %d\n", baiwei);
	printf("十位 : %d\n", shiwei);
	printf("个位 : %d\n", gewei);
	return 0;
}
