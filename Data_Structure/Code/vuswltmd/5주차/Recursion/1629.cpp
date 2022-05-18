#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

using ll = long long;

ll func(ll a, ll b, ll c)
{
	if (b == 1)
	{
		ll val = a % c;
		return val;
	}

	ll val = func(a, b / 2, c);
	val = val * val % c;

	if (b % 2 == 0)
	{
		return val;
	}
	else
	{
		return val * a % c;
	}
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;

	cout << func(a, b, c);
}