#include<bits/stdc++.h>
using namespace std;

class compare {
public:
	bool operator() (int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, compare> pq;
	int n;
	cin >> n;

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
