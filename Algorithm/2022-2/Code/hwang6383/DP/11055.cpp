#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int a[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i< N;i++)
    {
        cin >> arr[i];
    }
    a[0] = arr[0];
    int ans = a[0];
    for(int i = 1; i< N;i++)
    {
        pair<int,int> tmp = {0,0};
        for(int j = i - 1; j >=0;j--)
        {
            if(arr[i] > arr[j])
            {
                if (tmp.first < a[j])
                    tmp = {a[j], j};
            }
        }
        if(tmp.first == 0)
        {
            a[i] = arr[i];
        }
        else
        {
            a[i] = arr[i] + a[tmp.second];
        }
        if(ans < a[i])
            ans = a[i];
    }
    cout << ans;
    return 0;
}
