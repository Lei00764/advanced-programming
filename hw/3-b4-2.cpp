/* 2053932 ��� ���� */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double Pi = 3.14159;
	int a, b, angle;
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	cin >> a >> b >> angle;
	float s = (1.0 / 2) * a * b * sin(angle * Pi / 180.0);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "���������Ϊ" << " : " << s << endl;
	return 0;
}