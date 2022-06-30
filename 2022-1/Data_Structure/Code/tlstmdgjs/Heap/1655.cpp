#include<bits/stdc++.h>
using namespace std;

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		priority_queue<int, vector<int>, greater<int>> min_pq;	//최솟값 구하는 최소힙
		priority_queue<int, vector<int>> max_pq;	//최대값 구하는 최대힙
		
		int n,x;
		cin >> n;

		while (n--) {
			cin >> x;

			if (max_pq.empty())
				max_pq.push(x);
			else if (max_pq.size() == min_pq.size())
				max_pq.push(x);
			else
				min_pq.push(x);

			if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
				int a = max_pq.top();
				int b = min_pq.top();

				max_pq.pop();
				min_pq.pop();

				max_pq.push(b);
				min_pq.push(a);
			}

			cout << max_pq.top()<<"\n";
		}
	}