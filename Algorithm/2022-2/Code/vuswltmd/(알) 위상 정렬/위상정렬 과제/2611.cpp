#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> adj[10005];
vector<int> ans;
int deg[10005];
int dp[10005];
vector<int> route[1001];
//int pre[10005];
int N;
int M;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;

		adj[p].push_back({ q, r });
		deg[q]++;
	}

	queue<int> q;
	q.push(1);
	route[1].push_back(1);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (auto nxt : adj[cur])
		{
			int a = nxt.first;
			int b = nxt.second;

			//dp[a] = max(dp[a], dp[cur] + b);
			if (dp[a] < dp[cur] + b)
			{
				dp[a] = dp[cur] + b;
				route[a] = route[cur];
				route[a].push_back(a);
				//pre[a] = cur;
			}

			deg[a]--;

			if (deg[a] == 0)
			{
				q.push(a);
			}
		}
	}

	cout << dp[1] << '\n';
	for (int i = 0; i < route[1].size(); i++) {
		cout << route[1][i] << " ";
	}

	//ans.push_back(1);
	//int num = 1;

	//while (1)
	//{
	//	ans.push_back(pre[num]);
	//	if (pre[num] == 1)
	//	{
	//		break;
	//	}
	//	num = pre[num];
	//}

	//reverse(ans.begin(), ans.end());

	//for (auto a : ans)
	//{
	//	cout << a << ' ';
	//}
}



