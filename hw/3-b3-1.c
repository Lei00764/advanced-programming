/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������[0-100��)֮�������:\n");
	double num;
	scanf("%lf", &num);
	int shiyi = (int)(num / 1000000000.0);
	double num_remove_shiyi = num - shiyi * 1000000000.0;
	unsigned int num_remove_shiyi_zhengshu = (unsigned int)num_remove_shiyi;
	double num_xiaoshu = num_remove_shiyi - num_remove_shiyi_zhengshu;
	printf("ʮ��λ : %d\n", shiyi);
	printf("��λ   : %d\n", num_remove_shiyi_zhengshu / 100000000 % 10);
	printf("ǧ��λ : %d\n", num_remove_shiyi_zhengshu / 10000000 % 10);
	printf("����λ : %d\n", num_remove_shiyi_zhengshu / 1000000 % 10);
	printf("ʮ��λ : %d\n", num_remove_shiyi_zhengshu / 100000 % 10);
	printf("��λ   : %d\n", num_remove_shiyi_zhengshu / 10000 % 10);
	printf("ǧλ   : %d\n", num_remove_shiyi_zhengshu / 1000 % 10);
	printf("��λ   : %d\n", num_remove_shiyi_zhengshu / 100 % 10);
	printf("ʮλ   : %d\n", num_remove_shiyi_zhengshu / 10 % 10);
	printf("Բ     : %d\n", num_remove_shiyi_zhengshu / 1 % 10);
	printf("��     : %d\n", (int)((num_xiaoshu + 0.005) * 10));
	printf("��     : %d\n", (int)((num_xiaoshu + 0.005) * 100) % 10);
	return 0;
}