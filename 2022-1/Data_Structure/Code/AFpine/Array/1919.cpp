#include <bits/stdc++.h>

using namespace std;

int arr1[26];
int arr2[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    int cnt=0;
    
    cin>>s1>>s2;
    for(int j = 0;j<s1.size();++j)
    {
        ++arr1[s1[j]-'a'];
    }
    for(int j = 0;j<s2.size();++j)
    {
        ++arr2[s2[j]-'a'];
    }
    for(int j=0;j<26;++j)
    {
        if(arr1[j] != arr2[j])
        {
            cnt += abs(arr1[j]-arr2[j]);
        }
    }
    cout<<cnt<<"\n";

    return 0;

}