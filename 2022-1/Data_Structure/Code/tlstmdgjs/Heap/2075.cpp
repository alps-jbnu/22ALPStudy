#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			pq.push(x);
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top();
}