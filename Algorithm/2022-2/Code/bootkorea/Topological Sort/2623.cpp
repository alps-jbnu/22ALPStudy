#include <bits/stdc++.h>
const int MAX = 1000 + 1;
using namespace std;

int N, M;
int indegree[MAX];
vector<int> vec[MAX], result;

void Solve()
{
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		result.push_back(n);

		for (int i = 0; i < vec[n].size(); i++)
		{
			int next = vec[n][i];
			indegree[next]--;

			if (!indegree[next]) q.push(next);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int cnt, next, num;
		cin >> cnt;

		cin >> next;
		for (int j = 1; j < cnt; j++)
		{
			cin >> num;
			vec[next].push_back(num);
			indegree[num]++;
			next = num; // next turn
		}
	}

	Solve();

	if (result.size() != N)
	{
		cout << 0 << "\n";
		return 0;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			cout << result[i] << "\n";
		}
	}



	return 0;
}