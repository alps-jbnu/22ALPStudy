#include <bits/stdc++.h>
using namespace std;
int lc[100001];
int rc[100001];
bool visited[100001];
vector<int> adj[100001];
int ans = 0;
void inorder(int cur) {
	
	if (lc[cur] != 0)
	{
		ans++;
		inorder(lc[cur]);
	}
	
	visited[cur] = true;
	if (rc[cur] != 0) {
		inorder(rc[cur]);
		ans++;
	}

	for (auto nxt : adj[cur]) {
		if (visited[nxt] == true)continue;
		ans++;
	}
}