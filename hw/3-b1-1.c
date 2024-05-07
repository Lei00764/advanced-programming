/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入半径和高度\n");
	double Pi = 3.14159;
	double r, h;
	scanf("%lf %lf", &r, &h);
	double circleference = 2 * Pi * r;
	double circle_area = Pi * r * r;
	double sphere_surface_area = 4 * Pi * r * r;
	double sphere_volume = (4.0 / 3) * Pi * r * r * r;
	double cylindrical_volume = Pi * r * r * h;
	printf("圆周长     : %.2lf\n", circleference);
	printf("圆面积     : %.2lf\n", circle_area);
	printf("圆球表面积 : %.2lf\n", sphere_surface_area);
	printf("圆球体积   : %.2lf\n", sphere_volume);
	printf("圆柱面积   : %.2lf\n", cylindrical_volume);
	return 0;
}