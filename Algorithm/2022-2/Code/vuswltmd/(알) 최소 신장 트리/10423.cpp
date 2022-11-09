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
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[1005];
vector<int> baljeon;
double v[1005];
bool chk[1005];
double ans = 0;
int cnt = 0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		baljeon.push_back(num);
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	priority_queue<tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;
	
	for (int i = 0; i < baljeon.size(); i++)
	{
		//cout << "baljeon[i]: " << baljeon[i] << '\n';
		chk[baljeon[i]] = 1;
		cnt++;

		for (auto nxt : adj[baljeon[i]])
		{
			pq.push({ nxt.first, baljeon[i], nxt.second });
		}
	}

	while (cnt < n )
	{
		int a, b, cost;
		tie(cost, a, b) = pq.top(); pq.pop();

		if (chk[b]) continue;

		chk[b] = 1;
		cnt++;
		ans += cost;

		for (auto nxt : adj[b])
		{
			if (!chk[nxt.second])
			{
				pq.push({ nxt.first, b, nxt.second });
			}
		}
	}

	cout << ans << '\n';


}
