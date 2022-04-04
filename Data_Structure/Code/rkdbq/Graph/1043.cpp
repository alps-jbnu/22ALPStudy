#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int truthN;
vector<int> lis[51];
bool vis[51]; //they know truth
queue<int> Q;
int prtyPplNum;
vector<int> prtyPpl[51];

void bfs() {
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[nxt]) continue;
			vis[nxt] = true;
			Q.push(nxt);
		}
	}
}
void printAns() {
	int ans{};
	/*for (int i{ 1 }; i <= N; i++) {
		for (int j{}; j < lis[i].size(); j++) {
			cout << i << " " << lis[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i{}; i < 51; i++) {
		cout << vis[i] << " ";
	}*/
	for (int i{}; i < M; i++) {
		int cnt{};
		for (int j{}; j < prtyPpl[i].size(); j++) {
			if (vis[prtyPpl[i][j]]) {
				cnt = 0;
				continue;
			}
			cnt++;
		}
		if (cnt == prtyPpl[i].size()) ans++;
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin >> truthN;
	for (int i{}; i < truthN; i++) {
		int idx;
		cin >> idx;
		vis[idx] = true;
		Q.push(idx);
	}
	for (int i{}; i < M; i++) {
		cin >> prtyPplNum;
		for (int j{}; j < prtyPplNum; j++) {
			int num;
			cin >> num;
			prtyPpl[i].push_back(num);
		}
	}
	for (int i{}; i < M; i++) {
		for (int j{}; j < prtyPpl[i].size(); j++) {
			for (int k{}; k < prtyPpl[i].size(); k++) {
				if (j == k) continue;
				lis[prtyPpl[i][j]].push_back(prtyPpl[i][k]);
			}
		}
	}
	bfs();
	printAns();
	return 0;
}