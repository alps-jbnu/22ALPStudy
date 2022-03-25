#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

bool visited[1000001];
int dist[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int F,S,G,U,D;
    queue<int> q;

    cin>>F>>S>>G>>U>>D;

    for(int i = 0;i<=1000000;++i)
    {
        dist[i] = INF;
    }

    dist[S] = 0;
    visited[S] = true;
    q.push(S);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        if(now == G)
        {
            break;
        }

        if(now-D >= 1 && visited[now-D] == false)
        {
            visited[now-D] = true;
            dist[now-D] = dist[now] + 1;
            q.push(now-D);
        }
        if(now+U <= F && visited[now+U] == false)
        {
            visited[now+U] = true;
            dist[now+U] = dist[now] + 1;
            q.push(now + U);
        }
    }

    if(dist[G] == INF)
    {
        cout<<"use the stairs\n";
    }
    else
    {
        cout<<dist[G]<<"\n";
    }
    

    return 0;
}