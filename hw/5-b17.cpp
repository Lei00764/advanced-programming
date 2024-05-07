/* 2053932 软件 雷翔 */
#include <iostream>
#include <ctime>
using namespace std;

const int MaxSize = 16;
static const char other[] = "!@#$%^&*-_=+,.?";


/**
 * @brief 下面Insert**函数保证插入成功
 */
void InsertUpper(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 65对应A
	char ch = (char)(rand() % 26 + 65);
	arr[pos] = ch;
}

void InsertLower(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 97对应a
	char ch = (char)(rand() % 26 + 97);
	arr[pos] = ch;
}

void InsertDigit(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 48对应0
	char ch = (char)(rand() % 10 + 48);
	arr[pos] = ch;
}

void InsertOther(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	int w = rand() % 15;  // 从其它字符数组中选
	arr[pos] = other[w];
}


void CreatePasscode(char arr[], int passcodeLen, int upperCount, int lowerCount, int digitCount, int otherCount)
{
	for (int i = 0; i < upperCount; i++)
		InsertUpper(arr);
	for (int i = 0; i < lowerCount; i++)
		InsertLower(arr);
	for (int i = 0; i < digitCount; i++)
		InsertDigit(arr);
	for (int i = 0; i < otherCount; i++)
		InsertOther(arr);
	
	// 可能还剩下一些长度要设置
	int remain_sum = passcodeLen - (upperCount + lowerCount + digitCount + otherCount);
	for (int k = 0; k < remain_sum; k++)
	{
		int choice = rand() % 4;
		switch (choice)
		{
			case 0:
				InsertUpper(arr);
				break;  // 记住了！！！！！！！！！！
			case 1:
				InsertLower(arr);
				break;
			case 2:
				InsertDigit(arr);
				break;
			case 3:
				InsertOther(arr);
				break;
		}
	}
}


int main()
{
	char passcode[MaxSize] = { '\0' };  // 记录密码 16个密码，对应16个字符 
	int passcode_len = 0, upper_count = 0, lower_count = 0, digit_count = 0, other_count = 0;
	srand((unsigned)time(NULL));  // 随机种子
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> passcode_len >> upper_count >> lower_count >> digit_count >> other_count;
	if (cin.fail())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (passcode_len < 12 || passcode_len > 16)
	{
		cout << "密码长度[" <<  passcode_len << "]不正确" << endl;
		return 0;
	}
	if (upper_count < 2)
	{
		cout << "大写字母个数[" << upper_count <<  "]不正确" << endl;
		return 0;
	}
	if (lower_count < 2)
	{
		cout << "小写字母个数[" << lower_count << "]不正确" << endl;
		return 0;
	}
	if (digit_count < 2)
	{
		cout << "数字个数[" << digit_count << "]不正确" << endl;
		return 0;
	}
	if (other_count < 2)
	{
		cout << "其它符号个数[" << other_count << "]不正确" << endl;
		return 0;
	}
	int sum = upper_count + lower_count + digit_count + other_count;
	if (sum > passcode_len)
	{
		cout << "所有字符类型之和[" << upper_count << "+" << lower_count << "+" << digit_count << "+" << other_count << "]大于总密码长度[" << passcode_len << "]" << endl;
		return 0;
	}
	
	cout << passcode_len << " " << upper_count << " " << lower_count << " " << digit_count << " " << other_count << endl;
	for (int i = 0; i < 10; i++)
	{
		CreatePasscode(passcode, passcode_len, upper_count, lower_count, digit_count, other_count);
		for (int j = 0; j < MaxSize; j++)
		{
			char ch = passcode[j];
			if (ch != '\0')
				cout << ch;
		}
		cout << endl;
		for (int m = 0; m < MaxSize; m++)  // 清空密码，为生成下一次密码做准备
			passcode[m] = '\0';
	}
	
	
	return 0;
}

/* 
思路：依次处理大写、小写、数字和其它字符，大写全部设置好后在设置小写，依次类推。
      设密码数组为arr
	  以处理大写字符为例，先随机生成一个位置pos，确保arr[pos]='\0'，即当前位置没有设置密码，
	  否则就要更新pos=(pos+1)%MaxSize；然后在随机生成一个字符ch，ch在A~Z之间，在pos处插入该字符
	  循环重复以上动作
*/