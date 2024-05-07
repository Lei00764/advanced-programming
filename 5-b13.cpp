/* 2053932 ��� ���� */
#include <iostream>
#include <ctime>
using namespace std;


void Init(char arr[12][28])
{
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			arr[i][j] = '0';
		}
	}
}

/**
 * (i, j)���ף�����Χ8���㲻���׵ĵ��ֵ��+1
 * 
 */
void Add(char arr[12][28], int i, int j)
{
	if (arr[i - 1][j - 1] != '*')  // ����
		arr[i - 1][j - 1]++;
	if (arr[i][j - 1] != '*')      // ��
		arr[i][j - 1]++;
	if (arr[i + 1][j - 1] != '*')  // ����
		arr[i + 1][j - 1]++;
	if (arr[i - 1][j] != '*')      // ��
		arr[i - 1][j]++;
	if (arr[i + 1][j] != '*')      // ��
		arr[i + 1][j]++;
	if (arr[i - 1][j + 1] != '*')  // ����
		arr[i - 1][j + 1]++;
	if (arr[i][j + 1] != '*')      // ��
		arr[i][j + 1]++;
	if (arr[i + 1][j + 1] != '*')  // ����
		arr[i + 1][j + 1]++;
}

int main()
{
	// char arr[12][28] = {'0'}; ���� ����ȫ��ʼ��Ϊ \0
	char arr[12][28];  // ֮��������ô�󣬷�������Ȧ��+1����
	Init(arr);  // ��ʼ��
	int count = 0;  // ��¼�׵�����
	srand((unsigned)time(0));
	while (count < 50)
	{
		int x = rand() % 10 + 1;  // �ݵ���x
		int y = rand() % 26 + 1;  // �����y
		if (arr[x][y] == '0')
		{
			arr[x][y] = '*';
			count++;
		}
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			if (arr[i][j] == '*')  // ������ף����ܲ����׵Ķ�+1
			{
				Add(arr, i, j);
			}
		}
	}


	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}