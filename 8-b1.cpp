/* 2053932 软件 雷翔 */
/* 2050720 刘天煜 2154275 颜炜骞 2150806 刘广源 2150858 蔡明辉 2152118 史君宝 1952099 穆祖磊 */
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
	clog << "文件名以下形式均可以：" << endl;
	clog << "    a.txt                     : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入文件名 : ";
	char file_name[100];
	cin.getline(file_name, 100);
	fstream fin;
	fin.open(file_name, ios::in | ios::binary);
	if (fin.is_open() == 0)
	{
		cout << "输入文件" << file_name << "打开失败!" << endl;
		return -1;
	}
	cout.setf(ios::uppercase);
	// cout << setiosflags(ios::uppercase)
	
	int count = 0;      // 统计输出字符个数
	int per_count = 0;  // 每一行的字符 0~15
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
