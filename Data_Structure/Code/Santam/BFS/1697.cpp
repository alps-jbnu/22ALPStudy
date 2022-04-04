#include <iostream>
#include <queue>

using namespace std;

int vis[100000];

int main()
{
	queue<int> q;
	bool fin_chk = false;
	int d_x[2] = { 1,-1 };
	int n, k;
	cin >> n >> k;
	vis[n] = 1;
	vis[k] = -1;
	if (n == k)
	{
		fin_chk = true;
		cout << 0;
	}
	q.push(n);
	while (!q.empty()&&!fin_chk)
	{
		int cur = q.front(); q.pop();
		for (int dir = 0;dir < 3;dir++)
		{
			if (dir == 2)
			{
				int nx = cur*2;
				if (nx < 0 || nx>100000) continue;
				if (vis[nx] > 0) continue;
				if (vis[nx] == -1)
				{
					fin_chk = true;
					cout << vis[cur];
					break;
				}
				vis[nx] = vis[cur] + 1;
				q.push(nx);
			}
			else
			{
				int nx = cur + d_x[dir];
				if (nx < 0 || nx>100000) continue;
				if (vis[nx] > 0) continue;
				if (vis[nx] == -1)
				{
					fin_chk = true;
					cout << vis[cur];
					break;
				}
				vis[nx] = vis[cur] + 1;
				q.push(nx);
			}
		}
	}
	return 0;
}