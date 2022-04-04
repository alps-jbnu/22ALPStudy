#include <bits/stdc++.h>

//13913 Hide and Seek 4

using namespace std;

static const int INF = 100000000;

bool visited[200001];
int dist[200001];
int pre[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,K;
    queue<int> q;
    stack<int> results;
    int resulti;

    cin>>N>>K;

    for(int i = 0;i<=2*N;++i)
    {
        visited[i] = false;
        pre[i] = -1;
        dist[i] = INF;
    }

    q.push(N);
    visited[N] = true;
    dist[N] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == K)
        {
            break;
        }
        if(cur+1 <= 100000 && visited[cur+1] == false)
        {
            visited[cur+1] = true;
            dist[cur+1] = dist[cur] + 1;
            pre[cur+1] = cur;
            q.push(cur+1);
        }
        if(cur-1 >= 0 && visited[cur-1] == false)
        {
            visited[cur-1] = true;
            dist[cur-1] = dist[cur] + 1;
            pre[cur-1] = cur;
            q.push(cur-1);
        }
        if(cur*2 <= 200000 && visited[cur*2] == false)
        {
            visited[cur*2] = true;
            dist[cur*2] = dist[cur] + 1;
            pre[cur*2] = cur;
            q.push(cur*2);
        }
    }

    cout<<dist[K]<<'\n';
    
    while(K != -1)
    {
        results.push(K);
        K = pre[K];
    }
    while(!results.empty())
    {
        cout<<results.top()<<" ";
        results.pop();
    }


    return 0;
}