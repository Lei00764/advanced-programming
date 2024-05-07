/* 2053932 软件 雷翔 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
				result += chnstr[0];
			result += chnstr[1];
			break;
		case 1:
			result += chnstr[2];
			result += chnstr[3];
			break;
		case 2:
			result += chnstr[4];
			result += chnstr[5];
			break;
		case 3:
			result += chnstr[6];
			result += chnstr[7];
			break;
		case 4:
			result += chnstr[8];
			result += chnstr[9];
			break;
		case 5:
			result += chnstr[10];
			result += chnstr[11];
			break;
		case 6:
			result += chnstr[12];
			result += chnstr[13];
			break;
		case 7:
			result += chnstr[14];
			result += chnstr[15];
			break;
		case 8:
			result += chnstr[16];
			result += chnstr[17];
			break;
		case 9:
			result += chnstr[18];
			result += chnstr[19];
			break;
		default:
			cout << "error";
			break;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* --允许添加需要的内容 --*/
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

	int flag_of_zero = 0;
	cout << "大写结果是:" << endl;
	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan + jiao + fen == 0)
	{
		daxie(0, 1);
		result += "圆整";
	}
	if (shiyi != 0)
	{
		daxie(shiyi, flag_of_zero);
		result += "拾";
	}

	if (yi != 0)
	{
		daxie(yi, flag_of_zero);
	}

	if (shiyi + yi > 0)
		result += "亿";

	if (qianwan != 0)
	{
		daxie(qianwan, flag_of_zero);
		result += "仟";
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
		result += "佰";
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
		result += "拾";
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
		result += "万";
	}
	else
	{
		if (qianwan + baiwan + shiwan > 0)
		{
			result += "万";
		}

	}

	if (qian != 0)
	{
		daxie(qian, flag_of_zero);
		result += "仟";
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
		result += "佰";
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
		result += "拾";
	}
	else
	{
		if (yuan != 0 && (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai > 0))
		{
			flag_of_zero = 1;
			daxie(shi, flag_of_zero); // 输出零
			flag_of_zero = 0;
		}
	}

	if (yuan != 0)
	{
		daxie(yuan, flag_of_zero);
		result += "圆";
	}
	else
	{
		if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi > 0)
		{
			result += "圆";
		}
	}

	if (shiyi + yi + qianwan + baiwan + shiwan + wan + qian + bai + shi + yuan > 0 && (fen + jiao == 0))
	{
		result += "整";
	}

	if (jiao != 0)
	{
		daxie(jiao, flag_of_zero);
		result += "角";
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

		result += "分";
	}

	if (jiao != 0 && fen == 0)
	{
		result += "整";
	}

	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}