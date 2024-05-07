/* 2053932 软件 雷翔 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    cout << " " << n << "# " << src << "-->" << dst << endl;
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    cout << "请输入汉诺塔的层数(1-16)" << endl;
    int n;
    cin >> n;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
    }
    char src, dst;
    cout << "请输入起始柱(A-C)" << endl;
    cin >> src;
    while (cin.fail() ||
             ((src != 'a' && src != 'A')
             && (src != 'b' && src != 'B')
             && (src != 'c' && src != 'C')))
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
    }
    if (src > 96) // 把字母变大写
        src -= 32;
    
    cout << "请输入目标柱(A-C)" << endl;
    cin >> dst;
    while (cin.fail() ||
            ((dst != 'a' && dst != 'A')
            && (dst != 'b' && dst != 'B')
            && (dst != 'c' && dst != 'C')))
    {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
    }
    if (dst > 96)
        dst -= 32;

    while (src == dst)
    {
        cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (dst > 96)
            dst -= 32;
    }
    
    // 求中间层 src和dst已经变成大写
    char tmp;
    tmp = char(65 + 66 + 67 - src - dst);
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}