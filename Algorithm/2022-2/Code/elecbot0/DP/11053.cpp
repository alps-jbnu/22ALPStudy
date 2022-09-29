#include <bits/stdc++.h>

using namespace std;

int N;
int A[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int ans[1002] = {};
    A[0] = 0; ans[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = i; j >= 0; j--) {
            if (A[j] < A[i]) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }
    int m = 0;
    for (int i = 1; i <= N; i++) {
        m = max(m, ans[i]);
    }
    cout << m;
    return 0;
}