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
long long fibo[90];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= 90; i++)
	{
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}

	cout << fibo[n];
}