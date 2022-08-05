#include<iostream>
#include<queue>
#include<utility>

using namespace std;
#define x first
#define y second

int board[502][502] = {};
bool dist[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	int num = 0, mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || dist[i][j])continue;
			num++;//그림의 수
			queue<pair<int, int>> Q;
			dist[i][j] = 1;
			Q.push({ i,j });
			int area = 0;
			while (!Q.empty())
			{
				area++;//크기
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (dist[nx][ny] || board[nx][ny] != 1)
						continue;
					dist[nx][ny] = 1;
					Q.push({ nx,ny });
				}mx = max(mx, area);
			}
			
		}
			
		
	}
	cout << num << "\n" << mx;

	return 0;
}