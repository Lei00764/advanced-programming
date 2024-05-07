/* 2053932 软件 雷翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0; // 全局变量

void hanoi(int n, char src, char tmp, char dst)
{
    

    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    count++;
    printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
    // cout << setw(5) << count << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
    hanoi(n - 1, tmp, src, dst);

}


int main()
{
    
    int n, ret1;
    
    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret1 = scanf("%d", &n);
        if (ret1 == 1 && (n >= 1 && n <= 16))
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
    printf("移动步骤为:\n");
    
    hanoi(n, src, tmp, dst);

    return 0;
}