/* 2053932 ��� ���� */
#include <iostream>
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	double money;
	int wushi = 0, ershi = 0, shi = 0, wu = 0, yi = 0, wujiao = 0, yijiao = 0, wufen = 0, liangfen = 0, yifen = 0;
	cin >> money;
	if (money >= 50)
	{
		wushi += 1;
		money -= 50;
	}
	int k = (int)(money / 10); // Ŀ�ģ�ȡ��
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
	// ��ʱ money�� 0~10 ֮�� ������10
	if (money >= 5)
	{
		wu = 1;
		money -= 5;
	}
	// ��ʱ money�� 0~5 ֮�� ������5
	if (money > 0 && money < 5)
	{
		yi = (int)(money / 1);
		money -= yi;
	}
	// ��ʱ money�� 0~1 ֮�� ������1 
	money = (int) ((money + 0.005) * 100); // ����100���� ��ʱmoney�� 0~100 ֮��
	if (money >= 50)
	{
		wujiao = 1;
		money -= 50;
	}
	// ��ʱ money�� 0~0.5 ֮�� ������0.5
	if (money >= 10 && money < 50)
	{
		yijiao = (int)(money / 10);
		money -= yijiao * 10;
	}
	// ��ʱ money�� 0~0.1 ֮�� ������0.1
	if (money > 5)
	{
		wufen = 1;
		money -= 5;
	}
	// ��ʱ money�� 0~0.0.5 ֮�� ������0.05
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
	cout << "��" << sum << "�����㣬�������£�" << endl;
	if (wushi != 0)
		cout << "50Ԫ : " << wushi << "��" << endl;
	if (ershi != 0)
		cout << "20Ԫ : " << ershi << "��" << endl;
	if (shi != 0)
		cout << "10Ԫ : " << shi << "��" << endl;
	if (wu != 0)
		cout << "5Ԫ  : " << wu << "��" << endl;
	if (yi != 0)
		cout << "1Ԫ  : " << yi << "��" << endl;
	if (wujiao != 0)
		cout << "5��  : " << wujiao << "��" << endl;
	if (yijiao != 0)
		cout << "1��  : " << yijiao << "��" << endl;
	if (wufen != 0)
		cout << "5��  : " << wufen << "��" << endl;
	if (liangfen != 0)
		cout << "2��  : " << liangfen << "��" << endl;
	if (yifen != 0)
		cout << "1��  : " << yifen << "��" << endl;
}