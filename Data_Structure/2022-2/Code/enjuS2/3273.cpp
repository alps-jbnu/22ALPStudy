#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1, cnt = 0, sum;
    while (1) {
        if (l >= r) {
            break;
        }

        sum = arr[l] + arr[r];

        if (sum == x) {
            cnt++;
            l++;
            r--;
        }
        else if (sum < x) {
            l++;
        }
        else {
            r--;
        }
    }

    cout << cnt;

    return 0;
}
