#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
#define ll long long
#define X first
#define Y second
const int NUMBER = 100005;

int n, m;
vector<ll> tree;

ll sum(int st, int en, int node, int le, int ri) {
	if (le > en || ri < st) return 0; // 노드 구간 벗어날 경우
	if (le <= st && en <= ri) return tree[node]; //  범위에 포함될 경우

	int mid = (st + en) / 2;
	return sum(st, mid, node * 2, le, ri) + sum(mid + 1, en, node * 2 + 1, le, ri);
}

ll update(int st, int en, int node, int index, ll dif) {
	if (index < st || index > en) return tree[node];
	if (st == en) return tree[node] += dif; // 아예 새로운 값을 대체하는게 아닌 기존에 있던 값에 더하는 방식이므로 다음과 같은 식

	int mid = (st + en) / 2;
	return tree[node] = update(st, mid, node * 2, index, dif) + update(mid + 1, en, node * 2 + 1, index, dif);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	tree.resize(n * 4);

	while (m--) {
		int query, a;
		ll b;
		cin >> query >> a >> b;
		if (query == 1) update(1, n, 1, a, b); // 따로 세그먼트 트리 만들 필요 없이 매 순간 update 하면 된다.
		else cout << sum(1, n, 1, a, b) << '\n';
	}
	return 0;
}