/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	cout << "请输入年份(2000-2030)和月份(1-12) : ";
	int year, month;
	int one; // 第一天是星期几 eg. one = 6 表示第一天是星期六
	int day = 1;
	cin >> year >> month;

	while (cin.fail()) // 首先判断是不是非数字
	{
		cin.clear(); // 清空cin的错误状态
		cin.ignore(1024, '\n'); // 清空缓冲区  只清除1024个字符或遇到回车
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
	}
	while (1)
	{
		if (year > 2030 || year < 2000 || month > 12 || month < 0)
		{
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入年份(2000-2030)和月份(1-12) : ";

			cin >> year >> month;
		}
		break;
	}
	
	cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
	cin >> one;
	while (cin.fail()) // 处理字母错误
	{
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin.clear(); // 清空cin的错误状态
		cin.ignore(1024, '\n'); // 清空缓冲区  只清除1024个字符或遇到回车
		cin >> one;
	}
	while (1) // 处理数字超限错误
	{
		if (one >= 0 && one <= 6)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
			cin >> one;
		}
	}
	cout << endl << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日" << "  " << "星期一" << "  " << "星期二" << "  " << "星期三" << "  " << "星期四" << "  " << "星期五" << "  " << "星期六" << endl;

	// 判断是否是闰年
	bool isRunNian;
	isRunNian = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	if (month == 1)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 2)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 28)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
		if (isRunNian)
		{
			cout << setw(4) << day << "    " << endl;
		}
	}
	else if (month == 3)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 4)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 5)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 6)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 7)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 8)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 9)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 10)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 11)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 30)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 12)
	{
		for (int i = 0; i < one; i++)
		{
			cout << "        ";
		}
		while (day <= 31)
		{
			cout << setw(4) << day << "    ";
			day++;
			one++;
			if (one % 7 == 0)
				cout << endl;
		}
	}
	return 0;
}