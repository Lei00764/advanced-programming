/* 2053932 软件 雷翔 */

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

#include "cmd_console_tools.h"
#include "hanoi.h"

int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	int n;  // 盘子个数
	char src, tmp, dst;
	while (1)
	{
		int user_choice = Menu();
		int tag = 1;  // tag = 0 则退出死循环
		switch (user_choice)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 8:
				InputSrcDst(&n, &src, &tmp, &dst);  // 完成盘子个数、起始柱、中间柱和目标柱的输入
				DoByChoice(n, src, tmp, dst, user_choice);
				break;
			case 5:
				cct_cls();  // 清屏
				DrawTriYuanZhu();
				break;
			case 6:
			case 7:
				InputSrcDst(&n, &src, &tmp, &dst);  // 完成盘子个数、起始柱、中间柱和目标柱的输入
				DoByChoice2(n, src, tmp, dst, user_choice);
				break;
			case 9:
				InputSrcDst(&n, &src, &tmp, &dst);  // 完成盘子个数、起始柱、中间柱和目标柱的输入
				DoByChoice3(n, src, dst);
				break;
			case 0:
				tag = 0;
				break;
		}
		
		if (tag == 0)
			break;
		to_be_continued(0, 38);
	}
	
	return 0;
}
