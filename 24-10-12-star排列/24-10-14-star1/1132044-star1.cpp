/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* star() 列印n行，每行列印n個星星(*)符號
* <p>
    當i小於要求的行數(n)時，執行下一個迴圈判斷:
    列印星星數量直到與當前行數相等，便跳出此迴圈，返回第一個迴圈判斷。
    直到i大於要求的行數(n)，結束程式。
  </p>
*
* @param n :要求的行數
* @param i :行數
* @param g :星星個數
*/
void star()
{
    int n = 0;
    int i = 1;
    int g = 1;
    cin >> n;
    while (i <= n)
    {
        while (g <= i)
        {
            cout << "*";
            g++;
        }
        g = 1;
        i++;
        cout << endl;
    }
}

int main()
{
    star();
}