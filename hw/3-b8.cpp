/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int x;
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	cin >> x;
	if (x < -10 || x > 65)
	{
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
	}
	cout << setprecision(10);
	double sum = 1.0;
	double multiple = 1.0;
	int k = 1;
	while (fabs(pow(x, k) / multiple) >= pow(10, -6))
	{
		sum += pow(x, k) / multiple;
		k++;
		multiple *= k;
	}
	cout << "e^" << x << "=" << sum << endl;
	return 0;
}