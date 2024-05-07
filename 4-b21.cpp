/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4������������������κ���ʽ��ѭ��
   ---------------------------------------------------------------------
*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ݹ鷽ʽ���ʮ���Ƶ��������Ƶ�ת������ӡ
  ���������int num ��ʮ������
			int base��Ҫת���Ľ���
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������κ���ʽ��ѭ��
			3��������ʹ��cmath�еĺ���
			4��������ʹ��64λ����
***************************************************************************/
void dec_to_base_n(int num, int base)
{
	int yushu = -1;
	if (num < 0)
	{
		unsigned u_num = (unsigned)num;
		num = u_num / base;
		yushu = u_num % base;
	}
	if (num < base)
	{
		switch (num)
		{
			case 10:
			{
				cout << 'A';
				break;
			}
			case 11:
			{
				cout << 'B';
				break;
			}
			case 12:
			{
				cout << 'C';
				break;
			}
			case 13:
			{
				cout << 'D';
				break;
			}
			case 14:
			{
				cout << 'E';
				break;
			}
			case 15:
			{
				cout << 'F';
				break;
			}
			default:
				cout << num%base;
		}
		return;
	}
	dec_to_base_n(num / base, base);
	switch (num % base)
	{
		case 10:
		{
			cout << 'A';
			break;
		}
		case 11:
		{
			cout << 'B';
			break;
		}
		case 12:
		{
			cout << 'C';
			break;
		}
		case 13:
		{
			cout << 'D';
			break;
		}
		case 14:
		{
			cout << 'E';
			break;
		}
		case 15:
		{
			cout << 'F';
			break;
		}
		default:
			cout << num%base;
	}
	if (yushu > 0)
	{
		switch (yushu)
		{
			case 10:
			{
				cout << 'A';
				break;
			}
			case 11:
			{
				cout << 'B';
				break;
			}
			case 12:
			{
				cout << 'C';
				break;
			}
			case 13:
			{
				cout << 'D';
				break;
			}
			case 14:
			{
				cout << 'E';
				break;
			}
			case 15:
			{
				cout << 'F';
				break;
			}
			default:
				cout << yushu;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int num, base;

	cout << "������ʮ��������(int��)��Ҫת���Ľ���[2..16]" << endl;
	cin >> num >> base;		//�������������numΪint�ͷ�Χ�κ�ֵ���ɣ�baseΪ2~16��������10����

	if (base == 10) //����Ϊ10ֱ���˳�
		return -1;

	/* ��ɽ���ת������ӡ */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}

/*
	�����ڼ�����ж��Զ����Ʋ�����ʽ�洢������int�ฺ����˵�������һλ�ض���1��ת���������ƣ���ʮ������Ϊ�������λһ�����ڻ����8��1000��
*/