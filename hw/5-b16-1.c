/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ST 10

/**
 * @brief 将s2的内容复制到s1中，覆盖s1中原有内容，复制包括尾零
 */
int tj_strcpy(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int count2 = 0;
	while (s2[count2] != '\0')
		count2++;
	for (int i = 0; i < count2; i++)
		s1[i] = s2[i];
	s1[count2] = '\0';
	return 0; //return值可根据需要修改
}

/*
 * @brief 比较两个字符串大小，相等则返回0，不相等则返回差值 
 */
int tj_strcmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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

	return s1[i] - s2[i]; //return值可根据需要修改
}


void Input(char id_str[][8], char name_str[][9], int score[])
{
	for (int i = 0; i < ST; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", &id_str[i], &name_str[i], &score[i]);
	}
}


void Sorted(char id_str[][8], char name_str[][9], int score[])
{
	// 把学号小的放在数组末尾
	for (int i = 0; i < ST; i++)
	{
		for (int j = 0; j < ST - i - 1; j++)
		{
			if (tj_strcmp(id_str[j], id_str[j + 1]) < 0)  // 左边小于右边 -> 交换
			{
				// 交换学号
				char id_item[8];
				tj_strcpy(id_item, id_str[j]);
				tj_strcpy(id_str[j], id_str[j + 1]);
				tj_strcpy(id_str[j + 1], id_item);
				// 交换名字
				char name_item[9];
				tj_strcpy(name_item, name_str[j]);
				tj_strcpy(name_str[j], name_str[j + 1]);
				tj_strcpy(name_str[j + 1], name_item);
				// 交换成绩
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
	printf("\n及格名单(学号降序):\n");
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
