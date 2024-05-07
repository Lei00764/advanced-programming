/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

const int MAX_SIZE = 21;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
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
	int n = i;  // 数组真实长度 不包括 -1 正常情况下最大为20
	// eg. 2 8 11 23 26 28 34 37 39 41 42 46 51 53 57 58 60 62 64 67 - 1 -> n = 20
	// eg. 2 8 11 23 26 28 34 37 39 41 42 46 51 53 57 58 60 62 64 67 70 - 1 -> n = 21
	// 当输入超过20个时，n=21
	if (n == 21)  // 说明超过20个
	{
		n--;
		arr[n] = -1;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (arr[0] == -1)  
	{
		cout << "无有效输入" << endl;
		return 0;
	}

	// 通过前面的操作，让arr[n]始终等于-1，数组长度为n（不包括最后的-1）
	cout << "原数组为：" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
	int insert_num;
	cin >> insert_num;

	cout << "插入后的数组为：" << endl;
	for (int k = 0; k < n; k++)
	{
		if (arr[n - 1] < insert_num) // 原数组全比要插入的数小
		{
			arr[n] = insert_num;
			break;
		}
		if (arr[k] > insert_num)
		{
			for (int w = n; w > k; w--) // 后移一位
			{
				arr[w] = arr[w - 1];
			}
			arr[k] = insert_num;
			break;
		}
	}
	
	for (int m = 0; m < n + 1; m++) // 数组多了一个元素
	{
		cout << arr[m] << " ";
	}
	cout << endl;

	return 0;
}