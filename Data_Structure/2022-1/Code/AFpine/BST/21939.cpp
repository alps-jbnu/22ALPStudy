#include <bits/stdc++.h>

//21939 문제 추천 시스템 Version 1

using namespace std;

const int MAX = 1000001;

int N,M,P,L;
multiset<pair<int,int>> mset;
map<int,int> problem;
//problem[P] = L

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>P>>L;
        problem[P] = L;
        mset.insert({L,P});
    }

    cin>>M;
    for(int i = 1;i<=M;++i)
    {
        string mode;
        cin>>mode;
        if(mode == "recommend")
        {   
            int x;
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
        else if(mode == "add")
        {
            cin>>P>>L;
            problem[P] = L;
            mset.insert({L,P});
        }
        else
        {
            cin>>P;
            mset.erase(mset.find({problem[P],P}));
            problem.erase(P);
        }
    }

    return 0;
}