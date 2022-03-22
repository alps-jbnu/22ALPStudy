#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
    int maxvalue=0;
    int num;
    int prenum = 0;
    int diff;
    bool error = false;
    queue<char> q;
    stack<int> s;

    cin>>n;

    for(int i = 0;i<n;++i)
    {
        cin>>num;

        if(num > prenum)
        {
            if(num > maxvalue)
            {
                for(int i = maxvalue+1; i<=num;++i)
                {
                    s.push(i);
                }
                diff = num-maxvalue;
                maxvalue = num;
                for(int j = 0;j<diff;++j)
                {
                    q.push('+');
                }
                q.push('-');
                s.pop();
            }
            else
            {
                error = true;
            }
        }
        else
        {
            q.push('-');
            if(s.top() != num)
            {
                error = true;
            }
            s.pop();
        }

        prenum = num;
    }

    if(error || q.size() != 2*n || !s.empty())
    {
        cout<<"NO\n";
    }
    else
    {
        while(!q.empty())
        {
            cout<<q.front()<<"\n";
            q.pop();
        }
    }
}