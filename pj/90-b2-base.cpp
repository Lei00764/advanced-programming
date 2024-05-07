/* 2053932 ��� ���� */
#include <iostream>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;


void DoByChoice2(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3])
{
	cout << endl;
	cout << "��ǰ���飺" << endl;
	PrintArr(arr, lines, cols);

	int start_line = -1, start_col = -1;  // �������
	int end_line = -1, end_col = -1;      // �յ�����


	for (int i = 0; i < 3; i++)  // Ϊ����ǰԤ�������ɫ
	{
		int color = rand() % 7 + 1;
		three_ball_color[i] = color; // 1�ĳ�color
	}
	InputStartEnd(arr, lines, cols, start_line, start_col, end_line, end_col, three_ball_color);  // ��ʾ��3�������Լ����������յ�����
	//BFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);
	int is_path = DFS(arr, lines, cols, start_line, start_col, end_line, end_col, visited, path);  // Ѱ��·��������·������1���������򷵻�0
	if (is_path == 1)
		PrintSearchResult(arr, visited, lines, cols);
	else
		cout << "�޷��ҵ��ƶ�·��" << endl;
}

void DoByChoice3(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball[3][2], int delete_ball_num[8])
{
	cout << endl;
	PrintArr(arr, lines, cols);

	int start_line = -1, start_col = -1;  // �������
	int end_line = -1, end_col = -1;      // �յ�����
	int score = 0;  // ��¼�ܵ÷�
	int is_path = 1;
	while (1)
	{
		int visited[11][11] = { 0 };   // ��¼���ʹ��ĵ�
		char path[100][2] = { '\0' };  // ��¼·��
		if (is_path == 1)  // ֻ�е�����·�����һ��ʱ�Ų����µ�3����ɫ��
		{
			for (int i = 0; i < 3; i++)
			{
				int color = rand() % 7 + 1;
				three_ball_color[i] = color;  // 1�ĳ�color
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
				three_ball_color[i] = color;  // 1�ĳ�color
			}
			CreateThreeBallInArr(arr, lines, cols, three_ball_color, three_ball);
			cout << endl;
			cout << "�ƶ��������<��ͬɫ��ʶ>��" << endl;
			PrintArr(arr, lines, cols);
			cout << endl;
			cout << "���ε÷֣�" << per_score << " " << "�ܵ÷֣�" << score << endl;
			cout << endl;
			cout << "��ǰ���飺" << endl;
			PrintArr(arr, lines, cols);
		}
		else
			cout << "�޷��ҵ��ƶ�·��" << endl;
		
		int sum = GetBallNumInArr(arr, lines, cols);  // sumΪ�������
		if (sum + 3 >= lines * cols)
		{
			cout << "ʧ�ܡ�����" << endl;
			break;
		}
		if (sum == 0)
		{
			cout << "�ɹ�������" << endl;
			break;
		}
	}
}

void DoByChoice45(int arr[11][11], int lines, int cols, int user_choice)
{
	cout << endl;
	PrintArr(arr, lines, cols);

	int pos_x, pos_y; // ��ǰ�������λ��
	cout << endl;
	cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
	to_be_continued(2, pos_x, pos_y);
	cct_cls();
	cct_setconsoleborder(40, 25, 40, 25);
	cct_setfontsize("������", 30); //Truetype����ֻ��Ҫ����һ�������߶ȼ���
	cout << "��Ļ��" << 25 << "��" << 40 << "��" << endl;
	if (user_choice == 4)
		DrawArr1(arr, lines, cols);  // �޼��
	else
		DrawArr2(arr, lines, cols);  // �м��  
}

