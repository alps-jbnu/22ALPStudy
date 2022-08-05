#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


int N;
bool matrix[101][101];
bool ans[101][101];
bool vis[101];
stack<int> S;

void init() {
	fill_n(vis, 101, 0);
}
void dfs() {
	while (!S.empty()) {
		int cur{ S.top() };
		S.pop();
		for (int i{}; i < N; i++) {
			if (matrix[cur][i] == false) continue;
			if (vis[i]) continue;
			vis[i] = true;
			S.push(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i{}; i < N; i++) {
		init();
		S.push(i);
		dfs();
		for (int j{}; j < N; j++) {
			if (vis[j]) ans[i][j] = true;
		}
	}
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}