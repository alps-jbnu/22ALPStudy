#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
char board[55][55];
int board_dis[55][55];
bool board_vis[55][55];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, S;
vector<pair<int, int>> Key;
int Key_Number[55][55];
vector< pair<int, int> > adj[255];

void find_distance(int start_first, int start_second)
{
	for (int i = 0; i < 55; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			board_dis[i][j] = -1;
		}
	}

	queue<pair<int, int>> Q;
	Q.push({ start_first , start_second });
	board_dis[start_first][start_second] = 1;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board_dis[nx][ny] >= 0 || board[nx][ny] == '1') continue;
			if (board[nx][ny] == 'K')
			{
				adj[Key_Number[nx][ny]].push_back({ board_dis[cur.first][cur.second], Key_Number[start_first][start_second] });
				adj[Key_Number[start_first][start_second]].push_back({ board_dis[cur.first][cur.second], Key_Number[nx][ny] });
			}
			board_dis[nx][ny] = board_dis[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board_dis[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
}

bool chk[10005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int Key_Num = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'S' || board[i][j] == 'K')
			{
				Key.push_back({ i, j });
				Key_Number[i][j] = Key_Num++;
			}
		}
	}

	for (int i = 0; i < Key.size(); i++)
	{
		find_distance(Key[i].first, Key[i].second);
	}
	
	chk[1] = 1;

	priority_queue< tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;
	for (auto nxt : adj[1])
		pq.push({ nxt.first, 1, nxt.second });

	int cnt = 0;
	int ans = 0;

	while (cnt < M && !pq.empty()) {
		int a, b, c;
		tie(c, a, b) = pq.top(); pq.pop();

		if (chk[b]) continue;

		chk[b] = 1;
		ans = ans + c;
		cnt++;

		for (auto nxt : adj[b])
		{
			if (!chk[nxt.second])
				pq.push({ nxt.first, b, nxt.second });
		}
	}

	if (cnt == M)
		cout << ans;
	else
		cout << -1;
}