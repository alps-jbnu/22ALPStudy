#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

vector<int> p[MAX];
vector<int> ch[MAX];
vector<int> dr[MAX];
int d[MAX];
int deg[MAX];
int score[MAX][MAX];
int n, m;

void func(int v){
	if (v == 1 && deg[v] == 0) {
		for (auto y : p[v]) {
			if (d[v] < d[y] + score[y][v]) {
				d[v] = d[y] + score[y][v];
				dr[v] = dr[y];
				dr[v].push_back(v);
			}
		}
		return;
	}
	for (auto x : ch[v]) {
		deg[x]--;
		if (deg[x] == 0) {
			for (auto y : p[x]) {
				if (d[x] < d[y] + score[y][x]) {
					d[x] = d[y] + score[y][x];
					dr[x] = dr[y];
					dr[x].push_back(x);
				}
			}
			
			func(x);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, sc;
		cin >> s >> e >> sc;
		ch[s].push_back(e);
		p[e].push_back(s);
		score[s][e] = sc;
		deg[e]++;
	}

	dr[1].push_back(1);
	func(1);

	cout << d[1] << "\n";
	for (auto a : dr[1]) {
		cout << a << " ";
	}
	

}