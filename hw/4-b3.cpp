/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		y--;
		m += 12;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	return w;
}

void calendar(int y, int m, int w)
{
	int day = 1;
	bool isRunNian;
	isRunNian = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
	cout << "======================================================" << endl;
	cout << "星期日" << "  " << "星期一" << "  " << "星期二" << "  " << "星期三" << "  " << "星期四" << "  " << "星期五" << "  " << "星期六" << endl;
	cout << "======================================================" << endl;

	if (m == 1)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 2)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 28)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
		if (isRunNian)
		{
			cout << setw(4) << day << "    ";
		}
	}
	else if (m == 3)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 4)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 5)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 6)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 7)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 8)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 9)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 10)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 11)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	else if (m == 12)
	{
		for (int i = 0; i < w; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			w++;
			if (w % 7 == 0)
				cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	cout << "请输入年[1900-2100]、月" << endl;
	int y, m;
	cin >> y >> m;

	while (cin.fail()) // 若输入字母
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m;
	}


	while (1)
	{
		while (y > 2100 || y < 1900)
		{
			cout << "年份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日：" << endl;
			cin >> y >> m;
		}
		while (m > 12 || m < 0)
		{
			cout << "月份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日：" << endl;
			cin >> y >> m;
		}
		break;
	}

	int w = zeller(y, m, 1);
	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;
	cout << endl; // 空行
	cout << y << "年" << m << "月" << endl; // 输出年和月
	calendar(y, m, w);
	cout << endl;
	return 0;
}