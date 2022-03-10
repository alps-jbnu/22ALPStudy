#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i = 0;i<N;++i)
    {
        string s;
        list<char> L;

        cin>>s;
        auto it = L.begin();
        for(int j = 0;j<s.size();++j)
        {
            if(s[j] == '<')
            {
                if(it != L.begin())
                {
                    it--;
                }
            }
            else if(s[j] == '>')
            {
                if(it != L.end())
                {
                    it++;
                }
            }
            else if(s[j] == '-')
            {
                if(it != L.begin())
                {
                    --it;
                    it = L.erase(it);
                    //erase char and decrease iterator
                }
            }
            else
            {
                it = L.insert(it,s[j]);
                it++;
                //insert char and increase iterator
                //(point inserted char)
            }
        }

        for(auto x : L)
        {
            cout<<x;
        }
        cout<<"\n";
    }

    return 0;

}