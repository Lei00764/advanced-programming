/* 2053932 软件 雷翔 */
#include <iostream>
#include <conio.h>  // for _getch()
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;


/**
  * 显示菜单，返回用户选项
  */
int Menu()
{
	cct_setconsoleborder(120, 35, 120, 1000);
	cct_setfontsize("点阵字体", 16, 8);
	cout << "--------------------------------------------" << endl;
	cout << "1.内部数组，随机生成初始5个球" << endl;
	cout << "2.内部数组，随机生成60 % 的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n * n的框架（无分隔线），随机显示5个球" << endl;
	cout << "5.画出n * n的框架（有分隔线），随机显示5个球" << endl;
	cout << "6.n * n的框架，60 % 的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "--------------------------------------------" << endl;
	char user_choice;
	cout << "[请选择:] ";
	while (1)
	{
		user_choice = (char)_getch();  // 读取单个字符 （无缓冲区 无回显）
		if (user_choice >= '0' && user_choice <= '7')
		{
			cout << user_choice << endl;  // 正确输入时显示用户选项
			break;
		}
	}
	cout << endl;
	return user_choice - '0';
}

void ClearAllArr(int arr[11][11], int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			arr[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		path[i][0] = '\0';
		path[i][1] = '\0';
	}
	for (int i = 0; i < 3; i++)
	{
		three_ball_color[i] = 0;
		three_ball_position[i][0] = 0;
		three_ball_position[i][1] = 0;

	}
	for (int i = 0; i < 8; i++)
		delete_ball_num[i] = 0;
}


int main()
{
	int arr[11][11];  // 内部数组
	int lines, cols;  // 行数和列数
	srand((unsigned)time(NULL));  // 随机种子

	int visited[11][11] = { 0 };   // 记录访问过的点
	char path[100][2] = { '\0' };  // 记录每次访问的路径
	int three_ball_color[3] = { 0 };  // 记录下3球的颜色
	int three_ball_position[3][2] = { 0 };  // 存储下3球在数组中的位置
	int delete_ball_num[8] = { 0 };  // 记录各种颜色球消除总数量

	while (1)
	{
		ClearAllArr(arr, visited, path, three_ball_color, three_ball_position, delete_ball_num);
		int user_choice = Menu();
		int tag = 1;  // tag = 0 则退出死循环
		switch (user_choice)
		{
			case 1:
				InputLinesCols(lines, cols);  // 输入行数和列数
				InitBallInArr(arr, lines, cols, 1);  // 在数组中随机生成5个球 
				cout << endl;
				cout << "初始数组：" << endl;
				PrintArr(arr, lines, cols);  // 打印数组
				break;
			case 2:
				InputLinesCols(lines, cols);  // 输入行数和列数
				InitBallInArr(arr, lines, cols, 2);  // 在数组中随机生成60%个球 
				DoByChoice2(arr, lines, cols, visited, path, three_ball_color);
				break;
			case 3:
				InputLinesCols(lines, cols);  // 输入行数和列数
				InitBallInArr(arr, lines, cols, 1);  // 在数组中随机生成5个球 
				DoByChoice3(arr, lines, cols, visited, path, three_ball_color, three_ball_position, delete_ball_num);
				break;
			case 4:
			case 5:
				InputLinesCols(lines, cols);
				InitBallInArr(arr, lines, cols, 1);
				DoByChoice45(arr, lines, cols, user_choice);
				break;
			case 6:
			case 7:
				InputLinesCols(lines, cols);
				InitBallInArr(arr, lines, cols, user_choice);
				DoByChoice67(arr, lines, cols, user_choice, visited, path, three_ball_color, three_ball_position, delete_ball_num);
				break;
			case 0:
				tag = 0;
				break;
			default:
				break;
		}
		if (tag == 0)
			break;
		cout << endl;
		int pos_x, pos_y;
		if (user_choice == 1 || user_choice == 2)
		{
			cct_getxy(pos_x, pos_y);
		}
		else if (user_choice == 4)
		{
			pos_x = BASIS_COL + 0;
			pos_y = BASIS_LINE + lines + 2;
		}
		else
		{
			pos_x = BASIS_COL + 0;
			pos_y = BASIS_LINE + 2 * lines + 1;
		}
		to_be_continued(1, pos_x, pos_y);
	}
	return 0;
}

