#include <bits/stdc++.h>

using namespace std;

struct heightindex
{
    int height = 0;
    int index = 0;
};

heightindex people[500001];
int cnt1[500001];
int cnt2[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    long long sum=0;
    stack<heightindex> stack;
    int height;

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>height;
        people[i] = {height,i};
    }

    for(int i = 1;i<=N;++i)
    {
        int count = 0;
        while(!stack.empty() && people[i].height > stack.top().height)
        {
            ++count;
            heightindex temp = stack.top();
            stack.pop();
            if(stack.empty())
            {
                cnt2[temp.index] = 0;
                break;
            }
            if(temp.height < stack.top().height)
            {
                cnt2[temp.index]++;
            }
            else if(temp.height == stack.top().height)
            {
                cnt2[temp.index]++;
                cnt2[stack.top().index] = cnt2[temp.index];
            }
        }
        cnt1[i] = count;
        stack.push(people[i]);
    }
    while(!stack.empty())
    {
        heightindex temp = stack.top();
        stack.pop();
        if(stack.empty())
        {
            cnt2[temp.index] = 0;
            break;
        }
        if(temp.height < stack.top().height)
        {
            cnt2[temp.index]++;
        }
        else if(temp.height == stack.top().height)
        {
            cnt2[temp.index]++;
            cnt2[stack.top().index] = cnt2[temp.index];
        }
    }
    
    for(int i = 1;i<=N;++i)
    {
        sum += cnt1[i];
        sum += cnt2[i];
    }

    cout<<sum<<"\n";
}