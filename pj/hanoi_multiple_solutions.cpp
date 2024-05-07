/* 2053932 软件 雷翔 */


/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>  // 格式控制
#include <Windows.h>  // Sleep()
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <conio.h>  // _getch()
using namespace std;

static int pace_count = 0;  // 记录移动总部步数
static int topA = 0, topB = 0, topC = 0;  // topX 对应圆柱上现有圆盘的数量
static int arrayA[10] = { 0 }, arrayB[10] = { 0 }, arrayC[10] = { 0 };  // arrayX 对应圆柱上现有圆盘的编号 编号从1开始
static int move_speed = 0;  // 移动延时 1最慢 5最快 0单步运行

const int BaseArrayInX = 10, BaseArrayInY = 11;         // 以左边A为基准，输出纵向数组 选项4、8
const int OffsetX = 0, OffsetY = 15;                    // 输出纵向数组的整体偏移量  选项8
const int BaseYuanZhuX = 0, BaseYuanZhuDrawY = 15;      // 以图形圆柱最左下角为基准，输出整个图形 选项5、6、7、8

void to_be_continued(const int X = 0, const int Y = 22)
{
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(X, Y);

    cout << "按回车键继续...";

    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

void hanoi(int n, char src, char tmp, char dst, int choice)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, choice);
    pace_count++;
    MovePanInArray(n, src, dst);  // 将盘子从src对应的数组移动到dst对应的数组
    PrintByChoice(n, src, tmp, dst, choice);  // 根据用户选项来显示对应结果
    hanoi(n - 1, tmp, src, dst, choice);
}

void DoByChoice(int n, char src, char tmp, char dst, int choice)
{
    InitSrcArray(n, src);
    if (choice == 4)
    {
        InputMoveSpeed();  // 输入移动速度
        cct_cls();  // 清屏
        InitForOp4(n, src, dst);  // 显示初始化界面
        Delay(move_speed);
    }
    else if (choice == 8)
    {
        InputMoveSpeed();  // 输入移动速度
        cct_cls();  // 清屏
        InitForOp8(n, src, dst);  // 显示初始化界面
        Delay(move_speed);
    }
    hanoi(n, src, tmp, dst, choice);
    GuiLing();
}

void DoByChoice2(int n, char src, char tmp, char dst, int choice)
{
    InitSrcArray(n, src);
    cct_cls();  // 清屏
    cct_setcursor(3);  // 不显示光标
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;

    DrawTriYuanZhu();  // 初始状态
    DrawSrcPanZi(n, src);

    if (choice == 7)
    {
        Sleep(1000);  // 延迟1秒
       
        if (n % 2 != 0) // 奇数个盘子，第一个从起始柱向目标柱移动
        {
            MovePanInArray(n, src, dst);
            MovePanFromSrcToDst(1, src, dst);  // 移动图形盘子  第一个参数给1 只移动最上面的 颜色固定
        }
        else            // 偶数个盘子，第一个从起始柱向中间柱移动
        {
            MovePanInArray(n, src, tmp);
            MovePanFromSrcToDst(1, src, tmp);
        }
    }
    GuiLing();
}

