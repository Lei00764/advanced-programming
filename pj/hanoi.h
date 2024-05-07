/* 2053932 软件 雷翔 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
void to_be_continued(const int X, const int Y);  // 一轮游戏结束后光标移动

int Menu();  // 显示菜单，并返回用户正确选项

void hanoi(int n, char src, char tmp, char dst, int choice);  // 递归函数

void DoByChoice(int n, char src, char tmp, char dst, int choice);   // 根据用户选项来决定执行何种操作 选项：1、2、3、4、8
void DoByChoice2(int n, char src, char tmp, char dst, int choice);  // 根据用户选项来决定执行何种操作 选项：6、7
void DoByChoice3(int n, char src, char dst);                        // 根据用户选项来决定执行何种操作 选项：9
void GuiLing();                                                     // 每次执行完一次用户选项后，静态全局变量置原值

int IsMove(char from_ch, char to_ch);  // 选项 9 判断要不要移动 返回0表示会大盘压小盘，返回-1表示起始柱为空，返回大于0表示要移动盘的编号

void MovePanInArray(int n, char src, char dst);                       // 将盘子从src对应的数组移动到dst对应的数组
void PrintByChoice(int n, char src, char tmp, char dst, int choice);  // 紧接上一个函数，在屏幕上显示相应内容

void MovePanFromSrcToDst(int id, char src, char dst);
void GoToHigh(int one_x, int one_y, int another_x, int another_y, int id, int len);    // 上移
void GoToInLine(int one_x, int one_y, int another_x, int another_y, int id, int len);  // 平移
void GoToLow(int one_x, int one_y, int another_x, int another_y, int id, int len);     // 下移

void InputSrcDst(int* n_pre, char* src_ptr, char* tmp_ptr, char* dst_ptr);  // 输入盘子个数、起始柱和目标柱
void InputMoveSpeed();                                                      // 输入移动速度

void InitSrcArray(int n, char src);          // 初始化：往起始柱填盘子编号；越大的盘子，编号越大
void InitForOp4(int n, char src, char dst);  // 输出选项4的界面：第一行显示内容、纵向打印、横向打印
void InitForOp8(int n, char src, char dst);  // 输出选项8的界面：第一行显示内容、纵向打印、横向打印 + 圆柱 + 起始柱

void DrawTriYuanZhu();               // 画三根圆柱
void DrawSrcPanZi(int n, char src);  // 画初始化时起始柱上的盘子

void PrintInX();                            // 打印横向数组
void PrintInY(int offset_x, int offset_y);  // 打印纵向数组  不包括底座(A.B.C和一排等号)

void Delay(int x);  // 延时设置

