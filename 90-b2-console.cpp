/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/**
  * ��cmd���ڴ�ӡ����
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
				cct_getxy(ch_pos_x, ch_pos_y);  // ��ȡ��ǰ�������λ��
				cct_showch(ch_pos_x, ch_pos_y, (char)(id + '0'), COLOR_HYELLOW, id, 1);
				cct_setcolor();  //�ָ�ȱʡ��ɫ
				cout << " ";
			}
		}
		cout << endl;
	}
}

/**
  * ��cmd���ڴ�ӡ���ҽ��������ƶ�·��
  */
void PrintSearchResult(int arr[11][11], int visited[11][11], int lines, int cols)
{
	cout << endl;
	cout << "���ҽ�����飺" << endl;
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
	cout << "�ƶ�·��<��ͬɫ��ʶ>��" << endl;
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
				cct_getxy(ch_pos_x, ch_pos_y);  // ��ȡ��ǰ�������λ��
				cct_showch(ch_pos_x, ch_pos_y, (char)(arr[i][j] + '0'), COLOR_HYELLOW, COLOR_HBLUE, 1);
				cct_setcolor();  //�ָ�ȱʡ��ɫ
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void DrawArr1(int arr[11][11], int lines, int cols)
{
	// ����һ�� 
	cct_showstr(BASIS_COL + 0, BASIS_LINE + 0, "��", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i <= cols; i++)
	{
		cct_showstr(BASIS_COL + i * 2, BASIS_LINE + 0, "��", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + (cols + 1) * 2, BASIS_LINE + 0, "��", COLOR_HWHITE, COLOR_HBLACK);
	// ����м�
	for (int i = 1; i <= lines; i++)
	{
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i, "��", COLOR_HWHITE, COLOR_HBLACK);
		for (int j = 1; j <= cols; j++)
		{
			if (arr[i][j] == 0)
				cct_showstr(BASIS_COL + j * 2, BASIS_LINE + i, "  ", COLOR_HWHITE, COLOR_HBLACK);
			else
				cct_showstr(BASIS_COL + j * 2, BASIS_LINE + i, "��", arr[i][j], COLOR_HWHITE);
		}
		cct_showstr(BASIS_COL + cols * 2 + 2, BASIS_LINE + i, "��", COLOR_HWHITE, COLOR_HBLACK);
	}
	// ������һ��
	cct_showstr(BASIS_COL + 0, BASIS_LINE + lines + 1, "��", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i <= cols; i++)
	{
		cct_showstr(BASIS_COL + i * 2, BASIS_LINE + lines + 1, "��", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + (cols + 1) * 2, BASIS_LINE + lines + 1, "��", COLOR_HWHITE, COLOR_HBLACK);
	cct_setcolor();  // �ָ�Ĭ����ɫ
}

void DrawArr2(int arr[11][11], int lines, int cols)
{
	// ����һ��
	int x = 0;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "�X", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	while (x < 2 * cols - 1)
	{
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "�T", COLOR_HWHITE, COLOR_HBLACK);
		x++;
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "�j", COLOR_HWHITE, COLOR_HBLACK);
		x++;
	}
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "�T", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + 0, "�[", COLOR_HWHITE, COLOR_HBLACK);

	// ����м�
	int i = 1;
	while (i <= lines)
	{
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i * 2 - 1, "�U", COLOR_HWHITE, COLOR_HBLACK);
		int j = 1;
		while (j <= cols)
		{
			if (arr[i][j] == 0)
				cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2 - 1, "  ", COLOR_HWHITE, COLOR_HBLACK);
			else
				cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2 - 1, "��", arr[i][j], COLOR_HWHITE);
			cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2 - 1, "�U", COLOR_HWHITE, COLOR_HBLACK);
			j++;
		}
		if (i == lines)  // �������һ�ε����沿��
			break;
		cct_showstr(BASIS_COL + 0, BASIS_LINE + i * 2, "�c", COLOR_HWHITE, COLOR_HBLACK);
		j = 1;
		while (j < cols)
		{
			cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2, "�T", COLOR_HWHITE, COLOR_HBLACK);
			cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2, "�p", COLOR_HWHITE, COLOR_HBLACK);
			j++;
		}
		cct_showstr(BASIS_COL + j * 4 - 2, BASIS_LINE + i * 2, "�T", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + j * 4, BASIS_LINE + i * 2, "�g", COLOR_HWHITE, COLOR_HBLACK);
		i++;
	}
	// ������һ��
	x = 0;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "�^", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	while (x < 2 * cols - 1)
	{
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "�T", COLOR_HWHITE, COLOR_HBLACK);
		x++;
		cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "�m", COLOR_HWHITE, COLOR_HBLACK);
		x++;
	}
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "�T", COLOR_HWHITE, COLOR_HBLACK);
	x++;
	cct_showstr(BASIS_COL + x * 2, BASIS_LINE + i * 2, "�a", COLOR_HWHITE, COLOR_HBLACK);

	cct_setcolor();  // �ָ�Ĭ����ɫ
}

