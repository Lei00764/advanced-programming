/* 2053932 软件 雷翔 */
/* 2050720 刘天煜 2154275 颜炜骞 2150806 刘广源 2150858 蔡明辉 2152118 史君宝 1952099 穆祖磊 */
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	clog << "文件名以下形式均可以：" << endl;
	clog << "    a.hex                     : 不带路径形式" << endl;
	clog << "    ..\\data\\b.txt             : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.hex : 绝对相对路径形式" << endl;
	char file_name1[100] = { '\0' };
	char file_name2[100] = { '\0' };
	clog << "请输入要转换的hex格式文件名 : ";
	cin.getline(file_name1, 100);
	clog << "请输入转换后的文件名        : ";
	cin.getline(file_name2, 100);

	fstream fin;
	fstream fout;
	fin.open(file_name1, ios::in | ios::binary);
	// fout.open(file_name2, ios::out | ios::app);
	fout.open(file_name2, ios::out);
	if (fin.is_open() == 0)
	{
		cout << "输入文件" << file_name1 << "打开失败!" << endl;
		return -1;
	}

	int per_count = 0;  // 每一行读取的有效字符数
	char str[80] = { '\0' };  // 78 + 2 2是回车\r\n
	while (fin.read((char*)&str[0], 80))
	{
		int i = 11;
		while (i < 59)
		{
			if (i == 35)  // 短线 
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
		if (j == 35)  // 短线
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
