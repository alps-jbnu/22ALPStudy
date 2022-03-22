#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> S, S2;
int H[80001];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> H[i];
	}
	for (int i{ N - 1 }; i >= 0; i--) {
		int cnt{ 1 };
		while (!S.empty()) {
			if (H[i] > S.top()) {
				ans += S2.top();
				cnt += S2.top();
				S.pop();
				S2.pop();

			}
			else {
				S.push(H[i]);
				S2.push(cnt);
				break;
			}
		}
		if (S.empty()) {
			S.push(H[i]);
			S2.push(cnt);
		}
	}
	cout << ans;
}