#include <bits/stdc++.h>
const int MAX = 1e9;
using namespace std;

int N, M;
int start, destination;
int arr[1001];
vector<pair<int, int>> vec[1001];

void Dijkstra(const int& start, const int& destination) // 추적 과정
{
	vector<int> dist(N + 1, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

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

void Route(const int& start, const int& destination) // 역추적
{
	vector<int> result;
	result.push_back(destination);
	int next = destination;

	while (next != start)
	{
		next = arr[next];
		result.push_back(next);
	}
	cout << result.size() << "\n";

	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b, c });
	}

	cin >> start >> destination;

	Dijkstra(start, destination);
	Route(start, destination);

	return 0;
}