/* 2053932 ��� ���� */
#include <iostream>
using namespace std;


int main()
{
	int row[9][9] = { 0 };   // ��
	int col[9][9] = { 0 };   // ��
	int bbox[3][3][9] = { 0 };  // ����
	int tag = 0;  // ��� ���tag��1 ˵�����������Ľ�
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int num;
			while (1)
			{
				cin >> num;
				if (!cin.good())
				{
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (num > 0 && num < 10)
				{
					row[i][num - 1]++;
					col[j][num - 1]++;
					bbox[i / 3][j / 3][num - 1]++;
					if (row[i][num - 1] == 2 || col[j][num - 1] ==2 || bbox[i / 3][j / 3][num - 1] == 2)
						tag = 1;
					break;
				}
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
			}
		}
		if (tag == 1)
			cout << "���������Ľ�" << endl;
		else
			cout << "�������Ľ�" << endl;
		return 0;
	}

	return 0;
}