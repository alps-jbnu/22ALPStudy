#include<bits/stdc++.h>
using namespace std;

int arr1[1000005];
int arr2[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    stack<int> s;
    
    for(int i = 1; i <= n; i++)
        cin >> arr1[i];
    
    for(int i = n; i > 0; i--)
    {
        while(!s.empty() && s.top() <= arr1[i])
        {
            s.pop();
        }
        
        if(s.empty())
        {
            arr2[i] = -1;
        }
        else
        {
            arr2[i] = s.top();
        }
        s.push(arr1[i]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}