void DoByChoice3(int n, char src, char dst)
{
    InitSrcArray(n, src);
    cct_cls();  // 清屏
    cct_setcursor(3);  // 不显示光标
    InitForOp8(n, src, dst);  // 显示初始化界面

    cct_gotoxy(0, 18 + OffsetY);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) : ";
    int pos_x, pos_y; // 当前光标所在位置
    cct_getxy(pos_x, pos_y);
    while (1)
    {
        cct_gotoxy(pos_x, pos_y);
        char str[20] = { '\0' };  // 存放输入字符
        int count = 0;  // 记录输入字符的个数
        while (count < 20)  // 这里的逻辑比较麻烦，主要是为了跟老师demo一样
        {
            char ch = _getch();  // 读取回车返回 \r 13
            if (ch != ' ')
                cout << ch;
            else
                continue;
            if (ch >= 'a' && ch <= 'z')
                ch -= 'a' - 'A';
            str[count] = ch;
            count++;
            if (str[0] == 'Q' && str[1] == '\r' || str[0] == 'q' && str[1] == '\r')
            {
                cout << endl << "游戏中止!!!!!" << endl;
                return;
            }
            // str[0]表示出发柱 str[1]表示到达柱，即从str[0]到str[1]
            if (count == 3 && str[0] >= 'A' && str[0] <= 'C' && str[1] >= 'A' && str[1] <= 'C' && str[0] != str[1] && str[2] == '\r')
                break;
            if (str[count - 1] == '\r' || count == 19)
            {
                // 最多只能输19个字符，多了就清
                cct_gotoxy(pos_x, pos_y);
                cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
                cct_gotoxy(pos_x, pos_y);
                count = 0;
            }
        }
        int id = IsMove(str[0], str[1]);
        if (id == -1)
        {
            cct_gotoxy(0, pos_y + 1);
            cout << "源柱为空!";
            Sleep(1000);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
            cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 40);
        }
        else if (id == 0)
        {
            cct_gotoxy(0, pos_y + 1);
            cout << "大盘压小盘，非法移动!";
            Sleep(1000);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
            cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 40);
        }
        else
        {
            pace_count++;
            cct_gotoxy(0, 17 + OffsetY);
            MovePanInArray(id, str[0], str[1]);
            cout << "第" << setw(4) << pace_count << " 步" << "(" << setw(2) << id << "#: " << src << "-->" << dst << ")";
            PrintInX();
            PrintInY(OffsetX, OffsetY);
            MovePanFromSrcToDst(id, str[0], str[1]);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
        }

        // 判断游戏是否结束
        if (dst == 'A')
        {
            if (n == topA)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "游戏结束!!!!!" << endl;
                break;
            }
        }
        else if (dst == 'B')
        {
            if (n == topB)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "游戏结束!!!!!" << endl;
                break;
            }
        }
        else
        {
            if (n == topC)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "游戏结束!!!!!" << endl;
                break;
            }
        }
    }
    GuiLing();
}

void GuiLing()
{
    pace_count = 0;  // 记录移动总部步数
    topA = 0, topB = 0, topC = 0;  // topX 对应圆柱上现有圆盘的数量
    move_speed = 0;  // 移动延时 1最慢 5最快 0单步运行
}

// 返回0表示会大盘压小盘，返回-1表示起始柱为空，返回大于0表示要移动盘的编号
int IsMove(char from_ch, char to_ch)
{
    // a、b、c分别分别代表三根柱上最上面的盘子的大小 数组越大表示盘越大
    int a = arrayA[topA - 1], b = arrayB[topB - 1], c = arrayC[topC - 1];
    if (from_ch == 'A')
    {
        if (to_ch == 'B') // 从A柱去B柱
        {
            if (topA == 0)
                return -1;
            else if (topB == 0 || a < b)
                return a;
            else
                return 0;
        }
        else
        {
            if (topA == 0)
                return -1;
            else if (topC == 0 || a < c)
                return a;
            else
                return 0;
        }
    }
    else if (from_ch == 'B')
    {
        if (to_ch == 'A')
        {
            if (topB == 0)
                return -1;
            else if (topA == 0 || b < a)
                return b;
            else
                return 0;
        }
        else
        {
            if (topB == 0)
                return -1;
            else if (topC == 0 || b < c)
                return b;
            else
                return 0;
        }
    }
    else
    {
        if (to_ch == 'A')
        {
            if (topC == 0)
                return -1;
            else if (topA == 0 || c < a)
                return c;
            else
                return 0;
        }
        else
        {
            if (topC == 0)
                return -1;
            else if (topB == 0 || c < b)
                return c;
            else
                return 0;
        }
    }
}

void MovePanInArray(int n, char src, char dst)
{
    if (dst == 'A')
    {
        if (src == 'B')
            arrayA[topA++] = arrayB[--topB]; 
        else
            arrayA[topA++] = arrayC[--topC];
    }
    else if (dst == 'B')
    {
        if (src == 'A')
            arrayB[topB++] = arrayA[--topA];
        else
            arrayB[topB++] = arrayC[--topC];
    }
    else
    {
        if (src == 'A')
            arrayC[topC++] = arrayA[--topA];
        else
            arrayC[topC++] = arrayB[--topB];
    }
}

void PrintByChoice(int n, char src, char tmp, char dst, int choice)
{
    if (choice == 1)
        cout << n << "# " << src << "---->" << dst << endl;
    else if (choice == 2)
        cout << "第" << setw(4) << pace_count << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    else if (choice == 3)
    {
        cout << "第" << setw(4) << pace_count << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();
    }
    else if (choice == 4)
    {
        cct_gotoxy(0, 17);
        cout << "第" << setw(4) << pace_count << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();    // 横向
        Delay(move_speed);
        PrintInY(0, 0);  // 纵向
        Delay(move_speed);
    }
    else if (choice == 8)
    {
        cct_gotoxy(0, 17 + OffsetY);
        cout << "第" << setw(4) << pace_count << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();    // 横向
        PrintInY(OffsetX, OffsetY);  // 纵向
        MovePanFromSrcToDst(n, src, dst);  // 移动图形盘子
        Delay(move_speed);
    }
}

