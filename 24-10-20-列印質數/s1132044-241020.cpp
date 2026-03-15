/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* 列印2到n以內的所有質數
* <p>
*     使i從2開始到n判斷是否為質數，是則列印，否則判斷下一個數。
*     設布林值質數檢查為真。
*     讓除數d從2開始，如果d小於i就d+1。
*     判斷i除d的餘數是否為0，是則使布林值質數檢查為否，並跳出迴圈判斷下一個被除數i；
*     若餘數皆不為0，表示此i值為質數，列印i，再判斷下一個被除數i。
* </p>
*
* @param n (int) 欲判斷到的數
* @param i (int) 被除數(2~n)
* @param d (int) 除數(2~(i-1))
*/

void sequence()
{
    int n = 0;
    int i = 2;
    bool checkprime = true;
    cin >> n;

    for (i = 2; i <= n; i++)
    {
        int d = 2;
        checkprime = true;
        
        while (d <= i - 1 && checkprime)
        {
            if (i % d == 0)
            {
                checkprime = false;
                break;
            }
            d++;
        }
        if (checkprime)
        {
            cout << i << ",";
        }   
        
    }
    if (checkprime)
    {
        cout << i;
    }
}

int main()
{
    sequence();
}