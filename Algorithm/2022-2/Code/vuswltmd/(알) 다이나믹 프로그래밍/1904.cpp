#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
using namespace std;

int d[1000010][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	d[1][0] = 0;
	d[1][1] = 1;

	d[2][0] = 1;
	d[2][1] = 1;

	for (int i = 3; i <= N; i++)
	{
		d[i][0] = (d[i - 2][1] + d[i - 2][0]) % 15746;
		d[i][1] = (d[i - 1][1] + d[i - 1][0]) % 15746;
	}

	cout << (d[N][0] + d[N][1]) % 15746 << '\n';

}