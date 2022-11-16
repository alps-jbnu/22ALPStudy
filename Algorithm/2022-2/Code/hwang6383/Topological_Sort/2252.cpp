#include <bits/stdc++.h>

using namespace std;

vector<int> v[32001];
int connect[32001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M;i++)
    {
        int A,B;
        cin >> A >> B;
        v[A].push_back(B);
        connect[B]++;
    }
    queue<int> q;
    for(int i = 1; i <= N;i++)
        if(!connect[i])
            q.push(i);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int a : v[cur])
        {
            connect[a]--;
            if(!connect[a])
                q.push(a);
        }
    }
    return 0;
}
