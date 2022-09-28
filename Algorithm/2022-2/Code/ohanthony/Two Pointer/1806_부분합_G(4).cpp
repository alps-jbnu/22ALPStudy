#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff

int arr[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s, result = INF;
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> arr[i];

    int sum = arr[0];
    int en = 0;

    for (int st = 0; st < n; st++) {
        while (sum < s && en < n) {        
            en++;
            if (en != n) sum += arr[en];
        }

        if (en == n) break;

        result = min(result, en - st + 1);
        sum -= arr[st]; // st 구간을 n까지 +1 하면서 움직이니까 그에 맞게 기존 sum값에 과거 arr[st] 값을 빼줌
    }

    if (result == INF) cout << 0;
    else cout << result;
    return 0;
}