#include <iostream>
using namespace std;

int N;
bool starMap[3073][6145];

void star(int topX, int topY, int leftX, int leftY, int rightX, int rightY, int n) {
	if (n == 3) {
		for (int i{}; i < 3; i++) {
			starMap[topX + i][topY - i] = true;
			starMap[topX + i][topY + i] = true;
		}
		for (int i{ leftY }; i <= rightY; i++) {
			starMap[leftX][i] = true;
		}
		//cout << topX << ", " << topY << ", " << leftX << ", " << leftY << ", " << rightX << ", " << rightY << ", " << n <<"\n";
		return;
	}

	//cout << topX << ", " << topY << ", " << leftX << ", " << leftY << ", " << rightX << ", " << rightY << ", " << n << "\n";

	int nxtN = n / 2;
	star(topX, topY, leftX - nxtN, leftY + nxtN, rightX - nxtN, rightY - nxtN, nxtN);
	star(topX + nxtN, topY - nxtN, leftX, leftY, rightX, rightY - 2 * nxtN, nxtN);
	star(topX + nxtN, topY + nxtN, leftX, leftY + 2 * nxtN, rightX, rightY, nxtN);
}
void print() {
	for (int i{}; i < N; i++) {
		for (int j{}; j < 2 * N; j++) {
			if (starMap[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	star(0, N - 1, N - 1, 0, N - 1, 2 * (N - 1), N);
	print();
	return 0;
}