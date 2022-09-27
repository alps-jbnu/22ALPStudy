#include <bits/stdc++.h>
#define ll long long
const int MAX = 4000;
using namespace std;

int N;
vector<ll> vec;
ll arr[4][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vec.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(vec.begin(), vec.end());

	ll result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ll half = arr[0][i] + arr[1][j];
			ll low = lower_bound(vec.begin(), vec.end(), -half) - vec.begin();
			ll high = upper_bound(vec.begin(), vec.end(), -half) - vec.begin();

			if (-half == vec[low]) result += (high - low);
		}
	}
	cout << result;

	return 0;
}