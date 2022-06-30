#include <iostream>
#include <stack>
using namespace std;

int K;
stack<int> num;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for (int i{}; i < K; i++) {
		int input;
		cin >> input;
		if (input == 0) num.pop();
		else num.push(input);
	}
	while (!num.empty()) {
		sum += num.top();
		num.pop();
	}
	cout << sum;
}