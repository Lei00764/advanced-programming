/* 2053932 ��� ���� */
#include <iostream>
#include <conio.h>  // for _getch()
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

void to_be_continued(int choice, const int X = 0, const int Y = 22)
{
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    cct_gotoxy(X, Y);
    
    if (choice == 1)
    {
        cout << "��С�������������End����...";
        int pos_x, pos_y; // ��ǰ�������λ��
        cct_getxy(pos_x, pos_y);  // ��ȡ��ǰ�������λ��
        while (1)
        {
            cct_gotoxy(pos_x, pos_y);
            char str[20] = { '\0' };
            int count = 0;  // ��¼�ַ�����
            int flag = 1;  // flag = 0ʱ�����������ѭ��
            while (1)
            {
                char ch = getchar();
                if (ch == '\n')
                {
                    cout << "�����������������" << endl;
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
        cct_setconsoleborder(120, 35, 120, 1000);  // ���������д���� ��ѡ��5�˳� �˵��Ĵ�С�ͺ�ԭ����һ����
        cct_setfontsize("��������", 16, 8);
    }
    else if (choice == 2)
    {
        cout << "���س�����ʾͼ��...";

        /* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
        while (_getch() != '\r')
            ;
    }

    cct_cls();
    return;
}

