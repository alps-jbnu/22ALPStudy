#include<bits/stdc++.h>
using namespace std;

// 문제 조건에서 최소 힙으로 주어졌으므로 다음과 같은 식
priority_queue<int, vector<int>, greater<int>> pq; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << 0 << "\n";
		}
		else pq.push(x);
	}
	return 0;
} 