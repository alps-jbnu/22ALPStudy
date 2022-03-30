#include <iostream>
#include <queue>
using namespace std;

int board[500][500] = { 0 };
int vis[500][500] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int,int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	int cnt_paint = 0;
	int max_w = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> board[j][i];
		}
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (vis[i][j]||board[i][j]!=1) continue;
			int w_cnt = 0;
			vis[i][j] = 1;
			q.push({ i,j });
			cnt_paint++;
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				w_cnt++;
				for (int dir = 0;dir < 4;dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			if (w_cnt > max_w) max_w = w_cnt;
		}
	}
	cout << cnt_paint << "\n" << max_w;
	return 0;
}

/*
바킹독의 기본 BFS구현 예제를 응용
1. 먼저 도화지에 있는 그림의 수와 최대 넓이를 구해야되므로 각각을 저장할 변수 cnt_paint와 max_w설정
2. 각 그림마다 그림의 넓이를 구하기 위해 스택에 있는 좌표를 하나씩 pop할때마다 넓이를 1씩 올려줌
3. 큐가 비었을때 더이상 탑색할 좌표가 없으므로, 그 직후에 넓이를 기존의 최대 넓이와 비교
4. 그림의 수를 알기 위해 방문했는지에 따른 조건을 걸어 이중 반복문으로 시작점을 전부 탐색하고 시작점이 지정될때마다 그림의 수를 카운트해줌
*/