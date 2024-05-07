/* 2053932 软件 雷翔 */
#include <iostream>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;


void DoByChoice2(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3])
{
	cout << endl;
	cout << "当前数组：" << endl;
	PrintArr(arr, lines, cols);

	int start_line = -1, start_col = -1;  // 起点坐标
	int end_line = -1, end_col = -1;      // 终点坐标


	for (int i = 0; i < 3; i++)  // 为了提前预告球的颜色
	{
		int color = rand() % 7 + 1;
		three_ball_color[i] = color; // 1改成color
	}
	InputStartEnd(arr, lines, cols, start_line, start_col, end_line, end_col, three_ball_color);  // 显示下3个彩球以及输入起点和终点坐标
	//BFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);
	int is_path = DFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);  // 寻找路径，存在路径返回1；不存在则返回0
	if (is_path == 1)
		PrintSearchResult(arr, visited, lines, cols);
	else
		cout << "无法找到移动路径" << endl;
}

void DoByChoice3(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball[3][2], int delete_ball_num[8])
{
	cout << endl;
	PrintArr(arr, lines, cols);

	int start_line = -1, start_col = -1;  // 起点坐标
	int end_line = -1, end_col = -1;      // 终点坐标
	int score = 0;  // 记录总得分
	int is_path = 1;
	while (1)
	{
		int visited[11][11] = { 0 };   // 记录访问过的点
		char path[100][2] = { '\0' };  // 记录路径
		if (is_path == 1)  // 只有当存在路径或第一次时才产生新的3个颜色球
		{
			for (int i = 0; i < 3; i++)
			{
				int color = rand() % 7 + 1;
				three_ball_color[i] = color;  // 1改成color
			}
		}
		InputStartEnd(arr, lines, cols, start_line, start_col, end_line, end_col, three_ball_color);	
		is_path = DFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);
		if (is_path == 1)
		{
			int per_score = MoveStartToEndInArr(arr, path, lines, cols, delete_ball_num);
			score += per_score;
			for (int i = 0; i < 3; i++)
			{
				int color = rand() % 7 + 1;
				three_ball_color[i] = color;  // 1改成color
			}
			CreateThreeBallInArr(arr, lines, cols, three_ball_color, three_ball);
			cout << endl;
			cout << "移动后的数组<不同色标识>：" << endl;
			PrintArr(arr, lines, cols);
			cout << endl;
			cout << "本次得分：" << per_score << " " << "总得分：" << score << endl;
			cout << endl;
			cout << "当前数组：" << endl;
			PrintArr(arr, lines, cols);
		}
		else
			cout << "无法找到移动路径" << endl;
		
		int sum = GetBallNumInArr(arr, lines, cols);  // sum为球的数量
		if (sum + 3 >= lines * cols)
		{
			cout << "失败···" << endl;
			break;
		}
		if (sum == 0)
		{
			cout << "成功！！！" << endl;
			break;
		}
	}
}

void DoByChoice45(int arr[11][11], int lines, int cols, int user_choice)
{
	cout << endl;
	PrintArr(arr, lines, cols);

	int pos_x, pos_y; // 当前光标所在位置
	cout << endl;
	cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
	to_be_continued(2, pos_x, pos_y);
	cct_cls();
	cct_setconsoleborder(40, 25, 40, 25);
	cct_setfontsize("新宋体", 30); //Truetype字体只需要给出一个参数高度即可
	cout << "屏幕：" << 25 << "行" << 40 << "列" << endl;
	if (user_choice == 4)
		DrawArr1(arr, lines, cols);  // 无间隔
	else
		DrawArr2(arr, lines, cols);  // 有间隔  
}

