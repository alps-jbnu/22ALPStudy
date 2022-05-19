#include<iostream>
#include<queue>
#include<utility>
#define x first
#define y second
using namespace std;


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int x, y, t, num;

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		int board[52][52] = {0,};
		bool dist[52][52] = {0,};
		int count = 0;
		cin >> x >> y >> num;
		while (num--)
		{
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (board[i][j] == 1 && dist[i][j] == 0)
				{
					count++;
					queue<pair<int, int>> Q;
					dist[i][j] = 1;
					Q.push({ i,j });
					while (!Q.empty())
					{
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.x + dx[dir];
							int ny = cur.y + dy[dir];
							if (nx<0 || nx>=x || ny<0 || ny>=y)	continue;
							if (dist[nx][ny] || board[nx][ny]==0)	continue;
							dist[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}
			}

		}
		cout << count << "\n";
	}

}