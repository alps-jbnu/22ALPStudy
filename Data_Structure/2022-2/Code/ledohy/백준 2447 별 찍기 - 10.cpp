//#include <bits/stdc++.h>
//char board[2189][2189];
//
//void star(int n, int x, int y) {
//	/*if (n == 3) {
//		for (int i = x; i < x + n; i++) {
//			for (int j = y; j < y + n; j++) {
//				board[i][j] = '*';
//			}
//		}
//		board[x + 1][y + 1] = ' ';
//		return;
//	}*/
//	if (n == 1) {
//		board[x][y] = '*';
//		return;
//	}
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (i == 1 && j == 1) continue;
//			else
//				star(n / 3, n / 3 * i + x, n / 3 * j + y);
//		}
//	}
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	for (int i = 0; i < n; i++)
//		std::fill(board[i], board[i] + n, ' ');
//	star(n, 0, 0);
//	for (int i = 0; i < n; i++) {
//		//for (int j = 0; j < n; j++)
//			std::cout << board[i];
//		std::cout << "\n";
//	}
//	return 0;
//}