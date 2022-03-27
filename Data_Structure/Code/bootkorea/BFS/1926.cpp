#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 500 + 1
using namespace std;

queue<pair<int, int>> q;
int arr[MAX][MAX];
bool Visited[MAX][MAX];

int N, M;
int cnt, result = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 , 0, 1, -1 };

void BFS(int x, int y)
{
    int area = 1;

    Visited[x][y] = 1;
    q.push({ x, y });

    while (!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (!Visited[nx][ny] && arr[nx][ny])
            {
                Visited[nx][ny] = 1;
                q.push({ nx, ny });
                area++;
            }
        }
    }
    result = max(area, result);
}


int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] && !Visited[i][j])
            {
                BFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << result;
    return 0;
}
