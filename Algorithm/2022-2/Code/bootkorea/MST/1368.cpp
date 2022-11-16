#include <bits/stdc++.h>
#define MAX 100000 + 1
using namespace std;

int N;
tuple<int, int, int> edge[MAX];
vector<int> vec(300 + 1, -1);

int Find(int n)
{
	if (vec[n] < 0) return n;

	vec[n] = Find(vec[n]);

	return vec[n];
}

bool Group(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return 0;
	if (vec[x] == vec[y]) vec[x]--;

	if (vec[x] < vec[y]) vec[y] = x;
	else vec[x] = y;

	return 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int e = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int cost; cin >> cost;
		edge[e++] = { cost, i, N + 1 };
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int cost; cin >> cost;

			if (i >= j) continue;

			edge[e++] = { cost, i, j };
		}
	}
	N++; sort(edge, edge + e);

	int cnt = 0, result = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];

		if (!Group(a, b)) continue;

		result += cost;
		cnt++;

		if (cnt == N - 1) break;
	}
	cout << result;

	return 0;
}