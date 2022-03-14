#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	stack<int> tower;
	stack<int> b;
	cin >> n;
	tower.push(100000001);
	b.push(0);
	for (int i = 1; i <= n; i++) {
		int high;
		cin >> high;
		for (; tower.top() < high;) {
			tower.pop();
			b.pop();
		}
		cout << b.top() << " ";
		tower.push(high);
		b.push(i);
	}


}