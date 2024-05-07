/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>  // for _getch()
#include "90-b3.h"
#include "cmd_console_tools.h"
using namespace std;


/**
  * ��¼����״̬��ֻ�����¼�ͷ���س���esc���ĸ����Ż��˳��ú���
  * ����1 �ϼ�ͷ
  * ����2 �¼�ͷ
  * ����3 �س�
  * ����4 esc
  */
int GetButton()
{
	int mButton; // ������¼����ʲô�� 

	while (1)
	{
		// ��getch��ȡ���ܼ�ʱ���᷵������int����һ��int��224���ڶ���int���ǹ��ܼ���ASCII
		mButton = _getch();

		if (mButton == 224)
			mButton = _getch();
		else if (mButton == '\r')  // _getch()��ȡ�س�������'\r'
			return 3;
		else if (mButton == 27)  // esc��ASCIIΪ27
			return 4;
		else // if (mButton == 'H' || mButton == 'P') ��������
			continue;

		if (mButton == 72) // ��
		{
			return 1;
		}
		else if (mButton == 80) // ��
		{
			return 2;
		}
	}
}


/**
  * ����1��ʾ�ؿ���ʾ��ɣ�������һ����ʾ
  * ����0��ʾ����
  */
int fun(char files[200][50], int all_count)
{
	int files_first_index = 0;  // �����˵��ĵ�һλ�ö�Ӧ��files�е��±�
	int pos_index = 0;  // 0~24 ѡ�񵯳��˵��Ĺؿ� ��ɫ��ʾ
	int flag = -1;  // 1��ʾ�ؿ���ʾ��� 0��ʾ������Ϸ

	int menu_sum = 0;
	while (files[menu_sum][0] != '\0')
		menu_sum++;

	ShowPopMenu(files, all_count, files_first_index);  // ��ʾ�����˵�
	while (1)
	{
		char pre_guanqia_name[8] = "�ؿ�";
		char cur_guanqia_name[8] = "�ؿ�";
		if (pos_index == 0)
		{
			strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
			cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
			cur_guanqia_name[4] = '\0';
		}
		int tag = 1;  // �������Ϊ1������зǷ��ַ�����0
		int choice = GetButton();
		switch (choice)
		{
			case 1:  // �����ϼ�ͷ
				if (pos_index == 0)
				{
					if (files_first_index != 0)
					{
						files_first_index--;
						cct_setcolor();  // �ָ�Ĭ����ɫ
						ShowPopMenu(files, all_count, files_first_index);  // ��ʾ�����˵�

						strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
						cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
					}
					break;
				}
				strncat(pre_guanqia_name, &files[files_first_index + pos_index][14], 3);
				cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, pre_guanqia_name, COLOR_BLACK, COLOR_WHITE);  // ���ԭ����ѡ�б��

				pos_index--;
				strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
				cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
				break;
			case 2:  // �����¼�ͷ
				if (pos_index == MenuMaxSum - 1)  // �����˵�����ʾ�����ؿ���
				{
					if (files_first_index != all_count - MenuMaxSum)
					{
						files_first_index++;
						ShowPopMenu(files, all_count, files_first_index + pos_index + 1 - MenuMaxSum);  // ��ʾ�����˵�

						strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
						cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
					}
					break;
				}
				if (menu_sum < MenuMaxSum && pos_index == menu_sum - 1)  // ����MenuMaxSum
					continue;
				else
				{
					strncat(pre_guanqia_name, &files[files_first_index + pos_index][14], 3);
					cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, pre_guanqia_name, COLOR_BLACK, COLOR_WHITE);  // ���ԭ����ѡ�б��

					pos_index++;
					strncat(cur_guanqia_name, &files[files_first_index + pos_index][14], 3);
					cct_showstr(PopMenuX + 2, PopMenuY + 2 + pos_index, cur_guanqia_name, COLOR_WHITE, COLOR_BLACK);
				}
				break;
			case 3:  // ���˻س�
				tag = ShowMap("stage", files[files_first_index + pos_index]);
				if (tag == 1)
					to_be_continued(3);
				flag = 1;
				break;
			case 4:  // ����esc
				to_be_continued(1);
				flag = 0;
				break;
		}
		cct_setcolor();  // �ָ�Ĭ����ɫ
		if (flag == 1 || flag == 0)
			break;
	}
	return flag;
}


