/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:" << endl;
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
	int jiao = (int)((num_xiaoshu + 0.005) * 10);
	int fen = (int)((num_xiaoshu + 0.005) * 100) % 10;

	// �㡢Ҽ, ��, ��, ��, ��, ½, ��, �ơ���
	// �ڡ���Ǫ���ۡ�ʰ
	// Բ���ǡ��֡���
	
	cout << "��д�����:" << endl;
	
	if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		cout << "��Բ";
	}
	
	// ʮ��~��
	if (shiyi == 0)
	{
		// ʲô������Ҫ��
	}
	else
	{
		switch (shiyi)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}
	if (yi != 0)
	{
		switch (yi)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	else
	{
		if (shiyi == 0)
		{

		}
		else 
		{
			cout << "��";
		}
		
	}
	int sum_zero = 0;
	// ǧ��~��
	if (qianwan == 0)
	{
		sum_zero += 1;
	}
	else
	{
		switch (qianwan)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "Ǫ";
	}
	if (baiwan == 0)
	{
		sum_zero += 1;
	}
	else if (baiwan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0))
		{
			cout << "��";
			sum_zero = 0;
		}
		switch (baiwan)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	if (shiwan == 0)
	{
		sum_zero += 1;
	}
	else if (shiwan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0))
		{
			cout << "��";
			sum_zero = 0;
		}
		switch (shiwan)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}
	if (wan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan !=0) && sum_zero < 2)
		{
			cout << "��";
			sum_zero = 0;
		}
		switch (wan)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	else
	{
		if (sum_zero >= 3)
		{
			sum_zero += 1;
		}
		else
		{
			cout << "��";
		}
		
	}

	if (qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0)
	{
		sum_zero = 0;
	}
	// ǧ~Ԫ
	if (qian == 0)
	{
		sum_zero += 1;
	}
	else
	{
		switch (qian)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "Ǫ";
	}
	if (bai == 0)
	{
		sum_zero += 1;
	}
	else if (bai != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0) && sum_zero <4)
		{
			cout << "��";
			sum_zero = 0;
		}
		switch (bai)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	if (shi == 0)
	{
		sum_zero += 1;
	}
	else if (shi != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0))
		{ 	
			
			cout << "��";
			sum_zero = 0;
		}
		switch (shi)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}
	if (yuan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0) && sum_zero < 2)
		{
			cout << "��";
			sum_zero = 0;
		}
		if (qian != 0 && bai == 0 && shi == 0)
		{
			cout << "��";
			sum_zero = 0;
		}
		if (bai != 0 && shi == 0)
		{
			cout << "��";
			sum_zero = 0;
		}
		if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0) && qian == 0 && bai == 0 && shi == 0)
		{
			cout << "��";
			sum_zero = 0;
		}
		switch (yuan)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "Բ";
	}
	else
	{
		if (sum_zero >= 3)
		{ 
			sum_zero += 1;
		}
		if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && yuan == 0)
		{

		}
		else
		{
			cout << "Բ";
		}
	}
	
	if (jiao == 0 && fen == 0)
	{
		cout << "��";
	}
	else if (jiao != 0 && fen == 0)
	{
		switch (jiao)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "����";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (sum_zero <= 3)
			cout << "��";
		switch (fen)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	else
	{
		switch (jiao)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
		switch (fen)
		{
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	cout << endl;

	return 0;
}