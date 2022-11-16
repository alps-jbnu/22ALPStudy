#include <bits/stdc++.h>
const int INF = 1e9;
const int MAX = 100000 + 1;
using namespace std;

int V, E; // 정점 V, 간선 E
int K; // 시작 정점 번호
int result[MAX];
vector<pair<int, int>> vec[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;

		vec[u].push_back({ v, w }); // u<->v(거리 w) 데이터를 저장
	}

	for (int i = 1; i <= V; i++)
	{
		result[i] = INF; // result(정점 간 최단 이동거리)
	}

	// solve
	priority_queue<pair<int, int>> pq; // 사실 queue 써도 상관 없을 듯
	// 시간 초과 방지법으로 사용! 나중엔 그냥 queue로만 해볼 것
	pq.push({ 0, K }); // 거리, 시작점 순으로 pair 입력
	result[K] = 0;

	while (!pq.empty())
	{
		int Cost = -pq.top().first;
		int Far = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[Far].size(); i++)
		{
			int next = vec[Far][i].first; // 같은 간선에 여러 데이터 존재 가능
			int nextcost = vec[Far][i].second;

			if (result[next] > Cost + nextcost) // INF보다 간선 길이 총합이 더 크면
			{
				result[next] = Cost + nextcost; // 총합 수정
				pq.push({ -result[next], next }); // 난 왜 아직도 - 붙이는지 모르겠다
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (result[i] == INF)
		{
			cout << "INF" << "\n";
		}
		else cout << result[i] << "\n";
	}

	return 0;
}