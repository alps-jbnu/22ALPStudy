#include <bits/stdc++.h>

using namespace std;
stack<pair<int, int>> st;
int top[600000];
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long>::iterator iter;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		top[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.top().second < top[i]) {
			st.pop();
		}

		if (st.empty()) {
			cout << 0 << ' ';
		}
		else {
			cout << st.top().first << ' ';
		}
		st.push({ i,top[i] });
	}

}