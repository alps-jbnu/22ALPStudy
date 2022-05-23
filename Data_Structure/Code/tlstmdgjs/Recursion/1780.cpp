#include <bits/stdc++.h>
using namespace std;

int val[3]; //-1,0,1로 채워진 종이갯수
int board[2187][2187];

//종이안에 모든 칸들이 같은 수인지 아닌지 판단하는 함수
bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (board[r][c] != board[i][j])
				return false;
		}
	}
	return true;
}

//9분할하는 함수
void divide(int r, int c, int n) {
	if (check(r, c, n)) { //모든 칸들이 같은 값을 가질 경우
		val[board[r][c]]++;
	}
	else {
		int size = n / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(r + size * i, c + size * j, size); //재귀 함수 호출?
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
			board[i][j]++;
		}
	}
	divide(0, 0, n);
	cout << val[0] << "\n" << val[1] << "\n" << val[2];
}