void DoByChoice67(int arr[11][11], int lines, int cols, int user_choice, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8])
{
	int pos_x, pos_y;
	if (user_choice == 6)
	{
		cout << endl;
		PrintArr(arr, lines, cols);
		cout << endl;
		cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
		to_be_continued(2, pos_x, pos_y);
	}
	cct_cls();
	cct_setcursor(CURSOR_INVISIBLE);  // 不显示光标
	cct_setconsoleborder(70, 60, 70, 60);
	cct_setfontsize("新宋体", 28); //Truetype字体只需要给出一个参数高度即可
	cout << "屏幕：" << 23 << "行" << 70 << "列(右键退出)" << endl;
	DrawArr2(arr, lines, cols);  // 有间隔  

	int start_line = -1, start_col = -1;  // 起点坐标
	int end_line = -1, end_col = -1;      // 终点坐标
	int score = 0;  // 记录总得分
	

	while (1)
	{
		// 这里不需要判断是否有路径，因为之后有路径才会退出MouseAction
		for (int i = 0; i < 3; i++)  // 为了提前预告球的颜色
		{
			int color = rand() % 7 + 1;
			three_ball_color[i] = color;  // 1改成color
		}
		if (user_choice == 7)
			ShowMessage(arr, score, three_ball_color, lines, cols, delete_ball_num);
		MouseAction(arr, lines, cols, start_line, start_col, end_line, end_col);
		if (end_line == -1 && end_col == -1)  // 说明按了右键
			break;
		if (user_choice == 6)
			break;
		int per_score = IsDelete(arr, end_line, end_col, lines, cols, delete_ball_num);  // 如果有5个及以上的话，会更改arr的值
		if (per_score != 0)  // 说明本次移动完成了消球
		{
			start_line = -1;
			start_col = -1;
			end_line = -1;
			end_col = -1;
		}
		score += per_score;
		CreateThreeBallInArr(arr, lines, cols, three_ball_color, three_ball_position);
		DrawArr2(arr, lines, cols);  // 消除5个球后，重新画一遍
		DrawThreeBall(three_ball_position, three_ball_color);

		int sum = GetBallNumInArr(arr, lines, cols);  // sum为球的数量
		if (sum + 3 >= lines * cols)
		{
			cct_gotoxy(BASIS_COL + 0, BASIS_LINE + 2 * lines + 2);
			cout << "失败···" << endl;
			break;
		}
		if (sum == 0)
		{
			cct_gotoxy(BASIS_COL + 0, BASIS_LINE + 2 * lines + 2);
			cout << "成功！！！" << endl;
			break;
		}
	}
}

/**
  * 返回数组中球的数量
  */
int GetBallNumInArr(int arr[11][11], int lines, int cols)
{
	int sum = 0;
	for (int i = 1; i <= lines; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			if (arr[i][j] > 0)
				sum++;
		}
	}
	return sum;
}

void InputLinesCols(int& lines, int& cols)
{
	cct_cls();  // 清屏
	while (1)
	{
		cout << "请输入行数(7-9)：" << endl;
		cin >> lines;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (lines >= 7 && lines <= 9)
			break;
	}

	while (1)
	{
		cout << "请输入列数(7-9)：" << endl;
		cin >> cols;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\0');
		}
		if (cols >= 7 && cols <= 9)
			break;
	}

	while (getchar() != '\n');  // 清空缓冲区
}

void InitArrToZero(int arr[11][11])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void InitBallInArr(int arr[11][11], int lines, int cols, int user_chioce)
{
	InitArrToZero(arr);  // 初始化数组，全部置0
	int count = 0;  // 记录生成球的数量
	if (user_chioce == 1 || user_chioce == 4 || user_chioce == 5 || user_chioce == 7)
		count = 5;
	else if (user_chioce == 2 || user_chioce == 6)
		count = (int)lines * cols * 3 / 5;
	while (count > 0)
	{
		int line_pos = rand() % lines + 1;  // 纵
		int col_pos = rand() % cols + 1;    // 横
		int color = rand() % 7 + 1;
		if (arr[line_pos][col_pos] == 0)
		{
			arr[line_pos][col_pos] = color;  // 1改成color
			count--;
		}
	}
}

