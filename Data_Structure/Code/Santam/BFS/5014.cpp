#include <iostream>
#include <queue>

using namespace std;

int vis[1000001];

int main()
{
	queue<int> q;
	bool fin_chk = false;
	int f, s, g, u, d,res=0;
	int d_h[2];
	cin >> f >> s >> g >> u >> d;
	vis[s] = 1;
	vis[g] = -1;
	d_h[0] = u;
	d_h[1] = -d;
	q.push(s);
	if (s == g) fin_chk = true;
	while (!q.empty()&&!fin_chk)
	{
		int cur = q.front(); q.pop();
		for (int dir = 0;dir < 2;dir++)
		{
			int nh = cur + d_h[dir];
			if (nh<1 || nh>f) continue;
			if (vis[nh] > 0) continue;
			if (vis[nh] == -1)
			{
				res = vis[cur];
				fin_chk = true;
				break;
			}
			vis[nh] = vis[cur] + 1;
			q.push(nh);
		}
	}

	if (fin_chk) cout << res;
	else cout << "use the stairs";

	return 0;
}

/*
bfs 최단거리 구하기 유형에서 차원을 1차원으로 바꾸면 된다고 생각
*/