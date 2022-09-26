#include <bits/stdc++.h>

using namespace std;

stack<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long total = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		while (!S.empty() && S.top() <= h) {
			S.pop();
		}
		total += S.size();
		S.push(h);
	}
	cout << total;

	return 0;
}