#include <bits/stdc++.h>

//2250 트리의 높이와 너비

using namespace std;

const int MAX = 10001;

struct Node
{
    int depth = -1;
    int width = -1;
    int cntlc = 0;
    int parent = -1;
    int left = -1;
    int right = -1;
};

int N;
int root;
Node node[MAX];
int minval[MAX];
int maxval[MAX];
pair<int,int> result;

int dfs(int cur)
{
    int res = 0;
    if(node[cur].left != -1)
    {
        node[node[cur].left].depth = node[cur].depth+1;
        res += dfs(node[cur].left);
    }
    node[cur].cntlc = res;
    if(node[cur].right != -1)
    {
        node[node[cur].right].depth = node[cur].depth+1;
        res += dfs(node[cur].right);
    }
    return res+1;
}

void setwidth(int cur, int w)
{
    node[cur].width = w;
    if(node[cur].left != -1)
    {
        setwidth(node[cur].left, w - node[cur].cntlc + node[node[cur].left].cntlc);
    }
    if(node[cur].right != -1)
    {
        setwidth(node[cur].right, w + node[node[cur].right].cntlc + 1);
    }
}

void traverse(int cur)
{
    if(maxval[node[cur].depth] < node[cur].width)
    {
        maxval[node[cur].depth] = node[cur].width;
    }
    if(minval[node[cur].depth] > node[cur].width)
    {
        minval[node[cur].depth] = node[cur].width;
    }
    if(node[cur].left != -1)
    {
        traverse(node[cur].left);
    }
    if(node[cur].right != -1)
    {
        traverse(node[cur].right);
    }
}

void init()
{
    result.first = -1;
    result.second = 0;
    for(int i = 0;i<MAX;++i)
    {
        minval[i] = 1e9+1;
        maxval[i] = -1e9-1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        node[a].left = b;
        node[a].right = c;
        if(b != -1)
        {
            node[b].parent = a;
        }
        if(c != -1)
        {
            node[c].parent = a;
        }
    }  

    for(int i = 1;i<=N;++i)
    {
        if(node[i].parent == -1)
        {
            root = i;
            break;
        }
    }

    node[root].depth = 1;
    
    dfs(root);
    setwidth(root,0);
    traverse(root);

    for(int i = 1;i<=N;++i)
    {
        if(minval[i] == 1e9+1 || maxval[i] == -1e9-1)
        {
            continue;
        }
        if(maxval[i]-minval[i]+1 > result.second)
        {
            result.first = i;
            result.second = maxval[i]-minval[i]+1;
        }
    }

    cout<<result.first<<" "<<result.second;


    return 0;
}