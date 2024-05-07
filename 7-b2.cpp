/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>  // _getch()
using namespace std;

const int NumberOfCategories = 26;  // 单品数量



struct KFC
{
	char id;
	char name[40];
	double cost;
};

struct SPECIAL
{
	char ids[20];
	char name[40];
	double cost;
};

const struct KFC list[] = {
	{'A', "香辣鸡腿堡",         18.5},
	{'B', "劲脆鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "劲爆鸡米花",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "藤椒无骨大鸡柳(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "香甜粟米棒",         9.0},
	{'U', "葡式蛋挞",           8.0},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//	{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
		{NULL, NULL, 0}
};

// 返回在list中的下标
int FindIndexByCh(char id, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i].id == id)
			return i;
	}
	return -1;
}

void ClearArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

void ShowOrder(int arr[], int n)
{
	int tag = 0;  // 0表示第一次输出
	for (int k = 0; k < n; k++)
	{
		if (tag == 0 && arr[k] != 0)
		{
			cout << list[k].name;
			if (arr[k] > 1)
				cout << "*" << arr[k];
			tag = 1;
		}
		else if (tag == 1 && arr[k] != 0)
		{
			cout << "+" << list[k].name;
			if (arr[k] > 1)
				cout << "*" << arr[k];
		}
	}
}

void Menu()
{
	int arr[NumberOfCategories];  // 用来存放用户点的单品的数量
	int taocan_count = sizeof(special) / sizeof(special[0]) - 1;
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021秋季菜单                       " << endl;
	cout << "=============================================================" << endl;
	for (int i = 0; i < NumberOfCategories; i++)
	{
		cout << " " << list[i].id << " " << setw(20) << setiosflags(ios::left) << list[i].name << setw(6) << list[i].cost << " ";
		if (i % 2 == 0)
			cout << "|  ";
		else
			cout << endl;
	}
	cout << endl;
	cout << "【优惠信息】：" << endl;
	for (int i = 0; i < taocan_count; i++)
	{
		ClearArr(arr, NumberOfCategories);
		cout << special[i].name << "=";
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, NumberOfCategories);
			arr[index]++;
		}
		ShowOrder(arr, NumberOfCategories);
		cout << "=" << special[i].cost << endl;
	}
	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小)/akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
}

double ComputeCost(int order_arr[], int n)
{
	double cost_money = 0;
	int taocan_count = sizeof(special) / sizeof(special[0]) - 1;  // 套餐种类总数
	int taocan_arr[NumberOfCategories];
	for (int i = 0; i < taocan_count; i++)
	{
		ClearArr(taocan_arr, NumberOfCategories);
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, NumberOfCategories);
			taocan_arr[index]++;
		}
		int is_special = 0;  // 判断是否可以凑成套餐 0表示不能
		while (1)  // 之所以要循环 -> 可能可以凑成多个套餐
		{
			for (int k = 0; k < NumberOfCategories; k++)
			{
				if (taocan_arr[k] != 0)
				{
					if (order_arr[k] >= taocan_arr[k])
						is_special = 1;
					else
					{
						is_special = 0;
						break;  // 有一个单品不符合就立即退出
					}
				}
			}
			if (is_special == 1)  // 点一个套餐  -> 从order_arr中把套餐中的单品删掉
			{
				cost_money += special[i].cost;
				for (int w = 0; w < NumberOfCategories; w++)
				{
					if (taocan_arr[w] != 0)
						order_arr[w] -= taocan_arr[w];
				}
			}
			else
				break;
		}
	}
	for (int m = 0; m < NumberOfCategories; m++)  // 不能凑成套餐的其余的单品
	{
		if (order_arr[m] != 0)
		{
			cost_money += order_arr[m] * list[m].cost;
			order_arr[m] = 0;
		}
	}
	return cost_money;
}

int main()
{
	system("mode con cols=120 lines=35");
	while (1)
	{
		system("cls");
		Menu();
		cout << "请点单：";
		int order_arr[NumberOfCategories] = { 0 };// arr 里面存放点的所有单品
		char ch;  // 记录点餐的单品的字母
		int flag = 0;    // 0表示读取第一个字符
		int IsSucc = 1;  // 记录是否成功读取
		while ((ch = getchar()) != '\n')
		{
			if (ch == ' ')
				continue;
			if (flag == 0)
			{
				flag++;  // 表示已经读取了第一个字符
				if (ch == '0')
					return 0;
			}
			if (ch >= 'a' && ch <= 'z')
				ch -= 'a' - 'A';
			if (ch >= 'A' && ch <= 'Z')
			{
				int index = FindIndexByCh(ch, NumberOfCategories);
				order_arr[index]++;
			}
			else
			{
				cout << "输入错误，按任意键继续." << endl;
				char item1 = _getch();
				IsSucc = 0;
				break;
			}
		}
		if (flag != 0 && IsSucc == 1)  
		{
			cout << "你的点餐=";
			ShowOrder(order_arr, NumberOfCategories);
			double cost_money = ComputeCost(order_arr, NumberOfCategories);  // ConputeCost后order_arr全为0
			cout << endl;
			cout << "共计：" << cost_money << "元" << endl;
			cout << "点单完成，按任意键继续." << endl;
			char item2 = _getch();
		}
		if (IsSucc != 1)  // 只有当读取错误时才需要清空缓冲区
			while (getchar() != '\n');
	}

	return 0;
}