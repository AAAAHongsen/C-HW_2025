/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* sequence() 輸入五組數字，列印最大值與最小值。
* <p>
*    設a[0]值為最大值與最小值。
*    如果陣列下一組數字大於a[0]值，此數字更新成最大值；
*    反之如果陣列下一組數字小於a[0]值，此數字更新成最小值。
*    重複判斷後面四組數字與當前的最大值/最小值，可得陣列的最大值與最小值。
* </p>
*
* @param a[5] 輸入的五組數字
* @param max 五組數字內最大值
* @param min 五組數字內最小值
*
*/
void sequence()
{
    int a[5];
    for (int i = 0; i <= 4; i++)
    {
        cin >> a[i];
    }

    int max = a[0];
    int min = a[0];
    for (int i = 0; i <= 4; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << max << " " << min;
}

int main()
{
    sequence();
}