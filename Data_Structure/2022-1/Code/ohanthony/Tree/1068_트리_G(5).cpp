#include<bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int  n, parent, eraseNode, result, root;
/*
- n: 노드의 개수
- eraseNode: 지울 노드의 번호
- root: 루트
*/

int dfs(int root) {
	if (root == eraseNode) return -1;
	if (!adj[root].size()) {
		result++;
		return 0;
	}
	for (int i = 0; i < adj[root].size(); i++) {
		int temp = dfs(adj[root][i]);
		if (temp == -1 && adj[root].size() == 1) result++;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else adj[parent].push_back(i); // 자식이 없는 리프노드만 판별하므로 다음과 같은 식
	}

	cin >> eraseNode;
	dfs(root);
	cout << result;

	return 0;
}

