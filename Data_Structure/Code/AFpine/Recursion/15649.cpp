#include <bits/stdc++.h>

// 15649 N과 M (1)

using namespace std;

static const int INF = 1000000000;

int N,M;
bool check[9];
int result[8];

void recursion(int m)
{
    if(m == M)
    {
        for(int i = 0;i<M;++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i = 1;i<=N;++i)
    {
        if(check[i] == false)
        {
            check[i] = true;
            result[m] = i;
            recursion(m+1);
            check[i] = false;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M;

    recursion(0);

    return 0;
}