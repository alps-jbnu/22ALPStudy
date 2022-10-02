#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> line[32002];
int indeg[32002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        line[A].push_back(B);
        indeg[B] += 1;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for (int i : line[cur]) {
            indeg[i] -= 1;
            if (!indeg[i]) q.push(i);
        }
    }
    return 0;
}