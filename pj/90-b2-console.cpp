/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/**
  * 在cmd窗口打印数组
  */
void PrintArr(int arr[11][11], int lines, int cols)
{
	cout << " " << " | ";
	for (int i = 1; i <= cols; i++)
		cout << " " << i << " ";
	cout << endl;
	cout << "--+-";
	int jianhao_num = 3 * cols;
	cout << setw(jianhao_num) << setfill('-') << "-" << endl;
	for (int i = 1; i <= lines; i++)
	{
		cout << (char)(i + 'A' - 1) << " " << "|" << " ";
		for (int j = 1; j <= cols; j++)
		{
			int id = arr[i][j];

			if (id == 0)
				cout << " " << id << " ";
			else
			{
				int ch_pos_x, ch_pos_y;
				cout << " ";
				cct_getxy(ch_pos_x, ch_pos_y);  // 获取当前光标所在位置
				cct_showch(ch_pos_x, ch_pos_y, (char)(id + '0'), COLOR_HYELLOW, id, 1);
				cct_setcolor();  //恢复缺省颜色
				cout << " ";
			}
		}
		cout << endl;
	}
}

/**
  * 在cmd窗口打印查找结果数组和移动路径
  */
void PrintSearchResult(int arr[11][11], int visited[11][11], int lines, int cols)
{
	cout << endl;
	cout << "查找结果数组：" << endl;
	cout << " " << " | ";
	for (int i = 1; i <= cols; i++)
		cout << " " << i << " ";
	cout << endl;
	int jianhao_num = 3 * cols + 4;
	cout << setw(jianhao_num) << setfill('-') << "-" << endl;
	for (int i = 1; i <= lines; i++)
	{
		cout << (char)(i + 'A' - 1) << " " << "|" << " ";
		for (int j = 1; j <= cols; j++)
		{
			int id = visited[i][j];

			if (id == 0)
				cout << " " << id << " ";
			else
				cout << " * ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "移动路径<不同色标识>：" << endl;
	cout << " " << " | ";
	for (int i = 1; i <= cols; i++)
		cout << " " << i << " ";
	cout << endl;
	cout << setw(jianhao_num) << setfill('-') << "-" << endl;
	for (int i = 1; i <= lines; i++)
	{
		cout << (char)(i + 'A' - 1) << " " << "|" << " ";
		for (int j = 1; j <= cols; j++)
		{
			int id = visited[i][j];

			if (id == 0)
				cout << " " << arr[i][j] << " ";
			else
			{
				int ch_pos_x, ch_pos_y;
				cout << " ";
				cct_getxy(ch_pos_x, ch_pos_y);  // 获取当前光标所在位置
				cct_showch(ch_pos_x, ch_pos_y, (char)(arr[i][j] + '0'), COLOR_HYELLOW, COLOR_HBLUE, 1);
				cct_setcolor();  //恢复缺省颜色
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void DrawArr1(int arr[11][11], int lines, int cols)
{
	// 表格第一行 
	cct_showstr(BASIS_COL + 0, BASIS_LINE + 0, "┏", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i <= cols; i++)
	{
		cct_showstr(BASIS_COL + i * 2, BASIS_LINE + 0, "━", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + (cols + 1) * 2, BASIS_LINE + 0, "┓", COLOR_HWHITE, COLOR_HBLACK);
	// 表格中间
	for (int i = 1; i <= lines; i++)
	{
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i, "┃", COLOR_HWHITE, COLOR_HBLACK);
		for (int j = 1; j <= cols; j++)
		{
			if (arr[i][j] == 0)
				cct_showstr(BASIS_COL + j * 2, BASIS_LINE + i, "  ", COLOR_HWHITE, COLOR_HBLACK);
			else
				cct_showstr(BASIS_COL + j * 2, BASIS_LINE + i, "○", arr[i][j], COLOR_HWHITE);
		}
		cct_showstr(BASIS_COL + cols * 2 + 2, BASIS_LINE + i, "┃", COLOR_HWHITE, COLOR_HBLACK);
	}
	// 表格最后一行
	cct_showstr(BASIS_COL + 0, BASIS_LINE + lines + 1, "┗", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i <= cols; i++)
	{
		cct_showstr(BASIS_COL + i * 2, BASIS_LINE + lines + 1, "━", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + (cols + 1) * 2, BASIS_LINE + lines + 1, "┛", COLOR_HWHITE, COLOR_HBLACK);
	cct_setcolor();  // 恢复默认颜色
}

void DrawArr2(int arr[11][11], int lines, int cols)
{
	// 表格第一行
	int x = 0;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "╔", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	while (x < 2 * cols - 1)
	{
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "═", COLOR_HWHITE, COLOR_HBLACK);
		x++;
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "╦", COLOR_HWHITE, COLOR_HBLACK);
		x++;
	}
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "═", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "╗", COLOR_HWHITE, COLOR_HBLACK);

	// 表格中间
	int i = 1;
	while (i <= lines)
	{
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i * 2 - 1, "║", COLOR_HWHITE, COLOR_HBLACK);
		int j = 1;
		while (j <= cols)
		{
			if (arr[i][j] == 0)
				cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2 - 1, "  ", COLOR_HWHITE, COLOR_HBLACK);
			else
				cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2 - 1, "〇", arr[i][j], COLOR_HWHITE);
			cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2 - 1, "║", COLOR_HWHITE, COLOR_HBLACK);
			j++;
		}
		if (i == lines)  // 不画最后一次的下面部分
			break;
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i * 2, "╟", COLOR_HWHITE, COLOR_HBLACK);
		j = 1;
		while (j < cols)
		{
			cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2, "═", COLOR_HWHITE, COLOR_HBLACK);
			cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2, "╬", COLOR_HWHITE, COLOR_HBLACK);
			j++;
		}
		cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2, "═", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2, "╣", COLOR_HWHITE, COLOR_HBLACK);
		i++;
	}
	// 表格最后一行
	x = 0;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "╚", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	while (x < 2 * cols - 1)
	{
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "═", COLOR_HWHITE, COLOR_HBLACK);
		x++;
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "╩", COLOR_HWHITE, COLOR_HBLACK);
		x++;
	}
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "═", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "╝", COLOR_HWHITE, COLOR_HBLACK);

	cct_setcolor();  // 恢复默认颜色
}

