#include <bits/stdc++.h>

using namespace std;

bool visited[200001];
int dist[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,K;

    cin>>N>>K;

    queue<int>Q;
    Q.push(N);

    dist[N] = 0;


    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        if(now == K)
        {
            break;
        }

        if(now-1 >= 0 && visited[now-1] == false)
        {
            visited[now-1] = true;
            dist[now-1] = dist[now] + 1;
            Q.push(now-1);
        }
        if(now+1 <= 200000 && visited[now+1] == false)
        {
            visited[now+1] = true;
            dist[now+1] = dist[now] + 1;
            Q.push(now+1);
        }
        if(now*2 <= 200000 && visited[now*2] == false)
        {
            visited[now*2] = true;
            dist[now*2] = dist[now] + 1;
            Q.push(now*2);
        }
    }

    cout<<dist[K]<<"\n";

    return 0;




}