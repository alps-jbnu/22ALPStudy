#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100 + 1;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int M, N, K, cnt;
int arr[MAX][MAX];
bool Visited[MAX][MAX];

vector<int> vec;

void DFS(int y, int x)
{
    Visited[y][x] = 1;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < M && 0 <= nx && nx < N)
        {
            if (arr[ny][nx] == 0 && !Visited[ny][nx])
            {
                DFS(ny, nx);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                arr[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0 && !Visited[i][j])
            {
                cnt = 0;
                DFS(i, j);
                vec.push_back(cnt);
            }
        }
    }
    cout << vec.size() << "\n";

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
