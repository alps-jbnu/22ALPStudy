#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 20000 + 1
using namespace std;

int K, V, E;
int Visited[MAX];
vector<int> vec[MAX];

void BFS(int num)
{
	queue<int> q;
	int color = 1;

	Visited[num] = 1;
	q.push(num);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (Visited[now] == 1)
		{
			color = 2;
		}
		else if (Visited[now] == 2)
		{
			color = 1;
		}

		int size = vec[now].size();
		for (int i = 0; i < size; i++)
		{
			int next = vec[now][i];

			if (!Visited[next])
			{
				Visited[next] = color;
				q.push(next);
			}
		}
	}
}

bool IsConnected()
{
	for (int i = 1; i <= V; i++)
	{
		int size = vec[i].size();

		for (int j = 0; j < size; j++)
		{
			int next = vec[i][j];

			if (Visited[i] == Visited[next])
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	cin >> K;

	while (K--)
	{
		for (int i = 0; i <= V; i++)
		{
			vec[i].clear();
		}
		memset(Visited, 0, sizeof(Visited));

		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int node1, node2;
			cin >> node1 >> node2;

			vec[node1].push_back(node2);
			vec[node2].push_back(node1);
		}

		for (int i = 1; i <= V; i++)
		{
			if (!Visited[i])
			{
				BFS(i);
			}
		}

		if (IsConnected()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}