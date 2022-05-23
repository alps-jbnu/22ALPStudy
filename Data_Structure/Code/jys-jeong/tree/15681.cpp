#include<bits/stdc++.h>
using namespace std;

vector<int> vec[100002];
bool vis[100002];
int num[100002];

int dfs(int n) {
 	if (num[n]!=0)	return num[n];
	vis[n] = true;
	int a = 1;
	for (int k : vec[n]) {
		if (vis[k])	continue;
		a += dfs(k);
	}
	num[n] = a;
	return a;
}




int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int node, root, query;
	cin >> node >> root >> query;

	for (int i = 0; i < node - 1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	num[root] = dfs(root);

	for (int i = 0; i < query; i++) {
		int a;
		cin >> a;
		cout << num[a] << "\n";
	}
}