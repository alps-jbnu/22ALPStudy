#include<bits/stdc++.h>
using namespace std;

int board[130][130];
int zero = 0, one = 0;
void cut(int size,int x, int y) {
	if (size == 1) {
		if (board[x][y] == 0) {
			++zero;
			return;
		}
		else if(board[x][y]==1){
			++one;
			return;
		}
	}

	bool flag = false;
	int a = board[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] != a) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		cut(size / 2, x, y);
		cut(size / 2, x+size/2, y);
		cut(size / 2, x, y + size / 2);
		cut(size / 2, x + size / 2, y + size / 2);
	}
	else {
		if (a == 0) {
			++zero;
			return;
		}
		else {
			++one;
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
	cut(n, 0, 0);
	cout << zero << "\n" << one;
}