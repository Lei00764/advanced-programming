/* 2053932 ��� ���� */
/* 2050720 ������ 2154275 ���� 2150806 ����Դ 2150858 ������ 2152118 ʷ���� 1952099 ������ */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void ShowArr(unsigned char str[16], int n)
{
	for (int i = 0; i < n; i++)
	{
		char ch = str[i];
		if ((int)ch >= 33 && (int)ch <= 126)
			cout << ch;
		else
			cout << '.';
	}
}

int main()
{
	clog << "�ļ���������ʽ�����ԣ�" << endl;
	clog << "    a.txt                     : ����·����ʽ" << endl;
	clog << "    ..\\data\\b.dat             : ���·����ʽ" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	clog << "�������ļ��� : ";
	char file_name[100];
	cin.getline(file_name, 100);
	fstream fin;
	fin.open(file_name, ios::in | ios::binary);
	if (fin.is_open() == 0)
	{
		cout << "�����ļ�" << file_name << "��ʧ��!" << endl;
		return -1;
	}
	cout.setf(ios::uppercase);
	// cout << setiosflags(ios::uppercase)
	
	int count = 0;      // ͳ������ַ�����
	int per_count = 0;  // ÿһ�е��ַ� 0~15
	unsigned char str[16] = { '\0' };
	while (fin.read((char*)&str[per_count], 1))
	{
		if (per_count == 0)
		{
			for (int i = 0; i < per_count; i++)
				str[i] = '\0';
			if (count > 0)
				cout << endl;
			cout << setw(8) << setfill('0') << hex << count << ":  ";
		}
		cout << setw(2) << setfill('0') << hex << (int)str[per_count] << " ";
		per_count++;
		if (per_count == 8)
			cout << "- ";
		if (per_count == 16)
		{
			count += 16;
			cout << " ";
			ShowArr(str, 16);
			per_count = 0;
		}
	}
	if (per_count != 0)
	{
		if (per_count <= 8)
			cout << "  ";
		for (int i = 16 - per_count; i > 0; i--)
			cout << "   ";
		cout << " ";
		ShowArr(str, per_count);
	}
	fin.close();
	cout << endl;
	return 0;
}
