/* 2053932 软件 雷翔 */
#include <iostream>
#include <conio.h>  // for _getch()
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

void to_be_continued(int choice, const int X = 0, const int Y = 22)
{
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(X, Y);
    
    if (choice == 1)
    {
        cout << "本小题结束，请输入End继续...";
        int pos_x, pos_y; // 当前光标所在位置
        cct_getxy(pos_x, pos_y);  // 获取当前光标所在位置
        while (1)
        {
            cct_gotoxy(pos_x, pos_y);
            char str[20] = { '\0' };
            int count = 0;  // 记录字符个数
            int flag = 1;  // flag = 0时跳出最外层死循环
            while (1)
            {
                char ch = getchar();
                if (ch == '\n')
                {
                    cout << "输入错误，请重新输入" << endl;
                    cct_gotoxy(pos_x, pos_y);
                    cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 10);
                    cct_gotoxy(pos_x, pos_y);
                    count = 0;
                    break;
                }
                else if (ch >= 'A' && ch <= 'Z')
                    str[count++] = (ch + 'a' - 'A');
                else if (ch >= 'a' && ch <= 'z')
                    str[count++] = ch;

                if (count == 3 && str[0] == 'e' && str[1] == 'n' && str[2] == 'd')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        cct_setconsoleborder(120, 35, 120, 1000);  // 加上这两行代码后 从选项5退出 菜单的大小就和原来的一样了
        cct_setfontsize("点阵字体", 16, 8);
    }
    else if (choice == 2)
    {
        cout << "按回车键显示图形...";

        /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
        while (_getch() != '\r')
            ;
    }

    cct_cls();
    return;
}

