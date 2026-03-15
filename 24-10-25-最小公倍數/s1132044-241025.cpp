/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/

#include <iostream>
using namespace std;

/**
* mul() 求輸入兩數的最小公倍數。
* <p>
*    最小公倍數 = 兩數相乘 除以 兩數的最大公因數。
*    複製a值到c值、複製b值到d值。
*    求a、b最大公因數：
*    當b不為0時，餘數=a%b；a=新b；b=新i。
*    當b為0時，a為兩數的最大公因數。
*    列印a、b兩數相乘再除以兩數的最大公因數。
* </p>
*
* @param a (int) 輸入值a
* @param b (int) 輸入值b
* @param c (int) 複製a值
* @param d (int) 複製b值
* @param i (int) 餘數
* @param common (int) 最小公倍數
*/
void mul()
{
    int a = 0, b = 0;
    cin >> a >> b;
    int c = a, d = b;

    int i = 0;
    while (b != 0)
    {
        i = a % b;
        a = b;
        b = i;
    }
    /*cout << a;*/
    int common = (c * d) / a;
    cout << common;
}

int main()
{
    mul();
}