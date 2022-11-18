//#include <bits/stdc++.h>
//
//char board[70][70];
//int div_flag[70][70];
//
//void quid_tree(int n, int x, int y) {
//	for (int i = x; i < x + n - 1; i++) {
//		for (int j = y; j < y + n - 1; j++) {
//			if (board[i][j] != board[i + 1][j] || board[i][j] != board[i][j + 1] || board[i][j] != board[i + 1][j + 1]) {
//				div_flag[x][y] = 1;
//				break;
//			}
//		}
//		if (div_flag[x][y] == 1) break;
//	}
//
//	if (div_flag[x][y] == 0) {
//		if (board[x][y] == '1')
//			std::cout << 1;
//		if (board[x][y] == '0')
//			std::cout << 0;
//		return;
//	}
//	if (div_flag[x][y] == 1) {
//		if (n == 2) {
//			std::cout << "(";
//			for (int i = x; i < x + n; i++)
//				for (int j = y; j < y + n; j++)
//					std::cout << board[i][j];
//			std::cout << ")";
//			return;
//		}
//		div_flag[x][y] = 0;
//		std::cout << "(";
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				quid_tree(n / 2, n / 2 * i + x, n / 2 * j + y);
//			}
//		}
//		std::cout << ")";
//	}
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	//int temp_index;
//	//for (int i = 0; i < n; i++) {
//	//	std::cin >> temp_index;
//	//	for (int j = n - 1; j >= 0; j--) {
//	//		board[i][j] = temp_index % 10;
//	//		temp_index /= 10;
//	//	}
//	//}
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			std::cin >> board[i][j];
//	quid_tree(n, 0, 0);
//	return 0;
//}