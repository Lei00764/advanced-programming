/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入找零值：" << endl;
	double money;
	int wushi = 0, ershi = 0, shi = 0, wu = 0, yi = 0, wujiao = 0, yijiao = 0, wufen = 0, liangfen = 0, yifen = 0;
	cin >> money;
	if (money >= 50)
	{
		wushi += 1;
		money -= 50;
	}
	int k = (int)(money / 10); // 目的：取整
	if (k == 4)
	{
		ershi = 2;
		money -= 2 * 20;
	}
	if (k == 3)
	{
		ershi = 1;
		shi = 1;
		money -= 30;
	}
	if (k == 2)
	{
		ershi = 1;
		money -= 20;
	}
	if (k == 1)
	{
		shi = 1;
		money -= 10;
	}
	// 此时 money在 0~10 之间 不包括10
	if (money >= 5)
	{
		wu = 1;
		money -= 5;
	}
	// 此时 money在 0~5 之间 不包括5
	if (money > 0 && money < 5)
	{
		yi = (int)(money / 1);
		money -= yi;
	}
	// 此时 money在 0~1 之间 不包括1 
	money = (int) ((money + 0.005) * 100); // 扩大100倍， 此时money在 0~100 之间
	if (money >= 50)
	{
		wujiao = 1;
		money -= 50;
	}
	// 此时 money在 0~0.5 之间 不包括0.5
	if (money >= 10 && money < 50)
	{
		yijiao = (int)(money / 10);
		money -= yijiao * 10;
	}
	// 此时 money在 0~0.1 之间 不包括0.1
	if (money > 5)
	{
		wufen = 1;
		money -= 5;
	}
	// 此时 money在 0~0.0.5 之间 不包括0.05
	if (money >= 4)
	{
		liangfen = 2;
		money -= 4;
	}
	if (money >= 2)
	{
		liangfen = 1;
		money -= 2;
	}
	if (money == 1)
	{
		yifen = 1;
	}
	int sum = wushi + ershi + shi + wu +  yi + wujiao + yijiao + wufen +  liangfen + yifen ;
	cout << "共" << sum << "张找零，具体如下：" << endl;
	if (wushi != 0)
		cout << "50元 : " << wushi << "张" << endl;
	if (ershi != 0)
		cout << "20元 : " << ershi << "张" << endl;
	if (shi != 0)
		cout << "10元 : " << shi << "张" << endl;
	if (wu != 0)
		cout << "5元  : " << wu << "张" << endl;
	if (yi != 0)
		cout << "1元  : " << yi << "张" << endl;
	if (wujiao != 0)
		cout << "5角  : " << wujiao << "张" << endl;
	if (yijiao != 0)
		cout << "1角  : " << yijiao << "张" << endl;
	if (wufen != 0)
		cout << "5分  : " << wufen << "张" << endl;
	if (liangfen != 0)
		cout << "2分  : " << liangfen << "张" << endl;
	if (yifen != 0)
		cout << "1分  : " << yifen << "张" << endl;
}