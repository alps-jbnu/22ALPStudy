#include <bits/stdc++.h>

using namespace std;

stack<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if (a == 0)S.pop();
		else S.push(a);
	}
	int t = 0;
	for (int i = 0; i < k; i++) {
		if (S.empty()) break;
		t += S.top();
		S.pop();
	}
	cout << t;

	return 0;
}