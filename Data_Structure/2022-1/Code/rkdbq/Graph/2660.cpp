#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> lis[51];
bool vis[51];
int dis[51][51];
int ans[51]; //dis Сп max АЊ
queue<int> Q;

void init() {
	fill_n(vis, 51, 0);
}
void bfs(int num) {
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[nxt]) continue;
			vis[nxt] = true;
			dis[num][nxt] = dis[num][cur] + 1;
			Q.push(lis[cur][i]);
		}
	}
}
void findAns() {
	ans[0] = 51;
	for (int i{ 1 }; i <= N; i++) {
		ans[i] = *max_element(dis[i], dis[i] + 6);
		//cout << ans[i] << " ans " << i << "\n";
		ans[0] = min(ans[0], ans[i]);
	}
	//ans[0] = *min_element(ans, ans + N);
	int cnt{};
	for (int i{ 1 }; i <= N; i++) {
		if (ans[0] == ans[i]) cnt++;
	}
	cout << ans[0] << " " << cnt << "\n";
	for (int i{ 1 }; i <= N; i++) {
		if (ans[0] == ans[i]) cout << i << " ";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	while (true) {
		int input[2];
		for (int i{}; i < 2; i++) cin >> input[i];
		if (input[0] == -1 && input[1] == -1) break;
		lis[input[0]].push_back(input[1]);
		lis[input[1]].push_back(input[0]);
	}
	for (int i{ 1 }; i <= N; i++) {
		init();
		if (lis[i].size() == 0) continue;
		vis[i] = true;
		Q.push(i);
		bfs(i);
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{}; j < lis[i].size(); j++) {
			cout << lis[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	findAns();
	
	return 0;
}