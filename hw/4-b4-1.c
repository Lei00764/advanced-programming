/* 2053932 软件 雷翔 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

// 菜单显示及选择 返回选择的0-4/0-6项
char meni(const HANDLE hout)
{
	char choice;
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)(允许按左箭头时向下移动)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(允许按左箭头时向下移动)\n");
	printf("3.用箭头键控制上下左右，边界停止(按大写HPKM时不准移动)\n");
	printf("4.用箭头键控制上下左右，边界回绕(按大写HPKM时不准移动)\n");
	printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止)(不允许按左箭头时向下移动)\n");
	printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(不允许按左箭头时向下移动)\n");
	printf("0.退出\n");

	printf("[请选择0-6] ");
	choice = _getche();
	while (1)
	{
		if (choice <= 54 && choice >= 48) // 48~48+6
		{
			break;
		}
		else
		{
			/* 此句的作用是调用系统的cls命令清屏 */
			cls(hout);
			printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)(允许按左箭头时向下移动)\n");
			printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(允许按左箭头时向下移动)\n");
			printf("3.用箭头键控制上下左右，边界停止(按大写HPKM时不准移动)\n");
			printf("4.用箭头键控制上下左右，边界回绕(按大写HPKM时不准移动)\n");
			printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止)(不允许按左箭头时向下移动)\n");
			printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(不允许按左箭头时向下移动)\n");
			printf("0.退出\n");

			printf("[请选择0-6] ");
			choice = _getche();
		}
	}
	return choice;

}

// 用i/j/k/l移动 对应选项1和选项2 后加选项5和选项6
void move_by_ijkl(const HANDLE hout, int x, int y, char choice)
{
	int mButton; // 用来记录按了什么键

	while (1)
	{
		if (choice == '1' || choice == '2')
		{
			mButton = _getch();
		}
		else
		{
			if ((mButton = _getch()) == 224)
			{
				mButton = _getch();
				continue;
			}
		}

		if (mButton == 'i' || mButton == 'I')
		{
			if (y == 1)
			{
				if (choice == '2' || choice == '6')
					y = 17;
				gotoxy(hout, x, y);

			}
			else
			{
				gotoxy(hout, x, --y);
			}
		}
		else if (mButton == 'j' || mButton == 'J')
		{
			if (x == 1)
			{
				if (choice == '2' || choice == '6')
					x = 69;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, --x, y);
			}
		}
		else if (mButton == 'k' || mButton == 'K')
		{
			if (y == 17)
			{
				if (choice == '2' || choice == '6')
					y = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, x, ++y);
			}
		}
		else if (mButton == 'l' || mButton == 'L')
		{
			if (x == 69)
			{
				if (choice == '2' || choice == '6')
					x = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, ++x, y);
			}
		}
		else if (mButton == 32) // 空格的ASCII
		{
			showch(hout, x, y, 32); // int -> char
			gotoxy(hout, x, y);  // 输出字符后，会自动右移1格 但x不会增加 
		}
		else if (mButton == 'q' || mButton == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.");
			break;
		}
		else
		{
			gotoxy(hout, x, y);
		}
	}
}

void move_by_arrow(const HANDLE hout, int x, int y, char choice)
{
	int mButton; // 用来记录按了什么键 

	while (1)
	{
		// 用getch读取功能键时，会返回两个int，第一个int是224，第二个int才是功能键的ASCII
		if ((mButton = _getch()) == 224)
		{
			if (mButton == 77 || mButton == 80 || mButton == 72 || mButton == 75)
				continue;
			mButton = _getch();
		}

		if (mButton == 72) // 上
		{
			if (y == 1)
			{
				if (choice == '4')
					y = 17;
				gotoxy(hout, x, y);
				// mButton = _getch();
			}
			else
			{
				gotoxy(hout, x, --y);
				// mButton = _getch();
			}
		}
		else if (mButton == 75) // 左
		{
			if (x == 1)
			{
				if (choice == '4')
					x = 69;
				gotoxy(hout, x, y);
				// mButton = _getch();
			}
			else
			{
				gotoxy(hout, --x, y);
				// mButton = _getch();
			}
		}
		else if (mButton == 80) // 下
		{
			if (y == 17)
			{
				if (choice == '4')
					y = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, x, ++y);
			}
		}
		else if (mButton == 77) // 右
		{
			if (x == 69)
			{
				if (choice == '4')
					x = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, ++x, y);
			}
		}
		else if (mButton == 32) // 空格的ASCII
		{
			showch(hout, x, y, 32); // int -> char
			gotoxy(hout, x, y);  // 输出字符后，会自动右移1格 但x不会增加 
		}
		else if (mButton == 'q' || mButton == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.");
			break;
		}
		else
		{
			gotoxy(hout, x, y);
		}
	}


}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄


	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (1)
	{
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
		char choice = meni(hout);
		if (choice == '0')
			break;

		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
		/* 显示初始的边框及其中的随机字符 */
		init_border(hout);

		// 程序开始时光标在中心位置
		int x = 35, y = 9;
		gotoxy(hout, x, y);

		if (choice == '1' || choice == '2' || choice == '5' || choice == '6')
		{
			move_by_ijkl(hout, x, y, choice);
		}
		else
		{
			move_by_arrow(hout, x, y, choice);
		}

		while (_getch() != 13);
	}

	return 0;
}
/* 在生成20个数过程中，恰好有两次生成的X和Y都相同，因此第二次生成的把第一次生成的给覆盖了 */ 
