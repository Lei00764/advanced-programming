/* 2053932 软件 雷翔 */
#include <iostream>
#include <cstdio> // getchar()
using namespace std;

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int max(int a, int b, int c)
{
	if (c >= max(a, b))
		return c;
	else
		return max(a, b);
}

int max(int a, int b, int c, int d)
{
	if (d >= max(a, b, c))
		return d;
	else
		return max(a, b, c);
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
				cout << "max=" << max(num1, num2) << endl;
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
			if (cin.good() && num1 > 0 && num2 > 0 && num3 > 0)
			{
				cout << "max=" << max(num1, num2, num3) << endl;
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
				cout << "max=" << max(num1, num2, num3, num4) << endl;
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