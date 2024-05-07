/* 2053932 ��� ���� */
#pragma once

const int PopMenuX = 100;   // �����˵���λ��
const int PopMenuY = 1;
const int MapX = 0;  // ��ͼ��λ��
const int MapY = 0;
const int MenuMaxSum = 25;  // �˵�������ʾ�����ؿ���
const int MaxLines = 14;    // ��ͼ�������
const int MaxCols = 16;     // ��ͼ�������


// base.cpp��
int IsDigitOrCharacter(char ch);  // �ж�һ��ch�Ƿ������ֻ��ַ�
int GetAllFiles(const char *file_spc, const char *format, char files[200][50]);  // �ҵ��ļ��������з���Ҫ����ļ�
void to_be_continued(int choice, const int X = 0, const int Y = 46);


// popmenu.cpp��
void ShowPopMenu(char files[200][50], int all_count, int start_count);  // ��ʾ�����˵� all_countΪ���ļ���������start_count��ʼ��ʾ


// console.cpp��
int GetButton();  // ��¼����״̬��ֻ�����¼�ͷ���س���esc���ĸ����Ż��˳��ú���������1 �ϼ�ͷ������2 �¼�ͷ������3 �س�������4 esc
int fun(char files[200][50], int all_count);  // ����1��ʾ�ؿ���ʾ��ɣ�������һ����ʾ������0��ʾ����
int ShowMap(const char* file_spc, char filename[]);  // ���ļ�����ʾ��ͼ:��������·���1������зǷ��ַ�������0
void ShowByCh(int i, int j, char ch);  // �����ļ���(i, j)������ĸ����ʾ��Ӧ��ɫ��
int CheckLegalInArr(char ch);  // ����ַ��Ƿ��ǷǷ��ַ���ɫ�����ַ��Ķ�Ӧ��ϵ�� �����ǷǷ���ĸ������1�����򷵻�0
