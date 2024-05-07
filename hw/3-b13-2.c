/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int year, month;
	int one; // 第一天是星期几 eg. one = 6 表示第一天是星期六
	int day = 1;
	int ret; 
	printf("请输入年份(2000-2030)和月份(1-12) : ");
	ret = scanf("%d %d", &year, &month); // ret表示正确的个数
	
	while (ret < 2) // 说明年或月中至少有一个错误
	{
		while (getchar() != '\n'); // 清空缓冲区
		printf("输入非法，请重新输入\n");
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &month);
	}

	while (1) // 处理数字超限（字母问题已解决）
	{
		if (year > 2030 || year < 2000 || month > 12 || month < 0)
		{
			printf("输入非法，请重新输入\n");
			printf("请输入年份(2000-2030)和月份(1-12) : ");
			scanf("%d %d", &year, &month);
		}
		break;
	}

	printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
	ret = scanf("%d", &one);

	while (ret < 1)
	{
		while (getchar() != '\n'); // 清空缓冲区
		printf("输入非法，请重新输入\n");
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret = scanf("%d", &one);
	}

	while (1) // 处理数字超限错误
	{
		if (one >= 0 && one <= 6)
			break;
		else
		{
			printf("输入非法，请重新输入\n");
			printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
			ret = scanf("%d", &one);
		}
	}

	printf("\n%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

	// 判断是否是闰年
	int isRunNian;
	isRunNian = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	if (month == 1)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 2)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 28)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
		if (isRunNian)
		{
			printf("%4d    ", day);
		}
	}
	else if (month == 3)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 4)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 30)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 5)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 6)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 30)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 7)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 8)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 9)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 30)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 10)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 30)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 11)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 30)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 12)
	{
		for (int i = 0; i < one; i++)
		{
			printf("        ");
		}
		while (day <= 31)
		{
			printf("%4d    ", day);
			day++;
			one++;
			if (one % 7 == 0)
				printf("\n");
		}
	}
	return 0;
}