/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* 求某整數n除3餘數等於2，且除5餘數等於3，且除7餘數等於2
* 
* <p>
*    假設n為1，
*
*    如果n除3餘數不等於2，n+1並再確認此數一次；
*    如果n除5餘數不等於3，n+1並再確認此數一次；
*    如果n除7餘數不等於2，n+1並再確認此數一次；
*
*    直至n除3餘數等於2，且除5餘數等於3，且除7餘數等於2，則得n值。
* </p>
*/
void remainder()
{
    int n = 1;
    while (n % 3 != 2 or n % 5 != 3 or n % 7 != 2)
    {
        n++;    
    }  
    cout << n << endl;
}

int main()
{   
    remainder();
}