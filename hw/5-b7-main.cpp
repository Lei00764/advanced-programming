/* 2053932 软件 雷翔 */
#include <iostream>
#include "5-b7.h"
#include <iomanip>
#include <iomanip>
#include <Windows.h>
using namespace std;

int topA = 0, topB = 0, topC = 0;
int arrayA[10] = { 0 }, arrayB[10] = { 0 }, arrayC[10] = { 0 };
static int move_speed;
static int show_arr;

void Delay(int x)  // 延时设置 5最慢 1最快
{
    if (x == 0)
    {
        while (getchar() != '\n');

    }
    else if (x == 1)
        Sleep(1000);
    else if (x == 2)
        Sleep(500);
    else if (x == 3)
        Sleep(300);
    else if (x == 4)
        Sleep(100);
    else
        Sleep(1);

}

void PrintLandscape()  // 打印横向数据（每个数组中的数字）
{
    cout << " A:";
    for (int k = 0; k < 10; k++)
    {
        if (arrayA[k] > 0)
            cout << setw(2) << arrayA[k];
        else
            cout << "  ";
    }

    cout << " B:";
    for (int k = 0; k < 10; k++)
    {
        if (arrayB[k] > 0)
            cout << setw(2) << arrayB[k];
        else
            cout << "  ";
    }

    cout << " C:";
    for (int k = 0; k < 10; k++)
    {
        if (arrayC[k] > 0)
            cout << setw(2) << arrayC[k];
        else
            cout << "  ";
    }
}



void PrintProtrait(char dst)  // 打印纵向数据（topX以下，打印数据元素；topX以上，打印空格，覆盖原有数据） 最后 要移动光标！！！
{
    int a_x = 10, a_y = 11;
    for (int i = 0; i < 10; i++)
    {
        cct_gotoxy(a_x, a_y);
        if (i < topA)
            cout << setw(2) << arrayA[i];
        else
            cout << "  ";
        a_y--;
    }
    int b_x = 20, b_y = 11;
    for (int j = 0; j < 10; j++)
    {
        cct_gotoxy(b_x, b_y);
        if (j < topB)
            cout << setw(2) << arrayB[j];
        else
            cout << "  ";
        b_y--;
    }
    int c_x = 30, c_y = 11;
    for (int k = 0; k < 10; k++)
    {
        cct_gotoxy(c_x, c_y);
        if (k < topC)
            cout << setw(2) << arrayC[k];
        else
            cout << "  ";
        c_y--;
    }

    if (dst == 'A')
        cct_gotoxy(12, 12 - topA);
    else if (dst == 'B')
        cct_gotoxy(22, 12 - topB);
    else
        cct_gotoxy(32, 12 - topC);
}


// src 起始柱
// dst 目标柱
void hanoi(int n, char src, char tmp, char dst)
{
    static int count = 0;
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);

    if (dst == 'A')
    {
        if (src == 'B')
        {
            arrayA[topA++] = arrayB[topB - 1];
            arrayB[--topB] = 0;
        }
        else
        {
            arrayA[topA++] = arrayC[topC - 1];
            arrayC[--topC] = 0;
        }
    }
    else if (dst == 'B')
    {
        if (src == 'A')
        {
            arrayB[topB++] = arrayA[topA - 1];
            arrayA[--topA] = 0;
        }
        else
        {
            arrayB[topB++] = arrayC[topC - 1];
            arrayC[--topC] = 0;
        }
    }
    else
    {
        if (src == 'A')
        {
            arrayC[topC++] = arrayA[topA - 1];
            arrayA[--topA] = 0;
        }
        else
        {
            arrayC[topC++] = arrayB[topB - 1];
            arrayB[--topB] = 0;
        }
    }

    cct_gotoxy(0, 17);
    count++;
    cout << "第" << setw(4) << count << " 步" << "(" << n  << "#: "  << src << "-->" << dst << ")";
    if (show_arr == 1)
    {
        PrintLandscape();
        Delay(move_speed);
    }

    PrintProtrait(dst);
    Delay(move_speed);
        
    hanoi(n - 1, tmp, src, dst);
}


int main()
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
    
    
    char tmp;
    tmp = (char)(65 + 66 + 67 - src - dst);

    if (src == 'A')
    {
        for (int i = n; i > 0; i--)
        {
            arrayA[topA++] = i;
        }
    }
    else if (src == 'B')
    {
        for (int i = n; i > 0; i--)
        {
            arrayB[topB++] = i;
        }
    }
    else
    {
        for (int i = n; i > 0; i--)
        {
            arrayC[topC++] = i;
        }
    }


    // int move_speed;  定义成静态全局变量 在上面
    while (1)  // 输入移动速度
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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
    while (getchar() != '\n');


    // int show_arr; 定义成静态全局变量 在上面
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show_arr;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');

            continue;
        }
        if (show_arr == 1 || show_arr == 0)
            break;
    }
    while (getchar() != '\n');

    cct_cls();

    
    if (show_arr == 1)
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << move_speed << "，显示内部数组值" << endl;
    if (show_arr == 0)
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << move_speed << "，不显示内部数组值" << endl;


    cct_gotoxy(0, 17);
    
    if (show_arr == 1)
    {
        cout << "初始:               ";
        PrintLandscape();
        Delay(move_speed);
    }
        

    cct_gotoxy(11, 13);
    cout << "A";
    cct_gotoxy(21, 13);
    cout << "B";
    cct_gotoxy(31, 13);
    cout << "C";
    cct_gotoxy(9, 12);
    cout << setw(25) << setfill('=') << " " << setfill(' ') << endl;


    PrintProtrait(src);  // 初始化时，让光标指向起始柱最上面数字的右边
    Delay(move_speed);

    hanoi(n, src, tmp, dst);

    cct_gotoxy(0, 27);
    system("pause");
    return 0;
}