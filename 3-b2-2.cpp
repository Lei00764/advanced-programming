/* 2053932 ��� ���� */
#include <iostream>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;
	int num;
	cin >> num;
	int gewei = num % 10;
	int shiwei = (num / 10) % 10;
	int baiwei = (num / 100) % 10;
	int qianwei = (num / 1000) % 10;
	int wanwei = (num / 10000) % 10;
	cout << "��λ" << " : " << wanwei << endl;
	cout << "ǧλ" << " : " << qianwei << endl;
	cout << "��λ" << " : " << baiwei << endl;
	cout << "ʮλ" << " : " << shiwei << endl;
	cout << "��λ" << " : " << gewei << endl;
	return 0;
}
