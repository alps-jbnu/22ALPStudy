#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	stack<long long> val;
	stack<int> idx;

	long long arr[80000];
	long long ans = 0; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >= 0; i--) {
		while (!val.empty()) {
			if (arr[i] > val.top()) {
				val.pop();
				idx.pop();
			}
			else {
				ans += idx.top() - i - 1;
				val.push(arr[i]);
				idx.push(i);
				break;
			}
		}

		if (val.empty()) {
			ans += n - i - 1;
			val.push(arr[i]);
			idx.push(i);
		}
	}

	cout << ans;

}
