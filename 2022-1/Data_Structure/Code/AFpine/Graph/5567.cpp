#include <bits/stdc++.h>

using namespace std;

int wedding[501][501];
int relation[501];
bool check[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;
    int n1,n2;
    int result=0;
    queue<int> q;

    cin>>n>>m;
    
    for(int i = 0;i<m;++i)
    {
        cin>>n1>>n2;
        wedding[n1][n2] = 1;
        wedding[n2][n1] = 1;
    }

    q.push(1);
    relation[1] = 0;
    check[1] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 1;i<=n;++i)
        {
            if(wedding[now][i] == 1 && check[i] == false)
            {
                check[i] = true;
                relation[i] = relation[now] + 1;
                q.push(i);
            }
        }
    }

    for(int i = 2;i<=n;++i)
    {
        if(relation[i] == 1 || relation[i] == 2)
        {
            ++result;
        }
    }
    
    cout<<result<<"\n";

    return 0;
}