/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int topA = 0, topB = 0, topC = 0;
int arrayA[10] = { 0 }, arrayB[10] = { 0 }, arrayC[10] = {0};

void Print()
{
    printf("A:");
    for (int k = 0; k < 10; k++)
    {
        if (arrayA[k] > 0)
            printf("%2d", arrayA[k]);
        else
            printf("  ");
    }
    printf(" B:");
    for (int k = 0; k < 10; k++)
    {
        if (arrayB[k] > 0)
            printf("%2d", arrayB[k]);
        else
            printf("  ");
    }
    printf(" C:");
    for (int k = 0; k < 10; k++)
    {
        if (arrayC[k] > 0)
            printf("%2d", arrayC[k]);
        else
            printf("  ");
    }
    printf("\n");
}


void hanoi(int n, char src, char tmp, char dst)
{

    static int count = 0;
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);

    count++;
    printf("第%4d 步(%2d): %c-->%c ", count, n, src, dst);
    if (dst == 'A')
    {
        if (src == 'B')
        {
            arrayA[topA++] = arrayB[topB - 1];
            arrayB[--topB] = 0;
        }
        else
        {
            arrayA[topA++] = arrayC[topC - 1];
            arrayC[--topC] = 0;
        }
    }
    else if (dst == 'B')
    {
        if (src == 'A')
        {
            arrayB[topB++] = arrayA[topA - 1];
            arrayA[--topA] = 0;
        }
        else
        {
            arrayB[topB++] = arrayC[topC - 1];
            arrayC[--topC] = 0;
        }
    }
    else
    {
        if (src == 'A')
        {
            arrayC[topC++] = arrayA[topA - 1];
            arrayA[--topA] = 0;
        }
        else
        {
            arrayC[topC++] = arrayB[topB - 1];
            arrayB[--topB] = 0;
        }
    }
    
    Print();

    hanoi(n - 1, tmp, src, dst);

}


int main()
{

    int n, ret1;

    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret1 = scanf("%d", &n);
        if (ret1 == 1 && (n >= 1 && n <= 10))
            break;

        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    char src, dst;
    int ret2, ret3;

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret2 = scanf("%c", &src);
        if (ret2 == 1 && (src == 'a' || src == 'A' || src == 'b' || src == 'B' || src == 'c' || src == 'C'))
            break;
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    if (src > 96) // 把字母变大写
        src -= 32;

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret3 = scanf("%c", &dst);
        if (dst > 96) // 如果输入小写，转成大写
            dst -= 32;
        if (ret3 == 1 && (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C') && src != dst)
            break;
        if (src == dst)
        {
            printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);

        }
        while (getchar() != '\n');
    }

    // 求中间层 src和dst已经变成大写
    char tmp;
    tmp = (char)(65 + 66 + 67 - src - dst);

    if (src == 'A')
    {
        for (int i = n; i > 0; i--)
        {
            arrayA[topA++] = i;
        }
    }
    else if (src == 'B')
    {
        for (int i = n; i > 0; i--)
        {
            arrayB[topB++] = i;
        }
    }
    else
    {
        for (int i = n; i > 0; i--)
        {
            arrayC[topC++] = i;
        }
    }

    printf("初始:                ");
    Print();
    hanoi(n, src, tmp, dst);

    return 0;
}