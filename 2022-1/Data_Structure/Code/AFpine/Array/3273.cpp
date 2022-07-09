#include <bits/stdc++.h>

using namespace std;

int arr[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int temp;;
    int x;
    int cnt=0;

    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        cin>>temp;
        arr[temp] = i;
    }
    cin>>x;

    for(int i = 1;i<x;++i)
    {
        if(i != (x-i) && arr[i] != 0 && arr[x-i] != 0)
        {
            if(arr[i] < arr[x-i])
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";

}