void MovePanFromSrcToDst(int id, char src, char dst)
{
    int src_x, src_y, dst_x, dst_y;
    int cur_pan_len;  // 当前移动的盘子的长度
    // 确定移动的起点和终点的位置
    if (dst == 'A')
    {
        if (src == 'B')
        {
            cur_pan_len = arrayA[topA - 1] * 2 + 1;
            src_x = 11 - arrayA[topA - 1] + 33;
            src_y = 14 - topB;
            dst_x = src_x - 33;
            dst_y = 15 - topA;
        }
        else  // C
        {
            cur_pan_len = arrayA[topA - 1] * 2 + 1;
            src_x = 11 - arrayA[topA - 1] + 66;
            src_y = 14 - topC;
            dst_x = src_x - 66;
            dst_y = 15 - topA;
        }
    }
    else if (dst == 'B')
    {
        if (src == 'A')
        {
            cur_pan_len = arrayB[topB - 1] * 2 + 1;  // topX 现有圆盘数量
            src_x = 11 - arrayB[topB - 1];
            src_y = 14 - topA;
            dst_x = src_x + 33;
            dst_y = 15 - topB;
        }
        else  // C
        {
            cur_pan_len = arrayB[topB - 1] * 2 + 1;
            src_x = 11 - arrayB[topB - 1] + 66;
            src_y = 14 - topC;
            dst_x = src_x - 33;
            dst_y = 15 - topB;
        }
    }
    else
    {
        if (src == 'A')
        {
            cur_pan_len = arrayC[topC - 1] * 2 + 1;  // topX 现有圆盘数量
            src_x = 11 - arrayC[topC - 1];
            src_y = 14 - topA;
            dst_x = src_x + 66;
            dst_y = 15 - topC;
        }
        else  // B
        {
            cur_pan_len = arrayC[topC - 1] * 2 + 1;
            src_x = 11 - arrayC[topC - 1] + 33;
            src_y = 14 - topB;
            dst_x = src_x + 33;
            dst_y = 15 - topC;
        }
    }
    GoToHigh(src_x, src_y, dst_x, dst_y, id, cur_pan_len);
    GoToInLine(src_x, src_y, dst_x, dst_y, id, cur_pan_len);
    GoToLow(src_x, src_y, dst_x, dst_y, id, cur_pan_len);
    cct_setcolor(); //恢复缺省颜色
}

