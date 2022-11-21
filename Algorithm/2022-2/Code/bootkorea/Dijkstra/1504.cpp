#include <bits/stdc++.h>
#define MAX 800 + 1
#define INF 987654321
using namespace std;

int N, E;
int arr[MAX];
vector<pair<int, int>> vec[MAX];

vector<int> Solve(int s, int v)
{
	vector<int> dist(v, INF);
	dist[s] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < cost) continue;

		for (int i = 0; i < vec[curr].size(); i++)
		{
			int x = vec[curr][i].first;
			int xdist = cost + vec[curr][i].second;

			if (dist[x] > xdist)
			{
				dist[x] = xdist;
				arr[x] = curr;
				pq.push({ xdist, x });
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;
	N++;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b, c });
		vec[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> result = Solve(1, N);
	vector<int> temp1 = Solve(v1, N);
	vector<int> temp2 = Solve(v2, N);

	int ans = min({ (result[v1] + temp1[v2] + temp2[N - 1]), (result[v2] + temp2[v1] + temp1[N - 1]) });

	if (ans >= INF || ans < 0) cout << -1;
	else cout << ans;

	return 0;
}