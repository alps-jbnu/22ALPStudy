#include <bits/stdc++.h>

//1715 카드 정렬하기

using namespace std;

const int MAX = 100005;

int N;
priority_queue<int,vector<int>,greater<int>> pq;
long long result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        int temp;
        cin>>temp;
        pq.push(temp);
    }

    if(N == 1)
    {
        cout<<"0";
        return 0;
    }

    while(pq.size() >= 2)
    {
        int card1 = pq.top();
        pq.pop();
        int card2 = pq.top();
        pq.pop();

        result += (card1+card2);
        pq.push(card1+card2);
    }

    cout<<result;

    return 0;
}