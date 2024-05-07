/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入[0-100亿)之间的数字: " << endl;
	double num;
	cin >> num;
	int shiyi = (int)(num / 1000000000.0);
	double num_remove_shiyi = num - shiyi * 1000000000.0;
	unsigned int num_remove_shiyi_zhengshu = (unsigned int)num_remove_shiyi;
	double num_xiaoshu = num_remove_shiyi - num_remove_shiyi_zhengshu;
	int yi = num_remove_shiyi_zhengshu / 100000000 % 10;
	int qianwan = num_remove_shiyi_zhengshu / 10000000 % 10;
	int baiwan = num_remove_shiyi_zhengshu / 1000000 % 10;
	int shiwan = num_remove_shiyi_zhengshu / 100000 % 10;
	int wan = num_remove_shiyi_zhengshu / 10000 % 10;
	int qian = num_remove_shiyi_zhengshu / 1000 % 10;
	int bai = num_remove_shiyi_zhengshu / 100 % 10;
	int shi = num_remove_shiyi_zhengshu / 10 % 10;
	int yuan = num_remove_shiyi_zhengshu / 1 % 10;
	cout << "十亿位" << " : " << shiyi << endl;
	cout << "亿位  " << " : " << yi << endl;
	cout << "千万位" << " : " << qianwan << endl;
	cout << "百万位" << " : " << baiwan << endl;
	cout << "十万位" << " : " << shiwan << endl;
	cout << "万位  " << " : " << wan << endl;
	cout << "千位  " << " : " << qian << endl;
	cout << "百位  " << " : " << bai << endl;
	cout << "十位  " << " : " << shi << endl;
	cout << "圆    " << " : " << yuan << endl;
	int jiao = (int)((num_xiaoshu + 0.005) * 10);
	int fen = (int)((num_xiaoshu + 0.005) * 100) % 10;
	cout << "角    " << " : " << jiao << endl;
	cout << "分    " << " : " << fen << endl;
	return 0;
}
/* 主要思路：把第十亿位单独拿出来，这样剩下的数据就可以存在unsigned int型中，且不会超出范围 */