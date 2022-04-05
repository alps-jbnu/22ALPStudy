#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[105];
int V_K[105];           // 사람당 케빈 베이컨 수
int vis[105];
int n;                // 사람의 번호
int m;                // 간선의 수(친구관계의 수)


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}




	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vis[j] = -1;
		}

		queue<int> Q;
		Q.push(i);
		vis[i] = 0;

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			for (auto nxt : V[cur])
			{
				if (vis[nxt] == -1)
				{
					vis[nxt] = vis[cur] + 1;
					Q.push(nxt);
				}

			}
		}

		for (int j = 1; j <= n; j++)
		{
			V_K[i] = V_K[i] + vis[j];
		}
		V_K[i] = V_K[i] - vis[i];


		

		

	}

	int mn = 100000000;

	for (int j = 1; j <= n; j++)
	{
		mn = min(mn, V_K[j]);
	}

	for (int j = 1; j <= n; j++)
	{
		if (V_K[j] == mn)
		{
			cout << j;
			return 0;
		}
	}
	
}