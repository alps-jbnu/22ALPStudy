#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
vector<pair<int, int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d[1005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    fill(d, d + n + 1, INF);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }
    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int> pq2[1005];
    d[1] = 0;
    pq.push({ d[1],1});
    pq2[1].push(0);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        for (auto nxt : adj[cur.Y]) {
            if (pq2[nxt.Y].size() < k || pq2[nxt.Y].top() > cur.X + nxt.X) {
                if (pq2[nxt.Y].size() == k) pq2[nxt.Y].pop();
                pq2[nxt.Y].push(nxt.X + cur.X);
                pq.push({ nxt.X + cur.X,nxt.Y });
           }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (pq2[i].size() == k) {
            cout << pq2[i].top() << "\n";
        }
        else cout << "-1\n";
    }
}