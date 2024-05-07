/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		y--;
		m += 12;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	return w;
}

int main()
{
	printf("请输入年[1900-2100]、月、日：\n");
	int y, m, d;
	int ret = scanf("%d %d %d", &y, &m, &d);

	while (ret < 3) // 若输入字母
	{
		while (getchar() != '\n');
		printf("输入错误，请重新输入\n");
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d %d %d", &y, &m, &d);
	}

	int isRunNian;
	isRunNian = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));

	while (1)
	{
		while (y > 2100 || y < 1900)
		{
			printf("年份不正确，请重新输入\n");
			printf("请输入年[1900-2100]、月、日：\n");
			scanf("%d %d %d", &y, &m, &d);
		}
		while (m > 12 || m < 0)
		{
			printf("月份不正确，请重新输入\n");
			printf("请输入年[1900-2100]、月、日：\n");
			scanf("%d %d %d", &y, &m, &d);
		}
		while (d < 0 || d >= 28)
		{
			if (m == 2 && isRunNian == 1 && d > 29)
			{
				printf("日不正确，请重新输入\n");
				printf("请输入年[1900-2100]、月、日：\n");
				scanf("%d %d %d", &y, &m, &d);
			}
			else if (m == 2 && isRunNian == 0 && d > 28)
			{
				printf("日不正确，请重新输入\n");
				printf("请输入年[1900-2100]、月、日：\n");
				scanf("%d %d %d", &y, &m, &d);
			}
			else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
			{
				printf("日不正确，请重新输入\n");
				printf("请输入年[1900-2100]、月、日：\n");
				scanf("%d %d %d", &y, &m, &d);
			}
			else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
			{
				printf("日不正确，请重新输入\n");
				printf("请输入年[1900-2100]、月、日：\n");
				scanf("%d %d %d", &y, &m, &d);
			}
			else
				break;
		}
		break;
	}

	int w = zeller(y, m, d);
	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;
	switch (w)
	{
		case 0:
			printf("星期天\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}
	return 0;
}