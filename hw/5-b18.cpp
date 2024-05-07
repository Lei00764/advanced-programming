/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	while (getchar() != '\n'); // 读取第一行 忽略该行
	int passcode_len, upper_count, lower_count, digit_count, other_count;
	int tag = 1;  // tag = 1 说明正确
	cin >> passcode_len >> upper_count >> lower_count >> digit_count >> other_count;
	while (getchar() != '\n'); // 读掉回车
	if (passcode_len < 12 || passcode_len > 16 || upper_count < 2 || lower_count < 2 || digit_count < 2 || other_count < 2)
	{
		cout << "错误" << endl;
		return 0;
	}

	for (int i = 0; i < 10; i++)
	{
		int len1 = 0, len2 = 0, len3 = 0, len4 = 0;
		char passcode[18];
		// fgets()给字符数组赋值的时候，会把末尾的回车键也放入到字符数组中（前提是有地方放），字符数组最后一个字符一定是\0补充
		fgets(passcode, 18, stdin);
		for (int j = 0; j < passcode_len; j++)
		{
			char ch = passcode[j];
			
			if (ch >= 'A' && ch <= 'Z')
				len1++;
			else if (ch >= 'a' && ch <= 'z')
				len2++;
			else if (ch >= '0' && ch <= '9')
				len3++;
			else
			{
				int in_tag = 0;  // 判断ch是否属于other数组 0表示不属于
				for (int w = 0; w < 15; w++)
				{
					if (other[w] == ch)
					{
						in_tag = 1;
						break;
					}
				}
				if (in_tag == 1)
					len4++;
				else  // 说明有非法字符
				{
					tag--;
				}
			}
		}
		
		if (len1 < upper_count || len2 < lower_count || len3 < digit_count || len4 < other_count  
			|| len1 + len2 + len3 + len4 != passcode_len)  // 仔细体会逻辑关系 xx_count是必要要有的（至少）有这个多该类字符
		{
			tag--;
		}
	}

	if (tag == 1)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;


	return 0;
}