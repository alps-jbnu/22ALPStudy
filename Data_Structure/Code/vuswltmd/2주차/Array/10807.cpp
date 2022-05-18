#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[500] = { 0, };


	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (a >= 0)
			arr[a]++;

		if (a < 0)
		{
			arr[a + 300]++;
		}
	}
	int f;
	cin >> f;

	if (f >= 0)
		cout << arr[f];

	if (f < 0)
	{
		cout << arr[f + 300];
	}

}