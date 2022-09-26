#include<bits/stdc++.h>
using namespace std;

int arr[10];
int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int mulNum = a * b * c;

	while (mulNum > 0)
	{
		arr[mulNum % 10]++;
		mulNum /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";

	return 0;
}
