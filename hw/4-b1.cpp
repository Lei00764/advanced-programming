/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考 num位前后均没有零
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[0-100亿)之间的数字:" << endl;
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

	int flag_of_zero = 0; // 0代表当前位的下一位为0
	cout << "大写结果是:" << endl;
	
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
	{
		daxie(0, 1);
		cout << "圆整";
	}
	if (shiyi != 0)
	{
		daxie(shiyi, flag_of_zero);
		cout << "拾";
	}

	if (yi != 0)
	{
		daxie(yi, flag_of_zero);
	}

	if (shiyi + yi > 0)
		cout << "亿";

	if (qianwan != 0)
	{
		daxie(qianwan, flag_of_zero);
		cout << "仟";
	}
	else
	{
		if (baiwan != 0 && shiyi + yi > 0)
		{
			flag_of_zero = 1;
			daxie(qianwan, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (baiwan != 0)
	{
		daxie(baiwan, flag_of_zero);
		cout << "佰";
	}
	else
	{
		if (shiwan != 0 && (shiyi + yi + qianwan > 0))
		{
			flag_of_zero = 1;
			daxie(baiwan, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (shiwan != 0)
	{
		daxie(shiwan, flag_of_zero);
		cout << "拾";
	}
	else
	{
		if (wan != 0 && (shiyi + yi + qianwan + baiwan > 0))
		{
			flag_of_zero = 1;
			daxie(shiwan, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (wan != 0)
	{
		daxie(wan, flag_of_zero);
		cout << "万";
	}
	else
	{
		if (qianwan + baiwan + shiwan > 0)
		{
			cout << "万";
		}
		
	}

	if (qian != 0)
	{
		daxie(qian, flag_of_zero);
		cout << "仟";
	}
	else
	{
		if (bai != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan > 0))
		{
			flag_of_zero = 1;
			daxie(qian, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (bai != 0)
	{
		daxie(bai, flag_of_zero);
		cout << "佰";
	}
	else
	{
		if (shi != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian > 0))
		{
			flag_of_zero = 1;
			daxie(bai, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (shi != 0)
	{
		daxie(shi, flag_of_zero);
		cout << "拾";
	}
	else
	{
		if (yuan != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai> 0))
		{
			flag_of_zero = 1;
			daxie(shi, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (yuan != 0)
	{
		daxie(yuan, flag_of_zero);
		cout << "圆";
	}
	else
	{
		if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi> 0)
		{
			cout << "圆";
		}
	}

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0 && (fen + jiao == 0))
	{
		cout << "整";
	}
	
	if (jiao != 0)
	{
		daxie(jiao, flag_of_zero);
		cout << "角";
	}
	else
	{
		if (fen != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0))
		{
			flag_of_zero = 1;
			daxie(jiao, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (fen != 0)
	{
		daxie(fen, flag_of_zero);
		cout << "分";
	}

	if (jiao != 0 && fen == 0)
	{
		cout << "整";
	}

	cout << endl;

	return 0;
}