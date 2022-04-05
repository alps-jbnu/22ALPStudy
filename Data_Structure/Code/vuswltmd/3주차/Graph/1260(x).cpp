#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
int n, m, v;
vector<int> V[1002];
int vis[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	stack<int> S;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		
		V[x].push_back(y);
		V[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(V[i].begin(), V[i].end());
	}
	
	//DFS 출력결과

	S.push({ v });

	while (!S.empty())
	{
		int cur = S.top(); S.pop();
		
		
		if (vis[cur] == 0)
		{
			vis[cur] = 1;
			cout << cur << " ";
		}
		else
		{
			continue;
		}
		

		for (int i = 0; i < V[cur].size(); i++)
		{
			int nxt = V[cur][V[cur].size() - 1 - i];
			if (vis[nxt] == 0)
			{
				S.push(nxt);
			}
		}
	}


	cout << '\n';

	//BFS 출력결과 
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
	}

	vis[v] = 1;
	Q.push({ v });

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
			
		for (auto nxt : V[cur])
		{
			if (vis[nxt] == 0)
			{
				Q.push(nxt);
				vis[nxt] = 1;
			}
		}
	}
	
}