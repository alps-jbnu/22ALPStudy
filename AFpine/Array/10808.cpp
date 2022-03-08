#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main()
{
    
    string s;
    cin>>s;

    for(int i = 0;i<s.size();++i)
    {
        arr[s[i]-'a']++;
    }
    for(auto x : arr)
    {
        cout<<x<<" ";
    }

}