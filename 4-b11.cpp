/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
   ***************************************************************************/
void print_tower(char end_ch, char start, int key) // key 正序或倒序
{
	/* 按需实现，函数中不允许任何形式的循环*/
	void print_pre_tower(char end_ch, char label); // 声明函数
	void print_pre_tower_daoxu(char end_ch, char label, char ch); // 声明函数
	if (key == 1)
	{
		if (start > end_ch)
		{
			return;
		}
		print_pre_tower(end_ch, start++);
		cout << endl;
		print_tower(end_ch, start, 1);
	}
	else
	{
		if (start > end_ch)
		{
			return;
		}
		print_pre_tower_daoxu(end_ch, start++, 'A');
		cout << endl;
		print_tower(end_ch, start, 0);
	}
	
}
// end_ch每次递归减1
void print_pre_tower(char end_ch, char label)  // 完成每一行的创建 正序
{
	if (end_ch == 65)
	{
		cout << 'A';
		return;
	}

	if (end_ch <= label)
		cout << end_ch;
	else
	{
		cout << " ";
	}

	print_pre_tower(end_ch - 1, label);

	if (end_ch <= label)
		cout << end_ch;
	else
	{
		// cout << " "; // 不需要
	}
}
// end_ch不变 label不变 -> 要加进来一个新参数 
void print_pre_tower_daoxu(char end_ch, char label, char ch) // end_ch不变 label不变 -> 要加进来一个新参数 
{														   // 加进来的这个参数始终从'A'开始 
	if (ch == end_ch)
	{
		cout << ch;
		return;
	}

	if (ch >= label)
		cout << ch;
	else
	{
		cout << " ";
	}

	print_pre_tower_daoxu(end_ch, label, ch + 1);

	if (ch >= label)
		cout << ch;
	else
	{
		// cout << " ";
	}
}


char print_equal(char end_ch)
{
	if (end_ch == 65)
	{
		return '=';
	}
	cout << "==";
	return print_equal(end_ch - 1);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 'A', 1);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 'A', 0);
	cout << endl;

	return 0;
}