/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������: " << endl;
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
	cout << "ʮ��λ" << " : " << shiyi << endl;
	cout << "��λ  " << " : " << yi << endl;
	cout << "ǧ��λ" << " : " << qianwan << endl;
	cout << "����λ" << " : " << baiwan << endl;
	cout << "ʮ��λ" << " : " << shiwan << endl;
	cout << "��λ  " << " : " << wan << endl;
	cout << "ǧλ  " << " : " << qian << endl;
	cout << "��λ  " << " : " << bai << endl;
	cout << "ʮλ  " << " : " << shi << endl;
	cout << "Բ    " << " : " << yuan << endl;
	int jiao = (int)((num_xiaoshu + 0.005) * 10);
	int fen = (int)((num_xiaoshu + 0.005) * 100) % 10;
	cout << "��    " << " : " << jiao << endl;
	cout << "��    " << " : " << fen << endl;
	return 0;
}
/* ��Ҫ˼·���ѵ�ʮ��λ�����ó���������ʣ�µ����ݾͿ��Դ���unsigned int���У��Ҳ��ᳬ����Χ */