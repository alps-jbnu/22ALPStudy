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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (!indeg[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << " ";
        for (int nxt : line[cur]) {
            indeg[nxt] -= 1;
            if (!indeg[nxt]) pq.push(nxt);
        }
    }
    return 0;
}