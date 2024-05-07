/* 2053932 软件 雷翔 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double Pi = 3.14159;
	int a, b, angle;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> angle;
	float s = (1.0 / 2) * a * b * sin(angle * Pi / 180.0);
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为" << " : " << s << endl;
	return 0;
}