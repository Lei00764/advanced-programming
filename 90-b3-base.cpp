/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <io.h>
using namespace std;

/**
  * �ж�һ��ch�Ƿ������ֻ��ַ�
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
  * �ҵ��ļ��������з���Ҫ����ļ�
  * @file_spc  �ļ���Ŀ¼
  * @format    �ļ���ʽҪ�� ?��ƥ��һ���ַ�
  * @files     �洢����Ҫ����ļ���
  */
int GetAllFiles(const char *file_spc, const char *format, char files[200][50])
{
	long hFile = 0;  // �ļ����
	struct _finddata_t fileinfo;  // �ṹ�������洢�ļ��Ļ�����Ϣ
	int count = 0;  // ����Ҫ����ļ�����
	// �ɹ�����0��ʧ�ܷ���-1
	char path[100] = {'\0'};
	strcat(path, file_spc);
	strcat(path, "\\");
	if ((hFile = _findfirst(strcat(path, format), &fileinfo)) != -1)  // �������������ĵ�һ���ļ�
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


