#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
unordered_map<string, int> s;
vector<string> vec;
int n, m, k;
char board[12][12];
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,-1,1 };
void dfs(int x, int y,string a) {
	if (a.size() > 5)	return;
	++s[a];
	for (int i = 0; i < 8; i++) {
		int gx = dx[i] + x;
		int gy = dy[i] + y;
		if (gx < 0)	gx = n - 1;
		if (gx >= n)	gx = 0;
		if (gy < 0)	gy = m - 1;
		if (gy >= m)	gy = 0;
		dfs(gx, gy, a + board[gx][gy]);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		string a;
		cin >> a;
		s.insert({ a,0 });
		vec.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string st = "";
			dfs(i, j, st + board[i][j]);
		}
	}
	for (string k : vec) {
		cout << s[k] << '\n';
	}
}