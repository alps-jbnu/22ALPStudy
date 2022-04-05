#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
	int arr[2][7] = { 0 };
	int count = 0;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b]++;
	}

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (arr[i][j] == 0)
			{
				continue;
			}
			else
			{
				if (arr[i][j] % k == 0)
					count = count + (arr[i][j] / k);
				else
				{
					count = count + (arr[i][j] / k) + 1;
				}
			}
		}
	}

	cout << count;
}