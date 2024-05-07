/* 2053932 软件 雷翔 */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么
class point {
private:
	int x;
	int y;
public:
	/* 仅允许在此添加一个成员函数【仅限1个】,要求体内实现 */
	void set(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
	// friend void triangle::getxy(point& p);  // 这样不行，编译器不知道triangle类的函数，所以声明友元函数失效 坑！！！除非前声明triangle类的时候，声明一下函数
	friend triangle;
};


class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1;
		getxy(p1, x1, y1);
		getxy(p2, x2, y2);
		getxy(p3, x3, y3);
		// flag = 0 表示不能组成三角形
		int flag = LeftRight(x1, y1, x2, y2, x3, y3);
		if (flag == 0)
			return -1;
		return GetTriangle(x1, y1, x2, y2, x3, y3);
	}
	/* 构造函数 */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	void getxy(point& p, int &p_x, int & p_y)
	{
		p_x = p.x;
		p_y = p.y;
	}
	// 计算三角形面积
	double GetTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		double single_area = fabs(x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - x3 * y2) / 2;
		return single_area;
	}
	// 判断是否能组成三角形
	// 返回1表示在直线右边；返回0表示在直线上；返回-1表示在直线左边
	int LeftRight(int x1, int y1, int x2, int y2, int x, int y)
	{
		int result = (y - y2) * (x1 - x2) - (x - x2) * (y1 - y2);
		if (result > 0)
			return 1;
		else if (result == 0)
			return 0;
		else
			return -1;
	}
};




/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //三点共线
		cout << "三角形面积应该是：-1， 实际是：" << tr.area() << endl;
	}

	return 0;
}
