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

ll init(int st, int en, int node) {
	if (st == en) return tree[node] = a[st];
	int mid = (st + en) / 2;

	return tree[node] = init(st, mid, node * 2) + init(mid + 1, en, node * 2 + 1);
}

ll sum(int st, int en, int node, int le, int ri) {
	if (le > en || ri < st) return 0; // 노드 구간 벗어날 경우
	if (le <= st && en <= ri) return tree[node]; //  범위에 포함될 경우

	int mid = (st + en) / 2;
	return sum(st, mid, node * 2, le, ri) + sum(mid + 1, en, node * 2 + 1, le, ri);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	init(1, n, 1); //  구간 합 트리 생성

	while (m--) {
		int st, en;
		cin >> st >> en;
		cout << sum(1, n, 1, st, en) << '\n';
	}
	return 0;
}