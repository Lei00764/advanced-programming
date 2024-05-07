/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <cstring>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;


/**
  * 显示菜单，返回用户选项
  */
int Menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.显示关卡" << endl;
	cout << "0.退出" << endl;
	cout << "--------------------------------------------" << endl;
	char user_choice;
	cout << "[请选择:] ";
	while (1)
	{
		user_choice = (char)_getch();  // 读取单个字符 （无缓冲区 无回显）
		if (user_choice == '0' || user_choice == '1')
		{
			cout << user_choice << endl;  // 正确输入时显示用户选项
			break;
		}
	}
	cout << endl;
	return user_choice - '0';
}


int main()
{
	cct_setconsoleborder(130, 48, 130, 48);
	cct_setfontsize("点阵字体", 16, 8);
	char files[200][50] = {'\0'};  // 存放“很纯粹”的文件名 eg Sokoban-Level-000.txt
	int user_choice = Menu();
	if (user_choice == 1)
	{
		cct_cls();
		int tag = GetAllFiles("stage", "Sokoban-Level-???.txt", files);  // 用通配符*来匹配也可以，只不过需要额外处理
		if (tag == 0)
		{
			cout << "无法打开[.\\stage\\]目录." << endl;
			return -1;
		}
		int all_count = 0;  // 总共有多少个文件
		while (files[all_count][0] != '\0')
			all_count++;

		int flag = 0;
		while (1)
		{
			flag = fun(files, all_count);
			if (flag == 0)
				break;
		}
	}

	return 0;
}
