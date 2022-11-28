//#include <bits/stdc++.h>
//
//int board[130][130];
//int cut_flag[130][130];
//int color;
//int paper = 1;
//
//void color_paper(int n, int x, int y) {
//	if (n == 1) {
//		if (board[x][y] == 1)
//			color++;
//		return;
//	}
//	for (int i = x; i < x + n - 1; i++) {
//		for (int j = y; j < y + n - 1; j++) {
//			if (board[i][j] != board[i + 1][j] || board[i][j] != board[i][j + 1] || board[i][j] != board[i + 1][j + 1]) {
//				cut_flag[x][y] = 1;
//				break;
//			}
//		}
//		if (cut_flag[x][y] == 1) break;
//	}
//	if (cut_flag[x][y] == 0) {
//		if (board[x][y] == 1)
//			color++;
//		return;
//	}
//	if (cut_flag[x][y] == 1) {
//		cut_flag[x][y] = 0;
//		paper += 3;
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				color_paper(n / 2, n / 2 * i + x, n / 2 * j + y);
//			}
//		}
//	}
//		
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			std::cin >> board[i][j];
//		}
//	}
//
//	color_paper(n, 0, 0);
//	std::cout << paper - color << "\n";
//	std::cout << color << "\n";
//	return 0;
//}