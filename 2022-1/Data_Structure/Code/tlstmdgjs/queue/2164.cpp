#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int>q;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}