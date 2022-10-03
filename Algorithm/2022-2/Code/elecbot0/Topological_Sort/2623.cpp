#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> line[1002];
int indeg[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A; cin >> A;
        int prev = 0;
        for (int j = 0; j < A; j++) {
            int B; cin >> B;
            if (prev) {
                line[prev].push_back(B);
                indeg[B] += 1;
            }
            prev = B;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) q.push(i);
    }
    vector<int> v;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        v.push_back(cur);
        for (int nxt : line[cur]) {
            indeg[nxt] -= 1;
            if (!indeg[nxt]) q.push(nxt);
        }
    }
    if (v.size() == N) {
        for (int i : v) {
            cout << i << "\n";
        }
    } else {
        cout << 0;
    }
    return 0;
}