/* 2053932 软件 雷翔 */
#pragma once

const int PopMenuX = 100;   // 弹出菜单的位置
const int PopMenuY = 1;
const int MapX = 0;  // 地图的位置
const int MapY = 0;
const int MenuMaxSum = 25;  // 菜单所能显示的最大关卡数
const int MaxLines = 14;    // 地图最大行数
const int MaxCols = 16;     // 地图最大列数


// base.cpp中
int IsDigitOrCharacter(char ch);  // 判断一个ch是否是数字或字符
int GetAllFiles(const char *file_spc, const char *format, char files[200][50]);  // 找到文件夹中所有符合要求的文件
void to_be_continued(int choice, const int X = 0, const int Y = 46);


// popmenu.cpp中
void ShowPopMenu(char files[200][50], int all_count, int start_count);  // 显示弹出菜单 all_count为总文件个数，从start_count开始显示


// console.cpp中
int GetButton();  // 记录按键状态，只有上下箭头、回车、esc这四个键才会退出该函数：返回1 上箭头；返回2 下箭头；返回3 回车；返回4 esc
int fun(char files[200][50], int all_count);  // 返回1表示关卡显示完成，继续下一次显示；返回0表示结束
int ShowMap(const char* file_spc, char filename[]);  // 打开文件，显示地图:正常情况下返回1，如果有非法字符，返回0
void ShowByCh(int i, int j, char ch);  // 根据文件里(i, j)处的字母来显示相应的色块
int CheckLegalInArr(char ch);  // 检查字符是否是非法字符（色块与字符的对应关系） 若不是非法字母，返回1；否则返回0
