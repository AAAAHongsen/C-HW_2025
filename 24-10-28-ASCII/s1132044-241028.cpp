/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;
/**
* change() 將輸入的數字(<15)轉換成英文。
* <p>
*    設定字串S每個數字位置(從0開始)相對英文，輸入數字n會等於字串S的第n位。
* </p>
*
* @param n (int) 輸入數字
*/
void change()
{
    string S[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen"};
    int n = 0;
    cin >> n;
    cout << S[n];
}

int main()
{
    change();
}