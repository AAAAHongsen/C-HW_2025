#include <iostream>
#include <vector>
using namespace std;

bool isone(int n)
{
    if (n % 2 == 1) return true;
    else if (n % 2 == 0) return false;
}
void binary(int n)
{
    int n0 = 0;
    int a;
    vector<int> Mod2;
    while (n!=0)
    {
        if (isone(n))a = 1;
        else a = 0;
        Mod2.push_back(a);
        n = n / 2;
    }
    int i = 0;
    cout << "The parity of ";
    for (i = Mod2.size() - 1; i >= 0; i--)
    {
        cout << Mod2[i];
        if (Mod2[i] == 1)n0++;
    }
    cout << " is " << n0 << " (mod 2)." << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    binary(n);
}