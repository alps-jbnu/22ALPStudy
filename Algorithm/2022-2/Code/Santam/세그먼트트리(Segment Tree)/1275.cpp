#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll board[400000]{}, v[100001]{};
int n, m;

ll init(int s, int e, int node)
{
	if (s == e) return board[node] = v[s];
	int mid = (s + e) / 2;
	return board[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

ll sum(int s, int e, int node, int left, int right)
{
	if (s > right || e < left) return 0;
	if (left <= s && e <= right) return board[node];
	int mid = (s + e) / 2;
	return sum(s, mid, node * 2, left, right) + sum(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, int idx, ll dif)
{
	if (idx < s || e < idx) return;
	board[node] += dif;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, node * 2, idx, dif);
	update(mid + 1, e, node * 2 + 1, idx, dif);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;
		v[i + 1] = t;
	}
	init(1, n, 1);
	for (int i = 0; i < m; i++)
	{
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << sum(1, n, 1, x < y ? x : y, x < y ? y : x) << "\n";
		update(1, n, 1, a, b - v[a]);
		v[a] = b;
	}
	return 0;
}