void InputStartEnd(int arr[11][11], int lines, int cols, int& start_line, int& start_col, int& end_line, int& end_col, int three_ball_color[3])
{
	cout << endl;
	cout << "下3个彩球的颜色分别是：" << three_ball_color[0] << " " << three_ball_color[1] << " " << three_ball_color[2] << endl;
	int pos_x, pos_y; // 当前光标所在位置
	cout << "请以字母+数组形式[例：c2]输入要移动球的矩阵坐标：";
	cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
	while (1)
	{
		cct_gotoxy(pos_x, pos_y);
		cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 10);
		cct_gotoxy(pos_x, pos_y);
		char ch1 = getchar();
		if (ch1 >= 'A' && ch1 <= 'A' + lines - 1)
			ch1 += ('a' - 'A');
		if (ch1 < 'a' || ch1 > 'a' + lines - 1)
		{
			cout << "输入错误，请重新输入." << endl;
			while (getchar() != '\n');  // 清空缓冲区
			continue;
		}
		char ch2 = getchar();

		if (ch2 < '1' || ch2 > '1' + cols - 1)
		{
			cout << "输入错误，请重新输入." << endl;
			if (ch2 != '\n')
			while (getchar() != '\n');  // 清空缓冲区
			continue;
		}
		start_line = ch1 - 'a' + 1;
		start_col = ch2 - '1' + 1;
		if (start_line >= 1 && start_line <= lines && start_col >= 1 && start_col <= cols)
		{
			if (arr[start_line][start_col] == 0)
			{
				cout << "起始位置为空，请重新输入." << endl;
				while (getchar() != '\n');  // 清空缓冲区
				cout << "请以字母+数组形式[例：c2]输入要移动球的矩阵坐标：";
				pos_y += 2;
				continue;
			}
			else
			{
				cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 10);
				cct_gotoxy(0, pos_y + 1);
				cout << "输入为" << (char)(ch1 - 'a' + 'A') << "行" << ch2 - '1' + 1 << "列" << endl;
				break;
			}
		}
	}
	while (getchar() != '\n');  // 清空缓冲区

	cout << "请以字母+数组形式[例：c2]输入要移动球的目标坐标：";
	cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
	while (1)
	{
		cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 10);
		cct_gotoxy(pos_x, pos_y);
		char ch3 = getchar();
		if (ch3 >= 'A' && ch3 <= 'A' + lines - 1)
			ch3 += ('a' - 'A');
		if (ch3 < 'a' || ch3 > 'a' + lines - 1)
		{
			cout << "输入错误，请重新输入." << endl;
			while (getchar() != '\n');  // 清空缓冲区
			continue;
		}
		char ch4 = getchar();
		if (ch4 < '1' || ch4 > '1' + cols - 1)
		{
			cout << "输入错误，请重新输入." << endl;
			while (getchar() != '\n');  // 清空缓冲区
			continue;
		}
		end_line = ch3 - 'a' + 1;
		end_col = ch4 - '1' + 1;
		if (end_line >= 1 && end_line <= lines && end_col >= 1 && end_col <= cols)
		{
			if (arr[end_line][end_col] != 0)
			{
				cout << "目标位置非空，请重新输入" << endl;
				while (getchar() != '\n');  // 清空缓冲区
				cout << "请以字母+数组形式[例：c2]输入要移动球的目的坐标：";
				pos_y += 2;
			}
			else
			{
				cout << "输入为" << (char)(ch3 - 'a' + 'A') << "行" << ch4 - '1' + 1 << "列" << endl;
				break;
			}
		}
	}
	while (getchar() != '\n'); // 清空缓冲区
}

/**
  * 判断从(start_line, start_col)到(end_line, end_col)是否存在路径，如果存在，将路径记录在path数组中，并返回1，不存在则返回0
  */
int DFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2])
{
	visited[start_line][start_col] = 1;
	if (start_line == end_line && start_col == end_col)
	{
		InsertPoint(path, end_line, end_col);
		return 1;
	}
	//visited[start_line][start_col] = 1;
	InsertPoint(path, start_line, start_col);
	int result1 = 0, result2 = 0, result3 = 0, result4 = 0;
	if (arr[start_line - 1][start_col] == 0 && start_line > 1 && visited[start_line - 1][start_col] == 0)  // 向上
	{
		result1 = DFS(arr, lines, cols, start_line - 1, start_col, end_line, end_col, visited, path);
		if (result1 == 1)
			return 1;
	}
	if (arr[start_line][start_col + 1] == 0 && start_col < cols && visited[start_line][start_col + 1] == 0)  // 向右
	{
		result2 = DFS(arr, lines, cols, start_line, start_col + 1, end_line, end_col, visited, path);
		if (result2 == 1)
			return 1;
	}
	if (arr[start_line + 1][start_col] == 0 && start_line < lines && visited[start_line + 1][start_col] == 0)  // 向下
	{
		result3 = DFS(arr, lines, cols, start_line + 1, start_col, end_line, end_col, visited, path);
		if (result3 == 1)
			return 1;
	}
	if (arr[start_line][start_col - 1] == 0 && start_col > 1 && visited[start_line][start_col - 1] == 0)  // 向左
	{
		result4 = DFS(arr, lines, cols, start_line, start_col - 1, end_line, end_col, visited, path);
		if (result4 == 1)
			return 1;
	}
	visited[start_line][start_col] = 0;
	RemovePoint(path);
	return 0;
}


