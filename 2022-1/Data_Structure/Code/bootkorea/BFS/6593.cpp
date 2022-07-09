#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 30 + 1;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int df[6] = { 0, 0, 0, 0, 1, -1 };

int L, R, C;
int Block[MAX][MAX][MAX];
char ch[MAX][MAX][MAX];
bool Visited[MAX][MAX][MAX];

pair<pair<int, int>, int> S, E;

int BFS(int f, int y, int x)
{
    memset(Visited, 0, sizeof(Visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    q.push({ {f, y}, {x, 0} });
    Visited[f][y][x] = 1;

    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (a == E.first.first && b == E.first.second && c == E.second)
        {
            return cnt;
        }

        for (int i = 0; i < 6; i++)
        {
            int nf = a + df[i];
            int ny = b + dy[i];
            int nx = c + dx[i];

            if (0 <= nf && nf < L && 0 <= ny && ny < R && 0 <= nx && nx < C)
            {
                if (!Visited[nf][ny][nx] && !Block[nf][ny][nx])
                {
                    Visited[nf][ny][nx] = 1;
                    cnt++;
                    q.push({{nf, ny}, {nx, cnt}});
                }
            }
        }
        
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (1)
    {
        memset(Block, 0, sizeof(Block));

        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> ch[i][j][k];

                    if (ch[i][j][k] == 'S')
                    {
                        S.first.first = i;
                        S.first.second = j;
                        S.second = k;
                    }
                    else if (ch[i][j][k] == '#') Block[i][j][k] = 1;
                    else if (ch[i][j][k] == 'E')
                    {
                        E.first.first = i;
                        E.first.second = j;
                        E.second = k;
                    }
                }
            }
        }
        int result = BFS(S.first.first, S.first.second, S.second);

        if (result == -1) cout << "Trapped!" << "\n";
        else cout << "Escaped in " << result << " minute(s).";
    }
    return 0;
}
