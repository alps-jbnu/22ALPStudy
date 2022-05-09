#include <bits/stdc++.h>

// 1992 쿼드트리

using namespace std;

static const int INF = 1000000000;

int N;
string s;
char tree[65][65];
string result;

int check(int n, int x, int y)
{
    int check = 0;
    for(int i = x;i<x+n;++i)
    {
        for(int j = y;j<y+n;++j)
        {
            if(tree[i][j] == '1')
            {
                check++;
            }
        }
    }
    if(check == 0)
    {
        return 0;
    }
    else if(check == n*n)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void quadTree(int n, int x, int y)
{
    if(n == 0)
    {
        return;
    }
    int flag = check(n,x,y);
    if(flag == 0)
    {
        result += '0';
        return;
    }
    else if(flag == 1)
    {
        result += '1';
        return;
    }
    else
    {
        result += '(';
        quadTree(n/2,x,y);
        quadTree(n/2,x,y+n/2);
        quadTree(n/2,x+n/2,y);
        quadTree(n/2,x+n/2,y+n/2);
        result += ')';
        return;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 0;i<N;++i)
    {
        cin>>s; 
        for(int j = 0;j<N;++j)
        {
            tree[i][j] = s[j];
        }
    }

    quadTree(N,0,0);
    cout<<result;

    return 0;
}