#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>s;
	long long count = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;

		if (s.empty()) {
			s.push(h);
			continue;
		}

		while (!s.empty() && s.top() <= h) {
			s.pop();
		}

		count += s.size();

		s.push(h);
	}
	cout << count;
}