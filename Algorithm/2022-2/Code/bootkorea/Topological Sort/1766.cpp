#include <bits/stdc++.h>
#define sync_tie ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pqg priority_queue<int, vector<int>, greater<int>>
const int MAX = 32000 + 1;
using namespace std;

int N, M;
int Indegree[MAX];
vector<int> vec[MAX];
pqg pq;

int main()
{
	sync_tie;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		Indegree[b]++;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!Indegree[i]) pq.push(i);
	}

	while (!pq.empty())
	{
		int num = pq.top();
		pq.pop();
		cout << num << " ";

		for (int next : vec[num])
		{
			if (--Indegree[next] == 0) pq.push(next);
		}
	}

	return 0;
}