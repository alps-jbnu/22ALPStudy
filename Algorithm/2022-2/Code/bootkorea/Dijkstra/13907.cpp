#include <bits/stdc++.h>
#define ll unsignelong long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tiii tuple<int, int, int>
const int MAX = 1000 + 1;
const int INF = 1e9;
using namespace std;

int N, M, K;
int S, D, result = INF, tax = 0;
int arr[MAX][MAX];
vector<pii> vec[MAX];

void Dijkstra()
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= MAX; j++)
			arr[i][j] = INF;

	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	pq.push({ 0, S, 0 });
	arr[S][0] = 0;

	while (!pq.empty())
	{
		int cost, cur, len; tie(cost, cur, len) = pq.top();
		pq.pop();

		if (arr[cur][len] < cost || len >= N) continue;

		for (auto it : vec[cur])
		{
			int dest = it.first;
			int temp = it.second;

			if (arr[dest][len + 1] >= temp + cost)
			{
				arr[dest][len + 1] = temp + cost;
				pq.push({ arr[dest][len + 1], dest, len + 1 });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	cin >> S >> D;
	S--; D--;
	for (int i = 0; i < M; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		vec[a - 1].push_back({ b - 1, w });
		vec[b - 1].push_back({ a - 1, w });
	}
	Dijkstra();

	for (int i = 1; i < N; i++)
	{
		result = min(result, arr[D][i]);
	}
	cout << result << "\n";

	while (K--)
	{
		result = INF;
		int t; cin >> t; tax += t;

		for (int j = 1; j < N; j++)
		{
			result = min(result, arr[D][j] + tax * j);
		}
		cout << result << "\n";
	}

	return 0;
}