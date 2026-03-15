/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* sequence() 列印n個數字，從1開始每次遞加e。
* <p>
*    從1開始列印，每次加e直到有n個數字。
*    如果目前列印的個數小於n個，就在後面列印逗號。
* </p>
*
* @param n 欲列印多少個數字
* @param i 第i個數
* @param e 遞增值
* 
*/
void sequence()
{
    int n = 0;
    int i = 1;
    int e = 0;

    cin >> n >> e;

    for (i = 1; i <= n; i++)
    {
        cout << 1+e*(i-1);
        if (i < n)cout << ",";
    }
}

int main()
{
    sequence();
}
