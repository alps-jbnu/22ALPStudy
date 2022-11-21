//#include <bits/stdc++.h>
//
//int board[2500][2500];
//int count_minus, count_zero, count_plus;
//int flag[2500][2500];
//
//void paper(int n, int x, int y) {
//	if (n == 0) return;
//
//	for (int i = x; i < x + n - 1; i++) {
//		for (int j = y; j < y + n - 1; j++) {
//			if (board[i][j] != board[i + 1][j] || board[i][j] != board[i][j + 1] || board[i][j] != board[i + 1][j + 1])
//				flag[x][y] = 1;
//		}
//	}
//	if (flag[x][y] == 0) {
//		if (board[x][y] == 1)
//			count_plus++;
//		if (board[x][y] == 0)
//			count_zero++;
//		if (board[x][y] == -1)
//			count_minus++;
//		return;
//	}
//
//	if (flag[x][y] == 1) {
//		flag[x][y] = 0;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				paper(n / 3, n / 3 * i + x, n / 3 * j + y);
//			}
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
//		for (int j = 0; j < n; j++) 
//			std::cin >> board[i][j];
//
//	paper(n, 0, 0);
//	std::cout << count_minus << "\n";
//	std::cout << count_zero << "\n";
//	std::cout << count_plus << "\n";
//	return 0;
//}