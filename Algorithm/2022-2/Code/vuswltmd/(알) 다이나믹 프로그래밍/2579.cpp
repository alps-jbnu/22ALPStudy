#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int stair[305];
int d[305][3];
int n;


int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}

	d[1][1] = stair[1];
	d[1][2] = 0;
	//d[2][1] = stair[2];
	//d[2][2] = stair[1] + stair[2];

	for (int i = 2; i <= n; i++)
	{
		d[i][1] = max(d[i - 2][2], d[i - 2][1]) + stair[i];
		d[i][2] = d[i - 1][1] + stair[i];
	}

	cout << max(d[n][1], d[n][2]);

}