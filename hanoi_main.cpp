/* 2053932 ��� ���� */

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

#include "cmd_console_tools.h"
#include "hanoi.h"

int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	int n;  // ���Ӹ���
	char src, tmp, dst;
	while (1)
	{
		int user_choice = Menu();
		int tag = 1;  // tag = 0 ���˳���ѭ��
		switch (user_choice)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 8:
				InputSrcDst(&n, &src, &tmp, &dst);  // ������Ӹ�������ʼ�����м�����Ŀ����������
				DoByChoice(n, src, tmp, dst, user_choice);
				break;
			case 5:
				cct_cls();  // ����
				DrawTriYuanZhu();
				break;
			case 6:
			case 7:
				InputSrcDst(&n, &src, &tmp, &dst);  // ������Ӹ�������ʼ�����м�����Ŀ����������
				DoByChoice2(n, src, tmp, dst, user_choice);
				break;
			case 9:
				InputSrcDst(&n, &src, &tmp, &dst);  // ������Ӹ�������ʼ�����м�����Ŀ����������
				DoByChoice3(n, src, dst);
				break;
			case 0:
				tag = 0;
				break;
		}
		
		if (tag == 0)
			break;
		to_be_continued(0, 38);
	}
	
	return 0;
}
