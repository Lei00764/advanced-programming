/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>  // _getch()
using namespace std;

const int NumberOfCategories = 26;  // ��Ʒ����



struct KFC
{
	char id;
	char name[40];
	double cost;
};

struct SPECIAL
{
	char ids[20];
	char name[40];
	double cost;
};

const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};

// ������list�е��±�
int FindIndexByCh(char id, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i].id == id)
			return i;
	}
	return -1;
}

void ClearArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

void ShowOrder(int arr[], int n)
{
	int tag = 0;  // 0��ʾ��һ�����
	for (int k = 0; k < n; k++)
	{
		if (tag == 0 && arr[k] != 0)
		{
			cout << list[k].name;
			if (arr[k] > 1)
				cout << "*" << arr[k];
			tag = 1;
		}
		else if (tag == 1 && arr[k] != 0)
		{
			cout << "+" << list[k].name;
			if (arr[k] > 1)
				cout << "*" << arr[k];
		}
	}
}

void Menu()
{
	int arr[NumberOfCategories];  // ��������û���ĵ�Ʒ������
	int taocan_count = sizeof(special) / sizeof(special[0]) - 1;
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021�＾�˵�                       " << endl;
	cout << "=============================================================" << endl;
	for (int i = 0; i < NumberOfCategories; i++)
	{
		cout << " " << list[i].id << " " << setw(20) << setiosflags(ios::left) << list[i].name << setw(6) << list[i].cost << " ";
		if (i % 2 == 0)
			cout << "|  ";
		else
			cout << endl;
	}
	cout << endl;
	cout << "���Ż���Ϣ����" << endl;
	for (int i = 0; i < taocan_count; i++)
	{
		ClearArr(arr, NumberOfCategories);
		cout << special[i].name << "=";
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, NumberOfCategories);
			arr[index]++;
		}
		ShowOrder(arr, NumberOfCategories);
		cout << "=" << special[i].cost << endl;
	}
	cout << endl;
	cout << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С)/akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl;
}

double ComputeCost(int order_arr[], int n)
{
	double cost_money = 0;
	int taocan_count = sizeof(special) / sizeof(special[0]) - 1;  // �ײ���������
	int taocan_arr[NumberOfCategories];
	for (int i = 0; i < taocan_count; i++)
	{
		ClearArr(taocan_arr, NumberOfCategories);
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, NumberOfCategories);
			taocan_arr[index]++;
		}
		int is_special = 0;  // �ж��Ƿ���Դճ��ײ� 0��ʾ����
		while (1)  // ֮����Ҫѭ�� -> ���ܿ��Դճɶ���ײ�
		{
			for (int k = 0; k < NumberOfCategories; k++)
			{
				if (taocan_arr[k] != 0)
				{
					if (order_arr[k] >= taocan_arr[k])
						is_special = 1;
					else
					{
						is_special = 0;
						break;  // ��һ����Ʒ�����Ͼ������˳�
					}
				}
			}
			if (is_special == 1)  // ��һ���ײ�  -> ��order_arr�а��ײ��еĵ�Ʒɾ��
			{
				cost_money += special[i].cost;
				for (int w = 0; w < NumberOfCategories; w++)
				{
					if (taocan_arr[w] != 0)
						order_arr[w] -= taocan_arr[w];
				}
			}
			else
				break;
		}
	}
	for (int m = 0; m < NumberOfCategories; m++)  // ���ܴճ��ײ͵�����ĵ�Ʒ
	{
		if (order_arr[m] != 0)
		{
			cost_money += order_arr[m] * list[m].cost;
			order_arr[m] = 0;
		}
	}
	return cost_money;
}

int main()
{
	system("mode con cols=120 lines=35");
	while (1)
	{
		system("cls");
		Menu();
		cout << "��㵥��";
		int order_arr[NumberOfCategories] = { 0 };// arr �����ŵ�����е�Ʒ
		char ch;  // ��¼��͵ĵ�Ʒ����ĸ
		int flag = 0;    // 0��ʾ��ȡ��һ���ַ�
		int IsSucc = 1;  // ��¼�Ƿ�ɹ���ȡ
		while ((ch = getchar()) != '\n')
		{
			if (ch == ' ')
				continue;
			if (flag == 0)
			{
				flag++;  // ��ʾ�Ѿ���ȡ�˵�һ���ַ�
				if (ch == '0')
					return 0;
			}
			if (ch >= 'a' && ch <= 'z')
				ch -= 'a' - 'A';
			if (ch >= 'A' && ch <= 'Z')
			{
				int index = FindIndexByCh(ch, NumberOfCategories);
				order_arr[index]++;
			}
			else
			{
				cout << "������󣬰����������." << endl;
				char item1 = _getch();
				IsSucc = 0;
				break;
			}
		}
		if (flag != 0 && IsSucc == 1)  
		{
			cout << "��ĵ��=";
			ShowOrder(order_arr, NumberOfCategories);
			double cost_money = ComputeCost(order_arr, NumberOfCategories);  // ConputeCost��order_arrȫΪ0
			cout << endl;
			cout << "���ƣ�" << cost_money << "Ԫ" << endl;
			cout << "�㵥��ɣ������������." << endl;
			char item2 = _getch();
		}
		if (IsSucc != 1)  // ֻ�е���ȡ����ʱ����Ҫ��ջ�����
			while (getchar() != '\n');
	}

	return 0;
}