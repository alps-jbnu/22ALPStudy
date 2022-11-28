#include<iostream>
#include<string>
using namespace std;
int board[64][64];

void rec(int n, int x, int y) {
	if (n == 1) {
		cout << board[x][y];
		return;
	}

	bool zero = true;
	bool one = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] == 1) {
				zero = false;
			}
			else {
				one = false;
			}
		}
	}
	if (zero) {
		cout << 0;
	}
	else if (one) {
		cout << 1;
	}
	else {
		cout << "(";
		rec(n / 2, x, y);
		rec(n / 2, x, y + n / 2);
		rec(n / 2, x + n / 2, y);
		rec(n / 2, x + n / 2, y + n / 2);
		cout << ")";
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			board[i][j] = str[j] - '0';
		}
	}
	rec(n, 0, 0);
}