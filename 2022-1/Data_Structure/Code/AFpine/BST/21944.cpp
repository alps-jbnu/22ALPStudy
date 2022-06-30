#include <bits/stdc++.h>

//21944 문제 추천 시스템 Version 2

using namespace std;

const int MAX = 1000001;

int N,M,P,L,G;
int x;
multiset<pair<int,int>> mset;
map<int, pair<int,int>> algo;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>P>>L>>G;
        mset.insert({L,P});
        algo[P] = {L,G};
    }

    cin>>M;
    for(int i = 1;i<=M;++i)
    {
        string mode;
        cin>>mode;
        if(mode == "recommend")
        {   
            cin>>G>>x;
            if(x > 0)
            {
                for(auto it = mset.rbegin(); it != mset.rend(); ++it)
                {
                    if(algo[(*it).second].second == G)
                    {
                        cout<<(*it).second<<'\n';
                        break;
                    }
                }
            }
            else
            {
                for(auto it = mset.begin(); it != mset.end(); ++it)
                {
                    if(algo[(*it).second].second == G)
                    {
                        cout<<(*it).second<<'\n';
                        break;
                    }
                }
            }
        }
        else if(mode == "recommend2")
        {
            cin>>x;
            if(x > 0)
            {
                cout<<(*mset.rbegin()).second<<'\n';
            }
            else
            {
                cout<<(*mset.begin()).second<<'\n';
            }
        }
        else if(mode == "recommend3")
        {
            cin>>x>>L;
            if(x > 0)
            {
                auto it = mset.lower_bound(pair<int,int>(L,0));
                if(it == mset.end())
                {
                    cout<<"-1\n";
                }
                else
                {
                    cout<<(*it).second<<'\n';
                }
            }
            else
            {
                auto it = mset.upper_bound(pair<int,int>(L,0)); 
                if(it == mset.begin())
                {
                    cout<<"-1\n";
                }
                else
                {
                    cout<<(*prev(it)).second<<'\n';
                }
            }
        }
        else if(mode == "add")
        {
            cin>>P>>L>>G;
            mset.insert({L,P});
            algo[P] = {L,G};
        }
        else
        {
            cin>>P;
            mset.erase({algo[P].first,P});
        }
    }

    return 0;
}