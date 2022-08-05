#include<bits/stdc++.h>
using namespace std;

vector<int> vec[502];
bool vis[502];
int cnt = 0;
int board[102][102];

void dfs(int n,int a) {

	for (int k : vec[n]) {
		if (vis[k])	continue;
		vis[k] = 1;
		board[a][k] = 1;
		dfs(k, a);

	}
}



int main() {
	int n;
	cin >> n;
	for (int i = 0; i <n ; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if(a==1)
				vec[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		if (vec[i].empty())	continue;
		
		dfs(i,i);
		fill(vis, vis + n, false);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}