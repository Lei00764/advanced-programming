/* 2053932 ���� ���� */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* �������������ݳ�Ա */

public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(�������������ݳ�Ա) */
	Date();
	Date(int y, int m, int d);
	Date(int sum);

	void set(int y, int m = 1, int d = 1);
	void get(int& y, int& m, int& d);
	void show();

	int IsRunNian();  // �ж��Ƿ������� 
};

/* --- ���� Date ������г�Ա����������ʵ�� --- */
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	if (y < 1900 || y > 2099)
		year = 2000;
	else
		year = y;
	int is_run_nian = IsRunNian();
	if (m < 1 || m > 12)
		month = 1;
	else
		month = m;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (d < 1 || d > 31)
			day = 1;
		else
			day = d;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (d < 1 || d > 30)
			day = 1;
		else
			day = d;
	}
	else if (month == 2)
	{
		if (is_run_nian == 1)
		{
			if (d < 1 || d > 29)
				day = 1;
			else
				day = d;
		}
		else
		{
			if (d < 1 || d > 28)
				day = 1;
			else
				day = d;
		}
	}
}

/**
  * sum��ʾ��1900.1.1��ʼ������
  */
Date::Date(int sum)
{
	year = 1900;
	month = 1;
	day = 1;
	sum--;
	if (sum > 0)
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		// ����������
		for (int i = 1; i <= sum; i++)
		{
			int is_run_nian = IsRunNian();
			int month_day = arr[month];
			if (is_run_nian == 1 && month == 2)  // ������2��
				month_day++;

			day++;
			if (day > month_day)
			{
				day = 1;
				month++;
			}
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}
	if (year > 2099)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
	
}

// mĬ��1��dĬ��1
void Date::set(int y, int m, int d)
{
	if (y != 0)
	{
		if (y < 1900 || y > 2099)
			year = 2000;
		else
			year = y;
	}
	
	int is_run_nian = IsRunNian();

	if (m != 0)
	{
		if (m < 1 || m > 12)
			month = 1;
		else
			month = m;
	}
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (d < 1 || d > 31)
			day = 1;
		else
			day = d;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (d < 1 || d > 30)
			day = 1;
		else
			day = d;
	}
	else if (month == 2)
	{
		if (is_run_nian == 1)
		{
			if (d < 1 || d > 29)
				day = 1;
			else
				day = d;
		}
		else
		{
			if (d < 1 || d > 28)
				day = 1;
			else
				day = d;
		}
	}
}

void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

void Date::show()
{
	cout << year << '.' << month << '.' << day << endl;
}

int Date::IsRunNian()
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}


/* --- �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� --- */

/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��������ʱ���滻
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 12, 9);	//2022.12.9

		cout << "�޲μ����ι��캯�����ԣ���ȫ��ȷ��" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.1.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.12.9��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "���ι��캯�����ԣ��ꡢ�¡��շǷ���" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.6.1�� ʵ��Ϊ��";
		d4.show();

		/* ���������������˳���� */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5Ӧ����2000.2.29��ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1�� ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.1.31��ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2000.1.1�� ʵ��Ϊ��";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "���ι��캯�����ԣ����꣩" << endl;
		cout << "========================" << endl;

		cout << "d1Ӧ����2022.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2020.2.29��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(44903);      //2022.12.9

		cout << "һ�ι��캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();
		cout << "d5Ӧ����1982.2.19�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2022.12.9�� ʵ��Ϊ��";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);		//2022.1.1

		cout << "d1Ӧ����2022.6.10��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.6.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.1.1�� ʵ��Ϊ��";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "����set���ꡢ�¡��շǷ�" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1Ӧ����2000.2.29�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2019.2.1��  ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.5.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.1.12�� ʵ��Ϊ��";
		d4.show();

		/* �����+��ȱʡֵ����������˳���� */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5Ӧ����2000.2.29�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1��  ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.2.1��  ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2020.2.1��  ʵ��Ϊ��";
		d8.show();
		cout << "d9Ӧ����2020.1.1��  ʵ��Ϊ��";
		d9.show();
		cout << "d10Ӧ����2000.1.31��ʵ��Ϊ��";
		d10.show();
		cout << "d11Ӧ����2000.1.1�� ʵ��Ϊ��";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 12, 9);
		int y, m, d;

		cout << "����get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "Ӧ��y=2022,m=12,d=9��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}