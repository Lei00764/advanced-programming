/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int year, month;
	int one; // ��һ�������ڼ� eg. one = 6 ��ʾ��һ����������
	int day = 1;
	int ret; 
	printf("���������(2000-2030)���·�(1-12) : ");
	ret = scanf("%d %d", &year, &month); // ret��ʾ��ȷ�ĸ���
	
	while (ret < 2) // ˵���������������һ������
	{
		while (getchar() != '\n'); // ��ջ�����
		printf("����Ƿ�������������\n");
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &year, &month);
	}

	while (1) // �������ֳ��ޣ���ĸ�����ѽ����
	{
		if (year > 2030 || year < 2000 || month > 12 || month < 0)
		{
			printf("����Ƿ�������������\n");
			printf("���������(2000-2030)���·�(1-12) : ");
			scanf("%d %d", &year, &month);
		}
		break;
	}

	printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
	ret = scanf("%d", &one);

	while (ret < 1)
	{
		while (getchar() != '\n'); // ��ջ�����
		printf("����Ƿ�������������\n");
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
		ret = scanf("%d", &one);
	}

	while (1) // �������ֳ��޴���
	{
		if (one >= 0 && one <= 6)
			break;
		else
		{
			printf("����Ƿ�������������\n");
			printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
			ret = scanf("%d", &one);
		}
	}

	printf("\n%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	// �ж��Ƿ�������
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