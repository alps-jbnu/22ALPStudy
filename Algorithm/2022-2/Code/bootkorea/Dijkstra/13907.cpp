#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1000 + 1
#define INF 987654321
using namespace std;

int N, M, K;
int S, D, result = 0;
int arr[MAX][MAX];
vector<pair<int, int>> vec[MAX];
vector<pair<long long, long long>> Route;

void Dijkstra()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			arr[i][j] = INF;
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 1, 1 });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int dest = pq.top().second;
		pq.pop();

		if (dist[dest] < cost) continue;

		for (int i = 0; i < vec[dest].size(); i++)
		{
			int next = vec[dest][i].first;
			int nextcost = cost + vec[dest][i].second;

			if (dist[next] > nextcost)
			{
				dist[next] = nextcost;
				arr[next] = dest;
				pq.push({ nextcost, next });
			}
		}
	}
	cout << dist[destination] << "\n";
}

int main()
{
	cin >> N >> M >> K;
	cin >> S >> D;

	long long Fisrt = INF, temp = 0, num;


	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back({ b, w });
		vec[b].push_back({ a, w });
	}

	Dijkstra(First);
	cout << First << "\n";

	for (long long i = 1; i <= N; i++)
	{
		if (arr[M][i] != INF)
		{
			Route.push_back({ arr[M][i], i });
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> num;
		temp += num;

		long long res = INF;

		for (int i = 0; i < res; i++)
		{
			res = min(res, )
		}
	}

	return 0;
}