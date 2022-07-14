#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    list<int> L;

    cin>>N>>K;

    for(int i = 1;i<=N;++i)
    {
        L.push_back(i);
    }
    auto it = L.begin();
    cout<<"<";
    while(L.size() != 1)
    {
        for(int i = 0;i<K-1;++i)
        {
            it++;
            if(it == L.end())
            {
                it = L.begin();
            }
        }
        cout<<(*it)<<", ";
        it = L.erase(it);
        if(it == L.end())
        {
            it = L.begin();
        }
    }
    cout<<(*it)<<">\n";

    return 0;

}