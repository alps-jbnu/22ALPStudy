#include<bits/stdc++.h>
using namespace std;

int table[205][205];
int n, m;
int nxt[205][205];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n + 1; i++) {
		fill(table[i], table[i] + n + 1, INT_MAX);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		table[a][b] = min(table[a][b], c);
		table[b][a] = min(table[b][a], c);
		nxt[a][b] = b;
		nxt[b][a] = a;
	}
	for (int i = 1; i <= n; i++) {
		table[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (table[j][i] == INT_MAX || table[i][k] == INT_MAX)	continue;
				if (table[j][k] > table[j][i] + table[i][k]) {
					table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
					nxt[j][k] = nxt[j][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}



	
}