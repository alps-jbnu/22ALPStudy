#include <bits/stdc++.h>

using namespace std;

int N, M, A, B, K;
set<int> C;

vector<int> line[1002];
int indeg[1002];
int cnt[1002];
int route[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to; cin >> from >> to;
        line[from].push_back(to);
        indeg[to] += 1;
    }
    cin >> A >> B >> K;
    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        C.insert(c);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) q.push(i);
    }
    route[A] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (C.find(cur) != C.end()) cnt[cur] += 1;
        for (int i : line[cur]) {
            if (cnt[cur] == cnt[i]) route[i] += route[cur];
            else if (cnt[cur] > cnt[i]) {
                cnt[i] = cnt[cur];
                route[i] = route[cur];
            }
            indeg[i] -= 1;
            if (!indeg[i]) q.push(i);
        }
    }
    if (cnt[B] == K) {
        cout << route[B];
    } else {
        cout << 0;
    }
    return 0;
}