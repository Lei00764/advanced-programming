/* 2053932 ��� ���� */


/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>  // ��ʽ����
#include <Windows.h>  // Sleep()
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <conio.h>  // _getch()
using namespace std;

static int pace_count = 0;  // ��¼�ƶ��ܲ�����
static int topA = 0, topB = 0, topC = 0;  // topX ��ӦԲ��������Բ�̵�����
static int arrayA[10] = { 0 }, arrayB[10] = { 0 }, arrayC[10] = { 0 };  // arrayX ��ӦԲ��������Բ�̵ı�� ��Ŵ�1��ʼ
static int move_speed = 0;  // �ƶ���ʱ 1���� 5��� 0��������

const int BaseArrayInX = 10, BaseArrayInY = 11;         // �����AΪ��׼������������� ѡ��4��8
const int OffsetX = 0, OffsetY = 15;                    // ����������������ƫ����  ѡ��8
const int BaseYuanZhuX = 0, BaseYuanZhuDrawY = 15;      // ��ͼ��Բ�������½�Ϊ��׼���������ͼ�� ѡ��5��6��7��8

void to_be_continued(const int X = 0, const int Y = 22)
{
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(X, Y);

    cout << "���س�������...";

    /* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
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
    MovePanInArray(n, src, dst);  // �����Ӵ�src��Ӧ�������ƶ���dst��Ӧ������
    PrintByChoice(n, src, tmp, dst, choice);  // �����û�ѡ������ʾ��Ӧ���
    hanoi(n - 1, tmp, src, dst, choice);
}

void DoByChoice(int n, char src, char tmp, char dst, int choice)
{
    InitSrcArray(n, src);
    if (choice == 4)
    {
        InputMoveSpeed();  // �����ƶ��ٶ�
        cct_cls();  // ����
        InitForOp4(n, src, dst);  // ��ʾ��ʼ������
        Delay(move_speed);
    }
    else if (choice == 8)
    {
        InputMoveSpeed();  // �����ƶ��ٶ�
        cct_cls();  // ����
        InitForOp8(n, src, dst);  // ��ʾ��ʼ������
        Delay(move_speed);
    }
    hanoi(n, src, tmp, dst, choice);
    GuiLing();
}

void DoByChoice2(int n, char src, char tmp, char dst, int choice)
{
    InitSrcArray(n, src);
    cct_cls();  // ����
    cct_setcursor(3);  // ����ʾ���
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;

    DrawTriYuanZhu();  // ��ʼ״̬
    DrawSrcPanZi(n, src);

    if (choice == 7)
    {
        Sleep(1000);  // �ӳ�1��
       
        if (n % 2 != 0) // ���������ӣ���һ������ʼ����Ŀ�����ƶ�
        {
            MovePanInArray(n, src, dst);
            MovePanFromSrcToDst(1, src, dst);  // �ƶ�ͼ������  ��һ��������1 ֻ�ƶ�������� ��ɫ�̶�
        }
        else            // ż�������ӣ���һ������ʼ�����м����ƶ�
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
    cct_cls();  // ����
    cct_setcursor(3);  // ����ʾ���
    InitForOp8(n, src, dst);  // ��ʾ��ʼ������

    cct_gotoxy(0, 18 + OffsetY);
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) : ";
    int pos_x, pos_y; // ��ǰ�������λ��
    cct_getxy(pos_x, pos_y);
    while (1)
    {
        cct_gotoxy(pos_x, pos_y);
        char str[20] = { '\0' };  // ��������ַ�
        int count = 0;  // ��¼�����ַ��ĸ���
        while (count < 20)  // ������߼��Ƚ��鷳����Ҫ��Ϊ�˸���ʦdemoһ��
        {
            char ch = _getch();  // ��ȡ�س����� \r 13
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
                cout << endl << "��Ϸ��ֹ!!!!!" << endl;
                return;
            }
            // str[0]��ʾ������ str[1]��ʾ������������str[0]��str[1]
            if (count == 3 && str[0] >= 'A' && str[0] <= 'C' && str[1] >= 'A' && str[1] <= 'C' && str[0] != str[1] && str[2] == '\r')
                break;
            if (str[count - 1] == '\r' || count == 19)
            {
                // ���ֻ����19���ַ������˾���
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
            cout << "Դ��Ϊ��!";
            Sleep(1000);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
            cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 40);
        }
        else if (id == 0)
        {
            cct_gotoxy(0, pos_y + 1);
            cout << "����ѹС�̣��Ƿ��ƶ�!";
            Sleep(1000);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
            cct_showch(0, pos_y + 1, ' ', COLOR_BLACK, COLOR_WHITE, 40);
        }
        else
        {
            pace_count++;
            cct_gotoxy(0, 17 + OffsetY);
            MovePanInArray(id, str[0], str[1]);
            cout << "��" << setw(4) << pace_count << " ��" << "(" << setw(2) << id << "#: " << src << "-->" << dst << ")";
            PrintInX();
            PrintInY(OffsetX, OffsetY);
            MovePanFromSrcToDst(id, str[0], str[1]);
            cct_showch(pos_x, pos_y, ' ', COLOR_BLACK, COLOR_WHITE, 20);
        }

        // �ж���Ϸ�Ƿ����
        if (dst == 'A')
        {
            if (n == topA)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "��Ϸ����!!!!!" << endl;
                break;
            }
        }
        else if (dst == 'B')
        {
            if (n == topB)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "��Ϸ����!!!!!" << endl;
                break;
            }
        }
        else
        {
            if (n == topC)
            {
                cct_gotoxy(0, pos_y + 1);
                cout << "��Ϸ����!!!!!" << endl;
                break;
            }
        }
    }
    GuiLing();
}

void GuiLing()
{
    pace_count = 0;  // ��¼�ƶ��ܲ�����
    topA = 0, topB = 0, topC = 0;  // topX ��ӦԲ��������Բ�̵�����
    move_speed = 0;  // �ƶ���ʱ 1���� 5��� 0��������
}

// ����0��ʾ�����ѹС�̣�����-1��ʾ��ʼ��Ϊ�գ����ش���0��ʾҪ�ƶ��̵ı��
int IsMove(char from_ch, char to_ch)
{
    // a��b��c�ֱ�ֱ����������������������ӵĴ�С ����Խ���ʾ��Խ��
    int a = arrayA[topA - 1], b = arrayB[topB - 1], c = arrayC[topC - 1];
    if (from_ch == 'A')
    {
        if (to_ch == 'B') // ��A��ȥB��
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
        cout << "��" << setw(4) << pace_count << " ��" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    else if (choice == 3)
    {
        cout << "��" << setw(4) << pace_count << " ��" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();
    }
    else if (choice == 4)
    {
        cct_gotoxy(0, 17);
        cout << "��" << setw(4) << pace_count << " ��" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();    // ����
        Delay(move_speed);
        PrintInY(0, 0);  // ����
        Delay(move_speed);
    }
    else if (choice == 8)
    {
        cct_gotoxy(0, 17 + OffsetY);
        cout << "��" << setw(4) << pace_count << " ��" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        PrintInX();    // ����
        PrintInY(OffsetX, OffsetY);  // ����
        MovePanFromSrcToDst(n, src, dst);  // �ƶ�ͼ������
        Delay(move_speed);
    }
}

void MovePanFromSrcToDst(int id, char src, char dst)
{
    int src_x, src_y, dst_x, dst_y;
    int cur_pan_len;  // ��ǰ�ƶ������ӵĳ���
    // ȷ���ƶ��������յ��λ��
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
            cur_pan_len = arrayB[topB - 1] * 2 + 1;  // topX ����Բ������
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
            cur_pan_len = arrayC[topC - 1] * 2 + 1;  // topX ����Բ������
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
    cct_setcolor(); //�ָ�ȱʡ��ɫ
}

void GoToHigh(int one_x, int one_y, int another_x, int another_y, int id, int len)  // ����
{
    const char ch = ' ';
    int bg_color = id;  // ��֤�ƶ�ʱ��ɫ����
    const int fg_color = COLOR_BLACK;
    const int MIN_Y = 1;
    for (int y = one_y; y >= MIN_Y; y--)
    {
        cct_showch(one_x, y, ch, bg_color, fg_color, len);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
            Delay(4);
        /* �����ʾ���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
        cct_showch(one_x, y, ch, COLOR_BLACK, COLOR_WHITE, len);
        if (y > MIN_Y + 1)   // ����������
            cct_showch(one_x + (len - 1) / 2, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
            Delay(4);
    }
}

void GoToInLine(int one_x, int one_y, int another_x, int another_y, int id, int len)  // ƽ��
{
    const char ch = ' ';
    int bg_color = id;  // ��֤�ƶ�ʱ��ɫ����
    const int fg_color = COLOR_BLACK;
    // ����������ƶ�
    if (one_x < another_x)  // ����
    {
        const int MAX_X = another_x;
        for (int x = one_x; x <= MAX_X; x++)
        {
            cct_showch(x, 1, ch, bg_color, fg_color, len);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
                Delay(4);
            cct_showch(x, 1, ch, COLOR_BLACK, COLOR_WHITE, len);  // �����ʾ
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
                Delay(4);
        }
    }
    else  // ����
    {
        const int MIN_X = another_x;
        for (int x = one_x; x >= MIN_X; x--)
        {
            cct_showch(x, 1, ch, bg_color, fg_color, len);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
                Delay(4);
            cct_showch(x, 1, ch, COLOR_BLACK, COLOR_WHITE, len);  // �����ʾ
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
                Delay(4);
        }
    }
}

void GoToLow(int one_x, int one_y, int another_x, int another_y, int id, int len)  // ����
{
    const char ch = ' ';
    int bg_color = id;  // ��֤�ƶ�ʱ��ɫ����
    const int fg_color = COLOR_BLACK;
    const int MAX_Y = another_y;
    for (int y = 1; y <= MAX_Y; y++)
    {
        cct_showch(another_x, y, ch, bg_color, fg_color, len);
        if (move_speed != 0)
            Delay(move_speed);
        else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
            Delay(4);
        if (y < MAX_Y)
        {
            cct_showch(another_x, y, ch, COLOR_BLACK, COLOR_WHITE, len);  // �����ʾ
            if (y > 2)   // ����������
                cct_showch(another_x + (len - 1) / 2, y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);
            if (move_speed != 0)
                Delay(move_speed);
            else  // move_speedѡ��Ϊ0ʱ��ÿһ���Զ�����
                Delay(4);
        }
    }
}

void InitForOp4(int n, char src, char dst)
{
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << move_speed << endl;

    PrintInY(0, 0);  // ��ʾ��ʼ��ʱ�����������
    cct_gotoxy(11, 13);
    cout << "A" << "         B" << "         C";
    cct_gotoxy(9, 12);
    cout << setw(25) << setfill('=') << " " << setfill(' ') << endl;

    cct_gotoxy(0, 17);
    cout << "��ʼ: ";
    PrintInX();  // ��ʾ��ʼ��ʱ�����������

    cct_setcursor(3);  // ����ʾ��� -> cmd_console_tools.cpp ��140��
}

void InitForOp8(int n, char src, char dst)
{
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << move_speed << endl;

    PrintInY(OffsetX, OffsetY);  // ��ʾ��ʼ��ʱ�����������
    cct_gotoxy(11, 13 + OffsetY);
    cout << "A" << "         B" << "         C";
    cct_gotoxy(9, 12 + OffsetY);
    cout << setw(25) << setfill('=') << " " << setfill(' ') << endl;

    cct_gotoxy(0, 17 + OffsetY);
    cout << "��ʼ: ";
    PrintInX();  // ��ʾ��ʼ��ʱ�����������

    DrawTriYuanZhu();  // ������Բ��
    DrawSrcPanZi(n, src);  // ����ʼ��ʱ��ʼ���ϵ�����

    cct_setcursor(3);  // ����ʾ��� -> cmd_console_tools.cpp ��140��
}

void InputSrcDst(int* n_ptr, char* src_ptr, char* tmp_ptr, char* dst_ptr)
{
    int n;
    while (1)  // �������
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n >= 1 && n <= 10)  // ��ȷ���� ����
            break;
    }
    while (getchar() != '\n');

    char src;  // ������ʼ��
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        if (src == 'a' || src == 'A' || src == 'b' || src == 'B' || src == 'c' || src == 'C')  // ��ȷ���� ����
            break;

    }
    while (getchar() != '\n');
    if (src > 96)  // ����ĸ���д
        src -= 32;

    char dst;  //����Ŀ����
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C')  // ��ȷ���� ����
            break;
    }
    while (getchar() != '\n');
    if (dst > 96)
        dst -= 32;

    while (1)  // ��Ŀ��������ʼ�������ж� ���Ƿ���ͬ
    {
        if (src == dst)
        {
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            while (1)
            {
                cout << "������Ŀ����(A-C)" << endl;
                cin >> dst;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                if (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C')  // ��ȷ���� ����
                    break;
            }
            while (getchar() != '\n');
            if (dst > 96)
                dst -= 32;
        }
        else
            break;
    }

    char tmp;  // �м���
    tmp = (char)('A' + 'B' + 'C' - src - dst);
    *n_ptr = n;
    *src_ptr = src;
    *tmp_ptr = tmp;
    *dst_ptr = dst;
}

void InputMoveSpeed()
{
    while (1)  // �����ƶ��ٶ�
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ";
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
    while (getchar() != '\n');  // ��ȡ�������еĻس�
}

void InitSrcArray(int n, char src)
{
    // Խ�ӽ������±�0��ֵԽ��ͬʱ����Բ��Խ��
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
        // fgxxxΪǰ��ɫ���ֵ���ɫ bg�������ı���ɫ
        cct_showch(BaseYuanZhuX + x, BaseYuanZhuDrawY, 32, COLOR_HYELLOW, COLOR_WHITE, 1);       // �ÿո����
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
    cct_setcolor(); //�ָ�ȱʡ��ɫ
}

void DrawSrcPanZi(int n, char src)
{
    int id = n;  // ���ӱ�� -> �������ɫһһ��Ӧ ��ʼ��ʱ���������ӵı����n�����������ӵı����1
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
    cct_setcolor(); //�ָ�ȱʡ��ɫ
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

void Delay(int x)  // ��ʱ���� 5��� 1���� 0����
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