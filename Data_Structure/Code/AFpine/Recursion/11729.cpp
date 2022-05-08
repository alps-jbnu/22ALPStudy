#include <bits/stdc++.h>

// 11729 하노이 탑 이동 순서

using namespace std;

static const int INF = 1000000000;

int N;
vector<pair<int,int>> result;

int hanoi(int n, int cur, int mid, int dest)
{
    int temp = 0;
    if(n <= 1)
    {   
        result.push_back({cur,dest});
        return 1;
    }
    temp += hanoi(n-1,cur,dest,mid);
    result.push_back({cur,dest});
    temp += hanoi(n-1,mid,cur,dest);
    return temp+1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    cout<<hanoi(N,1,2,3)<<'\n';

    for(auto p : result)
    {
        cout<<p.first<<" "<<p.second<<'\n';
    }

    return 0;
}