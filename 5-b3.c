/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// ����1��ʾ�����꣬����0��ʾ��������
int IsRunNian(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

int SumFun(int year, int month, int day)
{
	int runnian_day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int not_runnian_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	if (IsRunNian(year) == 1)
	{
		for (int i = 0; i < month - 1; i++)
		{
			sum += runnian_day[i];
		}
	}
	else
	{
		for (int i = 0; i < month - 1; i++)
		{
			sum += not_runnian_day[i];
		}
	}
	sum += day;
	return sum;
}

int main()
{	
	printf("�������꣬�£���\n");
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);

	int runnian = IsRunNian(year);
	if (runnian == 1)
	{
		if ((month < 1) || (month > 12))
		{
			printf("�������-�·ݲ���ȷ\n");
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 29))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
	}
	else
	{
		if ((month < 1) || (month > 12))
		{
			printf("�������-�·ݲ���ȷ\n");
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 28))
			{
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
				return 0;
			}
		}
	}

	int sum = SumFun(year, month, day);

	
	printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, sum);
	return 0;
}