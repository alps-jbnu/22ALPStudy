#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> line[102];
int indeg[102];
int dp[102][102];
vector<int> default_parts;
set<int> default_parts_set;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int X, Y, K; cin >> X >> Y >> K;
        line[Y].push_back(X);
        indeg[X] += 1;
        dp[X][Y] = K;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) {
            q.push(i);
            default_parts.push_back(i);
            default_parts_set.insert(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : line[cur]) {
            if (default_parts_set.find(cur) == default_parts_set.end()) {
                for (int d_part : default_parts) {
                    dp[nxt][d_part] += dp[cur][d_part] * dp[nxt][cur];
                }
            }
            indeg[nxt] -= 1;
            if (!indeg[nxt]) q.push(nxt);
        }
    }
    for (int d_part : default_parts) {
        cout << d_part << " " << dp[N][d_part] << "\n";
    }
    return 0;
}