void DoByChoice67(int arr[11][11], int lines, int cols, int user_choice, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8])
{
	int pos_x, pos_y;
	if (user_choice == 6)
	{
		cout << endl;
		PrintArr(arr, lines, cols);
		cout << endl;
		cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
		to_be_continued(2, pos_x, pos_y);
	}
	cct_cls();
	cct_setcursor(CURSOR_INVISIBLE);  // ����ʾ���
	cct_setconsoleborder(70, 60, 70, 60);
	cct_setfontsize("������", 28); //Truetype����ֻ��Ҫ����һ�������߶ȼ���
	cout << "��Ļ��" << 23 << "��" << 70 << "��(�Ҽ��˳�)" << endl;
	DrawArr2(arr, lines, cols);  // �м��  

	int start_line = -1, start_col = -1;  // �������
	int end_line = -1, end_col = -1;      // �յ�����
	int score = 0;  // ��¼�ܵ÷�
	

	while (1)
	{
		// ���ﲻ��Ҫ�ж��Ƿ���·������Ϊ֮����·���Ż��˳�MouseAction
		for (int i = 0; i < 3; i++)  // Ϊ����ǰԤ�������ɫ
		{
			int color = rand() % 7 + 1;
			three_ball_color[i] = color;  // 1�ĳ�color
		}
		if (user_choice == 7)
			ShowMessage(arr, score, three_ball_color, lines, cols, delete_ball_num);
		MouseAction(arr, lines, cols, start_line, start_col, end_line, end_col);
		if (end_line == -1 && end_col == -1)  // ˵�������Ҽ�
			break;
		if (user_choice == 6)
			break;
		int per_score = IsDelete(arr, end_line, end_col, lines, cols, delete_ball_num);  // �����5�������ϵĻ��������arr��ֵ
		if (per_score != 0)  // ˵�������ƶ����������
		{
			start_line = -1;
			start_col = -1;
			end_line = -1;
			end_col = -1;
		}
		score += per_score;
		CreateThreeBallInArr(arr, lines, cols, three_ball_color, three_ball_position);
		DrawArr2(arr, lines, cols);  // ����5��������»�һ��
		DrawThreeBall(three_ball_position, three_ball_color);

		int sum = GetBallNumInArr(arr, lines, cols);  // sumΪ�������
		if (sum + 3 >= lines * cols)
		{
			cct_gotoxy(BASIS_COL + 0, BASIS_LINE + 2 * lines + 2);
			cout << "ʧ�ܡ�����" << endl;
			break;
		}
		if (sum == 0)
		{
			cct_gotoxy(BASIS_COL + 0, BASIS_LINE + 2 * lines + 2);
			cout << "�ɹ�������" << endl;
			break;
		}
	}
}

