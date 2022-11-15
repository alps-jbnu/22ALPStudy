#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int MAX = 1000 + 1;
using namespace std;

int N, M, K;
bool Visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
priority_queue<int> heap[MAX];
vector<pii> vec[MAX];

void Dijkstra()
{
    pq.push({ 0, 1 }); heap[1].push(0);

    while (!pq.empty())
    {
        int coscos = pq.top().first;
        int temp = pq.top().second;
        pq.pop();

        for (int i = 0; i < vec[temp].size(); i++)
        {
            int next = vec[temp][i].first;
            int cost = coscos + vec[temp][i].second;

            if (heap[next].size() < K)
            {
                heap[next].push(cost);
                pq.push({ cost, next });
            }
            else
            {
                if (heap[next].top() > cost)
                {
                    heap[next].pop();
                    heap[next].push(cost);
                    pq.push({ cost, next });
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        vec[a].push_back({ b, c });
    }

    Dijkstra();

    for (int i = 1; i <= N; i++)
    {
        if (heap[i].size() < K) cout << "-1\n";
        else cout << heap[i].top() << "\n";
    }

    return 0;
}