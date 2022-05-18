#include <iostream>
#include <cmath>
using namespace std;

int N, mtrx[65][65];

bool isSameNum(int r, int c, int n) {
	int cnt[2]{};
	for (int i{ r }; i < r + n; i++) {
		for (int j{ c }; j < c + n; j++) {
			for (int k{}; k < 2; k++) {
				if (mtrx[i][j] == k) cnt[k]++;
			}
		}
	}
	for (int i{}; i < 2; i++) {
		if (cnt[i] == n * n) {
			//if (n == N) cout << "(";
			cout << i;
			//if (n == N) cout << ")";
			return true;
		}
	}
	return false;
}
void rec(int r, int c, int n) {
	if (isSameNum(r, c, n)) return;
	else
	{
		cout << "(";
		n /= 2;
		for (int i{}; i < 2; i++) {
			for (int j{}; j < 2; j++) {
				rec(r + i * n, c + j * n, n);
			}
		}
		cout << ")";
	}
	return;
}

int main() {
	cin >> N;
	for (int i{}; i < N; i++) {
		string r;
		cin >> r;
		for (int j{}; j < N; j++) {
			mtrx[i][j] = r[j] - '0';
		}
	}
	rec(0, 0, N);
	return 0;
}