#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lis[101];
bool vis[101][101];
int dis[101][101];
int ans[101];
queue<int> Q;

void bfs(int idx) {
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[idx][nxt]) continue;
			vis[idx][nxt] = true;
			dis[idx][nxt] = dis[idx][cur] + 1;
			Q.push(nxt);
		}
	}
}
void findAns() {
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			ans[i] += dis[i][j];
		}
	}
	ans[0] = *min_element(ans + 1, ans + N);
	for (int i{ 1 }; i <= N; i++) {
		if (ans[0] == ans[i]) {
			cout << i;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i{}; i < M; i++) {
		int input[2];
		for (int i{}; i < 2; i++) cin >> input[i];
		lis[input[0]].push_back(input[1]);
		lis[input[1]].push_back(input[0]);
	}
	for (int i{ 1 }; i <= N; i++) {
		vis[i][i] = true;
		Q.push(i);
		bfs(i);
	}
	/*for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}*/
	findAns();
	return 0;
}