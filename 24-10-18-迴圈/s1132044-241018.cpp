/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* sequence() 列印數字1到n。
* <p>
*    從1開始列印，每次加1直到數字n。
*    如果目前列印的數字小於欲列印到的數字，就在後面列印逗號。
* </p>
*
* @param n 欲列印到的數
* @param i 初始值(1)
*/
void sequence()
{
    int n=0;
    int i=1;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << i ;
        if (i < n)cout << ",";
    }   
}

int main()
{
    sequence();
}
