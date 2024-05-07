/* 2053932 ��� ���� */
#include <iostream>
#include <ctime>
using namespace std;

const int MaxSize = 16;
static const char other[] = "!@#$%^&*-_=+,.?";


/**
 * @brief ����Insert**������֤����ɹ�
 */
void InsertUpper(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 65��ӦA
	char ch = (char)(rand() % 26 + 65);
	arr[pos] = ch;
}

void InsertLower(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 97��Ӧa
	char ch = (char)(rand() % 26 + 97);
	arr[pos] = ch;
}

void InsertDigit(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	// 48��Ӧ0
	char ch = (char)(rand() % 10 + 48);
	arr[pos] = ch;
}

void InsertOther(char arr[])
{
	int pos = rand() % MaxSize;
	while (arr[pos] != '\0')
		pos = (pos + 1) % MaxSize;
	int w = rand() % 15;  // �������ַ�������ѡ
	arr[pos] = other[w];
}


void CreatePasscode(char arr[], int passcodeLen, int upperCount, int lowerCount, int digitCount, int otherCount)
{
	for (int i = 0; i < upperCount; i++)
		InsertUpper(arr);
	for (int i = 0; i < lowerCount; i++)
		InsertLower(arr);
	for (int i = 0; i < digitCount; i++)
		InsertDigit(arr);
	for (int i = 0; i < otherCount; i++)
		InsertOther(arr);
	
	// ���ܻ�ʣ��һЩ����Ҫ����
	int remain_sum = passcodeLen - (upperCount + lowerCount + digitCount + otherCount);
	for (int k = 0; k < remain_sum; k++)
	{
		int choice = rand() % 4;
		switch (choice)
		{
			case 0:
				InsertUpper(arr);
				break;  // ��ס�ˣ�������������������
			case 1:
				InsertLower(arr);
				break;
			case 2:
				InsertDigit(arr);
				break;
			case 3:
				InsertOther(arr);
				break;
		}
	}
}


int main()
{
	char passcode[MaxSize] = { '\0' };  // ��¼���� 16�����룬��Ӧ16���ַ� 
	int passcode_len = 0, upper_count = 0, lower_count = 0, digit_count = 0, other_count = 0;
	srand((unsigned)time(NULL));  // �������
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> passcode_len >> upper_count >> lower_count >> digit_count >> other_count;
	if (cin.fail())
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (passcode_len < 12 || passcode_len > 16)
	{
		cout << "���볤��[" <<  passcode_len << "]����ȷ" << endl;
		return 0;
	}
	if (upper_count < 2)
	{
		cout << "��д��ĸ����[" << upper_count <<  "]����ȷ" << endl;
		return 0;
	}
	if (lower_count < 2)
	{
		cout << "Сд��ĸ����[" << lower_count << "]����ȷ" << endl;
		return 0;
	}
	if (digit_count < 2)
	{
		cout << "���ָ���[" << digit_count << "]����ȷ" << endl;
		return 0;
	}
	if (other_count < 2)
	{
		cout << "�������Ÿ���[" << other_count << "]����ȷ" << endl;
		return 0;
	}
	int sum = upper_count + lower_count + digit_count + other_count;
	if (sum > passcode_len)
	{
		cout << "�����ַ�����֮��[" << upper_count << "+" << lower_count << "+" << digit_count << "+" << other_count << "]���������볤��[" << passcode_len << "]" << endl;
		return 0;
	}
	
	cout << passcode_len << " " << upper_count << " " << lower_count << " " << digit_count << " " << other_count << endl;
	for (int i = 0; i < 10; i++)
	{
		CreatePasscode(passcode, passcode_len, upper_count, lower_count, digit_count, other_count);
		for (int j = 0; j < MaxSize; j++)
		{
			char ch = passcode[j];
			if (ch != '\0')
				cout << ch;
		}
		cout << endl;
		for (int m = 0; m < MaxSize; m++)  // ������룬Ϊ������һ��������׼��
			passcode[m] = '\0';
	}
	
	
	return 0;
}

/* 
˼·�����δ����д��Сд�����ֺ������ַ�����дȫ�����úú�������Сд���������ơ�
      ����������Ϊarr
	  �Դ����д�ַ�Ϊ�������������һ��λ��pos��ȷ��arr[pos]='\0'������ǰλ��û���������룬
	  �����Ҫ����pos=(pos+1)%MaxSize��Ȼ�����������һ���ַ�ch��ch��A~Z֮�䣬��pos��������ַ�
	  ѭ���ظ����϶���
*/