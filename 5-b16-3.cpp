/* 2053932 ��� ���� */
#include <iostream>
using namespace std;
const int ST = 10;  // ѧ������


void Input(string id[], string name[], int score[])
{
	for (int i = 0; i < ST; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> id[i] >> name[i] >> score[i];
	}
}


void Sorted(string id[], string name[], int score[])
{
	for (int i = 0; i < ST; i++)
	{
		for (int j = 0; j < ST - i - 1; j++)
		{
			if (id[j] > id[j + 1])
			{
				// ����ѧ�š����֡��ɼ�
				string id_item = id[j];
				id[j] = id[j + 1];
				id[j + 1] = id_item;
				string name_item = name[j];
				name[j] = name[j + 1];
				name[j + 1] = name_item;
				int temp;
				temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}
}


void Output(string id[], string name[], int score[])
{
	cout << endl << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < ST; i++)
	{
		cout << name[i] << " " << id[i] << " " << score[i] << endl;
	}
}


int main()
{
	string id[ST], name[ST];
	int score[ST];
	Input(id, name, score);
	Sorted(id, name, score);
	Output(id, name, score);

	return 0;
}