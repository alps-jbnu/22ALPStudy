#include <iostream>
using namespace std;

int N, K, S, Y;
int boy[7], girl[7];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i{}; i < N; i++) {
		cin >> S >> Y;
		if (S) {
			boy[Y]++;
		}
		else {
			girl[Y]++;
		}
	}
	for (int i{ 1 }; i < 7; i++) {
		ans += boy[i] / K;
		if (boy[i] % K) ans += 1; // 그대로 더하면 안 됨
		ans += girl[i] / K;
		if (girl[i] % K) ans += 1;
	}
	cout << ans;

	return 0;
}