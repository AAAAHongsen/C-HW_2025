/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;
/**
* sequence() 列印n個數字，初始數列 1,1,2,... 此後數字都為前兩數相加和。
* <p>
    設初始a、b值為1。
    令c值為a+b，再令a值為b；b值為c。
    重複上述迴圈i+2次，即可得到想要的字數，結束程式。
* </p>
*
* @param n (int) 欲列印多少個數字
* @param i (int) 重複i次迴圈
* @param a (int) a值
* @param b (int) b值
* @param c (int) a+b值
*/
void sequence()
{
    int n = 0;
    int i = 1;
    int a = 1;
    int b = 1;
    int c = 0;
    cin >> n;
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";

    for (i = 1; i+2 <= n; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

int main()
{
    sequence();
}