void MouseAction(int arr[11][11], int lines, int cols, int& pre_line, int& pre_col, int& cur_line, int& cur_col)
{
	cout << endl;
	cct_gotoxy(BASIS_COL, BASIS_LINE + 2 * lines + 1);
	int pos_x, pos_y;
	cct_getxy(pos_x, pos_y);
	cct_enable_mouse();
	int mouse_x, mouse_y, action, keycode1, keycode2;  // x 横 y 竖

	while (1)
	{
		cct_read_keyboard_and_mouse(mouse_x, mouse_y, action, keycode1, keycode2);
		if (action == MOUSE_RIGHT_BUTTON_CLICK)  // 右键退出
		{
			cur_line = -1;
			cur_col = -1;
			break;
		}
			
		int line = (mouse_y + 1 - BASIS_LINE) / 2;
		int col = (mouse_x + 2 - BASIS_COL) / 4;
		if (line >= 1 && line <= lines && col >= 1 && col <= cols)
		{
			cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 30);
			cct_gotoxy(pos_x, pos_y);
			cout << "[当前光标] " << (char)(line + 'A' - 1) << "行" << col << "列" << endl;
			if (action == MOUSE_LEFT_BUTTON_CLICK)  // 按一下左键
			{
				cur_line = line;
				cur_col = col;
				if (arr[cur_line][cur_col] != 0)  // 说明选中球
				{
					if (pre_line != -1 && pre_col != -1)  // 原来选中的球 取消选中标记
						RecoverMark(pre_line, pre_col, arr[pre_line][pre_col]);
					DrawMark(cur_line, cur_col, arr[cur_line][cur_col]);
					pre_line = cur_line;
					pre_col = cur_col;
				}
				else  // 说明选中空白地方
				{
					if (pre_line != -1 && pre_col != -1)  // 说明之前选中过球 此时就要寻找路径了
					{
						int flag = DrawMove(arr, lines, cols, pre_line, pre_col, cur_line, cur_col);
						if (flag == 1)  // 说明有路径
						{
							arr[cur_line][cur_col] = arr[pre_line][pre_col];  // 这两行的顺序不能换
							arr[pre_line][pre_col] = 0;
							pre_line = cur_line;  // 只有有路径才更新 没路径pre不变
							pre_col = cur_col;
							break;
						}
					}
				}
			}
		}
	}
	cct_setcolor();  // 恢复默认颜色
}

/**
 * 在(line, col)画选中标记
 */
void DrawMark(int line, int col, int color)  
{
	cct_showstr(BASIS_COL + col * 4 - 2, BASIS_LINE + line * 2 - 1, "◎", color, COLOR_HWHITE);
}

