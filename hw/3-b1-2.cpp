/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������뾶�͸߶�" << endl;
	double Pi = 3.14159;
	double r, h;
	cin >> r >> h;
	double circleference = 2 * Pi * r;
	double circle_area = Pi * r * r;
	double sphere_surface_area = 4 * Pi * r * r;
	double sphere_volume = (4.0 / 3) * Pi * r * r * r;
	double cylindrical_volume = Pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�    " << " : " << circleference << endl;
	cout << "Բ���    " << " : " << circle_area << endl;
	cout << "Բ������" << " : " << sphere_surface_area << endl;
	cout << "Բ�����  " << " : " << sphere_volume << endl;
	cout << "Բ�����  " << " : " << cylindrical_volume << endl;
	return 0;
}