#include <bits/stdc++.h>

using namespace std;

vector<int> v[32001];
int connect[32001];
bool vis[32001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A,B; cin >> A >> B;
        v[A].push_back(B);
        connect[B]++;
    }
    set<int> st;
    queue<int> q;
    for(int i =1 ; i<= N;i++)
    {
        if(!connect[i])
        {
            st.insert(i);
            vis[i] = true;
        }
    }
    if(!st.empty())
    {
        q.push(*(st.begin()));
        st.erase(st.begin());
    }
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int i = v[cur].size()-1; i >= 0; i--)
        {
            connect[v[cur][i]]--;
            if(!connect[v[cur][i]])
            {
                st.insert(v[cur][i]);
            }
            vis[v[cur][i]] = true;
        }
        if(!st.empty())
        {
            q.push(*(st.begin()));
            st.erase(st.begin());
        }
    }
    for(int i = 1; i <= N;i++)
    {
        if(vis[i]) continue;
        cout << i << ' ';
    }
    return 0;
}
