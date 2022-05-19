#include <bits/stdc++.h>
using namespace std;

int val[2]; //0,1로 이루어진 종이 갯수
int board[128][128];

bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (board[r][c] != board[i][j])
				return false;
		}
	}
	return true;
}

void divide(int r, int c, int n) {
	if (check(r, c, n)) {
		val[board[r][c]]++;
	}
	else {
		int size = n / 2;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				divide(r + size * i, c + size * j, size);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	divide(0, 0, n);
	cout << val[0] << "\n" << val[1];
}