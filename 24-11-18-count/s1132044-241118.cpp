/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* count(int x, int y) 用兩隊分數的和與差值，求兩隊最終分數。
* <p>
*  a + b  = x ; |a - b| = y 
* 因此a隊分數等於兩隊比分和值加差值再除二；b隊分數是和值減a隊分數。
* 若和值加差值為奇數，因a隊分數為小數，所以最終分數不存在。
* 若計算完a隊或b隊分數為負數，則最終分數不存在。
* </p>
*
* @param x :輸入的比分兩數和值 (sum)
* @param y :輸入的比分兩數(絕對)差值 (diff)
* @param a :a隊最終分數 (較大)
* @param b :b隊最終分數 (較小)
*/
void count(int x, int y)
{
    int a = 0, b = 0;

    a = (x + y) / 2; b = x - a;

    if ((x + y) % 2 != 0 || a < 0 || b < 0)
    {
        cout << "Impossible" << endl;
    }
    else cout << a << " " << b << endl;
    
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int sum = 0, diff = 0;
        cin >> sum >> diff;
        count(sum, diff);
    }
}