struct Point
{
	int line;
	int col;
	Point() : line(-1), col(-1) {};
};



void InsertPath(int i, int j, Point pre[11][11], char path[100][2], int& p)
{
	if (pre[i][j].line != -1)
		InsertPath(pre[i][j].line, pre[i][j].col, pre, path, p);
	path[p][0] = i + 'A' - 1;
	path[p][1] = j + '0';
	p++;
}

int BFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2])
{

	int is_path = 0; 
	Point pre[11][11];  // pre用于存储该点的前一点（类似父节点）从这一点走过来

	int to_line;
	int to_col;

	// 使用BFS遍历时，为了获得最短路径，每次路径需要保存上一点位置
	int path_index_arr[100][2] = {0};
	for (int i = 0; i < 100; i++)
	{
		path_index_arr[i][0] = -1;
		path_index_arr[i][1] = -1;
	}

	int front = -1, tail = -1;  // front指向队首，tail指向队尾 front指向第一个元素的前一项，tail指向最后一个元素
	tail++;
	path_index_arr[tail][0] = start_line;
	path_index_arr[tail][1] = start_col;

	pre[start_line][start_col].line = -1;
	pre[start_line][start_col].col = -1;
	while (front != tail)
	{
		int line = path_index_arr[front + 1][0];  // (line, col)为队头点
		int col = path_index_arr[front + 1][1];
		front++;  // 队首元素出队，移动队首指针就行
		if (line == end_line && col == end_col)  // 找到终点
		{
			is_path = 1;  // 存在路径
			break;
		}
		visited[line][col] = 1;
		if (arr[line - 1][col] == 0 && line > 1 && visited[line - 1][col] == 0)  // 向上
		{
			to_line = line - 1;
			to_col = col;
			visited[to_line][to_col] = 1;
			tail++;
			path_index_arr[tail][0] = to_line;
			path_index_arr[tail][1] = to_col;
			pre[to_line][to_col].line = line;
			pre[to_line][to_col].col = col;
		}
		if (arr[line][col + 1] == 0 && col < cols && visited[line][col + 1] == 0)  // 向右
		{
			to_line = line;
			to_col = col + 1;
			visited[to_line][to_col] = 1;
			tail++;
			path_index_arr[tail][0] = to_line;
			path_index_arr[tail][1] = to_col;
			pre[to_line][to_col].line = line;
			pre[to_line][to_col].col = col;
		}
		if (arr[line + 1][col] == 0 && line < lines && visited[line + 1][col] == 0)  // 向下
		{
			to_line = line + 1;
			to_col = col;
			visited[to_line][to_col] = 1;
			tail++;
			path_index_arr[tail][0] = to_line;
			path_index_arr[tail][1] = to_col;
			pre[to_line][to_col].line = line;
			pre[to_line][to_col].col = col;
		}
		if (arr[line][col - 1] == 0 && col > 1 && visited[line][col - 1] == 0)  // 向左
		{
			to_line = line;
			to_col = col - 1;
			visited[to_line][to_col] = 1;
			tail++;
			path_index_arr[tail][0] = to_line;
			path_index_arr[tail][1] = to_col;
			pre[to_line][to_col].line = line;
			pre[to_line][to_col].col = col;
		}
	}
	int p = 0;
	InsertPath(end_line, end_col, pre, path, p);
	int i = 0;
	return is_path;
}


/**
  * 插在path数组最后 DFS方法中使用
  */
void InsertPoint(char path[100][2], int line, int col)
{
	int i = 0;
	while (path[i][0] != '\0')
		i++;
	path[i][0] = line + 'A' - 1;
	path[i][1] = col + '0';
}

/**
  * 删除path数组最后一个点 DFS方法中使用
  */
void RemovePoint(char path[100][2])
{
	int i = 0;
	while (path[i][0] != '\0')
		i++;
	path[i - 1][0] = '\0';
	path[i - 1][1] = '\0';
}

