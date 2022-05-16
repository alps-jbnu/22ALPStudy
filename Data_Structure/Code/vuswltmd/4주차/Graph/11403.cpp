#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[105];
int vis[105];
int board[105][105];
int n;               
int m;                


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;

			if(x==1)
			V[i].push_back(j);
		}
	}


	for (int i = 1; i <= n; i++)
	{
		queue<int> Q;
		Q.push(i);

		for (int j = 1; j <= n; j++)
		{
			vis[j] = -1;
		}

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			for (auto nxt : V[cur])
			{
				if (vis[nxt] != -1) continue;
				vis[nxt] = 0;
				board[i][nxt] = 1;
				//cout << "i: " << i << " nxt: " << nxt << endl;
				Q.push(nxt);
			}
		}

	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

}