#include <bits/stdc++.h>

using namespace std;
vector<long> top;
long arr[500001];

int main(void) {
	long n;
	cin >> n;
	vector<long>::iterator iter;
	for (int i = 0; i < n; i++) {
		long a;
		cin >> a;
		top.push_back(a);
	}
	stack<int> st;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() < top[i]) {
			st.pop();
		}

		if (st.empty()) {
			arr[i] = 0;
		}
		else {
			iter = find(top.begin(), top.end(), st.top());
			arr[i] = distance(top.begin(), iter) + 1;
		}
		st.push(top[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}