/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
#include <vector>
using namespace std;

/**
* average() 輸入n個數字，求n個數字相加平均值。
* <p>
    迴圈重複0到n-1次，每次輸入一組數字。
    迴圈重複0到n-1次，每次都讓當前data值加上sum值。
    輸出sum除n值。
  </p>
*
* @param n :數字數量
* @param i :迴圈重複次數
* @param sum :相加值
*/
void average()
{
    int n = 0;
    cin >> n;

    int i = 0;
    vector<double> data(n);
    for (i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    double sum = 0;
    for (i = 0; i < n; i++)
    {              
        sum = data[i] + sum;;
    }
    cout << sum/n;
}

int main()
{
    average();
}