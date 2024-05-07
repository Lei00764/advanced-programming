/* 2053932 Èí¼þ À×Ïè */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
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

	// Áã¡¢Ò¼, ·¡, Èþ, ËÁ, Îé, Â½, Æâ, °Æ¡¢¾Á
	// ÒÚ¡¢Íò¡¢Çª¡¢°Û¡¢Ê°
	// Ô²¡¢½Ç¡¢·Ö¡¢Õû
	
	cout << "´óÐ´½á¹ûÊÇ:" << endl;
	
	if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && yuan == 0 && jiao == 0 && fen == 0)
	{
		cout << "ÁãÔ²";
	}
	
	// Ê®ÒÚ~ÒÚ
	if (shiyi == 0)
	{
		// Ê²Ã´¶¼²»ÐèÒª×ö
	}
	else
	{
		switch (shiyi)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}
	if (yi != 0)
	{
		switch (yi)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "ÒÚ";
	}
	else
	{
		if (shiyi == 0)
		{

		}
		else 
		{
			cout << "ÒÚ";
		}
		
	}
	int sum_zero = 0;
	// Ç§Íò~Íò
	if (qianwan == 0)
	{
		sum_zero += 1;
	}
	else
	{
		switch (qianwan)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Çª";
	}
	if (baiwan == 0)
	{
		sum_zero += 1;
	}
	else if (baiwan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0))
		{
			cout << "Áã";
			sum_zero = 0;
		}
		switch (baiwan)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "°Û";
	}
	if (shiwan == 0)
	{
		sum_zero += 1;
	}
	else if (shiwan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0))
		{
			cout << "Áã";
			sum_zero = 0;
		}
		switch (shiwan)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}
	if (wan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan !=0) && sum_zero < 2)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		switch (wan)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Íò";
	}
	else
	{
		if (sum_zero >= 3)
		{
			sum_zero += 1;
		}
		else
		{
			cout << "Íò";
		}
		
	}

	if (qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0)
	{
		sum_zero = 0;
	}
	// Ç§~Ôª
	if (qian == 0)
	{
		sum_zero += 1;
	}
	else
	{
		switch (qian)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Çª";
	}
	if (bai == 0)
	{
		sum_zero += 1;
	}
	else if (bai != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0) && sum_zero <4)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		switch (bai)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "°Û";
	}
	if (shi == 0)
	{
		sum_zero += 1;
	}
	else if (shi != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0))
		{ 	
			
			cout << "Áã";
			sum_zero = 0;
		}
		switch (shi)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}
	if (yuan != 0)
	{
		if (sum_zero != 0 && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0) && sum_zero < 2)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		if (qian != 0 && bai == 0 && shi == 0)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		if (bai != 0 && shi == 0)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || wan != 0 || shiwan != 0 || wan != 0) && qian == 0 && bai == 0 && shi == 0)
		{
			cout << "Áã";
			sum_zero = 0;
		}
		switch (yuan)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ô²";
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
			cout << "Ô²";
		}
	}
	
	if (jiao == 0 && fen == 0)
	{
		cout << "Õû";
	}
	else if (jiao != 0 && fen == 0)
	{
		switch (jiao)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "½ÇÕû";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (sum_zero <= 3)
			cout << "Áã";
		switch (fen)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "·Ö";
	}
	else
	{
		switch (jiao)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "½Ç";
		switch (fen)
		{
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "·Ö";
	}
	cout << endl;

	return 0;
}