/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* interest() 利息計算
*
* <p>
*   A單利(10%)；B複利(5%)，
*   求到第幾期B的本利和會大於A的本利和。
*   設A和B本金100元，
*
*   如果A的本利和大於B的本利和，
*   則 A + 10 ； B * 1.05，
*   並再判斷一次。
*
*   直至B的本利和大於A的本利和。
* </p>
* 
* @param A (double) A的本金
* @param B (double) B的本金
* @param n 期數
*/
void interest()
{
    int n = 0;
    double A = 100;
    double B = 100;
    while (B <= A)
    {
        A = A + 10;
        B = B * 1.05;
        n++;         
    }
    cout << n << endl;
}

int main()
{
    interest();
}
