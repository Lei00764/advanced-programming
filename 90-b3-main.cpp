/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <cstring>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;


/**
  * ��ʾ�˵��������û�ѡ��
  */
int Menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.��ʾ�ؿ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "--------------------------------------------" << endl;
	char user_choice;
	cout << "[��ѡ��:] ";
	while (1)
	{
		user_choice = (char)_getch();  // ��ȡ�����ַ� ���޻����� �޻��ԣ�
		if (user_choice == '0' || user_choice == '1')
		{
			cout << user_choice << endl;  // ��ȷ����ʱ��ʾ�û�ѡ��
			break;
		}
	}
	cout << endl;
	return user_choice - '0';
}


int main()
{
	cct_setconsoleborder(130, 48, 130, 48);
	cct_setfontsize("��������", 16, 8);
	char files[200][50] = {'\0'};  // ��š��ܴ��⡱���ļ��� eg Sokoban-Level-000.txt
	int user_choice = Menu();
	if (user_choice == 1)
	{
		cct_cls();
		int tag = GetAllFiles("stage", "Sokoban-Level-???.txt", files);  // ��ͨ���*��ƥ��Ҳ���ԣ�ֻ������Ҫ���⴦��
		if (tag == 0)
		{
			cout << "�޷���[.\\stage\\]Ŀ¼." << endl;
			return -1;
		}
		int all_count = 0;  // �ܹ��ж��ٸ��ļ�
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
