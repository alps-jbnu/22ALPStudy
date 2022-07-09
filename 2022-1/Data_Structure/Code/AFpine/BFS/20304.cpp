#include <bits/stdc++.h>

// 20304 Password Product (Bitmask, BFS)

// update 220412

using namespace std;

static const int INF = 1e9+1;

int adminpw[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    int trypw;
    queue<int> Q;
    int result = -1;

    cin>>N>>M;

    for(int i = 0;i<=N;++i)
    {
        adminpw[i] = INF;
    }
    for(int i = 0;i<M;++i)
    {
        cin>>trypw;
        adminpw[trypw] = 0;
        Q.push(trypw);
    }

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for(int i = 0;i<=19;++i)
        {
            int x = (1<<i) ^ cur;

            if(x<=N && adminpw[cur]+1 < adminpw[x])
            {
                adminpw[x] = adminpw[cur]+1;
                Q.push(x);
            }
        }
    }

    for(int i = 0;i<=N;++i)
    {
        if(adminpw[i] != INF && adminpw[i] > result)
        {
            result = adminpw[i];
        }
    }

    cout<<result;
    
	return 0;
}