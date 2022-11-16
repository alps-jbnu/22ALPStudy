#include <iostream>
using namespace std;

int num;
int board[130][130];
int paper[2];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void recur(int x, int y, int z) {
	if (check(x, y, z)) {
		paper[board[x][y]] += 1;
		return;
	}
	int n = z / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			recur(x + i * n, y + j * n, n);
		}
	}
}


int main(void)
{
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> board[i][j];
		}
	}

	recur(0, 0, num);
	cout << paper[0] << "\n" << paper[1];
}
