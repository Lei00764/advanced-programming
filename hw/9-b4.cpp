/* 2053932 软件 雷翔 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

class stu_list;
/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int flag;  // flag = 1 表示第一轮，flag = 2 表示第二轮
public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
	friend stu_list;
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* 允许按需加入private数据成员和成员函数 */
	int point;  // 起到类似指针的作用，指向最后一个元素，值等于元素个数-1

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单
	

	/* 允许按需加入其它public成员函数 */
	void Sort();  // 根据学号排序
	void Swap(int i, int j);  // 根据序号交换两个数组元素
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append)
{
	if (append == 0)
		point = -1;
	
	fstream fin;
	fin.open(filename, ios::in);
	if (fin.is_open() != 1)
		return -1;
	int num;
	while (fin >> num)
	{
		point++;
		stu[point].stu_no = num;
		fin >> stu[point].stu_name;
		
		if (append == 0)
			stu[point].flag = 1;
		else
			stu[point].flag = 2;
	}
	//cout << "point" << point << endl;
	return 1;
}

int stu_list::print(const char* prompt)
{
	
	Sort();  // 根据学号排序
	//for (int i = 0; i < point + 1; i++)
		//cout << stu[i].stu_no << " " << stu[i].stu_name << stu[i].flag << endl;;
	cout << prompt << endl;
	
	cout << "===========================================================" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;
	int index = 1;
	for (int i = 0; i < point + 1; i++)
	{
		cout << setiosflags(ios::left) << setw(4) << index++ << " " << stu[i].stu_no << " " << setw(MAX_NAME_LEN) << stu[i].stu_name << " ";
		if (stu[i].flag == 1)
		{
			cout << "Y      ";
			if (stu[i].stu_no == stu[i + 1].stu_no)
			{
				cout << "Y" << endl;
				i++;
			}
			else
			{
				cout << "退课" << endl;
			}
		}
		else  // 第一次没有选，第二次选了
		{
			cout << "/      补选" << endl;
			
		}
	}
	cout << "===========================================================" << endl;
	return 0;
}

void stu_list::Sort()
{
	for (int i = 0; i <= point; i++)
	{
		for (int j = 0; j <= point - i - 1; j++)
		{
			if (stu[j].stu_no > stu[j + 1].stu_no)
				Swap(j, j + 1);
		}
	}
}

void stu_list::Swap(int i, int j)
{
	stu_info temp = stu[i];

	stu[i].flag = stu[j].flag;
	strcpy(stu[i].stu_name, stu[j].stu_name);
	stu[i].stu_no = stu[j].stu_no;

	stu[j].flag = temp.flag;
	strcpy(stu[j].stu_name, temp.stu_name);
	stu[j].stu_no = temp.stu_no;
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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */

	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}