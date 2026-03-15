/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* star() 列印n(奇數)行，每行遞增一個星星(*)符號，到中間行後遞減。
* <p>
    執行第一個迴圈:
    列印星星數量與當前行數相等，列印(n+1)/2行，
    直到i大於等於一半行數((n+1)/2)，結束此迴圈。
    執行第二個迴圈:
    設定初始星星數=n/2個，列印n/2行，每行遞減一個星星。
    直到i大於一半行數(n/2)，結束程式。
  </p>
*
* @param n :要求的行數
* @param i :行數 (奇數)
* @param g :星星個數
*/
void star()
{
    int n = 0; 
    int i = 1; 
    int g = 1; 
    cin >> n;

    for (i = 1; i <= (n + 1) / 2; i++)
    {
        for (g = 1; g <= i; g++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = 1; i <= n / 2; i++)
    {
        for (g = n / 2; g >= i; g--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    star();
}