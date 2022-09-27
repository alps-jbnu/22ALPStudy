#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int MAX = 1000000 + 1;
using namespace std;

int T, N;
ll cur = 0, temp = 0;
int arr[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        memset(arr, 0, sizeof(arr)); cur = 0; temp = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        for (int i = N - 1; i >= 0; i--)
        {
            if (arr[i] < temp) cur += (temp - arr[i]);
            else temp = arr[i];
        }

        cout << cur << "\n";
    }

    return 0;
}