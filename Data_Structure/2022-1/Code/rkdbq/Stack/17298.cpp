#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> A;
int arr[1000001];
int ans[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		cin >> arr[i];
	}
	for (int i{ N - 1 }; i >= 0; i--) {
		while (!A.empty()) {
			if (arr[i] < A.top()) {
				ans[i] = A.top();
				A.push(arr[i]);
				break;
			}
			else A.pop();
		}
		if(A.empty()) ans[i] = -1, A.push(arr[i]);
	}
	for (int i{}; i < N; i++) {
		cout << ans[i] << " ";
	}
}