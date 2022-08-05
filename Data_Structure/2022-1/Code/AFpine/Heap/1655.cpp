#include <bits/stdc++.h>

//1655 가운데를 말해요

using namespace std;

const int MAX = 100005;

int N;
priority_queue<int,vector<int>,greater<int>> pq;
priority_queue<int,vector<int>> tempPQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    pq.push(-100001);
    for(int i = 1;i<=N;++i)
    {
        int temp;
        cin>>temp;

        if(!tempPQ.empty() && tempPQ.top() > temp)
        {
            pq.push(tempPQ.top());
            tempPQ.pop();
            tempPQ.push(temp);
        }
        else
        {
            pq.push(temp);
        }

        if(i % 2 == 1)
        {
            tempPQ.push(pq.top());
            pq.pop();
        }

        cout<<pq.top()<<'\n';
    }

    return 0;
}