/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入年，月，日\n");
	int year, month, day;
	int sum = 0; // 计算天数
	scanf("%d %d %d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // 闰年
	{
		if ((month < 1) || (month > 12))
		{
			printf("输入错误-月份不正确\n");
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 29))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 1)
		{
			sum += day;
		}
		else if (month == 2)
		{
			sum += (31 + day);
		}
		else if (month == 3)
		{
			sum += (31 + 29 + day);
		}
		else if (month == 4)
		{
			sum += (31 + 29 + 31 + day);
		}
		else if (month == 5)
		{
			sum += (31 + 29 + 31 + 30 + day);
		}
		else if (month == 6)
		{
			sum += (31 + 29 + 31 + 30 + 31 + day);
		}
		else if (month == 7)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + day);
		}
		else if (month == 8)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + day);
		}
		else if (month == 9)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day);
		}
		else if (month == 10)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
		}
		else if (month == 11)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
		}
		else if (month == 12)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, sum);
		return 0;
	}
	else // 不是闰年
	{
		if ((month < 1) || (month > 12))
		{
			printf("输入错误-月份不正确\n");
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 28))
			{
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
		if (month == 1)
		{
			sum += day;
		}
		else if (month == 2)
		{
			sum += (31 + day);
		}
		else if (month == 3)
		{
			sum += (31 + 28 + day);
		}
		else if (month == 4)
		{
			sum += (31 + 28 + 31 + day);
		}
		else if (month == 5)
		{
			sum += (31 + 28 + 31 + 30 + day);
		}
		else if (month == 6)
		{
			sum += (31 + 28 + 31 + 30 + 31 + day);
		}
		else if (month == 7)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + day);
		}
		else if (month == 8)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + day);
		}
		else if (month == 9)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day);
		}
		else if (month == 10)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
		}
		else if (month == 11)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
		}
		else if (month == 12)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, sum);
		return 0;
	}
}