#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[20005];
int vis[20005];
int n;               
int m;                


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		V[y].push_back(x);
		V[x].push_back(y);
	}

	for (int j = 1; j <= n; j++)
	{
		vis[j] = -1;
	}
		
	queue<int> Q;
	Q.push(1);
	vis[1] = 0;
	int dist = 0; //최대거리 저장

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		for (auto nxt : V[cur])
		{
			if (vis[nxt] == -1)
			{
				vis[nxt] = vis[cur] + 1; 
				
				if (dist < vis[nxt])
				{
					dist = vis[nxt];
				}
				
				Q.push(nxt);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist == vis[i])
		{
			cout << i << " ";
			break;
		}
	}

	cout << dist << " ";

	int num = 0; // 최대거리를 갖는 헛간과 같은 거리를 가지는 헛간의 개수

	for (int i = 1; i <= n; i++)
	{
		if (dist == vis[i])
		{
			num++;
		}
	}

	cout << num;
}