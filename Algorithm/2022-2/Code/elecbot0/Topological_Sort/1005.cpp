#include <bits/stdc++.h>

using namespace std;

int T, N, K, W;
int D[1002], dp[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            dp[i] = D[i];
        }
        int indeg[1002] = {0, };
        vector<int> line[1002] = {vector<int>(), };
        for (int i = 0; i < K; i++) {
            int X, Y; cin >> X >> Y;
            line[X].push_back(Y);
            indeg[Y] += 1;
        }
        cin >> W;
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (!indeg[i]) q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : line[cur]) {
                dp[nxt] = max(dp[nxt], dp[cur] + D[nxt]);
                indeg[nxt] -= 1;
                if (!indeg[nxt]) q.push(nxt);
            }
        }
        cout << dp[W] << "\n";
    }
    return 0;
}