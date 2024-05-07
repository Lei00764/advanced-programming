/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double num;
	scanf("%lf", &num);
	int shiyi = (int)(num / 1000000000.0);
	double num_remove_shiyi = num - shiyi * 1000000000.0;
	unsigned int num_remove_shiyi_zhengshu = (unsigned int)num_remove_shiyi;
	double num_xiaoshu = num_remove_shiyi - num_remove_shiyi_zhengshu;
	printf("十亿位 : %d\n", shiyi);
	printf("亿位   : %d\n", num_remove_shiyi_zhengshu / 100000000 % 10);
	printf("千万位 : %d\n", num_remove_shiyi_zhengshu / 10000000 % 10);
	printf("百万位 : %d\n", num_remove_shiyi_zhengshu / 1000000 % 10);
	printf("十万位 : %d\n", num_remove_shiyi_zhengshu / 100000 % 10);
	printf("万位   : %d\n", num_remove_shiyi_zhengshu / 10000 % 10);
	printf("千位   : %d\n", num_remove_shiyi_zhengshu / 1000 % 10);
	printf("百位   : %d\n", num_remove_shiyi_zhengshu / 100 % 10);
	printf("十位   : %d\n", num_remove_shiyi_zhengshu / 10 % 10);
	printf("圆     : %d\n", num_remove_shiyi_zhengshu / 1 % 10);
	printf("角     : %d\n", (int)((num_xiaoshu + 0.005) * 10));
	printf("分     : %d\n", (int)((num_xiaoshu + 0.005) * 100) % 10);
	return 0;
}