/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>  // _getch()
#include <fstream>
using namespace std;

const int MaxCategories = 30;  // 单品数量


struct KFC
{
	char id;
	char name[33];
	double cost;
	KFC() : id('\0'), name("\0"), cost(0) {};
};

struct SPECIAL  // 套餐 多个编号 一个套餐名 一个总花费
{
	char ids[20];
	char special_name[33];
	double cost;
	SPECIAL() : ids("\0"), special_name("\0"), cost(0) {};
};

/**
  * 将文件的内容读到list和special数组中
  */
int OpenFile(struct KFC list[], struct SPECIAL special[])
{
	int list_count = 0, special_count = 0;  // 分别记录单品和套餐的数量
	fstream fin("KFC-price.cfg", ios::in);
	if (fin.is_open() == 0)
	{
		cout << "文件打开失败" << endl;
		return -1;
	}
	
	char str1[20];  
	char str2[20];
	char str[400];  // 用来读取#后面的
	
	
	while (1)
	{
		fin >> str1;
		if (strcmp(str1, "[单品菜单]") == 0)
			break;
	}
	
	while (1)
	{
		fin >> str2;
		if (strcmp(str2, "[组合菜单]") == 0)
			break;
		if (str2[0] == '#')
		{
			fin.getline(str,400, '\n');
		}
		else if ((int)str2[0] >= 33 && (int)str2[0] <= 126)
		{
			list[list_count].id = str2[0];
			char danpin_name[33];
			fin >> danpin_name;
			strcpy(list[list_count].name, danpin_name);
			double danpin_cost;
			fin >> danpin_cost;
			list[list_count].cost = danpin_cost;
			list_count++;
		}
	}
	
	while (fin >> str1)
	{
		if (str1[0] == '#')
		{
			fin.getline(str, 400, '\n');
		}
		else 
		{
			strcpy(special[special_count].ids, str1);
			char special_name[33];
			fin >> special_name;
			strcpy(special[special_count].special_name, special_name);
			double specital_cost;
			fin >> specital_cost;
			special[special_count].cost = specital_cost;
			special_count++;
		}
	}
	return 1;
}

void Swap(int i, int j, struct KFC list[])
{
	struct KFC item = list[i];

	list[i].id = list[j].id;
	strcpy(list[i].name, list[j].name);
	list[i].cost = list[j].cost;

	list[j].id = item.id;
	strcpy(list[j].name, item.name);
	list[j].cost = item.cost;
}

// 给list结构体数组的id按ASCII从小到大排序
void Sorted(struct KFC list[])
{
	int danpin_count = 0;
	while (list[danpin_count].id != '\0')
		danpin_count++;
	int n = danpin_count;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (list[j + 1].id < list[j].id)
				Swap(j, j + 1, list);
		}
	}

}

// 返回在list中的下标
int FindIndexByCh(char id, int n, struct KFC list[])
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

void ShowOrder(int order_arr[], int n, struct KFC list[])
{
	int tag = 0;  // 0表示第一次输出
	for (int k = 0; k < n; k++)
	{
		if (tag == 0 && order_arr[k] != 0)
		{
			cout << list[k].name;
			if (order_arr[k] > 1)
				cout << "*" << order_arr[k];
			tag = 1;
		}
		else if (tag == 1 && order_arr[k] != 0)
		{
			cout << "+" << list[k].name;
			if (order_arr[k] > 1)
				cout << "*" << order_arr[k];
		}
	}
}

void Menu(struct KFC list[], struct SPECIAL special[])
{
	int arr[MaxCategories];  // 用来存放用户点的单品的数量 一件单品对应一个元素
	int danpin_count = 0;
	while (list[danpin_count].id != '\0')
		danpin_count++;
	int taocan_count = 0;
	while (special[taocan_count].ids[0] != '\0')
		taocan_count++;
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021秋季菜单                       " << endl;
	cout << "=============================================================" << endl;
	for (int i = 0; i < danpin_count; i++)
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
		ClearArr(arr, MaxCategories);
		cout << special[i].special_name << "=";
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, danpin_count, list);
			arr[index]++;
		}
		ShowOrder(arr, danpin_count, list);
		cout << "=" << special[i].cost << endl;
	}
	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小)/akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母区分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
}

// 计算钱
double ComputeCost(int order_arr[], int n, struct KFC list[], struct SPECIAL special[])
{
	double cost_money = 0;
	int danpin_count = 0;
	while (list[danpin_count].id != '\0')
		danpin_count++;
	int taocan_count = 0;
	while (special[taocan_count].ids[0] != '\0')
		taocan_count++;
	int taocan_arr[MaxCategories];
	for (int i = 0; i < taocan_count; i++)
	{
		ClearArr(taocan_arr, MaxCategories);
		for (int j = 0; j < (int)strlen(special[i].ids); j++)
		{
			char ch = special[i].ids[j];
			int index = FindIndexByCh(ch, danpin_count, list);
			taocan_arr[index]++;
		}
		int is_special = 0;  // 判断是否可以凑成套餐 0表示不能
		while (1)  // 之所以要循环 -> 可能可以凑成多个套餐
		{
			for (int k = 0; k < danpin_count; k++)
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
				for (int w = 0; w < danpin_count; w++)
				{
					if (taocan_arr[w] != 0)
						order_arr[w] -= taocan_arr[w];
				}
			}
			else
				break;
		}
	}
	for (int m = 0; m < danpin_count; m++)  // 不能凑成套餐的其余的单品
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
	struct KFC list[31];
	struct SPECIAL special[11];
	while (1)
	{
		system("cls");
		int is_open_file = OpenFile(list, special);  // 将文件的内容读到list和special数组中
		if (is_open_file == -1)
			return -1;
		Sorted(list);  // 给list排个序
		int danpin_count = 0;
		while (list[danpin_count].id != '\0')
			danpin_count++;
		Menu(list, special);
		cout << "请点单：";
		int order_arr[MaxCategories] = { 0 };// arr 里面存放点的所有单品
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
			
			if ((int)ch >= 33 && (int)ch <= 126)
			{
				int index = FindIndexByCh(ch, danpin_count, list);
				if (index == -1)
				{
					cout << "输入错误，按任意键继续." << endl;
					char item1 = _getch();
					IsSucc = 0;
					break;
				}
				else
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
			ShowOrder(order_arr, danpin_count, list);
			double cost_money = ComputeCost(order_arr, danpin_count, list, special);  // ConputeCost后order_arr全为0
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