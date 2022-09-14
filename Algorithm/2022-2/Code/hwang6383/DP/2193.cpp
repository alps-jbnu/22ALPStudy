#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long arr[91];
    int N;
    cin >> N;
    arr[1] = 1; arr[2] = 1;
    for(int i =3 ; i<=N;i++)
    {
        arr[i] = arr[i-1] + arr[i -2];
    }
    cout << arr[N];
    return 0;
}
