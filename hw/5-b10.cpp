/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>

using namespace std;

int zeller(int y, int m, int d) // 某月1日的日期 0-6 0表示星期天 x表示星期x
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
	while (w < 0)
		w += 7;
	w = w % 7;
	return w;
}

void PrintName()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sun Mon Tue Wed Thu Fri Sat" << "     ";
	}
	cout << endl;
}

void FillArr(int arr[], int year)  // 填满 每个月份都占连续的42*4Byte
{
	bool is_run_nian = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	for (int i = 1; i < 13; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			for (int j = 1; j < 32; j++)
			{
				int pos = zeller(year, i, 1);
				arr[pos + (i-1) * 6 * 7 + j - 1] = j;
			}
		}
		else if (i == 2)
		{
			for (int j = 1; j < 29; j++)
			{
				int pos = zeller(year, i, 1);
				arr[pos + (i-1) * 6 * 7 + j - 1] = j;
				if (j == 28 && is_run_nian)
					arr[pos + (i - 1) * 6 * 7 + j] = 29;
			}

		}
		else
		{
			for (int j = 1; j < 31; j++)
			{
				int pos = zeller(year, i, 1);
				arr[pos + (i - 1) * 6 * 7 + j - 1] = j;
			}
		}
	}
}

int main()
{
	system("mode con cols=120 lines=45");
	int year;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	cout << year << "年的日历:" << endl;
	cout << endl;
	int arr[4 * 3 * 7 * 6] = { 0 };
	FillArr(arr, year);

	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (j % 3 != 0)
				cout << "           " << setw(2) << (i - 1) * 3 + j << "月" << "                 ";
			else
				cout << "           " << setw(2) << (i - 1) * 3 + j << "月" << endl;
		}

		for (int k = 1; k < 4; k++)
		{
			if (k % 3 != 0)
				cout << "Sun Mon Tue Wed Thu Fri Sat" << "     ";
			else
				cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
		}

		for (int m = 1; m < 7; m++)
		{
			int index = (i - 1) * 6 * 7 * 3 + (m - 1) * 7;
			int lst[21] = { 0 };
			for (int n = 1; n < 22; n++)
			{
				
				lst[n - 1] = arr[index];
				if (n % 7 == 0 && n != 21)
				{
					index += (35 + 1);
				}	
				else
				{
					index++;
				}
			}
			int sum = 0;
			for (int i = 0; i < 21; i++)
			{
				sum += lst[i];
			}
			if (sum != 0)
			{
				for (int j = 1; j < 22; j++)
				{
					if (lst[j-1] != 0)
					{
						cout << setiosflags(ios::left) << setw(4) << lst[j-1];
					}
					else
					{
						cout << "    ";
					}
					if (j % 7 == 0 && j != 21)
					{
						cout << "    ";
					}
					if (j == 21)
					{
						cout << endl;
					}
				}
			}
			cout << resetiosflags(ios::left);
			
		}
		cout << endl;

	}
	cout << endl; 

	return 0;
}