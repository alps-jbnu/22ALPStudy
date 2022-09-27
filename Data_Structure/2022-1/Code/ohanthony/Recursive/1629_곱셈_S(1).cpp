#include<bits/stdc++.h>
using namespace std;
#define ll long long

int func(int a, int b, int c) {
	if (b == 1) return a % c;

	ll num = func(a, b / 2, c); // a^2n = a^n * a^n을 이용한다.
	num = num * num % c;

	if (b % 2 == 0) return num;
	else return num * a % c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
	return 0;
}
