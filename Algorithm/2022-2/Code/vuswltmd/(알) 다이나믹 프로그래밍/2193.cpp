#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int d[90][2];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = 0;

	for (int i = 3; i <= n; i++)
	{
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i - 1][0];
	}

	cout << d[n][0] + d[n][1];

}