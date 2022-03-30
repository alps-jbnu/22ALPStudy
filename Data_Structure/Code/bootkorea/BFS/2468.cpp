#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100 + 1;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, cnt = 0, result = 0;
int arr[MAX][MAX];
int temp[MAX][MAX];
bool Visited[MAX][MAX];

vector<int> vec;

void DFS(int y, int x)
{
    Visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < N && 0 <= nx && nx < N)
        {
            if (temp[ny][nx] && !Visited[ny][nx])
            {
                DFS(ny, nx);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    result = 1;

    for (int depth = 1; depth <= MAX; depth++)
    {
        memset(Visited, 0, sizeof(Visited));
        memset(temp, 0, sizeof(Visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] > depth) temp[i][j] = arr[i][j];
            }
        }

        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!Visited[i][j] && temp[i][j])
                {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        result = max(result, cnt);
    }

    cout << result;

    return 0;
}
