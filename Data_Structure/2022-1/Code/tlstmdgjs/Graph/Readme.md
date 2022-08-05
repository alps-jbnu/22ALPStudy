# [경로찾기](https://www.acmicpc.net/problem/11403)

n*n의 인접행렬 형식으로, 정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력하는 문제이다. 
## **구현**

정점i와 j가 이어지는 간선을 알아본뒤 vis배열에 방문했으면1, 방문하지않았으면 0을 넣는다. 입력값이 0이면 무시하고 1일때 해당그래프의 정점을 벡터에 push_back해준다.
그 뒤, n회의 행을 그때마다 배열을 초기화하며 dfs를 사용하며 받으면 n회의 열을 출력하면 답을 도출할 수 있다. 

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int>adj[101];
int vis[101];

void dfs(int cur) {
	stack<int>s;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (!vis[adj[cur][i]]) {
			vis[adj[cur][i]] = 1;
			dfs(adj[cur][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int p;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p;
			if (p==1)
				adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for (int j = 0; j < n; j++)
			cout << vis[j] << " ";
		cout << "\n";
	}
}
```
