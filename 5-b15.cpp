/* 2053932 ��� ���� */
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	int upper_count = 0, lower_count = 0, digit_count = 0, kongge_count = 0, other_count = 0;
	char str[3][128];

	// ���벿��
	// fgets()���ַ����鸳ֵ��ʱ�򣬻��ĩβ�Ļس���Ҳ���뵽�ַ������У�ǰ�����еط��ţ����ַ��������һ���ַ�һ����\0����
	cout << "�������1��" << endl;
	fgets(str[0], 128, stdin);  // �س��ᱻ����str[0]β��ǰ ��ӦASCII�룺10
	int len1 = strlen(str[0]) - 1;  // ����¼���Ļس�
	cout << "�������2��" << endl;
	fgets(str[1], 128, stdin);
	int len2 = strlen(str[1]) - 1;
	cout << "�������3��" << endl;
	fgets(str[2], 128, stdin);
	int len3 = strlen(str[2]);
	if (str[2][len3 - 1] == 10)  // ������Ϊ�˱�֤����ض����demoһ��
		len3--;

	// ������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (i == 0 && j == len1 || i == 1 && j == len2 || i == 2 && j == len3)  // ��������ֱ���жϻس��ģ���������Ŀ���Ǳ�֤����ض����demoһ��
				break;
			char ch = str[i][j];
			if (ch >= '0' && ch <= '9')  // ����
				digit_count++;
			else if (ch >= 'a' && ch <= 'z')  // СдӢ��
				lower_count++;
			else if (ch >= 'A' && ch <= 'Z')  // ��дӢ��
				upper_count++;
			else if (ch == 32)  // �ո�
				kongge_count++;
			else  // ���������ġ����ġ����ĵ� GBK�涨�����ֵĵ�һ���ֽڵ����λ��1
				other_count++;
		}
	}
	cout << "��д : " << upper_count << endl;
	cout << "Сд : " << lower_count << endl;
	cout << "���� : " << digit_count << endl;
	cout << "�ո� : " << kongge_count << endl;
	cout << "���� : " << other_count << endl;

	return 0;
}

