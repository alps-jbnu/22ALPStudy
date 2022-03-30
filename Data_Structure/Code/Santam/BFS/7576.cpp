#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int vis[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	queue<pair<int, int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	bool dont_fin_all = false,fin_already=true;
	int n, m, day=-1;
	cin >> m >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> board[j][i];
			if (board[j][i]==1)  q.push({ j,i });
			if (board[j][i]==0)
			{
				vis[j][i] = -1;
				fin_already = false;
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny]>=0) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (vis[j][i]==-1)
			{
				dont_fin_all = true;
			}
			if (vis[j][i] > day) day = vis[j][i];
		}
	}

	if (dont_fin_all||fin_already)
	{
		if (fin_already) cout << 0;
		else cout << -1;
	}
	else cout << day;

	return 0;
}

/*
처음에 토마토 상자에 익은 토마토가 여러개 일 수 있으므로 입력 받을 때 익은 토마토를 미리 큐에 넣어줘야 된다고 생각+토마토가 전부 익는 시간은 거리문제에서 봐왔던 최소 거리 찾는 문제랑 같음(큐의 FIFO성질 이용)
1. vis에 만약, 덜 익은 토마토가 들어온다면, 토마토가 없는 공간과 구분하기 위해 -1로 입력 --> 나중에 몇일이 지나도 안익은 토마토가 존재하는지의 여부 판단을 위해
2. vis배열 속 원소는 익은 토마토로 부터의 거리(거리 1은 시간 1일과 같은 의미)를 의미하므로 거리문제와 비슷하게 cur의 vis원소 +1만큼을 새로운 vis[nx][ny]에 저장
3. 큐에서의 모든 작업이 종료되고 남은 토마토에 안익은 토마토가 존재하는 지 여부 체크(vis배열 원소의 -1체크)와 함께 vis배열 속 최대값 찾기(다 익을 때까지 걸린 최대 일수)
*/