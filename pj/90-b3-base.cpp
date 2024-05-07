/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <io.h>
using namespace std;

/**
  * 判断一个ch是否是数字或字符
  */
int IsDigitOrCharacter(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return 1;
	else if (ch >= 'A' && ch <= 'Z')
		return 1;
	else if (ch >= '0' && ch <= '9')
		return 1;
	else
		return 0;
}

/**
  * 找到文件夹中所有符合要求的文件
  * @file_spc  文件夹目录
  * @format    文件格式要求 ?可匹配一个字符
  * @files     存储符合要求的文件名
  */
int GetAllFiles(const char *file_spc, const char *format, char files[200][50])
{
	long hFile = 0;  // 文件句柄
	struct _finddata_t fileinfo;  // 结构体用来存储文件的基本信息
	int count = 0;  // 符合要求的文件数量
	// 成功返回0，失败返回-1
	char path[100] = {'\0'};
	strcat(path, file_spc);
	strcat(path, "\\");
	if ((hFile = _findfirst(strcat(path, format), &fileinfo)) != -1)  // 查找满足条件的第一个文件
	{
		do
		{
			if ((IsDigitOrCharacter(fileinfo.name[14]) == 1) && (IsDigitOrCharacter(fileinfo.name[15]) == 1) && (IsDigitOrCharacter(fileinfo.name[16]) == 1))
			{
				strcpy(files[count++], fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) != -1);
		_findclose(hFile);
	}
	else
		return 0;
	return 1;
}


