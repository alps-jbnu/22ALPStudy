#include <bits/stdc++.h>
const int MAX = 1000 + 1;
const int INF = 1e9;
using namespace std;

int N, M;
int arr[MAX][MAX];
int path[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        arr[s][e] = w;
        arr[e][s] = w;
        path[s][e] = e;
        path[e][s] = s;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!path[i][j]) cout << "- ";
            else cout << path[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}