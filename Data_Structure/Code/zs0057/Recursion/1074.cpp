#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}
	int half = 1 << (n - 1);
	if (half > r && half > c) {
		return func(n - 1, r, c);
	}
	if (half > r && half <= c) {
		return half * half + func(n - 1, r, c - half);
	}
	if (half <= r && half > c) {
		return 2*half * half + func(n - 1, r-half, c );
	}
	if (half <= r && half <= c) {
		return 3*half * half + func(n - 1, r-half, c - half);
	}
}

int main(void) {
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}