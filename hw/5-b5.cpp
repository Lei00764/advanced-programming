/* 2053932 ��� ���� */
#include <iostream>
using namespace std;


int main()
{
	cout << "������ɼ������1000��������-1����" << endl;
	int a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		int num;
		cin >> num;
		if (num == -1)
			break;
		a[i] = num;
	}
	int n = i; // ������ʵ���� ������ -1

	cout << "���������Ϊ:" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j > 0 && j % 10 == 0)
			cout << endl;
		cout << a[j] << " ";
	}
	cout << endl;

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	int sum[101] = { 0 };  // �±��ʾ���� ���ֵ��ʾ�÷����ĸ���
	for (int k = 0; k < n; k++)
	{
		sum[a[k]]++;
	}

	// ���ԣ�87 86 56 76 87 92 76 96 92 23 -1
	int human = 1; // ��¼��ǰ����������
	for (int w = 100; w >= 0; w--)
	{
		if (sum[w] > 0)
		{
			for (int m = 0; m < sum[w]; m++)
				cout << w << " " << human << endl;
			human += sum[w];
		}
		
	}

	return 0;
}