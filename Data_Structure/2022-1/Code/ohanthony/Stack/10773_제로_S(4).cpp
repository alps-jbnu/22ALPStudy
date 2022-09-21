#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	stack<int> s;
	while (k--) {
		int num;
		cin >> num;

		if (!s.empty() && num == 0) s.pop();
		else s.push(num);
	}

	int count = 0;
	while (!s.empty()) {
		count += s.top();
		s.pop();
	}

	cout << count;
	return 0;
}