/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   ---------------------------------------------------------------------
*/

/***************************************************************************
  函数名称：
  功    能：递归方式完成十进制到其它进制的转换并打印
  输入参数：int num ：十进制数
			int base：要转换的进制
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、不允许出现任何形式的循环
			3、不允许使用cmath中的函数
			4、不允许使用64位整数
***************************************************************************/
void dec_to_base_n(int num, int base)
{
	int yushu = -1;
	if (num < 0)
	{
		unsigned u_num = (unsigned)num;
		num = u_num / base;
		yushu = u_num % base;
	}
	if (num < base)
	{
		switch (num)
		{
			case 10:
			{
				cout << 'A';
				break;
			}
			case 11:
			{
				cout << 'B';
				break;
			}
			case 12:
			{
				cout << 'C';
				break;
			}
			case 13:
			{
				cout << 'D';
				break;
			}
			case 14:
			{
				cout << 'E';
				break;
			}
			case 15:
			{
				cout << 'F';
				break;
			}
			default:
				cout << num%base;
		}
		return;
	}
	dec_to_base_n(num / base, base);
	switch (num % base)
	{
		case 10:
		{
			cout << 'A';
			break;
		}
		case 11:
		{
			cout << 'B';
			break;
		}
		case 12:
		{
			cout << 'C';
			break;
		}
		case 13:
		{
			cout << 'D';
			break;
		}
		case 14:
		{
			cout << 'E';
			break;
		}
		case 15:
		{
			cout << 'F';
			break;
		}
		default:
			cout << num%base;
	}
	if (yushu > 0)
	{
		switch (yushu)
		{
			case 10:
			{
				cout << 'A';
				break;
			}
			case 11:
			{
				cout << 'B';
				break;
			}
			case 12:
			{
				cout << 'C';
				break;
			}
			case 13:
			{
				cout << 'D';
				break;
			}
			case 14:
			{
				cout << 'E';
				break;
			}
			case 15:
			{
				cout << 'F';
				break;
			}
			default:
				cout << yushu;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int num, base;

	cout << "请输入十进制整数(int型)及要转换的进制[2..16]" << endl;
	cin >> num >> base;		//不考虑输入错误，num为int型范围任何值均可，base为2~16，不考虑10进制

	if (base == 10) //进制为10直接退出
		return -1;

	/* 完成进制转换并打印 */
	dec_to_base_n(num, base);
	cout << endl;

	return 0;
}

/*
	数据在计算机中都以二进制补码形式存储，对于int类负数来说，最左边一位必定是1，转成其他进制，以十六进制为例，最高位一定大于或等于8（1000）
*/