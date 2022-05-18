#include<bits/stdc++.h>
using namespace std;

int board[2188][2188];
int cnt[3];
void draw(int size, int x, int y) {

	if (size == 1) {
		if (board[x][y] == -1) {
			++cnt[1+(-1)];
			return;
		}
		else if (board[x][y] == 0) {
			++cnt[1 + 0];
			return;
		}
		else if (board[x][y] == 1) {
			++cnt[1 + 1];
			return;
		}
	}
	int a = board[x][y];
	bool flag = false;
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (a != board[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		draw(size / 3, x, y);
		draw(size / 3, x+size/3, y);
		draw(size / 3, x, y+size/3);
		draw(size / 3, x+ size / 3, y+ size / 3);
		draw(size / 3, x+ 2 * size / 3, y);
		draw(size / 3, x, y+ 2 * size / 3);
		draw(size / 3, x+ 2 * size / 3, y+ 2 * size / 3);
		draw(size / 3, x+ 2 * size / 3, y+ size / 3);
		draw(size / 3, x + size / 3, y + 2*size / 3);
	}
	else {
		if (a == -1) {
			++cnt[1 +(-1)];
			return;
		}
		else if (a == 0) {
			++cnt[1 + 0];
			return;
		}
		else if (a == 1) {
			++cnt[1 + 1];
			return;
		}
		
	}

}


int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	draw(n, 0, 0);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}
}