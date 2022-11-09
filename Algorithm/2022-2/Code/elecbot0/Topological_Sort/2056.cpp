#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> line[10002];
int indeg[10002];
int work_time[10002];
int dp[10002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> work_time[i];
        dp[i] = work_time[i];
        int M; cin >> M;
        for (int j = 0; j < M; j++) {
            int T; cin >> T;
            line[T].push_back(i);
            indeg[i] += 1;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : line[cur]) {
            dp[nxt] = max(dp[nxt], dp[cur] + work_time[nxt]);
            indeg[nxt] -= 1;
            if (!indeg[nxt]) q.push(nxt);
        }
    }
    int m = 0;
    for (int i = 1; i <= N; i++) {
        m = max(m, dp[i]);
    }
    cout << m;
    return 0;
}