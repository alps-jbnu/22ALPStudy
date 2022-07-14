#include<bits/stdc++.h>
using namespace std;

int n, erase;
vector<int>adj[51];

int dfs(int cur) {
	int cnt = 1;
	int child = 0;
	for (auto ch : adj[cur]) {
		if (ch == erase)
			continue;
		child += dfs(ch);
	}
	if (child)	//리프노드 아닐때
		return child;
	else	//리프노드일때
		return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int root;
	for (int i=0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1)
			root = i;
		else adj[parent].push_back(i);
	}

	cin >> erase;

	if (root != erase)	//루트 지우지 않았을 경우
		cout << dfs(root) << "\n";
	else cout << 0 << "\n";		//루트 지웠을 경우

	return 0;
}