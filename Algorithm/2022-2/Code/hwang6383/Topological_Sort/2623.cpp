#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];
int connect[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= M ;i++)
    {
        int n;
        cin >> n;
        int temp;
        for(int j = 0; j < n;j++)
        {
            int k;
            cin >> k;
            if(j != 0)
            {
                v[temp].push_back(k);
                connect[k]++;
            }
            temp = k;
        }
    }
    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(!connect[i])
            q.push(i);
    vector<int> vec;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        vec.push_back(cur);
        for(int a :v[cur])
        {
            connect[a]--;
            if(!connect[a])
            {
                q.push(a);
            }
        }
    }
    if(vec.size() == N)
        for(int b : vec)
            cout << b << '\n';
    else
        cout << 0;
    return 0;
}
