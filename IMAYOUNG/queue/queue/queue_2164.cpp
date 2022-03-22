#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	//버릴 카드는 맨 위 
	//넣는 카드는 맨 아래 
	
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}