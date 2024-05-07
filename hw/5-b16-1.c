/* 2053932 ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ST 10

/**
 * @brief ��s2�����ݸ��Ƶ�s1�У�����s1��ԭ�����ݣ����ư���β��
 */
int tj_strcpy(char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int count2 = 0;
	while (s2[count2] != '\0')
		count2++;
	for (int i = 0; i < count2; i++)
		s1[i] = s2[i];
	s1[count2] = '\0';
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/*
 * @brief �Ƚ������ַ�����С������򷵻�0��������򷵻ز�ֵ 
 */
int tj_strcmp(const char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int count1 = 0, count2 = 0;
	while (s1[count1] != '\0')
		count1++;
	while (s2[count2] != '\0')
		count2++;
	int count = count1 < count2 ? count1 : count2;
	int i;
	for (i = 0; i < count; i++)
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
	}

	return s1[i] - s2[i]; //returnֵ�ɸ�����Ҫ�޸�
}


void Input(char id_str[][8], char name_str[][9], int score[])
{
	for (int i = 0; i < ST; i++)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s %s %d", &id_str[i], &name_str[i], &score[i]);
	}
}


void Sorted(char id_str[][8], char name_str[][9], int score[])
{
	// ��ѧ��С�ķ�������ĩβ
	for (int i = 0; i < ST; i++)
	{
		for (int j = 0; j < ST - i - 1; j++)
		{
			if (tj_strcmp(id_str[j], id_str[j + 1]) < 0)  // ���С���ұ� -> ����
			{
				// ����ѧ��
				char id_item[8];
				tj_strcpy(id_item, id_str[j]);
				tj_strcpy(id_str[j], id_str[j + 1]);
				tj_strcpy(id_str[j + 1], id_item);
				// ��������
				char name_item[9];
				tj_strcpy(name_item, name_str[j]);
				tj_strcpy(name_str[j], name_str[j + 1]);
				tj_strcpy(name_str[j + 1], name_item);
				// �����ɼ�
				int item;
				item = score[j];
				score[j] = score[j + 1];
				score[j + 1] = item; 
			}
		}
	}
}


void Output(char id_str[][8], char name_str[][9], int score[])
{
	printf("\n��������(ѧ�Ž���):\n");
	for (int i = 0; i < ST; i++)
	{
		if (score[i] >= 60)
			printf("%s %s %d\n", name_str[i], id_str[i], score[i]);
	}
}


int main()
{	
	char id[ST][8], name[ST][9];
	int score[ST];
	Input(id, name, score);
	Sorted(id, name, score);
	Output(id, name, score);

	return 0;
}
