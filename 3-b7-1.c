/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入找零值：\n");
	double money;
	int wushi = 0, ershi = 0, shi = 0, wu = 0, yi = 0, wujiao = 0, yijiao = 0, wufen = 0, liangfen = 0, yifen = 0;
	scanf("%lf", &money);
	if (money >= 50)
	{
		wushi += 1;
		money -= 50;
	}
	int k = (int)(money / 10); // 目的：取整
	if (k == 4)
	{
		ershi = 2;
		money -= 2 * 20;
	}
	if (k == 3)
	{
		ershi = 1;
		shi = 1;
		money -= 30;
	}
	if (k == 2)
	{
		ershi = 1;
		money -= 20;
	}
	if (k == 1)
	{
		shi = 1;
		money -= 10;
	}
	// 此时 money在 0~10 之间 不包括10
	if (money >= 5)
	{
		wu = 1;
		money -= 5;
	}
	// 此时 money在 0~5 之间 不包括5
	if (money > 0 && money < 5)
	{
		yi = (int)(money / 1);
		money -= yi;
	}
	// 此时 money在 0~1 之间 不包括1 
	money = (int)((money + 0.005) * 100); // 扩大100倍， 此时money在 0~100 之间
	if (money >= 50)
	{
		wujiao = 1;
		money -= 50;
	}
	// 此时 money在 0~0.5 之间 不包括0.5
	if (money >= 10 && money < 50)
	{
		yijiao = (int)(money / 10);
		money -= yijiao * 10;
	}
	// 此时 money在 0~0.1 之间 不包括0.1
	if (money > 5)
	{
		wufen = 1;
		money -= 5;
	}
	// 此时 money在 0~0.0.5 之间 不包括0.05
	if (money >= 4)
	{
		liangfen = 2;
		money -= 4;
	}
	if (money >= 2)
	{
		liangfen = 1;
		money -= 2;
	}
	if (money == 1)
	{
		yifen = 1;
	}
	int sum = wushi + ershi + shi + wu + yi + wujiao + yijiao + wufen + liangfen + yifen;
	printf("共%d张找零，具体如下：\n", sum);
	if (wushi != 0)
		printf("50元 : %d张\n", wushi);
	if (ershi != 0)
		printf("20元 : %d张\n", ershi);
	if (shi != 0)
		printf("10元 : %d张\n", shi);
	if (wu != 0)
		printf("5元  : %d张\n", wu);
	if (yi != 0)
		printf("1元  : %d张\n", yi);
	if (wujiao != 0)
		printf("5角  : %d张\n", wujiao);
	if (yijiao != 0)
		printf("1角  : %d张\n", yijiao);
	if (wufen != 0)
		printf("5分  : %d张\n", wufen);
	if (liangfen != 0)
		printf("2分  : %d张\n", liangfen);
	if (yifen != 0)
		printf("1分  : %d张\n", yifen);		
}