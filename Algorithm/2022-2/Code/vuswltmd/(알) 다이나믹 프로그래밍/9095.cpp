#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int d[1000005];

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		d[1] = 1; d[2] = 2; d[3] = 4;

		for (int i = 4; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << '\n';
	}
}