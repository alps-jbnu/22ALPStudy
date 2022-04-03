#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int vis[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	fill(vis, vis + 100001, -1);

	vis[n] = 0;

	queue<int> Q;
	Q.push({ n });

	int dx = 0;


	while (vis[k] == -1)
	{
		int cur = Q.front(); Q.pop();

		dx = cur + 1;
		if (dx >= 0 && dx < 100001)
		{
			if (vis[dx] == -1)
			{
				vis[dx] = vis[cur] + 1;
				Q.push({ dx });
			}
		}

		dx = cur - 1;
		if (dx >= 0 && dx < 100001)
		{
			if (vis[dx] == -1)
			{
				vis[dx] = vis[cur] + 1;
				Q.push({ dx });
			}
		}

		dx = 2 * cur;
		if (dx >= 0 && dx < 100001)
		{
			if (vis[dx] == -1)
			{
				vis[dx] = vis[cur] + 1;
				Q.push({ dx });
			}
		}
	}

	cout << vis[k];
}

//int vis[100002];
//int n, k;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n >> k;
//
//	fill(vis, vis + 100001, -1);
//	
//	vis[n] = 0;
//	queue<int> Q;
//	Q.push({ n });
//
//	
//
//
//	while (vis[k] == -1)
//	{
//		int cur = Q.front(); Q.pop();
//		for (int dx : {cur + 1, cur - 1, 2 * cur})
//		{
//			if (dx < 0 || dx > 100000) continue;
//			if (vis[dx] != -1) continue;
//			vis[dx] = vis[cur] + 1;
//			Q.push(dx);
//		}
//	}
//
//	cout << vis[k];
//}
