#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int A[20005], B[20005];
        int a, b;
        cin >> a >> b;

        for (int i = 0; i < a; i++) cin >> A[i]; sort(A, A + a);
        for (int i = 0; i < b; i++) cin >> B[i]; sort(B, B + b);

        int ans = 0;
        for (int i = 0; i < a; i++) {
            int le = 0, ri = b;
            while (le + 1 < ri) {
                int mid = (le + ri) / 2;
                if (A[i] > B[mid]) le = mid;
                else ri = mid;
            }

            ans += le;
            if (A[i] > B[le]) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}