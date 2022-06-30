#include <iostream>
#include <stack>

using namespace std;
int main(void) {
	int k;
	int sum = 0;
	cin >> k;
	stack<int> st;
	int	num;
	while (k--) {
		cin >> num;
		if (num == 0) {
			st.pop();
		}
		else {
			st.push(num);
		}
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}