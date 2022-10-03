#include <bits/stdc++.h>

using namespace std;
int N[1000000];
int NGE[1000000];
stack<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> N[i];

	for (int i = n - 1; i >= 0; i--) {
		while (!S.empty() && S.top() <= N[i]) S.pop();
		if (S.empty())
			NGE[i] = -1;
		else
			NGE[i] = S.top();
		S.push(N[i]);
	}
	for (int i = 0; i < n; i++) cout << NGE[i] << ' ';

	return 0;
}