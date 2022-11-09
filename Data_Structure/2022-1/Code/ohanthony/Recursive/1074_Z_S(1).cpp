#include<bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0; // base condition

	int halfNum = 1 << (n - 1); // 2^2n = 2^n * 2^n을 활용

	// 제 1사분면
	if (r < halfNum && c < halfNum) return func(n - 1, r, c);

	// 제 2사분면
	if (r < halfNum && c >= halfNum) return halfNum * halfNum + func(n - 1, r, c - halfNum);
	
	// 제 3사분면
	if (r >= halfNum && c < halfNum) return 2 * halfNum * halfNum + func(n - 1, r - halfNum, c);

	// 제 4사분면
	if (r >= halfNum && c >= halfNum) return 3 * halfNum * halfNum + func(n - 1, r - halfNum, c - halfNum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	cout << func(n, r, c);
	return 0;
}