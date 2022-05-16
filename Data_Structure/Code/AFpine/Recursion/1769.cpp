#include <bits/stdc++.h>

// 1769 3의 배수

using namespace std;

static const int INF = 1000000000;

string s;

void recursion(string s, int n)
{
    int temp = 0;
    string next;
    stack<int> st;
    if(s.size() == 1)
    {
        temp = s[0]-'0';
        cout<<n<<'\n';
        if(temp == 3 || temp == 6 || temp == 9)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        return; 
    }
    for(int i = 0;i<s.size();++i)
    {
        temp += s[i]-'0';
    }
    while(temp != 0)
    {
        st.push(temp%10);
        temp /= 10;
    }
    while(!st.empty())
    {
        next += st.top()+'0';
        st.pop();
    }
    recursion(next, n+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>s;

    recursion(s,0);


    return 0;
}