/* 2053932 软件 雷翔 */
#include <iostream>
#include <cmath>
using namespace std;


/*
	判断某点(x, y)在由(x1, y1) (x2, y2)组成直线的左边还是右边 直线方程是两点式
	返回 1表示在直线右边；返回 0表示在直线上；返回 -1表示在直线左边
*/
int LeftRight(double x1, double y1, double x2, double y2, double x, double y)
{
	double result = (y - y2) * (x1 - x2) - (x - x2) * (y1 - y2);
	if (result > 0)
		return 1;
	else if (result == 0)
		return 0;
	else
		return -1;
}


// 判断是否是凸边形 如果是 返回 1；如果不是 返回 0
bool IsTu(double arr[7][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		i = i % n;
		int a = LeftRight(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1], arr[i + 2][0], arr[i + 2][1]);  
		for (int j = i + 3; j < n; j++)
		{
			j = j % n;
			int b = LeftRight(arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1], arr[j][0], arr[j][1]); 
			if (a * b <= 0)
				return false;
		}
	}
	
	return true;
}


// 获得由(x1, y1) (x2, y2) (x3, y3) 组成的三角形的面积
double GetTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double single_area = fabs(x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - x3 * y2)/2;
	return single_area;
}


double GetArea(double arr[7][2], int n)
{
	if (!IsTu(arr, n))
		return -1;  // 不是凸边形
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += GetTriangle(arr[0][0], arr[0][1], arr[i][0], arr[i][1], arr[i + 1][0], arr[i + 1][1]);
	}
	return area;
}

int main()
{
	int n; 
	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 4 && n <= 7)
			break;
	}
	while (getchar() != '\n');

	double arr[7][2];
	cout << "请按顺时针/逆时针方向输入" << n << "个顶点的x,y坐标：" << endl;
	for (int i = 0; i < n; i++)
	{
		double num1, num2;
		while (1)
		{
			cout << "请输入第" << i+1 << "个顶点的坐标：" << endl;
			cin >> num1 >> num2;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			break;
		}
		arr[i][0] = num1;
		arr[i][1] = num2;
	}

	double area = GetArea(arr, n);
	if (area != -1)
		cout << "凸" << n << "边形的面积=" << area << endl;
	else
		cout << "不是凸" << n << "边形" << endl;

	return 0;
}
