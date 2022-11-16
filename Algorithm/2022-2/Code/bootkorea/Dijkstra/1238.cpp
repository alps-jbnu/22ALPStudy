#include <bits/stdc++.h>
const int INF = 100000 + 1;
using namespace std;

int N, M, X;
int d[1001];
int result[1001];
vector<pair<int, int>> vec1[1001];
vector<pair<int, int>> vec2[1001];

void Dijkstra(int start, vector<pair<int, int>> arr[1001])
{
	for (int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
	d[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int poor = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (d[poor] < distance)
		{
			continue;
		}

		for (int i = 0; i < arr[poor].size(); i++)
		{
			int next = arr[poor][i].first;
			int nextdist = arr[poor][i].second + distance;

			if (d[next] > nextdist)
			{
				d[next] = nextdist;
				pq.push({ -nextdist, next });
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		result[i] += d[i];
	}
}

int main()
{
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec1[a].push_back({ b, c });
		vec2[b].push_back({ a, c });
	}

	Dijkstra(X, vec1);
	Dijkstra(X, vec2);

	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		if (max < result[i])
		{
			max = result[i];
		}
	}
	cout << max;

	return 0;
}