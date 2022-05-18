#include <iostream>
#include <cmath>
using namespace std;

int N, R, C, cnt;
void func(int r, int c, int n) {
	if (n == 0) {
		cout << cnt;
		return;
	}
	int nextN = n - 1;
	if (R <= r - pow(2, nextN) && C <= c - pow(2, nextN)) {
		func(r - pow(2, nextN), c - pow(2, nextN), nextN);
	}
	else if (R <= r - pow(2, nextN) && C >= c - pow(2, nextN)) {
		cnt += pow(4, nextN);
		func(r - pow(2, nextN), c, nextN);
	}
	else if (R >= r - pow(2, nextN) && C <= c - pow(2, nextN)) {
		cnt += 2 * pow(4, nextN);
		func(r, c - pow(2, nextN), nextN);
	}
	else if (R >= r - pow(2, nextN) && C >= c - pow(2, nextN)) {
		cnt += 3 * pow(4, nextN);
		func(r, c, nextN);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> C;
	func(pow(2, N) - 1, pow(2, N) - 1, N);
	//cout << cnt;
	return 0;
}