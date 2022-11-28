#include <bits/stdc++.h>
#define MAX 1000000 + 1
typedef long long ll;
using namespace std;

int N, M, K;
vector<ll> tree;
vector<ll> arr;

ll init(vector<ll> &arr, vector<ll> &tree, int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, start, mid, node * 2) + init(arr, tree, mid + 1, end, node * 2 + 1);
}

ll query(vector<ll>& tree, int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(tree, start, mid, node * 2, left, right) + query(tree, mid + 1, end, node * 2 + 1, left, right);
}

void update(vector<ll>& tree, int start, int end, int node, int index, ll data)
{
	if (index < start || index > end) return;
	tree[node] += data;

	int mid = (start + end) / 2;
	if (start != end)
	{
		update(tree, start, mid, node * 2, index, data);
		update(tree, mid + 1, end, node * 2 + 1, index, data);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		ll n; cin >> n;
		arr.push_back(n);
	}

	ll h = (int)ceil(log2(N));
	ll size = (1 << h + 1);
	tree.resize(size);

	init(arr, tree, 0, N - 1, 1);
	for (int i = 0; i < M + K; i++)
	{
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1)
		{
			update(tree, 0, N - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if 
			(a == 2) cout << query(tree, 0, N - 1, 1, b - 1, c - 1) << "\n";
	}

	return 0;
}