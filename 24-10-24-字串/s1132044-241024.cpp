/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
#include <string>
using namespace std;


/**
* count() 計算輸入字串中有多少數字。
* <p>
*    從字串第一個符號判斷，若是數字(編碼48-57)就使a加一。
*    直到判斷到字串最後一字，結束程式。
* </p>
*
* @param S (string) 輸入字串
* @param i (int) 迴圈數
* @param a (int) 數字數量
*
*/
void count()
{
    string S;
    cin >> S;

    int i = 0;
    int a = 0;
    for (size_t i = 0; i < S.size(); i++) 
    {
        if (S[i] >= 48 && S[i] <= 57)
        {
            a++;
        }
    }
    cout << a;
}

int main()
{
    count();
}