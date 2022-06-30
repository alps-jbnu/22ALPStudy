//! 2d

#include <iostream>
#include <cstring>
using namespace std;

long long h[100001];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    long long sum = 0;

    for(int k = 1;;k++)
    {
        //* 맨 앞이나 맨 마지막이 옆에 붙어있는 것보다 크면 불가능
        if(h[1] > h[2] || h[n - 1] < h[n])
        {
            cout << "-1\n";
            return;
        }
        long long prev_sum = sum;

        if(k % 2 == 1)
        {
            for (int i = 1; i <= n - 2; i++)
            {
                long long gap = h[i + 1] - h[i];
                if(gap <= 0) continue;
                if(h[i + 1] < gap || h[i + 2] < gap)
                {
                    cout << "-1\n";
                    return;
                }
                h[i + 1] -= gap;
                h[i + 2] -= gap;
                sum += gap * 2;
            }
        }
        else
        {
            for (int i = n; i >= 3; i--)
            {
                long long gap = h[i - 1] - h[i]; 
                if(gap <= 0) continue;
                if(h[i - 1] < gap || h[i - 2] < gap)
                {
                    cout << "-1\n";
                    return;
                }
                h[i - 1] -= gap;
                h[i - 2] -= gap;
                sum += gap * 2;
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << h[i] << " ";
        // }
        // cout << "\n";
        //* 변화가 없음 => 다 똑같은 상태
        if(prev_sum == sum)
        {
            cout << sum << "\n";
            return;
        }
    }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << h[i] << " ";
    // }
    // cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}