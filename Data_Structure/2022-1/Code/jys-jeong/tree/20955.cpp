#include<bits/stdc++.h>
using namespace std;

int parent[100001];
int cycle = 0;
int cnt = 0;
bool vis[100001];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void union_pair(int x, int y) {
	int ux = find(x);
	int uy = find(y);
	if (ux != uy) {
		parent[uy] = ux;
	}
}



int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			++cycle;
		}
		else {
			union_pair(a, b);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
			++cnt;
		}
	}
	cout << cnt - 1 + cycle;

}