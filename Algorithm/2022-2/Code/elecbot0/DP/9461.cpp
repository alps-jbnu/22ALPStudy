#include <bits/stdc++.h>

using namespace std;

int T;
long long arr[102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1; arr[4] = 2; arr[5] = 2;
    for (int i = 6; i <= 100; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    while (T--) {
        int N; cin >> N;
        cout << arr[N] << "\n";
    }
    return 0;
}