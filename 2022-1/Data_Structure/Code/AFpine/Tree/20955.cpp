#include <bits/stdc++.h>

//20955 민서의 응급 수술

using namespace std;

const int MAX = 100001;

int N,M;
int p[MAX];
bool selected[MAX];
set<int> S;
int cnt = 0;


int find(int a)
{
    if(p[a] < 0)
    {
        return a;
    }
    p[a] = find(p[a]);
    return p[a];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        return;
    }
    p[b] = a;
}

void init()
{
    for(int i = 0;i<MAX;++i)
    {
        p[i] = -1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();

    cin>>N>>M;
    
    for(int i = 1;i<=M;++i)
    {
        int u,v;
        cin>>u>>v;
        if(find(u) != find(v))
        {
            merge(u,v);
        }
        else
        {
            cnt++;
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(S.find(find(i)) == S.end())
        {
            S.insert(find(i));
        }
    }

    cout<<cnt+S.size()-1;

    return 0;
}