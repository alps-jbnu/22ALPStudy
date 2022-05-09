#include <iostream>
#include <cmath>
using namespace std;

int N, mtrx[2200][2200];
int ans[3];

void printAns() {
	cout << ans[2] << "\n";
	cout << ans[0] << "\n";
	cout << ans[1] << "\n";
}
bool isSameNum(int r, int c, int n) {
	int cnt[3]{};
	for (int i{ r }; i < r + n; i++) {
		for (int j{ c }; j < c + n; j++) {
			if (mtrx[i][j] == 1) cnt[1]++;
			else if (mtrx[i][j] == 0) cnt[0]++;
			else cnt[2]++;
		}
	}
	for (int i{}; i < 3; i++) {
		if (cnt[i] == n * n) {
			ans[i]++;
			return true;
		}
	}
	return false;
}
void rec(int r, int c, int n) {
	if (isSameNum(r, c, n)) return;
	else
	{
		n /= 3;
		for (int i{}; i < 3; i++) {
			for (int j{}; j < 3; j++) {
				rec(r + i * n, c + j * n, n);
			}
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cin >> mtrx[i][j];
		}
	}
	rec(0, 0, N);
	printAns();
	return 0;
}