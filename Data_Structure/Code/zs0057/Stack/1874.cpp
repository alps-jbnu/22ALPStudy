#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	stack<int> st;
	string ans;
	int cnt = 1;

	while (n--) {
		int num;
		cin >> num;
		if (num >= cnt) {
			for (int i = cnt; i <= num; i++) {
				st.push(i);
				cnt++;
				ans += '+';
			}
		}
		else {
			if (st.top() < num) {
				cout << "NO";
				return 0;
			}
		}
		st.pop();
		ans += '-';
		
	}
	for (char c : ans) {
		cout << c << '\n';
	}
}