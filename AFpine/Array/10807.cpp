#include <bits/stdc++.h>

using namespace std;

int arr[201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int result;
    int temp;

    cin>>N;
    for(int i = 0;i<N;++i)
    {
        cin>>temp;
        ++arr[temp+100];
    }
    cin>>result;
    result = arr[result+100];

    cout<<result<<"\n";
}