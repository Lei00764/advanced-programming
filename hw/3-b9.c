/* 2053932 Èí¼ş À×Ïè */
#include <stdio.h>
int main()
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < i+1; j++)
		{
			printf("%dx%d=%d  ", j, i, i * j);
			if (i * j < 10)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}