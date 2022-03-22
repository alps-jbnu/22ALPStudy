#include <iostream>
#include <stack>
using namespace std;

//스택을 오름차순으로 쌓기. 
//top이 가장 작고 bottom이 가장 큼.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;

	int arr[1000001];
	int arr2[1000001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && s.top() <= arr[i])
				s.pop();

			if (s.empty()) arr2[i] = -1;
			else arr2[i] = s.top();

			s.push(arr[i]);
		}

		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
}