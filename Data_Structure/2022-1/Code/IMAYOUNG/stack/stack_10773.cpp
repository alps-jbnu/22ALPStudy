#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> S;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			S.pop();
		}
		else {
			S.push(num);
		}
	}

	int sum = 0;

	//가장 윗 수를 더함. 더하고 위의 숫자를 계속 삭제.
	for (int i = 0; i <= k; i++) {
		sum += S.top();
		S.pop();
	}

	cout << sum;
	
}