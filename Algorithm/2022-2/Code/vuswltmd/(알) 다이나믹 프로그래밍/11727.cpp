#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int tile[1005][3];
int d[1005][3];
int n;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	d[1][0] = 1;
	d[1][1] = 0;
	d[1][2] = 0;
	d[2][0] = 1;
	d[2][1] = 1;
	d[2][2] = 1;


	for (int i = 3; i <= n; i++)
	{
		d[i][0] = (d[i - 1][1] + d[i - 1][2] + d[i - 1][0])%10007;
		d[i][1] = (d[i - 2][1] + d[i - 2][2] + d[i - 2][0])%10007;
		d[i][2] = (d[i - 2][1] + d[i - 2][2] + d[i - 2][0])%10007;
	}

	cout << (d[n][0] + d[n][1] + d[n][2])%10007;
}