/**
  * �����������������
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
	cct_cls();  // ����
	while (1)
	{
		cout << "����������(7-9)��" << endl;
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
		cout << "����������(7-9)��" << endl;
		cin >> cols;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\0');
		}
		if (cols >= 7 && cols <= 9)
			break;
	}

	while (getchar() != '\n');  // ��ջ�����
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
	InitArrToZero(arr);  // ��ʼ�����飬ȫ����0
	int count = 0;  // ��¼�����������
	if (user_chioce == 1 || user_chioce == 4 || user_chioce == 5 || user_chioce == 7)
		count = 5;
	else if (user_chioce == 2 || user_chioce == 6)
		count = (int)lines * cols * 3 / 5;
	while (count > 0)
	{
		int line_pos = rand() % lines + 1;  // ��
		int col_pos = rand() % cols + 1;    // ��
		int color = rand() % 7 + 1;
		if (arr[line_pos][col_pos] == 0)
		{
			arr[line_pos][col_pos] = color;  // 1�ĳ�color
			count--;
		}
	}
}

void InputStartEnd(int arr[11][11], int lines, int cols, int& start_line, int& start_col, int& end_line, int& end_col, int three_ball_color[3])
{
	cout << endl;
	cout << "��3���������ɫ�ֱ��ǣ�" << three_ball_color[0] << " " << three_ball_color[1] << " " << three_ball_color[2] << endl;
	int pos_x, pos_y; // ��ǰ�������λ��
	cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
	cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
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
			cout << "�����������������." << endl;
			while (getchar() != '\n');  // ��ջ�����
			continue;
		}
		char ch2 = getchar();

		if (ch2 < '1' || ch2 > '1' + cols - 1)
		{
			cout << "�����������������." << endl;
			if (ch2 != '\n')
			while (getchar() != '\n');  // ��ջ�����
			continue;
		}
		start_line = ch1 - 'a' + 1;
		start_col = ch2 - '1' + 1;
		if (start_line >= 1 && start_line <= lines && start_col >= 1 && start_col <= cols)
		{
			if (arr[start_line][start_col] == 0)
			{
				cout << "��ʼλ��Ϊ�գ�����������." << endl;
				while (getchar() != '\n');  // ��ջ�����
				cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
				pos_y += 2;
				continue;
			}
			else
			{
				cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 10);
				cct_gotoxy(0, pos_y + 1);
				cout << "����Ϊ" << (char)(ch1 - 'a' + 'A') << "��" << ch2 - '1' + 1 << "��" << endl;
				break;
			}
		}
	}
	while (getchar() != '\n');  // ��ջ�����

	cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
	cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
	while (1)
	{
		cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 10);
		cct_gotoxy(pos_x, pos_y);
		char ch3 = getchar();
		if (ch3 >= 'A' && ch3 <= 'A' + lines - 1)
			ch3 += ('a' - 'A');
		if (ch3 < 'a' || ch3 > 'a' + lines - 1)
		{
			cout << "�����������������." << endl;
			while (getchar() != '\n');  // ��ջ�����
			continue;
		}
		char ch4 = getchar();
		if (ch4 < '1' || ch4 > '1' + cols - 1)
		{
			cout << "�����������������." << endl;
			while (getchar() != '\n');  // ��ջ�����
			continue;
		}
		end_line = ch3 - 'a' + 1;
		end_col = ch4 - '1' + 1;
		if (end_line >= 1 && end_line <= lines && end_col >= 1 && end_col <= cols)
		{
			if (arr[end_line][end_col] != 0)
			{
				cout << "Ŀ��λ�÷ǿգ�����������" << endl;
				while (getchar() != '\n');  // ��ջ�����
				cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
				pos_y += 2;
			}
			else
			{
				cout << "����Ϊ" << (char)(ch3 - 'a' + 'A') << "��" << ch4 - '1' + 1 << "��" << endl;
				break;
			}
		}
	}
	while (getchar() != '\n'); // ��ջ�����
}

/**
  * �жϴ�(start_line, start_col)��(end_line, end_col)�Ƿ����·����������ڣ���·����¼��path�����У�������1���������򷵻�0
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
	if (arr[start_line - 1][start_col] == 0 && start_line > 1 && visited[start_line - 1][start_col] == 0)  // ����
	{
		result1 = DFS(arr, lines, cols, start_line - 1, start_col, end_line, end_col, visited, path);
		if (result1 == 1)
			return 1;
	}
	if (arr[start_line][start_col + 1] == 0 && start_col < cols && visited[start_line][start_col + 1] == 0)  // ����
	{
		result2 = DFS(arr, lines, cols, start_line, start_col + 1, end_line, end_col, visited, path);
		if (result2 == 1)
			return 1;
	}
	if (arr[start_line + 1][start_col] == 0 && start_line < lines && visited[start_line + 1][start_col] == 0)  // ����
	{
		result3 = DFS(arr, lines, cols, start_line + 1, start_col, end_line, end_col, visited, path);
		if (result3 == 1)
			return 1;
	}
	if (arr[start_line][start_col - 1] == 0 && start_col > 1 && visited[start_line][start_col - 1] == 0)  // ����
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
	Point pre[11][11];  // pre���ڴ洢�õ��ǰһ�㣨���Ƹ��ڵ㣩����һ���߹���

	int to_line;
	int to_col;

	// ʹ��BFS����ʱ��Ϊ�˻�����·����ÿ��·����Ҫ������һ��λ��
	int path_index_arr[100][2] = {0};
	for (int i = 0; i < 100; i++)
	{
		path_index_arr[i][0] = -1;
		path_index_arr[i][1] = -1;
	}

	int front = -1, tail = -1;  // frontָ����ף�tailָ���β frontָ���һ��Ԫ�ص�ǰһ�tailָ�����һ��Ԫ��
	tail++;
	path_index_arr[tail][0] = start_line;
	path_index_arr[tail][1] = start_col;

	pre[start_line][start_col].line = -1;
	pre[start_line][start_col].col = -1;
	while (front != tail)
	{
		int line = path_index_arr[front + 1][0];  // (line, col)Ϊ��ͷ��
		int col = path_index_arr[front + 1][1];
		front++;  // ����Ԫ�س��ӣ��ƶ�����ָ�����
		if (line == end_line && col == end_col)  // �ҵ��յ�
		{
			is_path = 1;  // ����·��
			break;
		}
		visited[line][col] = 1;
		if (arr[line - 1][col] == 0 && line > 1 && visited[line - 1][col] == 0)  // ����
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
		if (arr[line][col + 1] == 0 && col < cols && visited[line][col + 1] == 0)  // ����
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
		if (arr[line + 1][col] == 0 && line < lines && visited[line + 1][col] == 0)  // ����
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
		if (arr[line][col - 1] == 0 && col > 1 && visited[line][col - 1] == 0)  // ����
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
  * ����path������� DFS������ʹ��
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
  * ɾ��path�������һ���� DFS������ʹ��
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
  * �����ƶ���ķ��� 
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
	arr[i2][j2] = arr[i1][j1];  // ��һ�к���һ�е�˳���ܷ�
	arr[i1][j1] = 0;
	return IsDelete(arr, i2, j2, lines, cols, deleteBall);;
}

/**
  * �����Ƶ�(end_line, end_col)���ж��Ƿ��ܹ�����
  * ������ԣ�����Ȼ�󷵻ص÷֣�������з���0
  * ����demo������n���򣬵�(N-1)*(N-2)��
  */
