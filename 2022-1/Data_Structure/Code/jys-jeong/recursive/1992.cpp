#include<bits/stdc++.h>
using namespace std;

string board[65];
int zero = 0, one = 0;
string str="";
void cut(int size,int x, int y) {
	if (size == 1) {
		if (board[x][y] == '1') {
			str += '1';
			return;
		}
		else if (board[x][y] == '0') {
			str += '0';
			return;
		}
	}
	char a = board[x][y];
	bool flag = false;
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y + size; j++) {
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
		str += "(";
		cut(size / 2, x, y);
		cut(size / 2, x, y + size / 2);
		cut(size / 2, x+size/2, y);
		cut(size / 2, x + size / 2, y + size / 2);
		str += ")";
	}
	else {
		if (a == '1') {
			str += '1';
		}
		else {
			str += '0';
		}
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	cut(n, 0, 0);

	cout << str;
}