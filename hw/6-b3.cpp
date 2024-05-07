/* 2053932 软件 雷翔 */
#include <iostream>
#include <cmath>
using namespace std;

unsigned int Pow(int x, int n)
{
	unsigned int sum = 1;
	for (int i = 0; i < n; i++)
		sum *= x;
	return sum;
}

int main()
{
	char str[33] = { '\0' }, * p;  // 最多32个0/1
	p = str;
	unsigned int sum = 0;  // 记录结果
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	//fgets(str, 33, stdin);
	cin >> str;
	while (*p != '\0')  
		p++;
	int n = p - str;  // 0/1总个数
	for (char *ps = str; ps < p; ps++)
	{
		if (*ps == '1')
			sum += Pow(2, n - 1);
		n--;
	}
	cout << sum << endl;

	return 0;
}
// 如果用fgets的话，从文件和键盘输入可能读入不同的结果
// pow适用于double
