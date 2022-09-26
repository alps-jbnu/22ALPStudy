#include <bits/stdc++.h>
const int MAX = 10000 + 1;
using namespace std;

int N, result = 0;
int delay[MAX], temp[MAX], indegree[MAX];
queue<int> q;
vector<int> vec[MAX];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		cin >> a >> b;
		temp[i] = delay[i] = a;

		if (b != 0)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> c;
				vec[c].push_back(i);
				indegree[i]++;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (q.empty()) return 0;
	}

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		for (int next : vec[num])
		{
			if (delay[next] < temp[next] + delay[num])
			{
				delay[next] = temp[next] + delay[num];
			}

			indegree[next]--;

			if (!indegree[next]) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (result < delay[i]) result = delay[i];
	}

	cout << result;

	return 0;
}