/**
  * ����ڸ��ļ����޷Ƿ��ַ�������ʾ���飻���������ʾ
  * ��������·���1������зǷ��ַ�������0
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
		cout << "�ļ���ʧ�ܣ�" << endl;
		return 0;
	}

	char arr[MaxLines][MaxCols + 1] = { '\0' };
	for (int i = 0; i < MaxLines; i++)
	{
		if (fin.eof() == 1)
			break;
		int num = MaxCols + 1;  // ֱ�ӽ�MaxCols + 1д������ �����б�-��Ϣ������ʾxxx
		fin.getline(arr[i], num, '\n');  // ��һ���ַ���������numʱ��Ҫ���״̬�ͻ�����
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
	
	int flag = 1;  // ��������Ƿ��зǷ��ַ�
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < cols; j++)
			if (CheckLegalInArr(arr[i][j]) == 0)
			{
				flag = 0;
				cct_gotoxy(MapX, MapX + MaxLines * 2);
				cout << "�����������ļ�[" << filename << "]�зǷ��ַ�(" << i + 1 << "��" << j + 1 << "��)�����س�������" << endl;
				to_be_continued(2);  // ���س�������һ������
				return 0;
			}
	}
	// ����޷Ƿ��ַ���������ͼ
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
  * ����ַ��Ƿ��ǷǷ��ַ���ɫ�����ַ��Ķ�Ӧ��ϵ��
  * �����ǷǷ���ĸ������1�����򷵻�0
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
  * �����ļ���(i, j)������ĸ����ʾ��Ӧ��ɫ��
  */
void ShowByCh(int i, int j, char ch)
{
	int pos_x = 6 * j + MapX;
	int pos_y = 3 * i + MapY;
	if (ch == '9')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_BLACK, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 1, "�U  �U", COLOR_BLACK, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_BLACK, COLOR_BLACK);
	}
	else if (ch == 'W' || ch == 'w')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_RED, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 1, "�UXX�U", COLOR_RED, COLOR_BLACK);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_RED, COLOR_BLACK);
	}
	else if (ch == '0')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_WHITE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 1, "�U  �U", COLOR_WHITE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_WHITE, COLOR_WHITE);
	}
	else if (ch == 'B' || ch == 'b')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_GREEN, COLOR_YELLOW);
		cct_showstr(pos_x, pos_y + 1, "�U��U", COLOR_GREEN, COLOR_YELLOW);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_GREEN, COLOR_YELLOW);
	}
	else if (ch == 'F' || ch == 'f')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_CYAN, COLOR_GREEN);
		cct_showstr(pos_x, pos_y + 1, "�U��U", COLOR_CYAN, COLOR_GREEN);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_CYAN, COLOR_GREEN);
	}
	else if (ch == 'S' || ch == 's')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_BLUE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 1, "�U��U", COLOR_BLUE, COLOR_WHITE);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_BLUE, COLOR_WHITE);
	}
	else if (ch == 'R' || ch == 'r')
	{
		cct_showstr(pos_x, pos_y, "�X�T�[", COLOR_YELLOW, COLOR_RED);
		cct_showstr(pos_x, pos_y + 1, "�U��U", COLOR_YELLOW, COLOR_RED);
		cct_showstr(pos_x, pos_y + 2, "�^�T�a", COLOR_YELLOW, COLOR_RED);
	}
	cct_setcolor();  // �ָ�Ĭ����ɫ
}


void to_be_continued(int choice, const int X, const int Y)
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (choice == 1)
	{
		cout << "��С�������������End����...";
		int pos_x, pos_y; // ��ǰ�������λ��
		cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
		while (1)
		{
			cct_gotoxy(pos_x, pos_y);
			char str[20] = { '\0' };
			int count = 0;  // ��¼�ַ�����
			int flag = 1;  // flag = 0ʱ�����������ѭ��
			while (1)
			{
				char ch = getchar();
				if (ch == '\n')
				{
					cout << "�����������������" << endl;
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
		cct_setconsoleborder(120, 35, 120, 1000);  // ���������д���� ��ѡ��5�˳� �˵��Ĵ�С�ͺ�ԭ����һ����
		cct_setfontsize("��������", 16, 8);
	}
	else if (choice == 2)
	{
		/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
		while (_getch() != '\r')
			;
	}
	else if (choice == 3)
	{
		cout << "�ؿ���ʾ��ɣ���C/c����...";
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

