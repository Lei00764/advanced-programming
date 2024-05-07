/* 2053932 ��� ���� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
void to_be_continued(const int X, const int Y);  // һ����Ϸ���������ƶ�

int Menu();  // ��ʾ�˵����������û���ȷѡ��

void hanoi(int n, char src, char tmp, char dst, int choice);  // �ݹ麯��

void DoByChoice(int n, char src, char tmp, char dst, int choice);   // �����û�ѡ��������ִ�к��ֲ��� ѡ�1��2��3��4��8
void DoByChoice2(int n, char src, char tmp, char dst, int choice);  // �����û�ѡ��������ִ�к��ֲ��� ѡ�6��7
void DoByChoice3(int n, char src, char dst);                        // �����û�ѡ��������ִ�к��ֲ��� ѡ�9
void GuiLing();                                                     // ÿ��ִ����һ���û�ѡ��󣬾�̬ȫ�ֱ�����ԭֵ

int IsMove(char from_ch, char to_ch);  // ѡ�� 9 �ж�Ҫ��Ҫ�ƶ� ����0��ʾ�����ѹС�̣�����-1��ʾ��ʼ��Ϊ�գ����ش���0��ʾҪ�ƶ��̵ı��

void MovePanInArray(int n, char src, char dst);                       // �����Ӵ�src��Ӧ�������ƶ���dst��Ӧ������
void PrintByChoice(int n, char src, char tmp, char dst, int choice);  // ������һ������������Ļ����ʾ��Ӧ����

void MovePanFromSrcToDst(int id, char src, char dst);
void GoToHigh(int one_x, int one_y, int another_x, int another_y, int id, int len);    // ����
void GoToInLine(int one_x, int one_y, int another_x, int another_y, int id, int len);  // ƽ��
void GoToLow(int one_x, int one_y, int another_x, int another_y, int id, int len);     // ����

void InputSrcDst(int* n_pre, char* src_ptr, char* tmp_ptr, char* dst_ptr);  // �������Ӹ�������ʼ����Ŀ����
void InputMoveSpeed();                                                      // �����ƶ��ٶ�

void InitSrcArray(int n, char src);          // ��ʼ��������ʼ�������ӱ�ţ�Խ������ӣ����Խ��
void InitForOp4(int n, char src, char dst);  // ���ѡ��4�Ľ��棺��һ����ʾ���ݡ������ӡ�������ӡ
void InitForOp8(int n, char src, char dst);  // ���ѡ��8�Ľ��棺��һ����ʾ���ݡ������ӡ�������ӡ + Բ�� + ��ʼ��

void DrawTriYuanZhu();               // ������Բ��
void DrawSrcPanZi(int n, char src);  // ����ʼ��ʱ��ʼ���ϵ�����

void PrintInX();                            // ��ӡ��������
void PrintInY(int offset_x, int offset_y);  // ��ӡ��������  ����������(A.B.C��һ�ŵȺ�)

void Delay(int x);  // ��ʱ����

