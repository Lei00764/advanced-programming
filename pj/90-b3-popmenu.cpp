/* 2053932 软件 雷翔 */
#include <iostream>
#include <fstream>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

/**
  * 显示弹出菜单
  * @files       所有文件名
  * @count       文件名的数量
  * @start_count 从该下标开始显示
  */
void ShowPopMenu(char files[200][50], int all_count, int start_count)
{
	cct_gotoxy(PopMenuX, PopMenuY);
	cout << "请选择关卡" << endl;
	cct_gotoxy(PopMenuX, PopMenuY + 1);
	cout << "╔════╗" << endl;
	int count = start_count;
	int pos = 0;

	int menu_sum = 0;
	while (files[menu_sum][0] != '\0')
		menu_sum++;
	
	while (count < start_count + MenuMaxSum && count < menu_sum)
	{
		cct_gotoxy(PopMenuX, PopMenuY + 2 + pos);
		cout << "║" << "关卡" << files[count][14] << files[count][15] << files[count][16] << " ║" << endl;;
		count++;
		pos++;
	}
	if (menu_sum < MenuMaxSum)
		cct_gotoxy(PopMenuX, PopMenuY + 2 + menu_sum);
	else
		cct_gotoxy(PopMenuX, PopMenuY + 2 + MenuMaxSum);
	cout << "╚════╝" << endl;
}
