#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<long long, long long>
using namespace std;

int N, result = 0;
vector<pll> vec;

bool operator < (pll x, pll y)
{
	return make_pair(x.first, x.second) < make_pair(y.first, y.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int nl = 0, nr = 0;

	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end());
	nl = vec[0].first, nr = vec[0].second;

	for (int i = 1; i < N; i++)
	{
		int l = vec[i].first;
		int r = vec[i].second;

		if (l > nr)
		{
			result += (nr - nl);
			nl = l, nr = r;
		}
		else
		{
			nr = max(r, nr);
		}
	}
	result += (nr - nl);

	cout << result;

	return 0;
}