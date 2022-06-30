#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		int t;
		cin >> t;

		int sum = 0;

		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			pq.push(x);
		}

		while(pq.size() > 1)
		{
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();

			sum = sum + a + b;
			pq.push(a + b);
		}

		cout << sum << '\n';
	}

	
}