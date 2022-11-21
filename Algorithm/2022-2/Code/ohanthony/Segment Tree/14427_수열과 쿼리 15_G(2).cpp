#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second
const int NUMBER = 100005;

int n, m;
int a[NUMBER];
int tree[4 * NUMBER];

int minIndex(int x, int y) {
	if (a[x] == a[y]) return x < y ? x : y;
	return a[x] < a[y] ? x : y;
}

int init(int st, int en, int node) {
	if (st == en) return tree[node] = st;
	int mid = (st + en) / 2;

	return tree[node] = minIndex(init(st, mid, node * 2), init(mid + 1, en, node * 2 + 1));
}

int update(int st, int en, int node, int index) {
	if (index < st || index > en || st == en) return tree[node];

	int mid = (st + en) / 2;
	return tree[node] = minIndex(update(st, mid, node * 2, index), update(mid + 1, en, node * 2 + 1, index));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	init(0, n - 1, 1); // 세그먼트 트리 생성

	cin >> m;
	while (m--) {
		int query;
		cin >> query;
		if (query == 1) {
			int i, v;
			cin >> i >> v;
			a[--i] = v;
			update(0, n - 1, 1, i);
		}
		else cout << tree[1] + 1 << '\n';
	}
	return 0;
}