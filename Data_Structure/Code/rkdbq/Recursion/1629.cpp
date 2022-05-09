#include <iostream>
using namespace std;

long long A, B, C, ans{ 1 };
long long halfB;

long long product(long long num) {
	if (num == 1) {
		return A % C;
	}
	long long val{ product(num / 2) };
	val = val * val % C;
	if (num % 2 == 0) return val;
	else return val * A % C;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A >> B >> C;
	cout << product(B);
	return 0;
}