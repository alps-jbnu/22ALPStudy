#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

int member[51][51];
bool visited[51];
int dist[51];
int president[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    int n1,n2;
    int min = INF;
    int minpres = INF;
    queue<int> Q;
    queue<int> result;

    cin>>N;

    while(true)
    {
        cin>>n1>>n2;
        if(n1 == -1 && n2 == -1)
        {
            break;
        }
        else
        {
            member[n1][n2] = 1;
            member[n2][n1] = 1;
        }
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            visited[j] = false;
            dist[j] = 0;
        }
        visited[i] = true;
        president[i] = 0;
        Q.push(i);

        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();

            if(president[i] < dist[now])
            {
                president[i] = dist[now];
            }
            for(int j = 1;j<=N;++j)
            {
                if(member[now][j] == 1 && visited[j] == false)
                {
                    visited[j] = true;
                    dist[j] = dist[now] + 1;
                    Q.push(j);
                }
            }
        }
    }
    for(int i = 1;i<=N;++i)
    {
        if(minpres > president[i])
        {
            minpres = president[i];
        }
    }
    for(int i = 1;i<=N;++i)
    {
        if(president[i] == minpres)
        {
            result.push(i);
        }
    }

    cout<<minpres<<" "<<result.size()<<"\n";
    while(!result.empty())
    {
        cout<<result.front()<<" ";
        result.pop();
    }


    return 0;
}