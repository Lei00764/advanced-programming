/* 2053932 ��� ���� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

class stu_list;
/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int flag;  // flag = 1 ��ʾ��һ�֣�flag = 2 ��ʾ�ڶ���
public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
	friend stu_list;
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* ���������private���ݳ�Ա�ͳ�Ա���� */
	int point;  // ������ָ������ã�ָ�����һ��Ԫ�أ�ֵ����Ԫ�ظ���-1

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������
	

	/* �������������public��Ա���� */
	void Sort();  // ����ѧ������
	void Swap(int i, int j);  // ������Ž�����������Ԫ��
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	if (append == 0)
		point = -1;
	
	fstream fin;
	fin.open(filename, ios::in);
	if (fin.is_open() != 1)
		return -1;
	int num;
	while (fin >> num)
	{
		point++;
		stu[point].stu_no = num;
		fin >> stu[point].stu_name;
		
		if (append == 0)
			stu[point].flag = 1;
		else
			stu[point].flag = 2;
	}
	//cout << "point" << point << endl;
	return 1;
}

int stu_list::print(const char* prompt)
{
	
	Sort();  // ����ѧ������
	//for (int i = 0; i < point + 1; i++)
		//cout << stu[i].stu_no << " " << stu[i].stu_name << stu[i].flag << endl;;
	cout << prompt << endl;
	
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
	int index = 1;
	for (int i = 0; i < point + 1; i++)
	{
		cout << setiosflags(ios::left) << setw(4) << index++ << " " << stu[i].stu_no << " " << setw(MAX_NAME_LEN) << stu[i].stu_name << " ";
		if (stu[i].flag == 1)
		{
			cout << "Y      ";
			if (stu[i].stu_no == stu[i + 1].stu_no)
			{
				cout << "Y" << endl;
				i++;
			}
			else
			{
				cout << "�˿�" << endl;
			}
		}
		else  // ��һ��û��ѡ���ڶ���ѡ��
		{
			cout << "/      ��ѡ" << endl;
			
		}
	}
	cout << "===========================================================" << endl;
	return 0;
}

void stu_list::Sort()
{
	for (int i = 0; i <= point; i++)
	{
		for (int j = 0; j <= point - i - 1; j++)
		{
			if (stu[j].stu_no > stu[j + 1].stu_no)
				Swap(j, j + 1);
		}
	}
}

void stu_list::Swap(int i, int j)
{
	stu_info temp = stu[i];

	stu[i].flag = stu[j].flag;
	strcpy(stu[i].stu_name, stu[j].stu_name);
	stu[i].stu_no = stu[j].stu_no;

	stu[j].flag = temp.flag;
	strcpy(stu[j].stu_name, temp.stu_name);
	stu[j].stu_no = temp.stu_no;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */

	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}