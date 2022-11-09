#include <bits/stdc++.h>
#include <stack>
using namespace std;
int ans[1000001];
int seq[1000001];
stack<int> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= seq[i]) {
			s.pop();
		}
		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(seq[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}