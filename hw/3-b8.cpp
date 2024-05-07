/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int x;
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;
	if (x < -10 || x > 65)
	{
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
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