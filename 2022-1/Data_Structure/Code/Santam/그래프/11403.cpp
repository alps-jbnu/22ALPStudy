#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[101][101] = { 0 };
int vis[101][101] = { 0 };

int main()
{
	queue<pair<int,int>> q;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> board[j][i];
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (board[j][i])
			{
				vis[j][i] = 1;
				q.push({ j,i });
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int k = 1;k <= n;k++)
					{
						if (board[cur.second][k] != 1) continue;
						if (vis[cur.first][k] != 0) continue;
						vis[cur.first][k] = 1;
						board[cur.first][k] = 1;
						q.push({ cur.first,k });
					}					
				}
				memset(vis, 0, sizeof(int) * 101 * 101);
			}
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cout << board[j][i]<<" ";
		}
		cout << "\n";
	}
	return 0;
}

/*
이 문제 예제 중 (1,3),(2,1),(3,2)와 같은 간선이 주어질 때, 반복적으로 1,3과3,2가 만나 1,2가 되면 board에 1,2좌표를 저장하는 방식으로 가면 되겠다고 생각
1. board에 입력 값을 전부 넣고, 반복문을 돌려 1이 나오는 좌표가 생길 때마다 bfs를 돌려주었다.
2. bfs를 돌릴 때 나오는 새로운 좌표들에 대해 board에 정보를 업데이트해줘야 다음 bfs가 시작할 때, 그 새로운 좌표에 대한 경로도 반영할 수 있다고 판단
==> vis방문을 표시하면서 board에도 표시
3. bfs가 끝날 때, 다음 bfs를 돌리기 위해 vis를 0으로 초기화
==> 이거 안하면, 다음 방문한 bfs는 경로를 탐색할 수 없게 됨
*/