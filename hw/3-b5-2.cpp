/* 2053932 ��� ���� */
#include <iostream>
using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	int sum = 0; // ��������
	cin >> year >> month >> day;
	// 
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // ����
	{
		if ((month < 1) || (month > 12))
		{
			cout << "�������-�·ݲ���ȷ" << endl;
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 29))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 1)
		{
			sum += day;
		}
		else if(month == 2)
		{
			sum += (31 + day);
		}
		else if (month == 3)
		{
			sum += (31 + 29 + day);
		}
		else if (month == 4)
		{
			sum += (31 + 29 + 31+ day);
		}
		else if (month == 5)
		{
			sum += (31 + 29 + 31 + 30 + day);
		}
		else if (month == 6)
		{
			sum += (31 + 29 + 31 + 30 + 31 + day);
		}
		else if (month == 7)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + day);
		}
		else if (month == 8)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + day);
		}
		else if (month == 9)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day);
		}
		else if (month == 10)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
		}
		else if (month == 11)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
		}
		else if (month == 12)
		{
			sum += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << sum << "��" << endl;
		return 0;
	}
	else // ��������
	{
		if ((month < 1) || (month > 12))
		{
			cout << "�������-�·ݲ���ȷ" << endl;
			return 0;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if ((day < 1) || (day > 31))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if ((day < 1) || (day > 30))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 2)
		{
			if ((day < 1) || (day > 28))
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
		}
		if (month == 1)
		{
			sum += day;
		}
		else if (month == 2)
		{
			sum += (31 + day);
		}
		else if (month == 3)
		{
			sum += (31 + 28 + day);
		}
		else if (month == 4)
		{
			sum += (31 + 28 + 31 + day);
		}
		else if (month == 5)
		{
			sum += (31 + 28 + 31 + 30 + day);
		}
		else if (month == 6)
		{
			sum += (31 + 28 + 31 + 30 + 31 + day);
		}
		else if (month == 7)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + day);
		}
		else if (month == 8)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + day);
		}
		else if (month == 9)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day);
		}
		else if (month == 10)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
		}
		else if (month == 11)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
		}
		else if (month == 12)
		{
			sum += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << sum << "��" << endl;
		return 0;
	}
}