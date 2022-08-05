#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lis[100];
bool vis[100][100];
queue<int> Q;

void bfs(int idx) {
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[idx][nxt]) continue;
			vis[idx][nxt] = true;
			Q.push(nxt);
		}
	}
}
void printAns() {
	int ans{};
	/*for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i{ 1 }; i <= N; i++) {
		int colCnt{}, rowCnt{};
		for (int j{ 1 }; j <= N; j++) {
			if (vis[i][j]) colCnt++;
			if (vis[j][i]) rowCnt++;
		}
		if (colCnt >= (N + 1) / 2) ans++;
		if (rowCnt >= (N + 1) / 2) ans++;
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i{}; i < M; i++) {
		int hvy, lght;
		cin >> hvy >> lght;
		lis[hvy].push_back(lght);
	}
	for (int i{ 1 }; i <= N; i++) {
		Q.push(i);
		bfs(i);
	}
	printAns();
	return 0;
}