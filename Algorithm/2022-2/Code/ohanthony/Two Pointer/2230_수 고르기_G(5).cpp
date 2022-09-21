#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff

int arr[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, result = INF;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && arr[en] - arr[st] < m) en++; // a[en]-a[st] > m 이상이 되는 최초의 지점 en 을 찾는다.
        if (en == n) break;
        result = min(result, arr[en] - arr[st]);
    }
    cout << result;
    return 0;
}