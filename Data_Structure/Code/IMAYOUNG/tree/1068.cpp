#include <bits/stdc++.h>
using namespace std;

int n, deleteNodeNum;
vector<int> tree[50];
int visited[50];
int parent;
int root = 0;
int ans = 0;
void dfs(int x) {
	if (visited[x]) return;
	visited[x] = 1;
	bool isLeaf = true;
	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i];
		if (!visited[next]) {
			dfs(next);
			isLeaf = false; 
		}
	}
	if (isLeaf) ans++;
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else tree[parent].push_back(i);
	}
	cin >> deleteNodeNum;
	visited[deleteNodeNum] = true;
	dfs(root);
	cout << ans << "\n";
}