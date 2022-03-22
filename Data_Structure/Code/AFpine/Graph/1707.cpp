#include <bits/stdc++.h>

using namespace std;

struct Vertex
{
    vector<int> edge;
};

int visited [20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int TC;
    int V,E;
    int a,b;
    bool bipartite;
    cin>>TC;

    for(int t = 0;t<TC;++t)
    {
        for(int i = 1;i<=20000;++i)
        {
            visited[i] = 0;
        }
        bipartite = true;

        cin>>V>>E;

        vector<Vertex> v(V+1);
        queue<int> q;

        for(int i = 0;i<E;++i)
        {
            cin>>a>>b;
            v[a].edge.push_back(b);
            v[b].edge.push_back(a);
        }

        q.push(1);
        visited[1] = 1;
        while(!q.empty())
        {
            int now = q.front();
            int setnum = visited[now];
            q.pop();

            for(auto x : v[now].edge)
            {
                if(visited[x] == 0)
                {
                    if(setnum == 1)
                    {
                        visited[x] = 2;
                    }
                    else
                    {
                        visited[x] = 1;
                    }
                    q.push(x);
                }
                else if(visited[x] == setnum)
                {
                    bipartite = false;
                    break;
                }
            }
        }

        while(true)
        {
            bool flag = true;
            for(int i = 1;i<=V;++i)
            {
                if(visited[i] == 0)
                {
                    flag = false;
                    q.push(i);
                    visited[i] = 1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            while(!q.empty())
            {
                int now = q.front();
                int setnum = visited[now];
                q.pop();

                for(auto x : v[now].edge)
                {
                    if(visited[x] == 0)
                    {
                        if(setnum == 1)
                        {
                            visited[x] = 2;
                        }
                        else
                        {
                            visited[x] = 1;
                        }
                        q.push(x);
                    }
                    else if(visited[x] == setnum)
                    {
                        bipartite = false;
                        break;
                    }
                }
            }
        }

        if(bipartite)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
    return 0;
}