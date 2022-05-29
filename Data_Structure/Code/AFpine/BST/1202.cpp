#include <bits/stdc++.h>

//1202 보석 도둑

using namespace std;

const int MAX = 300005;

struct compare
{
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int N,K;
priority_queue<pair<int,int>,vector<pair<int,int>>,compare> jewelPQ;
multiset<int> bagSet;
long long result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>K;

    for(int i = 1;i<=N;++i)
    {
        int m,v;
        cin>>m>>v;
        jewelPQ.push({m,v});
    }
    for(int i = 1;i<=K;++i)
    {
        int c;
        cin>>c;
        bagSet.insert(c);
    }

    while(!jewelPQ.empty() && !bagSet.empty())
    {
        pair<int,int> curJewel = jewelPQ.top();
        jewelPQ.pop();

        auto it = bagSet.lower_bound(curJewel.first);
        if(it == bagSet.end())
        {
            continue;
        }
        else
        {
            bagSet.erase(it);
            result += curJewel.second;
        }
    }
    
    cout<<result;


    return 0;
}