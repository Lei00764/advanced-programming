/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	while (getchar() != '\n'); // ��ȡ��һ�� ���Ը���
	int passcode_len, upper_count, lower_count, digit_count, other_count;
	int tag = 1;  // tag = 1 ˵����ȷ
	cin >> passcode_len >> upper_count >> lower_count >> digit_count >> other_count;
	while (getchar() != '\n'); // �����س�
	if (passcode_len < 12 || passcode_len > 16 || upper_count < 2 || lower_count < 2 || digit_count < 2 || other_count < 2)
	{
		cout << "����" << endl;
		return 0;
	}

	for (int i = 0; i < 10; i++)
	{
		int len1 = 0, len2 = 0, len3 = 0, len4 = 0;
		char passcode[18];
		// fgets()���ַ����鸳ֵ��ʱ�򣬻��ĩβ�Ļس���Ҳ���뵽�ַ������У�ǰ�����еط��ţ����ַ��������һ���ַ�һ����\0����
		fgets(passcode, 18, stdin);
		for (int j = 0; j < passcode_len; j++)
		{
			char ch = passcode[j];
			
			if (ch >= 'A' && ch <= 'Z')
				len1++;
			else if (ch >= 'a' && ch <= 'z')
				len2++;
			else if (ch >= '0' && ch <= '9')
				len3++;
			else
			{
				int in_tag = 0;  // �ж�ch�Ƿ�����other���� 0��ʾ������
				for (int w = 0; w < 15; w++)
				{
					if (other[w] == ch)
					{
						in_tag = 1;
						break;
					}
				}
				if (in_tag == 1)
					len4++;
				else  // ˵���зǷ��ַ�
				{
					tag--;
				}
			}
		}
		
		if (len1 < upper_count || len2 < lower_count || len3 < digit_count || len4 < other_count  
			|| len1 + len2 + len3 + len4 != passcode_len)  // ��ϸ����߼���ϵ xx_count�Ǳ�ҪҪ�еģ����٣������������ַ�
		{
			tag--;
		}
	}

	if (tag == 1)
		cout << "��ȷ" << endl;
	else
		cout << "����" << endl;


	return 0;
}