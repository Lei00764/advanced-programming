/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	char str[80] = { '\0' }, * pfront, * ptail;  // 经测试，demo最多允许79个字符
	pfront = str;
	ptail = str;
	fgets(str, 80, stdin);
	while (*ptail != '\n' && *ptail != '\0')  // 文件读到\0停止
		ptail++;
	ptail--;  // 让ptail指向最后一个字符
	while (pfront <= ptail)
	{
		if (*pfront != *ptail)
		{
			cout << "no" << endl;
			return 0;
		}
		pfront++;
		ptail--;
	}
	cout << "yes" << endl;

	return 0;
}
// 用fgets读取：
// 若采用键盘输入的方式，会将最后输入的回车字符存入数组，再存入尾零
// 若采用输入重新向(文件)的方式，没有回车，已尾零结束

