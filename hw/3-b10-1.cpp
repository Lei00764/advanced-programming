/* 2053932 ��� ���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int i, j, k;
	int gei, gej, gek, shii, shij, shik, baii, baij, baik;
	int count = 1;
	for (i = 100; i < 652; i++)
	{
		gei = i % 10;
		shii = i / 10 % 10;
		baii = i / 100 % 10;
		if ((gei == 0 || shii == 0 || baii == 0) || (gei == shii) || (gei == baii) || (shii == baii))
			continue;
		for (j = i; j < 1000; j++)
		{
			gej = j % 10;
			shij = j / 10 % 10;
			baij = j / 100 % 10;
			if ((gej == 0 || shij == 0 || baij == 0) || (gej == shij) || (gej == baij) || (shij == baij)
				|| (gei == gej) || (gei == shij) || (gei == baij) 
				|| (shii == gej) || (shii == shij) || (shii == baij)
				|| (baii == gej) || (baii == shij) || (baii == baij)
				)
				continue;
			for (k = j; k < 1000; k++)
			{
				if (i + j + k != 1953)
					continue;
				gek = k % 10;
				shik = k / 10 % 10;
				baik = k / 100 % 10;
				if (gek == 0 || shik == 0 || baik == 0 || (gek == shik) || (gek == baik) || (shik == baik)
					|| (gek == gej) || (gek == shij) || (gek == baij) || (gek == gei) || (gek == shii) || (gek == baii)
					|| (shik == gej) || (shik == shij) || (shik == baij) || (shik == gei) || (shik == shii) || (shik == baii)
					|| (baik == gej) || (baik == shij) || (baik == baij) || (baik == gei) || (baik == shii) || (baik == baii)
					)
					continue;
				if (i + j + k == 1953)
				{
					cout << "No." << setw(3) << count << " : " << i << "+" << j << "+" << k  << "=" << 1953 << endl;
					count++;
				}
			}
		}
	}
	cout << "total=" << count-1 << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}