/**
 * 在(line, col)画球 1.可以是空处画球；2.也可以恢复未选中状态
 */
void RecoverMark(int line, int col, int color)
{
	cct_showstr(BASIS_COL + col * 4 - 2, BASIS_LINE + line * 2 - 1, "〇", color, COLOR_HWHITE);
}

/**
  * 如果存在路径，画出移动过程，并返回1，否则，返回0
  */
int DrawMove(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col)
{
	int color = arr[start_line][start_col];
	int visited[11][11] = { 0 };
	char path[100][2] = { '\0' };
	int is_path = BFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);
	//int is_path = DFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);
	if (is_path == 0)
	{
		cct_gotoxy(BASIS_COL, BASIS_LINE + 2 * lines + 1);
		cout << "[错误] 无法从[" << (char)(start_line + 'A' - 1) << start_col << "]移动到[" << (char)(end_line + 'A' - 1) << end_col << "]" << endl;
		return 0;
	}
	cct_gotoxy(BASIS_COL, BASIS_LINE + 2 * lines + 1);
	cout << "[提示] 可以从[" << (char)(start_line + 'A' - 1) << start_col << "]移动到[" << (char)(end_line + 'A' - 1) << end_col << "]" << endl;
		
	int w = 0;  // path[0][0] path[0][1] 存的是起点的信息
	
	while (path[w][0] != '\0')
	{
		if (path[w + 1][0] < path[w][0] && path[w + 1][1] == path[w][1])       // 上移
			//cout << "上" << " ";
			MoveUp(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] == path[w][0] && path[w + 1][1] > path[w][1])  // 右移
			//cout << "右" << " ";
			MoveRight(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] > path[w][0] && path[w + 1][1] == path[w][1])  // 下移
			//cout << "下" << " ";
			MoveDown(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] == path[w][0] && path[w + 1][1] < path[w][1])  // 左移
			//cout << "左" << " ";
			MoveLeft(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		w++;
	}
	cct_setcolor();  // 恢复默认颜色
	return 1;
}


// 从横x 纵y 向上移动
void MoveUp(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 2, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 3, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 2, "═", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

// 从横x 纵y 向右移动
void MoveRight(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4, BASIS_LINE +  y * 2 - 1, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 + 2, BASIS_LINE + y * 2 - 1, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4, BASIS_LINE + y * 2 - 1, "║", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

// 从横x 纵y 向下移动
void MoveDown(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 + 1, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2, "═", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}


// 从横x 纵y 向左移动
void MoveLeft(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 4, BASIS_LINE + y * 2 - 1, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 6, BASIS_LINE + y * 2 - 1, "◎", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 4, BASIS_LINE + y * 2 - 1, "║", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

void ShowMessage(int arr[11][11], int score, int three_ball_color[3], int lines, int cols, int deleteBall[8])
{
	ShowScore(cols, score);  // 显示得分
	ShowNextBall(cols, three_ball_color);  // 显示下3球颜色
	ShowResult(arr, lines, cols, deleteBall);  // 显示结果
	cct_setcolor();  // 恢复默认颜色
}

void ShowScore(int cols, int score)
{
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE, "╔", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 6; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE, "═", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE, "╗", COLOR_HWHITE, COLOR_HBLACK);

	cct_showch(BASIS_COL + 4 * cols + 4, BASIS_LINE + 1, ' ', COLOR_HWHITE, COLOR_HBLACK, 14);
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 1, "║", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + 1, "得分：", COLOR_HWHITE, COLOR_HBLACK);
	cct_showint(BASIS_COL + 4 * cols + 12, BASIS_LINE + 1, score, COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 1, "║", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 2, "╚", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 6; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 2, "═", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 2, "╝", COLOR_HWHITE, COLOR_HBLACK);
}

void ShowNextBall(int cols, int three_ball_color[3])
{
	// 接下来的三个球的颜色
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 4, "╔", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 3; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 2, BASIS_LINE + 4, "═", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 4, BASIS_LINE + 4, "╤", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 4, "═", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 4, "╗", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 5, "║", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + 5, "○", three_ball_color[0], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 8, BASIS_LINE + 5, "║", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 10, BASIS_LINE + 5, "○", three_ball_color[1], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 12, BASIS_LINE + 5, "║", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 5, "○", three_ball_color[2], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 5, "║", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 6, "╚", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 3; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 2, BASIS_LINE + 6, "═", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 4, BASIS_LINE + 6, "╧", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 6, "═", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 6, "╝", COLOR_HWHITE, COLOR_HBLACK);
}

void ShowResult(int arr[11][11], int lines, int cols, int deleteBall[8])
{
	int ball_color_num[8] = { 0 };
	for (int i = 1; i <= lines; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			if (arr[i][j] == 0)
				ball_color_num[0]++;
			else if (arr[i][j] == 1)
				ball_color_num[1]++;
			else if (arr[i][j] == 2)
				ball_color_num[2]++;
			else if (arr[i][j] == 3)
				ball_color_num[3]++;
			else if (arr[i][j] == 4)
				ball_color_num[4]++;
			else if (arr[i][j] == 5)
				ball_color_num[5]++;
			else if (arr[i][j] == 6)
				ball_color_num[6]++;
			else if (arr[i][j] == 7)
				ball_color_num[7]++;
		}
	}

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 8, "╔", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 13; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 8, "═", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + 8, "╗", COLOR_HWHITE, COLOR_HBLACK);

	for (int i = 0; i < 8; i++)
	{
		cct_showch(BASIS_COL + 4 * cols + 4, BASIS_LINE + i + 9, ' ', COLOR_HWHITE, COLOR_HBLACK, 28);
		cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + i + 9, "║", COLOR_HWHITE, COLOR_HBLACK);
		if (i == 0)
			cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + i + 9, "  ", COLOR_HWHITE, COLOR_HWHITE);
		else
			cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + i + 9, "○", i, COLOR_HWHITE);

		cct_showch(BASIS_COL + 4 * cols + 8, BASIS_LINE + i + 9, ':', COLOR_HWHITE, COLOR_HBLACK);

		if (ball_color_num[i] < 10)
		{
			cct_showch(BASIS_COL + 4 * cols + 9, BASIS_LINE + i + 9, '0', COLOR_HWHITE, COLOR_HBLACK);
			cct_showint(BASIS_COL + 4 * cols + 10, BASIS_LINE + i + 9, ball_color_num[i], COLOR_HWHITE, COLOR_HBLACK);
		}
		else
			cct_showint(BASIS_COL + 4 * cols + 9, BASIS_LINE + i + 9, ball_color_num[i], COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + 11, BASIS_LINE + i + 9, "/(", COLOR_HWHITE, COLOR_HBLACK);
		int num1 = ball_color_num[i] * 100 / lines / cols;
		int num2 = ball_color_num[i] * 10000 / lines / cols % 100;
		if (num1 < 10)
		{
			cct_showch(BASIS_COL + 4 * cols + 13, BASIS_LINE + i + 9, ' ', COLOR_HWHITE, COLOR_HBLACK);
			cct_showint(BASIS_COL + 4 * cols + 14, BASIS_LINE + i + 9, num1, COLOR_HWHITE, COLOR_HBLACK);
		}
		else
			cct_showint(BASIS_COL + 4 * cols + 13, BASIS_LINE + i + 9, num1, COLOR_HWHITE, COLOR_HBLACK);
		cct_showch(BASIS_COL + 4 * cols + 15, BASIS_LINE + i + 9, '.', COLOR_HWHITE, COLOR_HBLACK);
		if (num2 < 10)
		{
			cct_showch(BASIS_COL + 4 * cols + 16, BASIS_LINE + i + 9, '0', COLOR_HWHITE, COLOR_HBLACK);
			cct_showint(BASIS_COL + 4 * cols + 17, BASIS_LINE + i + 9, num2, COLOR_HWHITE, COLOR_HBLACK);
		}
		else
			cct_showint(BASIS_COL + 4 * cols + 16, BASIS_LINE + i + 9, num2, COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + 18, BASIS_LINE + i + 9, "%)", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + 21, BASIS_LINE + i + 9, "消除-", COLOR_HWHITE, COLOR_HBLACK);
		cct_showint(BASIS_COL + 4 * cols + 26, BASIS_LINE + i + 9, deleteBall[i], COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + i + 9, "║", COLOR_HWHITE, COLOR_HBLACK);

	}

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 17, "╚", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 13; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 17, "═", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + 17, "╝", COLOR_HWHITE, COLOR_HBLACK);

}

void DrawThreeBall(int three_ball[3][2], int three_ball_color[3])
{
	for (int w = 0; w < 3; w++)
	{
		int i = three_ball[w][0];
		int j = three_ball[w][1];
		int color = three_ball_color[w];
		RecoverMark(i, j, color);
	}
}

