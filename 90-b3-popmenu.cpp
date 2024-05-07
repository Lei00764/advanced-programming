/* 2053932 ��� ���� */
#include <iostream>
#include <fstream>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

/**
  * ��ʾ�����˵�
  * @files       �����ļ���
  * @count       �ļ���������
  * @start_count �Ӹ��±꿪ʼ��ʾ
  */
void ShowPopMenu(char files[200][50], int all_count, int start_count)
{
	cct_gotoxy(PopMenuX, PopMenuY);
	cout << "��ѡ��ؿ�" << endl;
	cct_gotoxy(PopMenuX, PopMenuY + 1);
	cout << "�X�T�T�T�T�[" << endl;
	int count = start_count;
	int pos = 0;

	int menu_sum = 0;
	while (files[menu_sum][0] != '\0')
		menu_sum++;
	
	while (count < start_count + MenuMaxSum && count < menu_sum)
	{
		cct_gotoxy(PopMenuX, PopMenuY + 2 + pos);
		cout << "�U" << "�ؿ�" << files[count][14] << files[count][15] << files[count][16] << " �U" << endl;;
		count++;
		pos++;
	}
	if (menu_sum < MenuMaxSum)
		cct_gotoxy(PopMenuX, PopMenuY + 2 + menu_sum);
	else
		cct_gotoxy(PopMenuX, PopMenuY + 2 + MenuMaxSum);
	cout << "�^�T�T�T�T�a" << endl;
}
