#include <iostream>
#include <string>
using namespace std;

int arr[65][65];

void func(int x, int y, int n) {
	if (n == 1) {
		cout << arr[x][y];
		return;
	}

	int a = arr[x][y];
	int flag = 1;

	for (int i = 0; i < n; i++) {
		if (flag == -1) break;
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] != a) {
				flag = -1;
				break;
			}
		}
	}

	if (flag == -1) {
		cout << "(";
		n /= 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(x + n * i, y + n * j, n);
			}
		}
		cout << ")";
	}
	else if (flag == 1) {
		cout << arr[x][y];
	}

	return;
}

int main(void) {
	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	func(0, 0, n);

	return 0;
}