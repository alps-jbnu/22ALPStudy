#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 100000 + 1;
using namespace std;

int N, Q;
vector<ll> arr;
vector<ll> tree;

ll init(vector<ll>& arr, vector<ll>& tree, int start, int end, int node)
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
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
		int temp; cin >> temp;
		arr.push_back(temp);
    }
	ll h = (int)ceil(log2(N));
	ll size = (1 << h + 1);
	tree.resize(size);

	init(arr, tree, 0, N - 1, 1);

    for (int i = 0; i < Q; i++)
    {
        int x, y, a, b; cin >> x >> y >> a >> b;

		int Top = x > y ? x : y;
		int Bottom = x < y ? x : y;

		cout << query(tree, 0, N - 1, 1, Bottom - 1, Top - 1) << "\n";

		ll temp = b - arr[a - 1];
		arr[a - 1] = b;

		update(tree, 0, N - 1, 1, a - 1, temp);
    }

    return 0;
}