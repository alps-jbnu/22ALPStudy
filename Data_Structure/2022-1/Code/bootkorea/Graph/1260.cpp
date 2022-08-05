#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int num = 1001;
int n, m, v;
int arr[num][num];
int visit[num] = { 0, };
queue<int> que;

void dfs(int v) {
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] && !visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int v) {
	que.push(v);
	visit[v] = 1;

	while (!que.empty()) {
		v = que.front();
		cout << que.front() << " ";
		que.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[v][i] && !visit[i]) {
				visit[i] = 1;
				que.push(i);
			}
		}
	}
}

int main() {
	int x, y;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}

	visit[v] = 1;

	dfs(v);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(v);
	return 0;
}