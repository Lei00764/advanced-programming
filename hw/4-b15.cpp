/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

int min(int a, int b, int c=2147483647, int d=2147483647)
{
	if (a <= b)
	{
		if (a <= c)
			if (a <= d)
				return a;
			else
				return d;
		else
		{
			if (c <= d)
				return c;
			else
				return d;
		}
	}
	else
	{
		if (b <= c)
			if (b <= d)
				return b;
			else
				return d;
		else
			if (c <= d)
				return c;
			else
				return d;
	}
}

int main()
{
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		int num; // 记录个数
		cin >> num;
		int num1, num2, num3, num4;

		if (cin.good() && (num > 4 || num < 2))
		{
			cout << "个数输入错误" << endl;
			break;
		}

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (num == 2)
		{
			cin >> num1 >> num2;
			if (cin.good() && num1 > 0 && num2 > 0)
			{
				cout << "min=" << min(num1, num2) << endl;
				break;
				
			}
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
		}
		else if (num == 3)
		{
			cin >> num1 >> num2 >> num3;
			if (cin.good() &&  num1 > 0 && num2 > 0 && num3 > 0)
			{
				cout << "min=" << min(num1, num2, num3) << endl;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
		}
		else
		{
			cin >> num1 >> num2 >> num3 >> num4;
			if (cin.good() && num1 > 0 && num2 > 0 && num3 > 0 && num4 > 0)
			{
				cout << "min=" << min(num1, num2, num3, num4) << endl;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
		}
	}

	return 0;
}