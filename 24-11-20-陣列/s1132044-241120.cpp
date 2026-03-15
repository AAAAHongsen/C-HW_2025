#include <iostream>
using namespace std;

void cacu(int n,int m)
{
	int a[100] = {0};
	a[0] = n;
	int i = 0;
	int T = 1;

	for (i = 1; n != 1; i++)
	{
		if (n % m == 0)
		{
			n = n / m;
			a[i] = n;
		}
		else
		{
			T = 0;
			break;
		}
	}

	if (T == 1)
	{
		for (int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
	}
	else cout << "Boring!" << endl;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	cacu(n,m);
}