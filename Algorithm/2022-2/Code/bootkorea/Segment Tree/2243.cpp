#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e6 + 1;
using namespace std;

int N;
ll Size, result;
vector<ll> tree;
vector<ll> vec;

ll init(vector<ll>& vec, vector<ll>& tree, int start, int end, int node)
{
	if (start == end) return tree[node] = vec[start];

	int mid = (start + end) / 2;
	return tree[node] = init(vec, tree, start, mid, node * 2) + init(vec, tree, mid + 1, end, node * 2 + 1);
}

ll query(vector<ll>& tree, int start, int end, int node, int K)
{
	if ((start == end) && !result)
	{
		cout << start << "\n";
		return start;
	}

	if (result == 0 && (node * 2 <= Size && tree[node * 2] >= K))
	{
		return result = query(tree, start, (start + end) / 2, node * 2, K);
	}

	K -= tree[node * 2];

	if (result == 0 && (node * 2 + 1 <= Size && tree[node * 2 + 1 >= K]))
	{
		return result = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, K);
	}
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

	cin >> N;
	vec.resize(N);

	ll h = (int)ceil(log2(MAX));
	Size = (1 << h + 1);
	tree.resize(Size);

	for (int i = 0; i < N; i++)
	{
		int temp; cin >> temp;

		if (temp == 1)
		{
			int idx;
			ll rank; cin >> rank;

			idx = query(tree, 0, MAX - 1, 1, rank);
			result = 0;
			update(tree, 0, MAX - 1, 1, idx, -1);
		}
		else if (temp == 2)
		{
			int flavor;
			ll cnt;
			cin >> flavor >> cnt;

			update(tree, 0, MAX - 1, 1, flavor, cnt);
		}
	}

	return 0;
}