#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 1000 + 1;
using namespace std;

int N, M, a, b, k;
int indegree[MAX];
int dp[MAX], route[MAX];
vector<int> vec[MAX];
set<int> path;

bool MustVisit(int node)
{
	if (path.find(node) != path.end()) return 1;
	else return 0;
}

void Solve()
{
	route[a] = 1;
	queue<int> q;
	for (int i = 1; i <= N; i++) if (!indegree[i]) q.push(i);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (MustVisit(temp)) dp[temp]++;

		for (int next : vec[temp])
		{
			if (dp[next] == dp[temp]) route[next] += route[temp];
			else if (dp[next] < dp[temp])
			{
				dp[next] = dp[temp];
				route[next] = route[temp];
			}

			if (!(--indegree[next])) q.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;  cin >> u >> v;

		vec[u].push_back(v);
		indegree[v]++;
	}

	cin >> a >> b >> k;
	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		path.insert(x);
	}

	Solve();

	if (dp[b] == path.size()) cout << route[b];
	else cout << 0;

	return 0;
}