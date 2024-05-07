/* 2053932 软件 雷翔 */
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
 * (i, j)是雷，让周围8个点不是雷的点的值都+1
 * 
 */
void Add(char arr[12][28], int i, int j)
{
	if (arr[i - 1][j - 1] != '*')  // 左上
		arr[i - 1][j - 1]++;
	if (arr[i][j - 1] != '*')      // 上
		arr[i][j - 1]++;
	if (arr[i + 1][j - 1] != '*')  // 右上
		arr[i + 1][j - 1]++;
	if (arr[i - 1][j] != '*')      // 左
		arr[i - 1][j]++;
	if (arr[i + 1][j] != '*')      // 右
		arr[i + 1][j]++;
	if (arr[i - 1][j + 1] != '*')  // 左下
		arr[i - 1][j + 1]++;
	if (arr[i][j + 1] != '*')      // 下
		arr[i][j + 1]++;
	if (arr[i + 1][j + 1] != '*')  // 右下
		arr[i + 1][j + 1]++;
}

int main()
{
	// char arr[12][28] = {'0'}; 错误 后面全初始化为 \0
	char arr[12][28];  // 之所以设这么大，方便最外圈的+1操作
	Init(arr);  // 初始化
	int count = 0;  // 记录雷的数量
	srand((unsigned)time(0));
	while (count < 50)
	{
		int x = rand() % 10 + 1;  // 纵的是x
		int y = rand() % 26 + 1;  // 横的是y
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
			if (arr[i][j] == '*')  // 如果是雷，四周不是雷的都+1
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