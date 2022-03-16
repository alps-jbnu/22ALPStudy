#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int temp;
    queue<int> q;
    
    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        q.push(i);
    }

    while(q.size() != 1)
    {
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout<<q.front()<<"\n";
}