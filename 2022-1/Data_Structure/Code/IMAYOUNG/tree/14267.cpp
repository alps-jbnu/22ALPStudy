#include <bits/stdc++.h>
using namespace std;


//dp사용하기 . ..

const int MAX = 100005;
vector<int> adj[MAX];
int p[MAX];
int dp[MAX];


void dfs(int cur) {

	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;
		dp[nxt] += dp[cur];
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M,cnt = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		p[i] = num;
		if (num != -1) {
			adj[num].push_back(i);
			adj[i].push_back(num);
		}
		
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dp[a] += b;		
	}

	dfs(1);

	for (int i = 1; i <= N; i++) cout << dp[i] << " ";
	

}