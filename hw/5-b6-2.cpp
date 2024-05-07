/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;

int top_array[3] = { 0 };
int arr[3][10] = { 0 };

void Print()
{
    cout << " A:";
    for (int k = 0; k < 10; k++)
    {
        if (arr[0][k] > 0)
            cout << setw(2) << arr[0][k];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int k = 0; k < 10; k++)
    {
        if (arr[1][k] > 0)
            cout << setw(2) << arr[1][k];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int k = 0; k < 10; k++)
    {
        if (arr[2][k] > 0)
            cout << setw(2) << arr[2][k];
        else
            cout << "  ";
    }
    cout << endl;
}


// src 起始柱
// dst 目标柱
void hanoi(int n, char src, char tmp, char dst)
{
    static int count = 0;
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);

    count++;
    cout << "第" << setw(4) << count << " 步" << "(" << setw(2) << n << "): " << src << "-->" << dst;
    arr[dst - 65][top_array[dst - 65]++] = arr[src - 65][top_array[src - 65] - 1];
    arr[src - 65][--top_array[src - 65]] = 0;
    Print();

    hanoi(n - 1, tmp, src, dst);
    
}


int main()
{
    
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.good() && n >= 1 && n <= 10)
            break;
        cin.clear();
        cin.ignore(1024, '\n');
    }

    char src;
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.good() && (src == 'a' || src == 'A' || src == 'b' || src == 'B' || src == 'c' || src == 'C'))
            break;
        cin.clear();
        cin.ignore(1024, '\n');
    }
    
    if (src > 96) // 把字母变大写
        src -= 32;

    char dst;
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.good() && (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C'))
            break;
        cin.clear();
        cin.ignore(1024, '\n');
    }
    if (dst > 96)
        dst -= 32;

    while (src == dst)
    {
        cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
        while (1)
        {
            cout << "请输入目标柱(A-C)" << endl;
            cin >> dst;
            if (cin.good() && (dst == 'a' || dst == 'A' || dst == 'b' || dst == 'B' || dst == 'c' || dst == 'C'))
                break;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        if (dst > 96)
            dst -= 32;
    }

    // 求中间层 src和dst已经变成大写
    char tmp;
    tmp = char(65 + 66 + 67 - src - dst);
    for (int i = n; i > 0; i--)
    {
        arr[src - 65][top_array[src - 65]++] = i;
    }

    cout << "初始:               ";
    Print();
    hanoi(n, src, tmp, dst);

    return 0;
}