/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
public:
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int y, int m, int d) : year(y), month(m), day(d) {};
	int IsRunNian();
	int IsValid();  // �ж������Ƿ�Ϸ�
};

/* --- �˴��������Ա����������ʵ�� --- */
int Days::calc_days()
{
	int is_valid = IsValid();
	if (is_valid == 0)  // ���չ�ϵ����ȷ
		return -1;
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	int is_run_nian = IsRunNian();
	for (int i = 1; i < month; i++)
	{
		sum += arr[i - 1];
		if (is_run_nian == 1 && i == 2)
			sum++;
	}
	sum += day;
	return sum;
}

/**
  * ���귵��1�������귵��0
  */
int Days::IsRunNian()
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}


/**
  * �����չ�ϵ����ȷ������0����ȷ�򷵻�1
  */
int Days::IsValid()
{
	if ((month < 1) || (month > 12))
		return 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if ((day < 1) || (day > 31))
			return 0;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if ((day < 1) || (day > 30))
			return 0;
	}
	if (month == 2)
	{
		int is_run_nian = IsRunNian();
		if (is_run_nian == 1)  // ����
		{
			if ((day < 1) || (day > 29))
				return 0;
		}
		else
		{
			if ((day < 1) || (day > 28))
				return 0;
		}
	}
	return 1;
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
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2022, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}