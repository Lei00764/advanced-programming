/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

const int MAX_SIZE = 21;

int main()
{
	cout << "��������������������������20��������-1����" << endl;
	int arr[MAX_SIZE];
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		if (num == -1)
			break;
	}
	int n = i;  // ������ʵ���� ������ -1 ������������Ϊ20
	// eg. 2 8 11 23 26 28 34 37 39 41 42 46 51 53 57 58 60 62 64 67 - 1 -> n = 20
	// eg. 2 8 11 23 26 28 34 37 39 41 42 46 51 53 57 58 60 62 64 67 70 - 1 -> n = 21
	// �����볬��20��ʱ��n=21
	if (n == 21)  // ˵������20��
	{
		n--;
		arr[n] = -1;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (arr[0] == -1)  
	{
		cout << "����Ч����" << endl;
		return 0;
	}

	// ͨ��ǰ��Ĳ�������arr[n]ʼ�յ���-1�����鳤��Ϊn������������-1��
	cout << "ԭ����Ϊ��" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;

	cout << "������Ҫ�����������" << endl;
	int insert_num;
	cin >> insert_num;

	cout << "����������Ϊ��" << endl;
	for (int k = 0; k < n; k++)
	{
		if (arr[n - 1] < insert_num) // ԭ����ȫ��Ҫ�������С
		{
			arr[n] = insert_num;
			break;
		}
		if (arr[k] > insert_num)
		{
			for (int w = n; w > k; w--) // ����һλ
			{
				arr[w] = arr[w - 1];
			}
			arr[k] = insert_num;
			break;
		}
	}
	
	for (int m = 0; m < n + 1; m++) // �������һ��Ԫ��
	{
		cout << arr[m] << " ";
	}
	cout << endl;

	return 0;
}