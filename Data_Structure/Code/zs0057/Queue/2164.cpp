#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	queue<int> Q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		Q.push(i);
	}
	int count = 1;
	while (!Q.empty()) {
		if (Q.size() == 1) {
			cout << Q.front();
			break;
		}
		if (count % 2 == 1) {
			Q.pop();
		}
		else if (count % 2 == 0){
			Q.push(Q.front());
			Q.pop();
		}
		count++;
		
		
	}
}