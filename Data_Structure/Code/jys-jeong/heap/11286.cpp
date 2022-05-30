#include<bits/stdc++.h>
using namespace std;



struct cmp {
	bool operator()(int x, int y) {
		if (abs(x) == abs(y)) {
			return x > y;
		}
		else {
			return abs(x) > abs(y);
		}
	}
};
priority_queue<int, vector<int>, cmp> q;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
			
		}
		else {
			q.push(x);
		}
	}
}