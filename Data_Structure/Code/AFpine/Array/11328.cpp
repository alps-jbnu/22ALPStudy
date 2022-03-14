#include <bits/stdc++.h>

using namespace std;

int arr1[26];
int arr2[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s1, s2;
    bool flag;
    cin>>N;
    for(int i = 0;i<N;++i)
    {
        for(int i = 0;i<26;++i)
        {
            arr1[i] = 0;
            arr2[i]= 0;
        }
        cin>>s1>>s2;
        flag = true;
        for(int j = 0;j<s1.size();++j)
        {
            ++arr1[s1[j]-'a'];
            ++arr2[s2[j]-'a'];
        }
        for(int j=0;j<26;++j)
        {
            if(arr1[j] != arr2[j])
            {
                flag = false;
            }
        }
        if(flag)
        {
            cout<<"Possible\n";
        }
        else
        {
            cout<<"Impossible\n";
        }
    }

    return 0;

}