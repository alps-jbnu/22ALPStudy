#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int N;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + N);

	pq.push(p[0].second);

	for (int i = 1; i < N; i++)
	{
		if (pq.top() <= p[i].first)
		{
			pq.pop();
			pq.push(p[i].second);
		}
		else
		{
			pq.push(p[i].second);
		}
	}

	cout << pq.size() << "\n";
	return 0;
}