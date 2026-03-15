/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* Estar() 列印n行，每行列印n個英文，英文從a到z。
* <p>
*   當i小於要求的行數(n)時，執行下一個迴圈判斷:
*   列印英文數量直到與當前行數相等，從a(E=97)開始每列印一個英文便讓英文編碼E+1，直到z(E=122)讓E重回a(E=97)，便跳出此迴圈，返回第一個迴圈判斷。
*   直到i大於要求的行數(n)，結束程式。
* </p>
*
* @param n :要求的行數
* @param i :行數
* @param g :英文個數
* @param E :ACSII英文小寫編碼
*/
void Estar()
{
    int n = 0;
    int i = 1;
    int g = 1;
    int E = 97;
    cin >> n;
    while (i <= n)
    {
        while (g <= i)
        {
            cout << char(E);
            g++;
            E++;
            if (E > 122) E = 97;
        }  
        g = 1;
        i++;
        cout << endl;
    }
}

int main()
{
    Estar();
}