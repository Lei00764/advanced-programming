/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;


int main()
{
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
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
	int n = i; // 数组真实长度 不包括 -1

	cout << "输入的数组为:" << endl;
	for (int j = 0; j < n; j++)
	{
		if (j > 0 && j % 10 == 0)
			cout << endl;
		cout << a[j] << " ";
	}
	cout << endl;

	cout << "分数与名次的对应关系为:" << endl;
	int sum[101] = { 0 };  // 下标表示分数 存的值表示该分数的个数
	for (int k = 0; k < n; k++)
	{
		sum[a[k]]++;
	}

	// 测试：87 86 56 76 87 92 76 96 92 23 -1
	int human = 1; // 记录当前分数的名次
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