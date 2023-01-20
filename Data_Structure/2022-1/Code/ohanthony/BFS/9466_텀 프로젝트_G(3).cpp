#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool vis[100005];
int student[100005];
bool isCycle[100005];

int result;

void dfs(int node)
{
    vis[node] = true;
    int nxt = student[node];

    if (!vis[nxt])
        dfs(nxt);
    else
    {
        if (!isCycle[nxt])
        {
            for (int i = nxt; i != node; i = student[i])
            {
                result++;
            }
            result++; // 본인을 선택한 경우
        }
    }
    isCycle[node] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        fill(&vis[0], &vis[100004], false);
        fill(&student[0], &student[100004], 0);
        fill(&isCycle[0], &isCycle[100004], false);
        result = 0;

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> student[i];

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;

            dfs(i);
        }

        cout << n - result << '\n';
    }
    return 0;
}