/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	cout << "���������(2000-2030)���·�(1-12) : ";
	int year, month;
	int one; // ��һ�������ڼ� eg. one = 6 ��ʾ��һ����������
	int day = 1;
	cin >> year >> month;

	while (cin.fail()) // �����ж��ǲ��Ƿ�����
	{
		cin.clear(); // ���cin�Ĵ���״̬
		cin.ignore(1024, '\n'); // ��ջ�����  ֻ���1024���ַ��������س�
		cout << "����Ƿ�������������" << endl;
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
	}
	while (1)
	{
		if (year > 2030 || year < 2000 || month > 12 || month < 0)
		{
			cout << "����Ƿ�������������" << endl;
			cout << "���������(2000-2030)���·�(1-12) : ";

			cin >> year >> month;
		}
		break;
	}
	
	cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
	cin >> one;
	while (cin.fail()) // ������ĸ����
	{
		cout << "����Ƿ�������������" << endl;
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin.clear(); // ���cin�Ĵ���״̬
		cin.ignore(1024, '\n'); // ��ջ�����  ֻ���1024���ַ��������س�
		cin >> one;
	}
	while (1) // �������ֳ��޴���
	{
		if (one >= 0 && one <= 6)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
			cin >> one;
		}
	}
	cout << endl << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������" << "  " << "����һ" << "  " << "���ڶ�" << "  " << "������" << "  " << "������" << "  " << "������" << "  " << "������" << endl;

	// �ж��Ƿ�������
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