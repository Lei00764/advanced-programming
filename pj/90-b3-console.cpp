/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>  // for _getch()
#include "90-b3.h"
#include "cmd_console_tools.h"
using namespace std;


/**
  * 记录按键状态，只有上下箭头、回车、esc这四个键才会退出该函数
  * 返回1 上箭头
  * 返回2 下箭头
  * 返回3 回车
  * 返回4 esc
  */
int GetButton()
{
	int mButton; // 用来记录按了什么键 

	while (1)
	{
		// 用getch读取功能键时，会返回两个int，第一个int是224，第二个int才是功能键的ASCII
		mButton = _getch();

		if (mButton == 224)
			mButton = _getch();
		else if (mButton == '\r')  // _getch()读取回车，返回'\r'
			return 3;
		else if (mButton == 27)  // esc的ASCII为27
			return 4;
		else // if (mButton == 'H' || mButton == 'P') 和其他键
			continue;

		if (mButton == 72) // 上
		{
			return 1;
		}
		else if (mButton == 80) // 下
		{
			return 2;
		}
	}
}


/**
  * 返回1表示关卡显示完成，继续下一次显示
  * 返回0表示结束
  */
int fun(char files[200][50], int all_count)
{
	int files_first_index = 0;  // 弹出菜单的第一位置对应在files中的下标
	int pos_index = 0;  // 0~24 选择弹出菜单的关卡 灰色显示
	int flag = -1;  // 1表示关卡显示完成 0表示结束游戏

	int menu_sum = 0;
	while (files[menu_sum][0] != '\0')
		menu_sum++;

	ShowPopMenu(files, all_count, files_first_index);  // 显示弹出菜单
	while (1)
	{
		char pre_guanqia_name[8] = "关卡";
		char cur_guanqia_name[8] = "关卡";
		if (pos_index == 0)
		{
			strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
			cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
			cur_guanqia_name[4] = '\0';
		}
		int tag = 1;  // 正常情况为1，如果有非法字符，置0
		int choice = GetButton();
		switch (choice)
		{
			case 1:  // 按了上箭头
				if (pos_index == 0)
				{
					if (files_first_index != 0)
					{
						files_first_index--;
						cct_setcolor();  // 恢复默认颜色
						ShowPopMenu(files, all_count, files_first_index);  // 显示弹出菜单

						strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
						cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
					}
					break;
				}
				strncat(pre_guanqia_name, &files[files_first_index + pos_index][14], 3);
				cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, pre_guanqia_name, COLOR_BLACK, COLOR_WHITE);  // 清空原来的选中标记

				pos_index--;
				strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
				cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
				break;
			case 2:  // 按了下箭头
				if (pos_index == MenuMaxSum - 1)  // 弹出菜单能显示的最大关卡数
				{
					if (files_first_index != all_count - MenuMaxSum)
					{
						files_first_index++;
						ShowPopMenu(files, all_count, files_first_index + pos_index + 1 - MenuMaxSum);  // 显示弹出菜单

						strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
						cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
					}
					break;
				}
				if (menu_sum < MenuMaxSum && pos_index == menu_sum - 1)  // 不足MenuMaxSum
					continue;
				else
				{
					strncat(pre_guanqia_name, &files[files_first_index + pos_index][14], 3);
					cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, pre_guanqia_name, COLOR_BLACK, COLOR_WHITE);  // 清空原来的选中标记

					pos_index++;
					strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
					cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
				}
				break;
			case 3:  // 按了回车
				tag = ShowMap("stage", files[files_first_index + pos_index]);
				if (tag == 1)
					to_be_continued(3);
				flag = 1;
				break;
			case 4:  // 按了esc
				to_be_continued(1);
				flag = 0;
				break;
		}
		cct_setcolor();  // 恢复默认颜色
		if (flag == 1 || flag == 0)
			break;
	}
	return flag;
}


/**
  * 如果在该文件中无非法字符，就显示数组；否则给予提示
  * 正常情况下返回1，如果有非法字符，返回0
  */
