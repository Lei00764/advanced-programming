/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double Pi = 3.14159;
	int a, b, angle;
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	scanf("%d %d %d", &a, &b, &angle);
	float s = (float) (a * b * sin(angle * Pi / 180.0) / 2.0);
	printf("���������Ϊ : %.3f", s);
	return 0;
}