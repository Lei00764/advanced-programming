/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼�� numλǰ���û����
				cout << "��";
			break;
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
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	cout << "������[0-100��)֮�������:" << endl;
	double num;
	cin >> num;
	int shiyi = (int)(num / 1000000000.0);
	double num_remove_shiyi = num - shiyi * 1000000000.0;
	unsigned int num_remove_shiyi_zhengshu = (unsigned int)num_remove_shiyi;
	double num_xiaoshu = num_remove_shiyi - num_remove_shiyi_zhengshu;
	int yi = num_remove_shiyi_zhengshu      / 100000000 % 10;
	int qianwan = num_remove_shiyi_zhengshu / 10000000 % 10;
	int baiwan = num_remove_shiyi_zhengshu  / 1000000 % 10;
	int shiwan = num_remove_shiyi_zhengshu  / 100000 % 10;
	int wan = num_remove_shiyi_zhengshu     / 10000 % 10;
	int qian = num_remove_shiyi_zhengshu    / 1000 % 10;
	int bai = num_remove_shiyi_zhengshu     / 100 % 10;
	int shi = num_remove_shiyi_zhengshu     / 10 % 10;
	int yuan = num_remove_shiyi_zhengshu    / 1 % 10;
	int jiao = (int)((num_xiaoshu + 0.005) * 10);
	int fen = (int)((num_xiaoshu + 0.005) * 100) % 10;

	int flag_of_zero = 0; // 0����ǰλ����һλΪ0
	cout << "��д�����:" << endl;
	
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
	{
		daxie(0, 1);
		cout << "Բ��";
	}
	if (shiyi != 0)
	{
		daxie(shiyi, flag_of_zero);
		cout << "ʰ";
	}

	if (yi != 0)
	{
		daxie(yi, flag_of_zero);
	}

	if (shiyi + yi > 0)
		cout << "��";

	if (qianwan != 0)
	{
		daxie(qianwan, flag_of_zero);
		cout << "Ǫ";
	}
	else
	{
		if (baiwan != 0 && shiyi + yi > 0)
		{
			flag_of_zero = 1;
			daxie(qianwan, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (baiwan != 0)
	{
		daxie(baiwan, flag_of_zero);
		cout << "��";
	}
	else
	{
		if (shiwan != 0 && (shiyi + yi + qianwan > 0))
		{
			flag_of_zero = 1;
			daxie(baiwan, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (shiwan != 0)
	{
		daxie(shiwan, flag_of_zero);
		cout << "ʰ";
	}
	else
	{
		if (wan != 0 && (shiyi + yi + qianwan + baiwan > 0))
		{
			flag_of_zero = 1;
			daxie(shiwan, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (wan != 0)
	{
		daxie(wan, flag_of_zero);
		cout << "��";
	}
	else
	{
		if (qianwan + baiwan + shiwan > 0)
		{
			cout << "��";
		}
		
	}

	if (qian != 0)
	{
		daxie(qian, flag_of_zero);
		cout << "Ǫ";
	}
	else
	{
		if (bai != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan > 0))
		{
			flag_of_zero = 1;
			daxie(qian, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (bai != 0)
	{
		daxie(bai, flag_of_zero);
		cout << "��";
	}
	else
	{
		if (shi != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian > 0))
		{
			flag_of_zero = 1;
			daxie(bai, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (shi != 0)
	{
		daxie(shi, flag_of_zero);
		cout << "ʰ";
	}
	else
	{
		if (yuan != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai> 0))
		{
			flag_of_zero = 1;
			daxie(shi, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (yuan != 0)
	{
		daxie(yuan, flag_of_zero);
		cout << "Բ";
	}
	else
	{
		if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi> 0)
		{
			cout << "Բ";
		}
	}

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0 && (fen + jiao == 0))
	{
		cout << "��";
	}
	
	if (jiao != 0)
	{
		daxie(jiao, flag_of_zero);
		cout << "��";
	}
	else
	{
		if (fen != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0))
		{
			flag_of_zero = 1;
			daxie(jiao, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (fen != 0)
	{
		daxie(fen, flag_of_zero);
		cout << "��";
	}

	if (jiao != 0 && fen == 0)
	{
		cout << "��";
	}

	cout << endl;

	return 0;
}