/**
  * 返回移动后的分数 
  */
int MoveStartToEndInArr(int arr[11][11], char path[100][2], int lines, int cols, int deleteBall[8])
{
	int i1 = path[0][0] - 'A' + 1;
	int j1 = path[0][1] - '0';
	int i = 0;
	while (path[i][0] != '\0')
		i++;
	int i2 = path[i - 1][0] - 'A' + 1;
	int j2 = path[i - 1][1] - '0';
	arr[i2][j2] = arr[i1][j1];  // 这一行和下一行的顺序不能反
	arr[i1][j1] = 0;
	return IsDelete(arr, i2, j2, lines, cols, deleteBall);;
}

/**
  * 将球移到(end_line, end_col)后判断是否能够消除
  * 如果可以，消除然后返回得分，如果不行返回0
  * 按照demo，消除n个球，得(N-1)*(N-2)分
  */
int IsDelete(int arr[11][11], int end_line, int end_col, int lines, int cols, int delete_ball_num[8])
{
	int n = 0;  // 统计每次消球的数量
	int per_score = 0;  // 统计分数
	int color = arr[end_line][end_col];
	int sumy1 = 0;  // 统计连续竖球的数量 该位置 + 向下
	int sumy2 = 0;  // 统计连续竖球的数量 不包括 + 向上
	int sumx1 = 0;  // 统计连续横球的数量 该位置 + 向右
	int sumx2 = 0;  // 统计连续横球的数量 不包括 + 向左
	// 先考虑竖
	// 向下
	for (int i = end_line; i <= lines; i++)
	{
		if (arr[i][end_col] == 0 || arr[i][end_col] != color)
			break;
		sumy1++;
	}
	// 向上
	for (int i = end_line - 1; i > 0; i--)
	{
		if (arr[i][end_col] == 0 || arr[i][end_col] != color)
			break;
		sumy2++;
	}
	// 考虑横
	// 向右
	for (int i = end_col; i <= cols; i++)
	{
		if (arr[end_line][i] == 0 || arr[end_line][i] != color)
			break;
		sumx1++;
	}
	// 向左
	for (int i = end_col - 1; i > 0; i--)
	{
		if (arr[end_line][i] == 0 || arr[end_line][i] != color)
			break;
		sumx2++;
	}

	// 既有竖也有横 计算球的分数，并从数组中删除这些点
	if (sumy1 + sumy2 >= 5 && sumx1 + sumx2 >= 5)
	{
		n = sumy1 + sumy2 + sumx1 + sumx2 - 1;
		per_score = (n - 1) * (n - 2);
		delete_ball_num[arr[end_line][end_col]] += n;
		for (int i = end_line - sumy2; i < end_line + sumy1; i++)
			arr[i][end_col] = 0;
		for (int i = end_col - sumx2; i < end_col + sumx1; i++)
			arr[end_line][i] = 0;
	}
	// 只有竖 计算球的分数，并从数组中删除这些点
	else if (sumy1 + sumy2 >= 5)
	{
		n = sumy1 + sumy2;
		per_score = (n - 1) * (n - 2);
		delete_ball_num[arr[end_line][end_col]] += n;
		for (int i = end_line - sumy2; i < end_line + sumy1; i++)
			arr[i][end_col] = 0;
	}
	// 只有横 计算球的分数，并从数组中删除这些点
	else if (sumx1 + sumx2 >= 5)
	{
		n = sumx1 + sumx2;
		per_score = (n - 1) * (n - 2);
		delete_ball_num[arr[end_line][end_col]] += n;
		for (int i = end_col - sumx2; i < end_col + sumx1; i++)
			arr[end_line][i] = 0;
	}
	return per_score;
}

void CreateThreeBallInArr(int arr[11][11], int lines, int cols, int three_ball_color[3], int three_ball[3][2])
{
	int count = 0;  // 记录生成球的数量
	while (count < 3)
	{
		int line_pos = rand() % lines + 1;  // 纵
		int col_pos = rand() % cols + 1;    // 横
		if (arr[line_pos][col_pos] == 0)
		{
			arr[line_pos][col_pos] = three_ball_color[count];
			three_ball[count][0] = line_pos;
			three_ball[count][1] = col_pos;
			count++;
		}
	}
}


