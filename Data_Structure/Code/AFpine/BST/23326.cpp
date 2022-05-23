#include <bits/stdc++.h>

//23326 홍익 투어리스트

using namespace std;

const int MAX = 500005;

int N,Q;
int x,q;
int cur;
int A[MAX];
set<int> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cur = 1;
    cin>>N>>Q;
    
    for(int i = 1;i<=N;++i)
    {
        cin>>A[i];
        if(A[i] == 1)
        {
            S.insert(i);
        }
    }
    
    while(Q--)
    {
        cin>>q;

        if(q == 1)
        {
            cin>>x;
            if(A[x] == 1)
            {
                S.erase(x);
                A[x] = 0;
            }
            else
            {
                S.insert(x);
                A[x] = 1;
            }
        }
        else if(q == 2)
        {
            cin>>x;
            x %= N;
            cur += x;
            if(cur > N)
            {
                cur -= N;
            }
        }
        else
        {
            auto it1 = S.lower_bound(cur);
            auto it2 = S.begin();
            if(S.empty())
            {
                cout<<"-1\n";
            }
            else
            {
                if(it1 != S.end())
                {
                    cout<<(*it1)-cur<<'\n';
                }
                else
                {
                    cout<<N-(abs(cur-(*it2)))<<'\n';
                }
            }
        }
    }


    return 0;
}