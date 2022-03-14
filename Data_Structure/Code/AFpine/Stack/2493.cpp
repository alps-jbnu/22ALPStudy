#include <bits/stdc++.h>

using namespace std;

int tower[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    stack<int> s;       //왼쪽의 빌딩부터 삽입
    queue<int> q;

    cin>>N;

    for(int i = 1;i<=N;++i)
    {
        cin>>tower[i];
    }
    
    for(int i = N-1;i>=0;--i)
    {
        if(tower[i] > tower[i+1])
        {
            tower[i+1] = i;
            while(!s.empty())
            {
                if(tower[i] > tower[s.top()])
                {
                    tower[s.top()] = i;
                    s.pop();
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            s.push(i+1);
        }
    }
    while(!s.empty())
    {
        tower[s.top()] = 0;
        s.pop();
    }

    for(int i = 1;i<=N;++i)
    {
        cout<<tower[i]<<" ";
    }

}