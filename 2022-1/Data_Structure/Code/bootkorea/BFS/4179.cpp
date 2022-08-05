#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1000;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

pair<int, int> p; // start
vector<pair<int, int>> vec; // fire
queue<pair<int, int>> q1; // 사람 이동 방향
queue<pair<int, int>> q2; // 불 퍼지는 방향

int cnt, R, C, result = 0;
string st[MAX];
bool Visited[MAX][MAX];

int BFS()
{
    q1.push(p);
    for (int i = 0; i < vec.size(); i++)
    {
        q2.push(vec[i]);
    }
    result = 0;

    while (!q1.empty())
    {
        int size = q2.size();
        for (int i = 0; i < size; i++)
        {
            int y = q2.front().first;
            int x = q2.front().second;
            q2.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 < ny && ny < R && 0 < nx && nx < C)
                {
                    if (st[ny][nx] == '.' || st[ny][nx] == 'J')
                    {
                        st[ny][nx] = 'F';
                        q2.push({ ny, nx });
                    }
                }
            }
        }
        size = q1.size();
        for (int i = 0; i < size; i++)
        {
            int y = q1.front().first;
            int x = q1.front().second;
            q1.pop();

            if (y == 0 || y == R - 1 || x == 0 || x == C - 1) return result + 1;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 < ny && ny < R && 0 < nx && nx < C && !Visited[ny][nx])
                {
                    if (st[ny][nx] == '.')
                    {
                        Visited[ny][nx] = 1;
                        q1.push({ ny, nx });
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> st[i];

        for (int j = 0; j < st[i].size(); j++)
        {
            if (st[i][j] == 'J') p = { i, j };
            else if (st[i][j] == 'F') vec.push_back({ i, j });
        }
    }
    result = BFS();

    if (result == -1) cout << "IMPOSSIBLE\n";
    else cout << result << "\n";

    return 0;
}
