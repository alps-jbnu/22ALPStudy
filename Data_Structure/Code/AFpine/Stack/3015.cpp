#include <bits/stdc++.h>

using namespace std;
//not AC
int people[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    stack<int> stack;
    long long sum = 0;
    int cnt=0;
    int samecnt=0;

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>people[i];
    }
    stack.push(people[1]);
    for(int i = 2;i<=N;++i)
    {
        cnt = 0;
        samecnt=0;
        if(people[i] >= people[i-1])
        {
            while(!stack.empty())
            {
                if(stack.top() < people[i])
                {
                    ++cnt;
                    stack.pop();                
                }
                else if(stack.top() == people[i])
                {
                    ++samecnt;
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            if(stack.empty())
            {
                sum += cnt + samecnt;
            }
            else
            {
                sum += cnt + samecnt + 1;
            }
            for(int j = 0;j<samecnt;++j)
            {
                stack.push(people[i]);
            }
        }
        else
        {
            sum += 1;
        }
        stack.push(people[i]);
    }
    cout<<sum<<"\n";
}