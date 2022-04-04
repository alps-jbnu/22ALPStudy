#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool f[501][501];
bool lists[501];
bool visit[501];

int main(void) {
	int count = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		f[x][y] = true;
		f[y][x] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (f[1][i]) {
			visit[i] = true;
			lists[i] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (lists[i]) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j]) {
					visit[j] = true;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (visit[i]) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}