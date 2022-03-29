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
#define X first
#define Y second
int board[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	

	while (k--)
	{
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;

		for (int i = ay; i < by; i++)
		{
			for (int j = ax; j < bx; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	
	vector<int> V;
	 // 각 영역의 넓이 
	//board[i][j] = 0 의 개수를 구하는 것!!!

	int num = 0; //영역의 개수
	
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && vis[i][j] == 0)
			{
				num++;
				Q.push({ i, j });
				vis[i][j] = 1;
				int area = 1;

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] > 0 || board[nx][ny] == 1) continue;

						vis[nx][ny] = 1;

						Q.push({ nx, ny });
						area++;
					}
				}

				V.push_back(area);
			}
		}
	}

	cout << num << endl;

	sort(V.begin(), V.end());

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}

}