#include <bits/stdc++.h>
using namespace std;

bool vis1[50];// /
bool vis2[100];// \

int board[10][10];
int ans[2];
int n;
vector<pair<int,int>> vec;

void func(int row,int col,int cnt,int color) {
	if (col >= n) {
		++row;
		if (col % 2 == 0)	col = 1;
		else col = 0;
	}
	if (row >= n) {
		ans[color] = max(ans[color], cnt);
		return;
	}
	if (board[row][col] && !vis1[col - row + n - 1] && !vis2[col + row]) {
		vis1[col - row + n - 1] = vis2[col + row] = 1;
		func(row, col + 2, cnt + 1, color);
		vis1[col - row + n - 1] = vis2[col + row] = 0;
	}
	func(row, col + 2, cnt, color);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(0,0,0,0);
	func(0, 1, 0, 1);
	cout << ans[0]+ans[1];
 }