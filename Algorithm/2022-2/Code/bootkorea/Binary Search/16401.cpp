#include <bits/stdc++.h>
#define ll long long
const int MAX = 1000000 + 1;
using namespace std;

int M, N, result = 0;
ll arr[MAX];

void Solve(ll low, ll high)
{
	if (low > high) return;
	ll mid = (low + high) / 2;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt += (arr[i] / mid);
	}

	if (cnt >= M)
	{
		if (result < mid) result = mid;
		Solve(mid + 1, high);
	}
	else Solve(low, mid - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	Solve(1, arr[N - 1]);

	cout << result;

	return 0;
}