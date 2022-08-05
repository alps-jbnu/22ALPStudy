#include <bits/stdc++.h>

//13975 파일 합치기 3

using namespace std;

const int MAX = 100005;

int T;
int K;
priority_queue<long long,vector<long long>,greater<long long>> pq;
long long result = 0;

void init()
{
    while(!pq.empty())
    {
        pq.pop();
    }
    result = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>T;
    while(T--)
    {
        init();
        
        cin>>K;
        
        for(int i = 1;i<=K;++i)
        {
            int temp;
            cin>>temp;
            pq.push(temp);
        }

        while(pq.size() >= 2)
        {
            long long c1 = pq.top();
            pq.pop();
            long long c2 = pq.top();
            pq.pop();

            result += (c1+c2);
            pq.push(c1+c2);
        }

        cout<<result<<'\n';

    }

    return 0;
}