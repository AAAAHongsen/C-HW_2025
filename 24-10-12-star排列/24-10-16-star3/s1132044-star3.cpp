/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* star() 列印n行，每行列印當前行數乘二減一個星星(*)符號；先放空格再放星星。
* <p>
    當i小於要求的行數(n)時，執行內層迴圈判斷:
    先列印空格，讓迴圈跑n減去當前行數的次數。
    再列印當前行數乘二減一個星星符號，便跳出內層迴圈，返回外層迴圈判斷。
    直到i大於要求的行數(n)，結束程式。
  </p>
*
* @param n :要求的行數
* @param i :行數
* @param g :星星個數
* @param s :空格數
*/
void star()
{
    int n = 0;
    int i = 1;
    int g = 1;
    int s = 1;
    cin >> n;
    while (i <= n)
    {
        s = 1;
        while (s <= (n - i))
        {
            cout << " ";
            s++;
        }
        g = 1;
        while (g <= (i * 2 - 1))
        {
            cout << "*";
            g++;
        }
        i++;
        cout << endl;
    }
}
int main()
{
    star();
}