#include <bits/stdc++.h>

using namespace std;

static const int INF = 100000000;

struct computer
{
    vector<int> edge;
};

int cnt[10001];
bool visited[10001];
bool checkdfs[10001];

void DFS(int start, vector<computer>& v, int i)
{
    for(auto x : v[i].edge)
    {
        if(visited[x] == false)
        {
            visited[x] = true;
            ++cnt[start];
            DFS(start,v,x);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int A,B;
    int maxhack = 0;
    vector<computer> v;
    queue<int> q;
    queue<int> result;


    cin>>N>>M;
    
    for(int i = 0;i<=N;++i)
    {
        v.push_back({});
    }

    for(int i = 0;i<M;++i)
    {
        cin>>A>>B;
        q.push(B);
        v[B].edge.push_back(A);
    }
    
    while(!q.empty())
    {
        for(int i = 0;i<=N;++i)
        {
            visited[i] = false;
        }

        int now = q.front();
        q.pop();
        
        visited[now] = true;
        if(checkdfs[now] == true)
        {
            continue;
        }
        else
        {
            DFS(now,v,now);
        }
        checkdfs[now] = true;
    }
    
    for(int i = 1;i<=N;++i)
    {
        if(maxhack < cnt[i])
        {
            maxhack = cnt[i];
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(maxhack == cnt[i])
        {
            result.push(i);
        }
    }

    while(!result.empty())
    {
        cout<<result.front()<<" ";
        result.pop();
    }

    return 0;
}