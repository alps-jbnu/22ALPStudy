#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 50 + 1;
const int INF = 1e9;
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int N, M, result = 0;
vector<int> parents;
vector<pii> vec;
vector<string> maze;

int Find(int x)
{
	if (x == parents[x]) return parents[x];
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y)
{
	x = Find(x), y = Find(y);

	if (x > y) parents[x] = y;
	else parents[y] = x;
}

bool is_reachable(int x, int y)
{
	if (maze[x][y] == '1') return false;
	else return true;
}

int BFS(int x, int y, int a, int b)
{
	vector<vector<int> > d;
	vector<int> temp;
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++) temp.push_back(INF);
	for (int i = 0; i < N; i++) d.push_back(temp);

	d[x][y] = 0;
	q.push({ x, y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (!is_reachable(nx, ny)) continue;

			if (d[cx][cy] + 1 < d[nx][ny])
			{
				d[nx][ny] = d[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return d[a][b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vec.push_back({ -1, -1 });
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		maze.push_back(str);

		for (int j = 0; j < N; j++)
		{
			if (str[j] == 'K') vec.push_back({ i, j });
			else if (str[j] == 'S') vec[0] = { i, j };
		}
	}

	vector<pair<int, pii>> nodedist;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			int temp = BFS(vec[i].first, vec[i].second, vec[j].first, vec[j].second);

			if (temp == INF) continue;
			nodedist.push_back({ temp, { i, j } });
		}
	}
	sort(nodedist.begin(), nodedist.end());

	for (int i = 0; i < vec.size(); i++)
	{
		parents.push_back(i);
	}

	for (auto& it : nodedist)
	{
		if (Find(it.second.first) != Find(it.second.second))
		{
			Union(it.second.first, it.second.second);
			result += it.first;
		}
	}

	bool flag = 1;
	for (auto& it : parents)
	{
		if (it != 0)
		{
			cout << -1;
			flag = false;
			break;
		}
	}
	if (flag) cout << result;

	return 0;
}