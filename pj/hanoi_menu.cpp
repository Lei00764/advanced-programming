/* 2053932 ���� ���� */

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1���ű� hanoi_main.cpp ���õĲ˵�������Ҫ����ʾ���˵��������ȷ��ѡ��󷵻�

     ���ļ�Ҫ��
	1�������������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�����������徲̬ȫ�ֱ�����ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

#include <iostream>
#include <conio.h>
using namespace std;

int Menu()
{
	cout << "--------------------------------- " << endl;
	cout << "1.������" << endl;
	cout << "2.������(������¼)" << endl;
	cout << "3.�ڲ�������ʾ(����)" << endl;
	cout << "4.�ڲ�������ʾ(���� + ����)" << endl;
	cout << "5.ͼ�ν� - Ԥ�� - ������Բ��" << endl;
	cout << "6.ͼ�ν� - Ԥ�� - ����ʼ���ϻ�n������" << endl;
	cout << "7.ͼ�ν� - Ԥ�� - ��һ���ƶ�" << endl;
	cout << "8.ͼ�ν� - �Զ��ƶ��汾" << endl;
	cout << "9.ͼ�ν� - ��Ϸ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "--------------------------------- " << endl;
	char user_choice;
	cout << "[��ѡ��:] ";
	while (1)
	{
		user_choice = _getch();  // ��ȡ�����ַ� ���޻����� �޻��ԣ�
		if (user_choice >= '0' && user_choice <= '9')
		{
			cout << user_choice << endl;  // ��ȷ����ʱ��ʾ�û�ѡ��
			break;
		}
	}
	cout << endl;
	return user_choice - '0';  // ���ص�������
}
