/* 2053932 ��� ���� */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

// �˵���ʾ��ѡ�� ����ѡ���0-4/0-6��
char meni(const HANDLE hout)
{
	char choice;
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(�������ͷʱ�����ƶ�)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)(�������ͷʱ�����ƶ�)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ(����дHPKMʱ��׼�ƶ�)\n");
	printf("4.�ü�ͷ�������������ң��߽����(����дHPKMʱ��׼�ƶ�)\n");
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(���������ͷʱ�����ƶ�)\n");
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����)(���������ͷʱ�����ƶ�)\n");
	printf("0.�˳�\n");

	printf("[��ѡ��0-6] ");
	choice = _getche();
	while (1)
	{
		if (choice <= 54 && choice >= 48) // 48~48+6
		{
			break;
		}
		else
		{
			/* �˾�������ǵ���ϵͳ��cls�������� */
			cls(hout);
			printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(�������ͷʱ�����ƶ�)\n");
			printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)(�������ͷʱ�����ƶ�)\n");
			printf("3.�ü�ͷ�������������ң��߽�ֹͣ(����дHPKMʱ��׼�ƶ�)\n");
			printf("4.�ü�ͷ�������������ң��߽����(����дHPKMʱ��׼�ƶ�)\n");
			printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(���������ͷʱ�����ƶ�)\n");
			printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����)(���������ͷʱ�����ƶ�)\n");
			printf("0.�˳�\n");

			printf("[��ѡ��0-6] ");
			choice = _getche();
		}
	}
	return choice;

}

// ��i/j/k/l�ƶ� ��Ӧѡ��1��ѡ��2 ���ѡ��5��ѡ��6
void move_by_ijkl(const HANDLE hout, int x, int y, char choice)
{
	int mButton; // ������¼����ʲô��

	while (1)
	{
		if (choice == '1' || choice == '2')
		{
			mButton = _getch();
		}
		else
		{
			if ((mButton = _getch()) == 224)
			{
				mButton = _getch();
				continue;
			}
		}

		if (mButton == 'i' || mButton == 'I')
		{
			if (y == 1)
			{
				if (choice == '2' || choice == '6')
					y = 17;
				gotoxy(hout, x, y);

			}
			else
			{
				gotoxy(hout, x, --y);
			}
		}
		else if (mButton == 'j' || mButton == 'J')
		{
			if (x == 1)
			{
				if (choice == '2' || choice == '6')
					x = 69;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, --x, y);
			}
		}
		else if (mButton == 'k' || mButton == 'K')
		{
			if (y == 17)
			{
				if (choice == '2' || choice == '6')
					y = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, x, ++y);
			}
		}
		else if (mButton == 'l' || mButton == 'L')
		{
			if (x == 69)
			{
				if (choice == '2' || choice == '6')
					x = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, ++x, y);
			}
		}
		else if (mButton == 32) // �ո��ASCII
		{
			showch(hout, x, y, 32); // int -> char
			gotoxy(hout, x, y);  // ����ַ��󣬻��Զ�����1�� ��x�������� 
		}
		else if (mButton == 'q' || mButton == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
			break;
		}
		else
		{
			gotoxy(hout, x, y);
		}
	}
}

void move_by_arrow(const HANDLE hout, int x, int y, char choice)
{
	int mButton; // ������¼����ʲô�� 

	while (1)
	{
		// ��getch��ȡ���ܼ�ʱ���᷵������int����һ��int��224���ڶ���int���ǹ��ܼ���ASCII
		if ((mButton = _getch()) == 224)
		{
			if (mButton == 77 || mButton == 80 || mButton == 72 || mButton == 75)
				continue;
			mButton = _getch();
		}

		if (mButton == 72) // ��
		{
			if (y == 1)
			{
				if (choice == '4')
					y = 17;
				gotoxy(hout, x, y);
				// mButton = _getch();
			}
			else
			{
				gotoxy(hout, x, --y);
				// mButton = _getch();
			}
		}
		else if (mButton == 75) // ��
		{
			if (x == 1)
			{
				if (choice == '4')
					x = 69;
				gotoxy(hout, x, y);
				// mButton = _getch();
			}
			else
			{
				gotoxy(hout, --x, y);
				// mButton = _getch();
			}
		}
		else if (mButton == 80) // ��
		{
			if (y == 17)
			{
				if (choice == '4')
					y = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, x, ++y);
			}
		}
		else if (mButton == 77) // ��
		{
			if (x == 69)
			{
				if (choice == '4')
					x = 1;
				gotoxy(hout, x, y);
			}
			else
			{
				gotoxy(hout, ++x, y);
			}
		}
		else if (mButton == 32) // �ո��ASCII
		{
			showch(hout, x, y, 32); // int -> char
			gotoxy(hout, x, y);  // ����ַ��󣬻��Զ�����1�� ��x�������� 
		}
		else if (mButton == 'q' || mButton == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
			break;
		}
		else
		{
			gotoxy(hout, x, y);
		}
	}


}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��


	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	while (1)
	{
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
		char choice = meni(hout);
		if (choice == '0')
			break;

		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
		/* ��ʾ��ʼ�ı߿����е�����ַ� */
		init_border(hout);

		// ����ʼʱ���������λ��
		int x = 35, y = 9;
		gotoxy(hout, x, y);

		if (choice == '1' || choice == '2' || choice == '5' || choice == '6')
		{
			move_by_ijkl(hout, x, y, choice);
		}
		else
		{
			move_by_arrow(hout, x, y, choice);
		}

		while (_getch() != 13);
	}

	return 0;
}
/* ������20���������У�ǡ�����������ɵ�X��Y����ͬ����˵ڶ������ɵİѵ�һ�����ɵĸ������� */ 
