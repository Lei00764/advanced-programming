/* 2053932 ��� ���� */
#include <iostream>
#include <cmath>
using namespace std;

unsigned int Pow(int x, int n)
{
	unsigned int sum = 1;
	for (int i = 0; i < n; i++)
		sum *= x;
	return sum;
}

int main()
{
	char str[33] = { '\0' }, * p;  // ���32��0/1
	p = str;
	unsigned int sum = 0;  // ��¼���
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	//fgets(str, 33, stdin);
	cin >> str;
	while (*p != '\0')  
		p++;
	int n = p - str;  // 0/1�ܸ���
	for (char *ps = str; ps < p; ps++)
	{
		if (*ps == '1')
			sum += Pow(2, n - 1);
		n--;
	}
	cout << sum << endl;

	return 0;
}
// �����fgets�Ļ������ļ��ͼ���������ܶ��벻ͬ�Ľ��
// pow������double
