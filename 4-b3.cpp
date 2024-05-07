/* 2053932 ��� ���� */
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
	cout << "������" << "  " << "����һ" << "  " << "���ڶ�" << "  " << "������" << "  " << "������" << "  " << "������" << "  " << "������" << endl;
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
	cout << "��������[1900-2100]����" << endl;
	int y, m;
	cin >> y >> m;

	while (cin.fail()) // ��������ĸ
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "�����������������" << endl;
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m;
	}


	while (1)
	{
		while (y > 2100 || y < 1900)
		{
			cout << "��ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
			cin >> y >> m;
		}
		while (m > 12 || m < 0)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
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
	cout << endl; // ����
	cout << y << "��" << m << "��" << endl; // ��������
	calendar(y, m, w);
	cout << endl;
	return 0;
}