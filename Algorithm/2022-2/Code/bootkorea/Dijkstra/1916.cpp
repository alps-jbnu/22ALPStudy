#include <bits/stdc++.h>
#define MAX 100001
#define INF 987654321
using namespace std;

int N, M, start, endit;
int arr[1001];
vector<pair<int, int>> vec[MAX];

void Dijkstra(int start)
{
	arr[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ arr[start], start });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		// 이미 담긴 것보다 distance가 크면 패스
		if (arr[current] < distance)
		{
			continue;
		}
		// 선택한 노드의 모든 인접 노드 파악
		for (int i = 0; i < vec[current].size(); i++)
		{
			int next = vec[current][i].first;
			int nextdist = vec[current][i].second + distance;

			if (arr[next] > nextdist)
			{
				arr[next] = nextdist;
				pq.push({ -nextdist, next });
			}
		}
	}
}

int main()
{
	//
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arr[i] = INF;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b, c });
	}

	cin >> start >> endit;
	//

	Dijkstra(start);

	cout << arr[endit];

	return 0;
}