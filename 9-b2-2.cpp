/* 2053932 ��� ���� */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ����һ����Ա����������1����,Ҫ������ʵ�� */
	void set(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
	/* ������������Ǹ���Ա�����⣬������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ����������� */
	// friend void triangle::getxy(point& p);  // �������У���������֪��triangle��ĺ���������������Ԫ����ʧЧ �ӣ���������ǰ����triangle���ʱ������һ�º���
	friend triangle;
};


class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1;
		getxy(p1, x1, y1);
		getxy(p2, x2, y2);
		getxy(p3, x3, y3);
		// flag = 0 ��ʾ�������������
		int flag = LeftRight(x1, y1, x2, y2, x3, y3);
		if (flag == 0)
			return -1;
		return GetTriangle(x1, y1, x2, y2, x3, y3);
	}
	/* ���캯�� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void getxy(point& p, int &p_x, int & p_y)
	{
		p_x = p.x;
		p_y = p.y;
	}
	// �������������
	double GetTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		double single_area = fabs(x1 * y2 - x1 * y3 + x2 * y3 - x2 * y1 + x3 * y1 - x3 * y2) / 2;
		return single_area;
	}
	// �ж��Ƿ������������
	// ����1��ʾ��ֱ���ұߣ�����0��ʾ��ֱ���ϣ�����-1��ʾ��ֱ�����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}
