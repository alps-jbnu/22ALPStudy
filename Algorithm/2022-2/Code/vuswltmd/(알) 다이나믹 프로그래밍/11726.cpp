#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int d[1005];

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n];
}