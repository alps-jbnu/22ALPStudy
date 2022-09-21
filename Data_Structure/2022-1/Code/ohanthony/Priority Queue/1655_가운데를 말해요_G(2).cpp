#include<bits/stdc++.h>
using namespace std;

int n, mid1, mid2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	// 핵심은 두 큐의 차이가 1이 넘지 않도록 유지해 max의 top값을 중간값으로 만든다.
	priority_queue<int, vector<int>, greater<int> > min; 
	priority_queue<int, vector<int>> max; 

	while (n--) {
		int num;
		cin >> num;

		// 최대힙의 크기는 항상 최소힙의 크기보다 같거나 1만큼 더 크다
		if (max.size() == min.size()) max.push(num);
		else min.push(num);

		// 최소힙의 top()값이 항상 최대힙의 top() 값보다 항상 같거나 커야한다.
		if (!max.empty() && !min.empty() && max.top() > min.top()) {
			int a = max.top();
			int b = min.top();

			max.pop();
			min.pop();

			max.push(b);
			min.push(a);
		}
		cout << max.top() << "\n";
	}

	return 0;
} 