void MouseAction(int arr[11][11], int lines, int cols, int& pre_line, int& pre_col, int& cur_line, int& cur_col)
{
	cout << endl;
	cct_gotoxy(BASIS_COL, BASIS_LINE + 2 * lines + 1);
	int pos_x, pos_y;
	cct_getxy(pos_x, pos_y);
	cct_enable_mouse();
	int mouse_x, mouse_y, action, keycode1, keycode2;  // x �� y ��

	while (1)
	{
		cct_read_keyboard_and_mouse(mouse_x, mouse_y, action, keycode1, keycode2);
		if (action == MOUSE_RIGHT_BUTTON_CLICK)  // �Ҽ��˳�
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
			cout << "[��ǰ���] " << (char)(line + 'A' - 1) << "��" << col << "��" << endl;
			if (action == MOUSE_LEFT_BUTTON_CLICK)  // ��һ�����
			{
				cur_line = line;
				cur_col = col;
				if (arr[cur_line][cur_col] != 0)  // ˵��ѡ����
				{
					if (pre_line != -1 && pre_col != -1)  // ԭ��ѡ�е��� ȡ��ѡ�б��
						RecoverMark(pre_line, pre_col, arr[pre_line][pre_col]);
					DrawMark(cur_line, cur_col, arr[cur_line][cur_col]);
					pre_line = cur_line;
					pre_col = cur_col;
				}
				else  // ˵��ѡ�пհ׵ط�
				{
					if (pre_line != -1 && pre_col != -1)  // ˵��֮ǰѡ�й��� ��ʱ��ҪѰ��·����
					{
						int flag = DrawMove(arr, lines, cols, pre_line, pre_col, cur_line, cur_col);
						if (flag == 1)  // ˵����·��
						{
							arr[cur_line][cur_col] = arr[pre_line][pre_col];  // �����е�˳���ܻ�
							arr[pre_line][pre_col] = 0;
							pre_line = cur_line;  // ֻ����·���Ÿ��� û·��pre����
							pre_col = cur_col;
							break;
						}
					}
				}
			}
		}
	}
	cct_setcolor();  // �ָ�Ĭ����ɫ
}

/**
 * ��(line, col)��ѡ�б��
 */
void DrawMark(int line, int col, int color)  
{
	cct_showstr(BASIS_COL + col * 4 - 2, BASIS_LINE + line * 2 - 1, "��", color, COLOR_HWHITE);
}

/**
 * ��(line, col)���� 1.�����ǿմ�����2.Ҳ���Իָ�δѡ��״̬
 */
void RecoverMark(int line, int col, int color)
{
	cct_showstr(BASIS_COL + col * 4 - 2, BASIS_LINE + line * 2 - 1, "��", color, COLOR_HWHITE);
}

