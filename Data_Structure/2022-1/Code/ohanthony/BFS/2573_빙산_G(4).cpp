#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;

int iice[303][303];
int ice[303][303];
bool vis[303][303];

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    vis[x][y] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int water = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (ice[nx][ny] != 0 && !vis[nx][ny])
                {
                    q.push({ nx, ny });
                    vis[nx][ny] = true;
                }
            }
        }
    }
}

int melt(int x, int y)
{
    int cnt = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (ice[nx][ny] == 0)
            cnt++;
    }
    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/vsCode_C++/input.txt", "r", stdin);
    freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }

    int year = 0; // 몇년 걸렸는지
    while (1)
    {
        int count = 0; // 빙산이 2개 이상으로 나누어져 있는지 판별하는 변수
        fill(&vis[0][0], &vis[302][303], false);
        fill(&iice[0][0], &iice[302][303], 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ice[i][j] != 0 && !vis[i][j])
                {
                    count++;
                    bfs(i, j);
                }
            }
        }

        if (count >= 2)
        {
            cout << year;
            break;
        }
        if (count == 0)
        {
            cout << 0;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ice[i][j] != 0)
                {
                    iice[i][j] = ice[i][j] - melt(i, j);
                    if (iice[i][j] < 0)
                        iice[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ice[i][j] = iice[i][j];
            }
        }
        year++;
    }
    return 0;
}