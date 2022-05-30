#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
long long ans = 0;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	for (int i = 0; i < n-1; i++) {
		int a1, a2;
		a1 = q.top();
		q.pop();
		a2 = q.top();
		q.pop();
		ans += a1 + a2;
		q.push(a1 + a2);
	}
	cout << ans;
}