/**
  * �������·���������ƶ����̣�������1�����򣬷���0
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
		cout << "[����] �޷���[" << (char)(start_line + 'A' - 1) << start_col << "]�ƶ���[" << (char)(end_line + 'A' - 1) << end_col << "]" << endl;
		return 0;
	}
	cct_gotoxy(BASIS_COL, BASIS_LINE + 2 * lines + 1);
	cout << "[��ʾ] ���Դ�[" << (char)(start_line + 'A' - 1) << start_col << "]�ƶ���[" << (char)(end_line + 'A' - 1) << end_col << "]" << endl;
		
	int w = 0;  // path[0][0] path[0][1] �����������Ϣ
	
	while (path[w][0] != '\0')
	{
		if (path[w + 1][0] < path[w][0] && path[w + 1][1] == path[w][1])       // ����
			//cout << "��" << " ";
			MoveUp(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] == path[w][0] && path[w + 1][1] > path[w][1])  // ����
			//cout << "��" << " ";
			MoveRight(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] > path[w][0] && path[w + 1][1] == path[w][1])  // ����
			//cout << "��" << " ";
			MoveDown(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		else if (path[w + 1][0] == path[w][0] && path[w + 1][1] < path[w][1])  // ����
			//cout << "��" << " ";
			MoveLeft(path[w][1] - '0', path[w][0] - 'A' + 1, color);
		w++;
	}
	cct_setcolor();  // �ָ�Ĭ����ɫ
	return 1;
}


// �Ӻ�x ��y �����ƶ�
void MoveUp(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 2, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 3, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 2, "�T", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

// �Ӻ�x ��y �����ƶ�
void MoveRight(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4, BASIS_LINE +  y * 2 - 1, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 + 2, BASIS_LINE + y * 2 - 1, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4, BASIS_LINE + y * 2 - 1, "�U", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

// �Ӻ�x ��y �����ƶ�
void MoveDown(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 + 1, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2, "�T", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}


// �Ӻ�x ��y �����ƶ�
void MoveLeft(int x, int y, int color)
{
	int bg_color = color;
	const int fg_color = COLOR_HWHITE;
	cct_showstr(BASIS_COL + x * 4 - 4, BASIS_LINE + y * 2 - 1, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 2, BASIS_LINE + y * 2 - 1, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(200);
	cct_showstr(BASIS_COL + x * 4 - 6, BASIS_LINE + y * 2 - 1, "��", bg_color, fg_color);
	cct_showstr(BASIS_COL + x * 4 - 4, BASIS_LINE + y * 2 - 1, "�U", COLOR_HWHITE, COLOR_BLACK);
	Sleep(200);
}

void ShowMessage(int arr[11][11], int score, int three_ball_color[3], int lines, int cols, int deleteBall[8])
{
	ShowScore(cols, score);  // ��ʾ�÷�
	ShowNextBall(cols, three_ball_color);  // ��ʾ��3����ɫ
	ShowResult(arr, lines, cols, deleteBall);  // ��ʾ���
	cct_setcolor();  // �ָ�Ĭ����ɫ
}

void ShowScore(int cols, int score)
{
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE, "�X", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 6; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE, "�T", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE, "�[", COLOR_HWHITE, COLOR_HBLACK);

	cct_showch(BASIS_COL + 4 * cols + 4, BASIS_LINE + 1, ' ', COLOR_HWHITE, COLOR_HBLACK, 14);
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 1, "�U", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + 1, "�÷֣�", COLOR_HWHITE, COLOR_HBLACK);
	cct_showint(BASIS_COL + 4 * cols + 12, BASIS_LINE + 1, score, COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 1, "�U", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 2, "�^", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 6; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 2, "�T", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 2, "�a", COLOR_HWHITE, COLOR_HBLACK);
}

void ShowNextBall(int cols, int three_ball_color[3])
{
	// �����������������ɫ
	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 4, "�X", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 3; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 2, BASIS_LINE + 4, "�T", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 4, BASIS_LINE + 4, "�h", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 4, "�T", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 4, "�[", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 5, "�U", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + 5, "��", three_ball_color[0], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 8, BASIS_LINE + 5, "�U", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 10, BASIS_LINE + 5, "��", three_ball_color[1], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 12, BASIS_LINE + 5, "�U", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 5, "��", three_ball_color[2], COLOR_HWHITE);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 5, "�U", COLOR_HWHITE, COLOR_HBLACK);

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 6, "�^", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 3; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 2, BASIS_LINE + 6, "�T", COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + i * 4 + 4, BASIS_LINE + 6, "�k", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 14, BASIS_LINE + 6, "�T", COLOR_HWHITE, COLOR_HBLACK);
	cct_showstr(BASIS_COL + 4 * cols + 16, BASIS_LINE + 6, "�a", COLOR_HWHITE, COLOR_HBLACK);
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

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 8, "�X", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 13; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 8, "�T", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + 8, "�[", COLOR_HWHITE, COLOR_HBLACK);

	for (int i = 0; i < 8; i++)
	{
		cct_showch(BASIS_COL + 4 * cols + 4, BASIS_LINE + i + 9, ' ', COLOR_HWHITE, COLOR_HBLACK, 28);
		cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + i + 9, "�U", COLOR_HWHITE, COLOR_HBLACK);
		if (i == 0)
			cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + i + 9, "  ", COLOR_HWHITE, COLOR_HWHITE);
		else
			cct_showstr(BASIS_COL + 4 * cols + 6, BASIS_LINE + i + 9, "��", i, COLOR_HWHITE);

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
		cct_showstr(BASIS_COL + 4 * cols + 21, BASIS_LINE + i + 9, "����-", COLOR_HWHITE, COLOR_HBLACK);
		cct_showint(BASIS_COL + 4 * cols + 26, BASIS_LINE + i + 9, deleteBall[i], COLOR_HWHITE, COLOR_HBLACK);
		cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + i + 9, "�U", COLOR_HWHITE, COLOR_HBLACK);

	}

	cct_showstr(BASIS_COL + 4 * cols + 4, BASIS_LINE + 17, "�^", COLOR_HWHITE, COLOR_HBLACK);
	for (int i = 1; i < 13; i++)
	{
		cct_showstr(BASIS_COL + 4 * cols + i * 2 + 4, BASIS_LINE + 17, "�T", COLOR_HWHITE, COLOR_HBLACK);
	}
	cct_showstr(BASIS_COL + 4 * cols + 30, BASIS_LINE + 17, "�a", COLOR_HWHITE, COLOR_HBLACK);

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

