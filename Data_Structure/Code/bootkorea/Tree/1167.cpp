#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100000 + 1
using namespace std;

int V, maxDist, maxindex;
int Visited[MAX];
vector<pair<int, int>> vec[MAX];

void DFS(int idx, int cost)
{
	if (Visited[idx])
	{
		return;
	}

	Visited[idx] = true;

	if (maxDist < cost)
	{
		maxDist = cost;
		maxindex = idx;
	}

	for (int i = 0; i < vec[idx].size(); i++)
	{
		DFS(vec[idx][i].first, vec[idx][i].second + cost);
	}
}

int main()
{
	int start, end, distance;

	cin >> V; // 반복 횟수 V

	while (V--)
	{
		cin >> start; // 첫 정점 num

		while (true)
		{
			cin >> end; // 간선 end 받고
			if (end == -1)
			{
				break; // 종료조건
			}

			cin >> distance; // 종료조건 패스하면 거리 입력
			vec[start].push_back({ end, distance }); // 정점-간선 정보 데이터
		}

	}

	DFS(1, 0);

	memset(Visited, false, sizeof(Visited));

	maxDist = 0;

	DFS(maxindex, 0);

	cout << maxDist;

	return 0;
}