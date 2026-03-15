#include <iostream>
using namespace std;
int main()
{
	int i = 7;
	int a;
	int b;
	int bin[8] = { 0 };
	int temp;
	cin >> a; //15
	b = a;

	if (a < 0)a * -1;
	while (a != 0)
	{
		temp = a % 2;
		a = a / 2;
		bin[i] = temp;
		i--;
	}
	if (b >= 0)
	{
		for (i = 0; i < 8; i++)
			cout << bin[i];
		cout << endl;
	}
	else
	{
		for (i = 0; i < 8; i++)
		{
			if (bin[i] == 0)bin[i] = 1;
			else bin[i] = 0;
		}
		bin[7]++;
		for (i = 7; i >= 0; i--)
			if (bin[i] == 2)
			{
				bin[i] = 0;
				bin[i - 1]++;
			}
		for (i = 0; i < 8; i++)
			cout << bin[i];
		cout << endl;
	}
}