void GoToHigh(int one_x, int one_y, int another_x, int another_y, int id, int len)  // 上移
{
    const char ch = ' ';
    int bg_color = id;  // 保证移动时颜色不变
    const int fg_color = COLOR_BLACK;
    const int MIN_Y = 1;
    for (int y = one_y; y >= MIN_Y; y--)
    {
        cct_showch(one_x, y, ch, bg_color, fg_color, len);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speed选择为0时，每一步自动进行
            Delay(4);
        /* 清除显示，清除方法为用正常颜色+空格重画一遍刚才的位置 */
        cct_showch(one_x, y, ch, COLOR_BLACK, COLOR_WHITE, len);
        if (y > MIN_Y + 1)   // 把柱子填充好
            cct_showch(one_x + (len - 1) / 2, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speed选择为0时，每一步自动进行
            Delay(4);
    }
}

void GoToInLine(int one_x, int one_y, int another_x, int another_y, int id, int len)  // 平移
{
    const char ch = ' ';
    int bg_color = id;  // 保证移动时颜色不变
    const int fg_color = COLOR_BLACK;
    // 向左或向右移动
    if (one_x < another_x)  // 右移
    {
        const int MAX_X = another_x;
        for (int x = one_x; x <= MAX_X; x++)
        {
            cct_showch(x, 1, ch, bg_color, fg_color, len);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speed选择为0时，每一步自动进行
                Delay(4);
            cct_showch(x, 1, ch, COLOR_BLACK, COLOR_WHITE, len);  // 清除显示
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speed选择为0时，每一步自动进行
                Delay(4);
        }
    }
    else  // 左移
    {
        const int MIN_X = another_x;
        for (int x = one_x; x >= MIN_X; x--)
        {
            cct_showch(x, 1, ch, bg_color, fg_color, len);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speed选择为0时，每一步自动进行
                Delay(4);
            cct_showch(x, 1, ch, COLOR_BLACK, COLOR_WHITE, len);  // 清除显示
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speed选择为0时，每一步自动进行
                Delay(4);
        }
    }
}

void GoToLow(int one_x, int one_y, int another_x, int another_y, int id, int len)  // 下移
{
    const char ch = ' ';
    int bg_color = id;  // 保证移动时颜色不变
    const int fg_color = COLOR_BLACK;
    const int MAX_Y = another_y;
    for (int y = 1; y <= MAX_Y; y++)
    {
        cct_showch(another_x, y, ch, bg_color, fg_color, len);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speed选择为0时，每一步自动进行
            Delay(4);
        if (y < MAX_Y)
        {
            cct_showch(another_x, y, ch, COLOR_BLACK, COLOR_WHITE, len);  // 清除显示
            if (y > 2)   // 把柱子填充好
                cct_showch(another_x + (len - 1) / 2, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speed选择为0时，每一步自动进行
                Delay(4);
        }
    }
}

void InitForOp4(int n, char src, char dst)
{
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << move_speed << endl;

    PrintInY(0, 0);  // 显示初始化时纵向数组情况
    cct_gotoxy(11, 13);
    cout << "A" << "         B" << "         C";
    cct_gotoxy(9, 12);
    cout << setw(25) << setfill('=') << " " << setfill(' ') << endl;

    cct_gotoxy(0, 17);
    cout << "初始: ";
    PrintInX();  // 显示初始化时横向数组情况

    cct_setcursor(3);  // 不显示光标 -> cmd_console_tools.cpp 第140行
}

void InitForOp8(int n, char src, char dst)
{
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << move_speed << endl;

    PrintInY(OffsetX, OffsetY);  // 显示初始化时纵向数组情况
    cct_gotoxy(11, 13 + OffsetY);
    cout << "A" << "         B" << "         C";
    cct_gotoxy(9, 12 + OffsetY);
    cout << setw(25) << setfill('=') << " " << setfill(' ') << endl;

    cct_gotoxy(0, 17 + OffsetY);
    cout << "初始: ";
    PrintInX();  // 显示初始化时横向数组情况

    DrawTriYuanZhu();  // 画三根圆柱
    DrawSrcPanZi(n, src);  // 画初始化时起始柱上的盘子

    cct_setcursor(3);  // 不显示光标 -> cmd_console_tools.cpp 第140行
}

void InputSrcDst(int* n_ptr, char* src_ptr, char* tmp_ptr, char* dst_ptr)
{
    int n;
    while (1)  // 输入层数
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n >= 1 && n <= 10)  // 正确输入 跳出
            break;
    }
    while (getchar() != '\n');

    char src;  // 输入起始柱
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        if (src == 'a' || src == 'A' || src == 'b' || src == 'B' || src == 'c' || src == 'C')  // 正确输入 跳出
            break;

    }
    while (getchar() != '\n');
    if (src > 96)  // 把字母变大写
        src -= 32;

    char dst;  //输入目标柱
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C')  // 正确输入 跳出
            break;
    }
    while (getchar() != '\n');
    if (dst > 96)
        dst -= 32;

    while (1)  // 对目标柱和起始柱进行判断 看是否相同
    {
        if (src == dst)
        {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            while (1)
            {
                cout << "请输入目标柱(A-C)" << endl;
                cin >> dst;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                if (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C')  // 正确输入 跳出
                    break;
            }
            while (getchar() != '\n');
            if (dst > 96)
                dst -= 32;
        }
        else
            break;
    }

    char tmp;  // 中间柱
    tmp = (char)('A' + 'B' + 'C' - src - dst);
    *n_ptr = n;
    *src_ptr = src;
    *tmp_ptr = tmp;
    *dst_ptr = dst;
}

void InputMoveSpeed()
{
    while (1)  // 输入移动速度
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短) ";
        cin >> move_speed;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');

            continue;
        }
        if (move_speed >= 0 && move_speed <= 5)
            break;
    }
    while (getchar() != '\n');  // 读取缓冲区中的回车
}

void InitSrcArray(int n, char src)
{
    // 越接近数组下标0，值越大，同时代表圆盘越大
    if (src == 'A')
    {
        for (int i = n; i > 0; i--)
            arrayA[topA++] = i;
    }
    else if (src == 'B')
    {
        for (int i = n; i > 0; i--)
            arrayB[topB++] = i;
    }
    else // 'C' 
    {
        for (int i = n; i > 0; i--)
            arrayC[topC++] = i;
    }

}

