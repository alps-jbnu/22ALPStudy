#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[52];
int V_sco[52]; // 
int vis[52];
int n; // 정점의 수
int m; // 간선의 수


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	

	while (1)
	{
		int x, y;
		cin >> x >> y;
		
		if (x == -1 && y == -1)
		{
			break;
		}

		V[x].push_back(y);
		V[y].push_back(x);
	}

	
	queue<int> Q;
	int mx = 0;

	
	for (int i = 1; i <= n; i++)
	{
		Q.push(i);
		vis[i] = 1;

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			for (auto nxt : V[cur])
			{
				if (vis[nxt] != 0) continue;

				vis[nxt] = vis[cur] + 1;
				
				Q.push(nxt);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			mx = max(mx, vis[i]);
		}

		V_sco[i] = mx;

		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
		}

		mx = 0;
	}
		
	int mn = V_sco[1];

	for (int i = 2; i <= n; i++)
	{
		mn = min(mn, V_sco[i]);
	}

	vector<int> num; //후보의 수

	for(int i = 1; i <= n; i++)
	{
		if (mn == V_sco[i])
		{
			num.push_back(i);
		}
	}

	cout << mn - 1 << " " << num.size() << "\n";
	
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}

	

}