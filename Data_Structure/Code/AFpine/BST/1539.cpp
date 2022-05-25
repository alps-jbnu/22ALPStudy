#include <bits/stdc++.h>

//1539 이진 검색 트리

using namespace std;

const int MAX = 250005;

int N,root;
int P[MAX];
int depth[MAX];
set<int> S;
set<int,greater<int>> rS;
long long result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        cin>>P[i];
    }
    
    S.insert(P[1]);
    rS.insert(P[1]);
    depth[P[1]] = 1;

    for(int i = 2;i<=N;++i)
    {
        auto it1 = S.lower_bound(P[i]);
        auto it2 = rS.lower_bound(P[i]);

        if(it1 == S.end())
        {
            depth[P[i]] = depth[(*it2)] + 1;
        }
        else if(it2 == rS.end())
        {
            depth[P[i]] = depth[(*it1)] + 1;
        }
        else
        {
            depth[P[i]] = max(depth[(*it2)], depth[(*it1)]) + 1;
        }
        S.insert(P[i]);
        rS.insert(P[i]);
    }

    for(int i = 0;i<N;++i)
    {
        result += depth[i];
    }
    
    cout<<result;

    return 0;
}