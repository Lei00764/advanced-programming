/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������[0-100��)֮�������:\n");
	double num;
	scanf("%lf", &num);
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
	printf("��д�����:\n");

	if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		printf("��Բ");
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
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	if (yi != 0)
	{
		switch (yi)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else
	{
		if (shiyi == 0)
		{

		}
		else
		{
			printf("��");
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
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	if (baiwan == 0)
	{
		sum_zero += 1;
	}
	else 
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0))
		{
			printf("��");
			sum_zero = 0;
		}
		switch (baiwan)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	if (shiwan == 0)
	{
		sum_zero += 1;
	}
	else 
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0))
		{
			printf("��");
			sum_zero = 0;
		}
		switch (shiwan)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	if (wan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0) && sum_zero < 2)
		{
			printf("��");
			sum_zero = 0;
		}
		switch (wan)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else
	{
		if (sum_zero >= 3)
		{
			sum_zero += 1;
		}
		else
		{
			printf("��");
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
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	if (bai == 0)
	{
		sum_zero += 1;
	}
	else if (bai != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0) && sum_zero < 4)
		{
			printf("��");
			sum_zero = 0;
		}
		switch (bai)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	if (shi == 0)
	{
		sum_zero += 1;
	}
	else
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0))
		{

			printf("��");
			sum_zero = 0;
		}
		switch (shi)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	if (yuan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0) && sum_zero < 2)
		{
			printf("��");
			sum_zero = 0;
		}
		if (qian != 0 && bai == 0 && shi == 0)
		{
			printf("��");
			sum_zero = 0;
		}
		if (bai != 0 && shi == 0)
		{
			printf("��");
			sum_zero = 0;
		}
		if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0) && qian == 0 && bai == 0 && shi == 0)
		{
			printf("��");
			sum_zero = 0;
		}
		switch (yuan)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Բ");
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
			printf("Բ");
		}
	}

	if (jiao == 0 && fen == 0)
	{
		printf("��");
	}
	else if (jiao != 0 && fen == 0)
	{
		switch (jiao)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("����");
	}
	else if (jiao == 0 && fen != 0)
	{
		if (sum_zero <= 3)
			printf("��");
		switch (fen)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else
	{
		switch (jiao)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
		switch (fen)
		{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	printf("\n");
	return 0;
}