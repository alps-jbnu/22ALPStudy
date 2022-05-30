#include <bits/stdc++.h>

//2075 N번째 큰 수

using namespace std;

const int MAX = 250005;

int N;
int element;
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            cin>>element;
            pq.push(element);
            if(pq.size() > N)
            {
                pq.pop();
            }
        }
    }

    cout<<pq.top();

    return 0;
}