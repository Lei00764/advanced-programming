/* 2053932 ��� ���� */
#include <iostream>
using namespace std;

int main()
{
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	char str[80] = { '\0' }, * pfront, * ptail;  // �����ԣ�demo�������79���ַ�
	pfront = str;
	ptail = str;
	fgets(str, 80, stdin);
	while (*ptail != '\n' && *ptail != '\0')  // �ļ�����\0ֹͣ
		ptail++;
	ptail--;  // ��ptailָ�����һ���ַ�
	while (pfront <= ptail)
	{
		if (*pfront != *ptail)
		{
			cout << "no" << endl;
			return 0;
		}
		pfront++;
		ptail--;
	}
	cout << "yes" << endl;

	return 0;
}
// ��fgets��ȡ��
// �����ü�������ķ�ʽ���Ὣ�������Ļس��ַ��������飬�ٴ���β��
// ����������������(�ļ�)�ķ�ʽ��û�лس�����β�����

