/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("����������ֵ��\n");
	double money;
	int wushi = 0, ershi = 0, shi = 0, wu = 0, yi = 0, wujiao = 0, yijiao = 0, wufen = 0, liangfen = 0, yifen = 0;
	scanf("%lf", &money);
	if (money >= 50)
	{
		wushi += 1;
		money -= 50;
	}
	int k = (int)(money / 10); // Ŀ�ģ�ȡ��
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
	// ��ʱ money�� 0~10 ֮�� ������10
	if (money >= 5)
	{
		wu = 1;
		money -= 5;
	}
	// ��ʱ money�� 0~5 ֮�� ������5
	if (money > 0 && money < 5)
	{
		yi = (int)(money / 1);
		money -= yi;
	}
	// ��ʱ money�� 0~1 ֮�� ������1 
	money = (int)((money + 0.005) * 100); // ����100���� ��ʱmoney�� 0~100 ֮��
	if (money >= 50)
	{
		wujiao = 1;
		money -= 50;
	}
	// ��ʱ money�� 0~0.5 ֮�� ������0.5
	if (money >= 10 && money < 50)
	{
		yijiao = (int)(money / 10);
		money -= yijiao * 10;
	}
	// ��ʱ money�� 0~0.1 ֮�� ������0.1
	if (money > 5)
	{
		wufen = 1;
		money -= 5;
	}
	// ��ʱ money�� 0~0.0.5 ֮�� ������0.05
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
	printf("��%d�����㣬�������£�\n", sum);
	if (wushi != 0)
		printf("50Ԫ : %d��\n", wushi);
	if (ershi != 0)
		printf("20Ԫ : %d��\n", ershi);
	if (shi != 0)
		printf("10Ԫ : %d��\n", shi);
	if (wu != 0)
		printf("5Ԫ  : %d��\n", wu);
	if (yi != 0)
		printf("1Ԫ  : %d��\n", yi);
	if (wujiao != 0)
		printf("5��  : %d��\n", wujiao);
	if (yijiao != 0)
		printf("1��  : %d��\n", yijiao);
	if (wufen != 0)
		printf("5��  : %d��\n", wufen);
	if (liangfen != 0)
		printf("2��  : %d��\n", liangfen);
	if (yifen != 0)
		printf("1��  : %d��\n", yifen);		
}