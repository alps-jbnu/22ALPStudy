#include <bits/stdc++.h>

//22856 트리 순회

using namespace std;

const int MAX = 100001;

struct Node
{
    int parent = -1;
    int left = -1, right = -1;
};

int N;
int cnt = 0;
Node node[MAX];
bool visited[MAX];
int inorderindex;
int result = 0;

void inorder(int cur)
{
    visited[cur] = true;
    if(node[cur].left != -1 && visited[node[cur].left] == false)
    {
        inorder(node[cur].left);
    }
    inorderindex = cur;
    if(node[cur].right != -1 && visited[node[cur].right] == false)
    {
        inorder(node[cur].right);
    }
}

void traverse(int cur)
{
    if(visited[cur] == false)
    {
        visited[cur] = true;
    }
    
    if(node[cur].left != -1 && visited[node[cur].left] == false)
    {
        result++;
        traverse(node[cur].left);
    }
    else if(node[cur].right != -1 && visited[node[cur].right] == false)
    {
        result++;
        traverse(node[cur].right);
    }
    else if(cur == inorderindex)
    {
        return;
    }
    else if(node[cur].parent != -1)
    {
        result++;
        traverse(node[cur].parent);
    }
}

void init()
{
    for(int i = 0;i<MAX;++i)
    {
        visited[i] = false;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    
    for(int i = 1;i<=N;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b != -1)
        {
            node[a].left = b;
            node[b].parent = a;
        }
        if(c != -1)
        {
            node[a].right = c;
            node[c].parent = a;
        }
    }

    init();
    inorder(1);

    init();
    traverse(1);

    cout<<result;

    return 0;
}