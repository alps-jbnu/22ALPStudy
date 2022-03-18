#include <bits/stdc++.h>

using namespace std;

// not AC

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<pair<int,int>>v;
    deque<pair<int,int>> dq;
    //pair 에서 first는 수열의 수이고, second는 수열에서 그 수의 순서다
    int N,L;
    cin>>N>>L;

    v.push_back({0,0});

    for(int i = 1;i<=N;++i)
    {
        int num;
        cin>>num;
        v.push_back({num,i});
    }

    //top of deque has the least value in the deque's elements
    for(int i = 1;i<=N;++i)
    {  
        if(i - L + 1 >= 2)
        {//before the A(i-L+1) element should pop
            if(dq.front().second == (i-L))
            {
                dq.pop_front();
            }
        }
        if(dq.empty())
        {
            dq.push_back(v[i]);
        }
        else
        {//deque is increasing sequence
            while(!dq.empty())
            {
                if(v[i].first < dq.back().first)
                {
                    dq.pop_back();
                }
                else
                {
                    break;
                }
            }
            dq.push_back(v[i]);
        }
        cout<<dq.front().first<<" ";
    }


}