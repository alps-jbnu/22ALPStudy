#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int n,t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		long long ans=0;
		priority_queue<long long,vector<long long>, greater<long long>> q;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1) {
			long long a = q.top(); q.pop();
			long long b = q.top(); q.pop();
			ans += a + b;
			q.push(a + b);
		}
		
		cout << ans<<"\n";
	}
    
}