int IsDelete(int arr[11][11], int end_line, int end_col, int lines, int cols, int delete_ball_num[8])
{
	int n = 0;  // ͳ��ÿ�����������
	int per_score = 0;  // ͳ�Ʒ���
	int color = arr[end_line][end_col];
	int sumy1 = 0;  // ͳ��������������� ��λ�� + ����
	int sumy2 = 0;  // ͳ��������������� ������ + ����
	int sumx1 = 0;  // ͳ��������������� ��λ�� + ����
	int sumx2 = 0;  // ͳ��������������� ������ + ����
	// �ȿ�����
	// ����
	for (int i = end_line; i <= lines; i++)
	{
		if (arr[i][end_col] == 0 || arr[i][end_col] != color)
			break;
		sumy1++;
	}
	// ����
	for (int i = end_line - 1; i > 0; i--)
	{
		if (arr[i][end_col] == 0 || arr[i][end_col] != color)
			break;
		sumy2++;
	}
	// ���Ǻ�
	// ����
	for (int i = end_col; i <= cols; i++)
	{
		if (arr[end_line][i] == 0 || arr[end_line][i] != color)
			break;
		sumx1++;
	}
	// ����
	for (int i = end_col - 1; i > 0; i--)
	{
		if (arr[end_line][i] == 0 || arr[end_line][i] != color)
			break;
		sumx2++;
	}

	// ������Ҳ�к� ������ķ���������������ɾ����Щ��
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
	// ֻ���� ������ķ���������������ɾ����Щ��
	else if (sumy1 + sumy2 >= 5)
	{
		n = sumy1 + sumy2;
		per_score = (n - 1) * (n - 2);
		delete_ball_num[arr[end_line][end_col]] += n;
		for (int i = end_line - sumy2; i < end_line + sumy1; i++)
			arr[i][end_col] = 0;
	}
	// ֻ�к� ������ķ���������������ɾ����Щ��
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
	int count = 0;  // ��¼�����������
	while (count < 3)
	{
		int line_pos = rand() % lines + 1;  // ��
		int col_pos = rand() % cols + 1;    // ��
		if (arr[line_pos][col_pos] == 0)
		{
			arr[line_pos][col_pos] = three_ball_color[count];
			three_ball[count][0] = line_pos;
			three_ball[count][1] = col_pos;
			count++;
		}
	}
}


