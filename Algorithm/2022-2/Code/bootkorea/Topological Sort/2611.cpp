#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 1000 + 1;
using namespace std;

int N, M;
int dp[MAX], route[MAX], indegree[MAX];
vector<pii> vec[MAX];

void Print(int x, int n)
{
    if (x == n)
    {
        cout << x << " ";
        return;
    }

    Print(route[x], n);
    cout << x << " ";
}

void Solve(int n)
{
    int temp;

    queue<int> q; q.push(n); dp[n] = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == 1 && !indegree[n]) break;

        for (int i = 0; i < vec[x].size(); i++)
        {
            int next = vec[x][i].first;
            temp = dp[x] + vec[x][i].second;

            if (temp > dp[next])
            {
                dp[next] = temp;
                route[next] = x;
            }

            if (!(--indegree[next])) q.push(next);
        }
    }

    cout << dp[n] << "\n";
    Print(route[n], n);
    cout << n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int p, q, r; cin >> p >> q >> r;

        vec[p].push_back({ q, r });
        indegree[q]++;
    }

    Solve(1);

    return 0;
}