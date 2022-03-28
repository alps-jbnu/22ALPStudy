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

string board[27];
int vis[27][27];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int num = 0; // 단지 수;
	vector<int> V;
	
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vis[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '1' && vis[i][j] == -1)
			{
				num++;
				vis[i][j] = 1;
				Q.push({ i, j });

				int house_num = 1; // 단지 내 집의 수
				while (!Q.empty())
				{
					

					pair<int, int> cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] == '0' || vis[nx][ny] != -1) continue;

						house_num++;
						vis[nx][ny] = 1;
						Q.push({ nx, ny });

					}
				}

				V.push_back(house_num);
			}
		}
	}

	sort(V.begin(), V.end());

	cout << num << "\n";

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << "\n";
	}
}