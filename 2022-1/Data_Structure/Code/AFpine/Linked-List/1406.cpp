#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    list<char> List;
    string s;
    int M;
    char exp;
    list<char>::iterator cursor;
    cin>>s;
    cin>>M;
    for(auto x:s)
    {
        List.push_back(x);
    }
    cursor = List.end();

    for(int i = 0;i<M;++i)
    {
        cin>>exp;
        if(exp == 'L')
        {
            if(cursor != List.begin())
            {
                cursor--;
            }
        }
        else if(exp == 'D')
        {
            if(cursor != List.end())
            {
                cursor++;
            }
        }
        else if(exp == 'B')
        {
            if(cursor != List.begin())
            {
                --cursor;
                cursor = List.erase(cursor);
            }
        }
        else if(exp == 'P')
        {
            char c;
            cin>>c;
            List.insert(cursor,c);
        }
    }

    for(auto x:List)
    {
        cout<<x;
    }
    cout<<"\n";
}