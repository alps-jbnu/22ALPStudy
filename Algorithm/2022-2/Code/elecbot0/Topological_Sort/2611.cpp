#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> line[1002];
int indeg[1002];
int dp[1002];
vector<int> ans[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int p, q, r; cin >> p >> q >> r;
        line[p].push_back(make_pair(q, r));
        indeg[q] += 1;
    }
    queue<int> q;
    q.push(1);
    ans[1].push_back(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto p : line[cur]) {
            indeg[p.first] -= 1;
            if (dp[p.first] < dp[cur] + p.second) {
                dp[p.first] = dp[cur] + p.second;
                ans[p.first] = ans[cur];
                ans[p.first].push_back(p.first);
            }
            if (!indeg[p.first]) q.push(p.first);
        }
    }
    cout << dp[1] << "\n";
    for (int i : ans[1]) {
        cout << i << " ";
    }
    return 0;
}