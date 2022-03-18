#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
    int result = 0;
    stack<int> stk;

    cin>>K;

    for(int i = 0;i<K;++i)
    {
        int num;
        cin>>num;
        if(num != 0)
        {
            stk.push(num);
        }
        else
        {
            stk.pop();
        }
    }

    while(!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    cout<<result<<"\n";
}