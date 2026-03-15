/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* divisor() 輸入a、b兩數，列印兩數的最大公因數。
* <p>
*    判斷a、b兩數大小，當a小於b時，兩數互換確保a大於b。
*    讓i永遠等於a除b的餘數，除完後b變成新的a值；i變成新的b值。
*    重複a除b直到餘數為0(整除)，此時的a值為兩數的最大公因數。
* </p>
*
* @param a (int) 輸入值a
* @param b (int) 輸入值b
* @param temp (int) 暫時數值
* @param i (int) 餘數
*/
void divisor()
{
    int a = 0, b = 0;
    cin >> a >> b;

    int temp = 0;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    int i = 0;
    while (b != 0)
    {
            i = a % b;
            a = b;
            b = i;
    }
    cout << a;
}

int main()
{
    divisor();
}