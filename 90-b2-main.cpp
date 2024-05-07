/* 2053932 ��� ���� */
#include <iostream>
#include <conio.h>  // for _getch()
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;


/**
  * ��ʾ�˵��������û�ѡ��
  */
int Menu()
{
	cct_setconsoleborder(120, 35, 120, 1000);
	cct_setfontsize("��������", 16, 8);
	cout << "--------------------------------------------" << endl;
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60 % ����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n * n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n * n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.n * n�Ŀ�ܣ�60 % ����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "--------------------------------------------" << endl;
	char user_choice;
	cout << "[��ѡ��:] ";
	while (1)
	{
		user_choice = (char)_getch();  // ��ȡ�����ַ� ���޻����� �޻��ԣ�
		if (user_choice >= '0' && user_choice <= '7')
		{
			cout << user_choice << endl;  // ��ȷ����ʱ��ʾ�û�ѡ��
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
	int arr[11][11];  // �ڲ�����
	int lines, cols;  // ����������
	srand((unsigned)time(NULL));  // �������

	int visited[11][11] = { 0 };   // ��¼���ʹ��ĵ�
	char path[100][2] = { '\0' };  // ��¼ÿ�η��ʵ�·��
	int three_ball_color[3] = { 0 };  // ��¼��3�����ɫ
	int three_ball_position[3][2] = { 0 };  // �洢��3���������е�λ��
	int delete_ball_num[8] = { 0 };  // ��¼������ɫ������������

	while (1)
	{
		ClearAllArr(arr, visited, path, three_ball_color, three_ball_position, delete_ball_num);
		int user_choice = Menu();
		int tag = 1;  // tag = 0 ���˳���ѭ��
		switch (user_choice)
		{
			case 1:
				InputLinesCols(lines, cols);  // ��������������
				InitBallInArr(arr, lines, cols, 1);  // ���������������5���� 
				cout << endl;
				cout << "��ʼ���飺" << endl;
				PrintArr(arr, lines, cols);  // ��ӡ����
				break;
			case 2:
				InputLinesCols(lines, cols);  // ��������������
				InitBallInArr(arr, lines, cols, 2);  // ���������������60%���� 
				DoByChoice2(arr, lines, cols, visited, path, three_ball_color);
				break;
			case 3:
				InputLinesCols(lines, cols);  // ��������������
				InitBallInArr(arr, lines, cols, 1);  // ���������������5���� 
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

