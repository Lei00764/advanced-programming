/* 2053932 软件 雷翔 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int y, int m, int d) : year(y), month(m), day(d) {};
	int IsRunNian();
	int IsValid();  // 判断输入是否合法
};

/* --- 此处给出类成员函数的体外实现 --- */
int Days::calc_days()
{
	int is_valid = IsValid();
	if (is_valid == 0)  // 月日关系不正确
		return -1;
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	int is_run_nian = IsRunNian();
	for (int i = 1; i < month; i++)
	{
		sum += arr[i - 1];
		if (is_run_nian == 1 && i == 2)
			sum++;
	}
	sum += day;
	return sum;
}

/**
  * 闰年返回1，非闰年返回0
  */
int Days::IsRunNian()
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}


/**
  * 若月日关系不正确，返回0，正确则返回1
  */
int Days::IsValid()
{
	if ((month < 1) || (month > 12))
		return 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if ((day < 1) || (day > 31))
			return 0;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if ((day < 1) || (day > 30))
			return 0;
	}
	if (month == 2)
	{
		int is_run_nian = IsRunNian();
		if (is_run_nian == 1)  // 闰年
		{
			if ((day < 1) || (day > 29))
				return 0;
		}
		else
		{
			if ((day < 1) || (day > 28))
				return 0;
		}
	}
	return 1;
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
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}