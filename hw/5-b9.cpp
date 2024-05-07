/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;


int main()
{
	int row[9][9] = { 0 };   // 行
	int col[9][9] = { 0 };   // 列
	int bbox[3][3][9] = { 0 };  // 方框
	int tag = 0;  // 标记 如果tag置1 说明不是数独的解
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
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
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
			}
		}
		if (tag == 1)
			cout << "不是数独的解" << endl;
		else
			cout << "是数独的解" << endl;
		return 0;
	}

	return 0;
}