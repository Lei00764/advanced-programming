/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������뾶�͸߶�\n");
	double Pi = 3.14159;
	double r, h;
	scanf("%lf %lf", &r, &h);
	double circleference = 2 * Pi * r;
	double circle_area = Pi * r * r;
	double sphere_surface_area = 4 * Pi * r * r;
	double sphere_volume = (4.0 / 3) * Pi * r * r * r;
	double cylindrical_volume = Pi * r * r * h;
	printf("Բ�ܳ�     : %.2lf\n", circleference);
	printf("Բ���     : %.2lf\n", circle_area);
	printf("Բ������ : %.2lf\n", sphere_surface_area);
	printf("Բ�����   : %.2lf\n", sphere_volume);
	printf("Բ�����   : %.2lf\n", cylindrical_volume);
	return 0;
}