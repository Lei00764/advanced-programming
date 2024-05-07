/* 2053932 软件 雷翔 */
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	int upper_count = 0, lower_count = 0, digit_count = 0, kongge_count = 0, other_count = 0;
	char str[3][128];

	// 输入部分
	// fgets()给字符数组赋值的时候，会把末尾的回车键也放入到字符数组中（前提是有地方放），字符数组最后一个字符一定是\0补充
	cout << "请输入第1行" << endl;
	fgets(str[0], 128, stdin);  // 回车会被放入str[0]尾零前 对应ASCII码：10
	int len1 = strlen(str[0]) - 1;  // 不记录最后的回车
	cout << "请输入第2行" << endl;
	fgets(str[1], 128, stdin);
	int len2 = strlen(str[1]) - 1;
	cout << "请输入第3行" << endl;
	fgets(str[2], 128, stdin);
	int len3 = strlen(str[2]);
	if (str[2][len3 - 1] == 10)  // 依旧是为了保证输出重定向和demo一致
		len3--;

	// 处理部分
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (i == 0 && j == len1 || i == 1 && j == len2 || i == 2 && j == len3)  // 本来可以直接判断回车的，这样做的目的是保证输出重定向和demo一致
				break;
			char ch = str[i][j];
			if (ch >= '0' && ch <= '9')  // 数字
				digit_count++;
			else if (ch >= 'a' && ch <= 'z')  // 小写英文
				lower_count++;
			else if (ch >= 'A' && ch <= 'Z')  // 大写英文
				upper_count++;
			else if (ch == 32)  // 空格
				kongge_count++;
			else  // 其它：中文、日文、韩文等 GBK规定：汉字的第一个字节的最高位是1
				other_count++;
		}
	}
	cout << "大写 : " << upper_count << endl;
	cout << "小写 : " << lower_count << endl;
	cout << "数字 : " << digit_count << endl;
	cout << "空格 : " << kongge_count << endl;
	cout << "其它 : " << other_count << endl;

	return 0;
}

