#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>> pq;

	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}
