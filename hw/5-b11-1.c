/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�
#include <string.h>


const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
			{
				strncat(result, &chnstr[0], 2);
			}
			break;
		case 1:
			strncat(result, &chnstr[2], 2);
			break;
		case 2:
			strncat(result, &chnstr[4], 2);
			break;
		case 3:
			strncat(result, &chnstr[6], 2);
			break;
		case 4:
			strncat(result, &chnstr[8], 2);
			break;
		case 5:
			strncat(result, &chnstr[10], 2);
			break;
		case 6:
			strncat(result, &chnstr[12], 2);
			break;
		case 7:
			strncat(result, &chnstr[14], 2);
			break;
		case 8:
			strncat(result, &chnstr[16], 2);
			break;
		case 9:
			strcat(result, &chnstr[18]);
			break;
		default:
			printf("error");
			break;
	}
}

int main()
{
	printf("������[0-100��)֮�������:\n");
	double num;
	scanf("%lf", &num);
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

	int flag_of_zero = 0;
	printf("��д�����:\n");

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
	{
		daxie(0, 1);
		strcat(result, "Բ��");
	}
	if (shiyi != 0)
	{
		daxie(shiyi, flag_of_zero);
		strcat(result, "ʰ");
	}

	if (yi != 0)
	{
		daxie(yi, flag_of_zero);
	}

	if (shiyi + yi > 0)
		strcat(result, "��");

	if (qianwan != 0)
	{
		daxie(qianwan, flag_of_zero);
		strcat(result, "Ǫ");
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
		strcat(result, "��");
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
		strcat(result, "ʰ");
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
		strcat(result, "��");
	}
	else
	{
		if (qianwan + baiwan + shiwan > 0)
		{
			strcat(result, "��");
		}

	}

	if (qian != 0)
	{
		daxie(qian, flag_of_zero);
		strcat(result, "Ǫ");
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
		strcat(result, "��");
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
		strcat(result, "ʰ");
	}
	else
	{
		if (yuan != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai > 0))
		{
			flag_of_zero = 1;
			daxie(shi, flag_of_zero); // �����
			flag_of_zero = 0;
		}
	}

	if (yuan != 0)
	{
		daxie(yuan, flag_of_zero);
		strcat(result, "Բ");
	}
	else
	{
		if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi > 0)
		{
			strcat(result, "Բ");
		}
	}

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0 && (fen + jiao == 0))
	{
		strcat(result, "��");
	}

	if (jiao != 0)
	{
		daxie(jiao, flag_of_zero);
		strcat(result, "��");
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
		strcat(result, "��");
	}

	if (jiao != 0 && fen == 0)
	{
		strcat(result, "��");
	}

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
