/* 2053932 ��� ���� */
/* 2050720 ������ 2154275 ���� 2150806 ����Դ 2150858 ������ 2152118 ʷ���� 1952099 ������ */
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	clog << "�ļ���������ʽ�����ԣ�" << endl;
	clog << "    a.hex                     : ����·����ʽ" << endl;
	clog << "    ..\\data\\b.txt             : ���·����ʽ" << endl;
	clog << "    C:\\Windows\\System32\\c.hex : �������·����ʽ" << endl;
	char file_name1[100] = { '\0' };
	char file_name2[100] = { '\0' };
	clog << "������Ҫת����hex��ʽ�ļ��� : ";
	cin.getline(file_name1, 100);
	clog << "������ת������ļ���        : ";
	cin.getline(file_name2, 100);

	fstream fin;
	fstream fout;
	fin.open(file_name1, ios::in | ios::binary);
	// fout.open(file_name2, ios::out | ios::app);
	fout.open(file_name2, ios::out);
	if (fin.is_open() == 0)
	{
		cout << "�����ļ�" << file_name1 << "��ʧ��!" << endl;
		return -1;
	}

	int per_count = 0;  // ÿһ�ж�ȡ����Ч�ַ���
	char str[80] = { '\0' };  // 78 + 2 2�ǻس�\r\n
	while (fin.read((char*)&str[0], 80))
	{
		int i = 11;
		while (i < 59)
		{
			if (i == 35)  // ���� 
				i += 2;
			int shi = 0, ge = 0;
			if (str[i] >= 'A' && str[i] <= 'F')
				shi = str[i] - 55;
			else if (str[i] >= '0' && str[i] <= '9')
				shi = str[i] - '0';
			if (str[i + 1] >= 'A' && str[i + 1] <= 'F')
				ge = str[i + 1] - 55;
			else if (str[i + 1] >= '0' && str[i + 1] <= '9')
				ge = str[i + 1] - '0';
			char ch = shi * 16 + ge;
			if (ch == '\r')
			{
				i += 3;
				continue;
			}
			fout << ch;
			i += 3;
		}
		for (int i = 0; i < 80; i++)
			str[i] = '\0';
	}
	
	int j = 11;
	while (str[j] != ' ' && str[j + 1] != ' ' && str[j] != '\0')
	{
		if (j == 35)  // ����
			j += 2;
		int shi = 0, ge = 0;
		if (str[j] >= 'A' && str[j] <= 'F')
			shi = str[j] - 55;
		else if (str[j] >= '0' && str[j] <= '9')
			shi = str[j] - '0';
		if (str[j + 1] >= 'A' && str[j + 1] <= 'F')
			ge = str[j + 1] - 55;
		else if (str[j + 1] >= '0' && str[j + 1] <= '9')
			ge = str[j + 1] - '0';
		char ch = shi * 16 + ge;
		if (ch == '\r')
		{
			j += 3;
			continue;
		}
		fout << ch;
		j += 3;
	}

	fin.close();
	fout.close();
	return 0;
}
