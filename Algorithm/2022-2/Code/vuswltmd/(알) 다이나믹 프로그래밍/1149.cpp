#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int d[1005][3];
int house[1005][3];

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[i][j];
		}
	}

	d[1][0] = house[1][0];
	d[1][1] = house[1][1];
	d[1][2] = house[1][2];


	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house[i][2];
	}

	int smaller;
	smaller = min(d[n][0], d[n][1]);
	cout << min(smaller, d[n][2]);

}