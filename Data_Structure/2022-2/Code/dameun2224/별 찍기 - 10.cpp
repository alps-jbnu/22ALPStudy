#include <iostream>
using namespace std;

char arr[6600][6600];

// 27,
void func(int x, int y, int n) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}

	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) arr[x + n + k][y + n + l] = ' ';
				}
				continue;
			}
			func(x + i * n, y + j * n, n);
		}
	}

	return;
}

int main(void) {
	int n;
	cin >> n;

	func(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}