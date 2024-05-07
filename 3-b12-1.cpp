/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

		if (cin.fail()) // 如果当前处于cin的错误状态
		{

			cin.clear(); // 清空cin的错误状态
			cin.ignore(1024, '\n'); // 清空缓冲区  只清除1024个字符或遇到回车
			/* cin.sync() 不好用 */
			continue;
		}

		if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}