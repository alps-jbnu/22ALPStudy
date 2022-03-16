#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> S, sumH;
int H[80001];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> H[i];
	}
	for (int i{N - 1}; i >= 0; i--) {
		int cnt{ 1 };
		while (!S.empty()) {
			if (H[i] > S.top()) {
				ans += sumH.top();
				cnt += sumH.top();
				S.pop();
				sumH.pop();
				
			}
			else {
				S.push(H[i]);
				sumH.push(cnt);
				break;
			}
		}
		if (S.empty()) {
			S.push(H[i]);
			sumH.push(cnt);
		}
	}
	cout << ans;
}