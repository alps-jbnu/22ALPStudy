#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    // {level, problemId}
    set<pair<int,int>> s;
    unordered_map<int,int> idToLv;
    for (int i=0;i<N;++i)
    {
        int P, L;
        cin >>P>>L;
        s.insert({L, P});
        idToLv[P]=L;
    }
    int M; cin >> M;
    for (int i=0;i<M;++i)
    {
        string op; int P, L;
        cin >> op >> P;
        if (op == "add")
        {
            cin >> L;
            s.insert({L, P});
            idToLv[P]=L;
        }
        else if (op == "recommend")
        {
            if (P == 1)
                cout << s.rbegin()->second << '\n';
            else
                cout << s.begin()->second << '\n';
        }
        else // op == solved
        {
            pair<int,int> p = {idToLv[P], P};
            s.erase(p);
            idToLv.erase(P);
        }
    }
}
