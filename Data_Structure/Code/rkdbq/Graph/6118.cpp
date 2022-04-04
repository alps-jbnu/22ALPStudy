#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lis[20001];
int dis[20001];
bool vis[20001];
queue<int> Q;

void bfs() {
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[nxt]) continue;
			vis[nxt] = true;
			dis[nxt] = dis[cur] + 1;
			Q.push(nxt);
		}
	}
}
void printAns() {

	/*for (int i{ 1 }; i <= N; i++) {
		cout << dis[i] << " ";
	}*/

	int ans[3]{};
	ans[1] = *max_element(dis + 1, dis + N);
	for (int i{ N }; i >= 1; i--) {
		if (ans[1] == dis[i]) {
			ans[0] = i;
			ans[2]++;
		}
	}
	for (int i{}; i < 3; i++) {
		cout << ans[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i{}; i < M; i++) {
		int A, B;
		cin >> A >> B;
		lis[A].push_back(B);
		lis[B].push_back(A);
	}
	vis[1] = true;
	Q.push(1);
	bfs();
	printAns();
	return 0;
}