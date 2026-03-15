/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* displacement() 給定一速率v與時間t，求經過2t時間後的距離為多少。
* <p>
*   距離公式：s = V₀t + 1/2 at² 。
*   帶入2t則得距離值。
* </p>
*
* @param v (int) : 初始速率
* @param t (int) : 特定時間
* @param s (int) : 行經距離
*/
void displacement()
{
    int v = 0, t = 0, s = 0;
    cin >> v >> t;

    s = 2 * v * t;
    cout << s << endl;
}

int main()
{
    displacement();
}