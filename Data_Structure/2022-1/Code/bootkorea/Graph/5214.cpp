#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
const int MAX = 100000 + 1;
const int HYPE = 1000;
using namespace std;

int N, K, M;
int Stat[MAX + HYPE];
vector<int> vec[MAX + HYPE];

int BFS()
{
    queue<int> q;
    q.push(1);
    Stat[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == N) return Stat[N];

        for (int i = 0; i < vec[cur].size(); i++)
        {
            int node = vec[cur][i];

            if (Stat[node] == 0)
            {
                if (node > N) Stat[node] = Stat[cur];
                else Stat[node] = Stat[cur] + 1;

                q.push(node);
            }
        }
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> M;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int x;
            cin >> x;
            
            vec[x].push_back(i + N);
            vec[N + i].push_back(x);
        }
    }

    cout << BFS();

    return 0;
}