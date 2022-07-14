#include <bits/stdc++.h>

using namespace std;

const int MAX = 600000;
int buildings[MAX];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}

	stack<int> st;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() <= buildings[i]) {
			st.pop();
		}
		st.push(buildings[i]);
		sum += st.size() - 1;
	}
	cout << sum;
}