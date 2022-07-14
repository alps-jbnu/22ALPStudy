#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (; q.size() != 1;) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}