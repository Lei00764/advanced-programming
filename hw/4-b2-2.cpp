/* 2053932 ��� ���� */
#include <iostream>
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

int main()
{
	cout << "��������[1900-2100]���¡��գ�" << endl;
	int y, m, d;
	cin >> y >> m >> d;

	while (cin.fail()) // ��������ĸ
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "�����������������" << endl;
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
	}

	bool isRunNian;
	isRunNian = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));

	while (1)
	{
		while (y > 2100 || y < 1900)
		{
			cout << "��ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
			cin >> y >> m >> d;
		}
		while (m > 12 || m < 0)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
			cin >> y >> m >> d;
		}
		while (d < 0 || d >= 28)
		{
			if (m == 2 && isRunNian == true && d > 29)
			{
				cout << "�ղ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�" << endl;
				cin >> y >> m >> d;
			}
			else if (m == 2 && isRunNian == false && d > 28)
			{
				cout << "�ղ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�" << endl;
				cin >> y >> m >> d;
			}
			else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
			{
				cout << "�ղ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�" << endl;
				cin >> y >> m >> d;
			}
			else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
			{
				cout << "�ղ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�" << endl;
				cin >> y >> m >> d;
			}
			else
				break;
		}
		break;
	}

	int w = zeller(y, m, d);
	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;
	switch (w)
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}
	return 0;
}