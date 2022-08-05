#include <bits/stdc++.h>

//1068 트리

using namespace std;

const int MAX = 51;

int N;
int root;
int parent[MAX];
vector<int> adj[MAX];
int eraseNode;

int countLeafs(int cur)
{
    if(cur == eraseNode)
    {
        return 0;
    }
    if(adj[cur].size() == 0)
    {
        return 1;
    }
    else if(adj[cur].size() == 1 && adj[cur][0] == eraseNode)
    {
        return 1;
    } 

    int res = 0;
    for(auto &e : adj[cur])
    {
        if(e == eraseNode)
        {
            continue;
        }
        res += countLeafs(e);
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 0;i<N;++i)
    {
        int p;
        cin>>p;
        parent[i] = p;
        if(p != -1)
        {
            adj[p].push_back(i);
        }
        else
        {
            root = i;
        }
    }

    cin>>eraseNode;
    adj[eraseNode].clear();

    cout<<countLeafs(root);

    return 0;
}