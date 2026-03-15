#include <iostream>
using namespace std;

bool square(int a)
{
    for (int i = 1; i <= a; i++)
    {
        if (((a / i) * (a / i)) == a)
        {
            return true;
        }
    }
    return false;
}

void count()
{
    int a = 0, b = 0;
    cin >> a >> b;

    int n = 0;
    while (a <= b)
    {
        if (square(a)) n++;
        a++;
    }
    if (n != 0) cout << n << endl;
}
int main()
{
    count();
}