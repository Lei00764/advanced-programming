/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度" << endl;
	double Pi = 3.14159;
	double r, h;
	cin >> r >> h;
	double circleference = 2 * Pi * r;
	double circle_area = Pi * r * r;
	double sphere_surface_area = 4 * Pi * r * r;
	double sphere_volume = (4.0 / 3) * Pi * r * r * r;
	double cylindrical_volume = Pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长    " << " : " << circleference << endl;
	cout << "圆面积    " << " : " << circle_area << endl;
	cout << "圆球表面积" << " : " << sphere_surface_area << endl;
	cout << "圆球体积  " << " : " << sphere_volume << endl;
	cout << "圆柱面积  " << " : " << cylindrical_volume << endl;
	return 0;
}