int ShowMap(const char* file_spc, char filename[])
{
	cct_gotoxy(MapX, MapY);
	char path[100] = { '\0' };
	strcat(path, file_spc);
	strcat(path, "\\");
	strcat(path, filename);
	fstream fin(path, ios::in);
	if (fin.is_open() == 0)
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}

	char arr[MaxLines][MaxCols + 1] = { '\0' };
	for (int i = 0; i < MaxLines; i++)
	{
		if (fin.eof() == 1)
			break;
		int num = MaxCols + 1;  // 直接将MaxCols + 1写在下面 错误列表-消息处会显示xxx
		fin.getline(arr[i], num, '\n');  // 当一行字符数量超多num时，要清空状态和缓冲区
		if (fin.fail() == 1)
		{
			fin.clear();
			fin.ignore(1024, '\n');
		}
		
	}
	int cols = strlen(arr[0]);
	int lines = 0;
	while (lines < MaxLines && arr[lines][0] != '\0')
		lines++;
	
	int flag = 1;  // 用来标记是否有非法字符
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < cols; j++)
			if (CheckLegalInArr(arr[i][j]) == 0)
			{
				flag = 0;
				cct_gotoxy(MapX, MapX + MaxLines * 2);
				cout << "推箱子数据文件[" << filename << "]有非法字符(" << i + 1 << "行" << j + 1 << "列)，按回车键继续" << endl;
				to_be_continued(2);  // 按回车进行下一步操作
				return 0;
			}
	}
	// 如果无非法字符，画出地图
	if (flag != 0)
	{
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < cols; j++)
				ShowByCh(i, j, arr[i][j]);
		}
	}
	return 1;
}


/**
  * 检查字符是否是非法字符（色块与字符的对应关系）
  * 若不是非法字母，返回1；否则返回0
  */
int CheckLegalInArr(char ch)
{
	int flag;
	switch (ch)
	{
		case '9':
		case 'W':
		case 'w':
		case '0':
		case 'B':
		case 'b':
		case 'F':
		case 'f':
		case 'S':
		case 's':
		case 'R':
		case 'r':
			flag = 1;
			break;
		default:
			flag = 0;
			break;
	}
	return flag;
}


/**
  * 根据文件里(i, j)处的字母来显示相应的色块
  */
void ShowByCh(int i, int j, char ch)
{
	int pos_x = 6 * j + MapX;
	int pos_y = 3 * i + MapY;
	if (ch == '9')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_BLACK, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 1, "║  ║", COLOR_BLACK, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_BLACK, COLOR_BLACK);
	}
	else if (ch == 'W' || ch == 'w')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_RED, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 1, "║XX║", COLOR_RED, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_RED, COLOR_BLACK);
	}
	else if (ch == '0')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_WHITE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 1, "║  ║", COLOR_WHITE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_WHITE, COLOR_WHITE);
	}
	else if (ch == 'B' || ch == 'b')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_GREEN, COLOR_YELLOW);
		cct_showstr(pos_x, pos_y + 1, "║★║", COLOR_GREEN, COLOR_YELLOW);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_GREEN, COLOR_YELLOW);
	}
	else if (ch == 'F' || ch == 'f')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_CYAN, COLOR_GREEN);
		cct_showstr(pos_x, pos_y + 1, "║●║", COLOR_CYAN, COLOR_GREEN);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_CYAN, COLOR_GREEN);
	}
	else if (ch == 'S' || ch == 's')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_BLUE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 1, "║♀║", COLOR_BLUE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_BLUE, COLOR_WHITE);
	}
	else if (ch == 'R' || ch == 'r')
	{
		cct_showstr(pos_x, pos_y, "╔═╗", COLOR_YELLOW, COLOR_RED);
		cct_showstr(pos_x, pos_y + 1, "║★║", COLOR_YELLOW, COLOR_RED);
		cct_showstr(pos_x, pos_y + 2, "╚═╝", COLOR_YELLOW, COLOR_RED);
	}
	cct_setcolor();  // 恢复默认颜色
}


void to_be_continued(int choice, const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (choice == 1)
	{
		cout << "本小题结束，请输入End继续...";
		int pos_x, pos_y; // 当前光标所在位置
		cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
		while (1)
		{
			cct_gotoxy(pos_x, pos_y);
			char str[20] = { '\0' };
			int count = 0;  // 记录字符个数
			int flag = 1;  // flag = 0时跳出最外层死循环
			while (1)
			{
				char ch = getchar();
				if (ch == '\n')
				{
					cout << "输入错误，请重新输入" << endl;
					cct_gotoxy(pos_x, pos_y);
					cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 10);
					cct_gotoxy(pos_x, pos_y);
					count = 0;
					break;
				}
				else if (ch >= 'A' && ch <= 'Z')
					str[count++] = (ch + 'a' - 'A');
				else if (ch >= 'a' && ch <= 'z')
					str[count++] = ch;

				if (count == 3 && str[0] == 'e' && str[1] == 'n' && str[2] == 'd')
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				break;
		}
		cct_setconsoleborder(120, 35, 120, 1000);  // 加上这两行代码后 从选项5退出 菜单的大小就和原来的一样了
		cct_setfontsize("点阵字体", 16, 8);
	}
	else if (choice == 2)
	{
		/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
		while (_getch() != '\r')
			;
	}
	else if (choice == 3)
	{
		cout << "关卡显示完成，按C/c继续...";
		char ch;
		while (1)
		{
			ch = _getch();
			if (ch == 'C' || ch == 'c')
				break;
		}
	}

	cct_cls();
	return;
}

