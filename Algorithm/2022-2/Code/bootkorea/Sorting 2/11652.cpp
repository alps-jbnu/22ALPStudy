#include <bits/stdc++.h>
const int MAX = 100000 + 1;
using namespace std;

int N;
long long arr[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int cnt = 1, max = 0, idx = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt; idx = i;
            }
        }
        else cnt = 1;
    }
    cout << arr[idx];

    return 0;
}