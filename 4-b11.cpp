/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ����;�̬�ֲ�����
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
   ***************************************************************************/
void print_tower(char end_ch, char start, int key) // key �������
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ��*/
	void print_pre_tower(char end_ch, char label); // ��������
	void print_pre_tower_daoxu(char end_ch, char label, char ch); // ��������
	if (key == 1)
	{
		if (start > end_ch)
		{
			return;
		}
		print_pre_tower(end_ch, start++);
		cout << endl;
		print_tower(end_ch, start, 1);
	}
	else
	{
		if (start > end_ch)
		{
			return;
		}
		print_pre_tower_daoxu(end_ch, start++, 'A');
		cout << endl;
		print_tower(end_ch, start, 0);
	}
	
}
// end_chÿ�εݹ��1
void print_pre_tower(char end_ch, char label)  // ���ÿһ�еĴ��� ����
{
	if (end_ch == 65)
	{
		cout << 'A';
		return;
	}

	if (end_ch <= label)
		cout << end_ch;
	else
	{
		cout << " ";
	}

	print_pre_tower(end_ch - 1, label);

	if (end_ch <= label)
		cout << end_ch;
	else
	{
		// cout << " "; // ����Ҫ
	}
}
// end_ch���� label���� -> Ҫ�ӽ���һ���²��� 
void print_pre_tower_daoxu(char end_ch, char label, char ch) // end_ch���� label���� -> Ҫ�ӽ���һ���²��� 
{														   // �ӽ������������ʼ�մ�'A'��ʼ 
	if (ch == end_ch)
	{
		cout << ch;
		return;
	}

	if (ch >= label)
		cout << ch;
	else
	{
		cout << " ";
	}

	print_pre_tower_daoxu(end_ch, label, ch + 1);

	if (ch >= label)
		cout << ch;
	else
	{
		// cout << " ";
	}
}


char print_equal(char end_ch)
{
	if (end_ch == 65)
	{
		return '=';
	}
	cout << "==";
	return print_equal(end_ch - 1);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 'A', 1);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 'A', 0);
	cout << endl;

	return 0;
}