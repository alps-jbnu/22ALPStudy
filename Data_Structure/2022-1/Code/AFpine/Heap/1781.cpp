#include <bits/stdc++.h>

//1781 컵라면

using namespace std;

const int MAX = 200005;

int N;
int dead[MAX];
int cup[MAX];
long long result = 0;
    

struct compare
{
    bool operator()(int a, int b)
    {
        return dead[a] < dead[b];
    }
};

priority_queue<int,vector<int>,compare> pq;
priority_queue<int,vector<int>> cupPQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>dead[i]>>cup[i];
        pq.push(i);
    }

    for(int i = N;i>=1;--i)
    {
        while(!pq.empty() && i <= dead[pq.top()])
        {
            cupPQ.push(cup[pq.top()]);
            pq.pop();
        }

        if(cupPQ.empty())
        {
            continue;
        }
        result += cupPQ.top();
        cupPQ.pop();
    }

    cout<<result;

    return 0;
}