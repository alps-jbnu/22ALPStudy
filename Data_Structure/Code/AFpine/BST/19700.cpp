#include <bits/stdc++.h>

//19700 수업

using namespace std;

const int MAX = 500005;

int N;
int h[MAX], k[MAX];
multiset<int,greater<int>> S;
map<int,int> M;
priority_queue<int,vector<int>> pq;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        cin>>h[i]>>k[i];
        pq.push(h[i]);
        M[h[i]] = k[i];
    }

    while(!pq.empty())
    {
        int curH = pq.top();
        int curK = M[curH];
        pq.pop();

        auto it = S.upper_bound(curK);
        if(it == S.end())
        {
            S.insert(1);
        }
        else
        {
            int temp = (*it);
            S.erase(it);
            S.insert(temp+1);
        }
    }

    cout<<S.size();

    return 0;
}