void DrawTriYuanZhu()
{
    for (int x = 0; x < 23; x++)
    {
        // fgxxx为前景色即字的颜色 bg是真正的背景色
        cct_showch(BaseYuanZhuX + x, BaseYuanZhuDrawY, 32, COLOR_HYELLOW, COLOR_WHITE, 1);       // 用空格填充
        cct_showch(BaseYuanZhuX + x + 33, BaseYuanZhuDrawY, 32, COLOR_HYELLOW, COLOR_WHITE, 1);
        cct_showch(BaseYuanZhuX + x + 66, BaseYuanZhuDrawY, 32, COLOR_HYELLOW, COLOR_WHITE, 1);
    }
    for (int y = BaseYuanZhuDrawY; y > 2; y--)
    {
        cct_showch(BaseYuanZhuX + 11, y, 32, COLOR_HYELLOW, COLOR_WHITE, 1);
        cct_showch(BaseYuanZhuX + 11 + 33, y, 32, COLOR_HYELLOW, COLOR_WHITE, 1);
        cct_showch(BaseYuanZhuX + 11 + 66, y, 32, COLOR_HYELLOW, COLOR_WHITE, 1);
        Sleep(100);
    }
    cct_setcolor(); //恢复缺省颜色
}

void DrawSrcPanZi(int n, char src)
{
    int id = n;  // 盘子编号 -> 标号与颜色一一对应 初始化时最下面盘子的编号是n，最上面盘子的编号是1
    if (src == 'A')
    {
        for (int y = BaseYuanZhuDrawY - 1; y > BaseYuanZhuDrawY - 1 - topA; y--)
        {
            for (int x = 11 - arrayA[BaseYuanZhuDrawY - 1 - y]; x < 12 + arrayA[BaseYuanZhuDrawY - 1 - y]; x++)
                cct_showch(x, y, 32, id, COLOR_BLACK, 1);
            id--;
            Sleep(100);
        }
    }
    else if (src == 'B')
    {
        for (int y = BaseYuanZhuDrawY - 1; y > BaseYuanZhuDrawY - 1 - topB; y--)
        {
            for (int x = 44 - arrayB[BaseYuanZhuDrawY - 1 - y]; x < 45 + arrayB[BaseYuanZhuDrawY - 1 - y]; x++)
                cct_showch(x, y, 32, id, COLOR_BLACK, 1);
            id--;
            Sleep(100);
        }
    }
    else
    {
        for (int y = BaseYuanZhuDrawY - 1; y > BaseYuanZhuDrawY - 1 - topC; y--)
        {
            for (int x = 77 - arrayC[BaseYuanZhuDrawY - 1 - y]; x < 78 + arrayC[BaseYuanZhuDrawY - 1 - y]; x++)
                cct_showch(x, y, 32, id, COLOR_BLACK, 1);
            id--;
            Sleep(100);
        }
    }
    cct_setcolor(); //恢复缺省颜色
}

void PrintInX()
{
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (i < topA)
            cout << setw(2) << arrayA[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (i < topB)
            cout << setw(2) << arrayB[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (i < topC)
            cout << setw(2) << arrayC[i];
        else
            cout << "  ";
    }
    cout << endl;
}

void PrintInY(int offset_x, int offset_y)
{
    int a_x = 10 + offset_x, a_y = 11 + offset_y;
    for (int i = 0; i < 10; i++)
    {
        cct_gotoxy(a_x, a_y);
        if (i < topA)
            cout << setw(2) << arrayA[i];
        else
            cout << "  ";
        a_y--;
    }
    int b_x = 20 + offset_x, b_y = 11 + offset_y;
    for (int j = 0; j < 10; j++)
    {
        cct_gotoxy(b_x, b_y);
        if (j < topB)
            cout << setw(2) << arrayB[j];
        else
            cout << "  ";
        b_y--;
    }
    int c_x = 30 + offset_x, c_y = 11 + offset_y;
    for (int k = 0; k < 10; k++)
    {
        cct_gotoxy(c_x, c_y);
        if (k < topC)
            cout << setw(2) << arrayC[k];
        else
            cout << "  ";
        c_y--;
    }
}

void Delay(int x)  // 延时设置 5最快 1最慢 0单步
{
    if (x == 0)
        while (getchar() != '\n');
    else if (x == 1)
        Sleep(400);
    else if (x == 2)
        Sleep(200);
    else if (x == 3)
        Sleep(100);
    else if (x == 4)
        Sleep(10);
    else
        Sleep(0);
}