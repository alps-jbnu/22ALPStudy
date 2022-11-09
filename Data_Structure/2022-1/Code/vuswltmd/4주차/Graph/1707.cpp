#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

vector<int> adj[20001];
bool vis[20001];
int color[20001];

int main()
{	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;

	while (t--)
	{
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < e; i++)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		for (int i = 1; i <= v; i++)
		{
			if (vis[i] != 0) continue; // 방문했다면 넘어간다.
			
			vis[i] = 1; 
			color[i] = 1; //방문하지 않았으면 1을 칠한다
		
			queue<int> q;
			q.push(i);

			while (!q.empty())
			{
				int cur = q.front(); q.pop();

				for (auto nxt : adj[cur])
				{
					if (vis[nxt] != 0)
					{
						continue;
					}
					
					q.push(nxt);
					vis[nxt] = 1;

					if (color[cur] == 1) color[nxt] = 2;
					else if (color[cur] == 2) color[nxt] = 1;
				}
			}
		}
		/// <summary>
		/// 여기까진 문제 없어보임
		/// </summary>
		/// <returns></returns>

		bool torf = false;

		for (int i = 1; i <= v; i++)
		{
			for (int j = 0; j < (int)(adj[i].size()); j++)
			{
				int next = adj[i][j];
				if (adj[i][j] == 0)
				{
					continue;
				}
				if (color[i] == color[next])
				{
					torf = true;
				}

				//cout << i << ":" << color[i] << " " << next << ":" << color[next] << '\n';

			}
		}

		if (torf == true)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}

		
		for (int i = 0; i < v; i++)
		{
			vis[i] = false;
			color[i] = 0;
		}

		for (int i = 1; i <= v; i++)
		{
			for (int j = 0; j < (int)adj[i].size(); j++)
			{
				adj[i][j] = 0;
			}
		}
	}

}