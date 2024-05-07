/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double Pi = 3.14159;
	int a, b, angle;
	printf("请输入三角形的两边及其夹角（角度）\n");
	scanf("%d %d %d", &a, &b, &angle);
	float s = (float) (a * b * sin(angle * Pi / 180.0) / 2.0);
	printf("三角形面积为 : %.3f", s);
	return 0;
}