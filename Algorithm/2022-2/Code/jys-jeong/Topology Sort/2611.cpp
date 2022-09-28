#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> vec[1005];
int pnt[1005][1005];
vector<int> res[1005];
int deg[1005];
int mx[1005];
int order[1005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n>>m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pnt[a][b] = c;
        vec[a].push_back(b);
        deg[b]++;
    }
    queue<pair<int, int>> q;
    q.push({ 1,0 });
    res[1].push_back(1);
    while (!q.empty()) {
        auto cur = q.front(); //현재 번호 / 순서
        q.pop();
        for (int nxt : vec[cur.first]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push({ nxt,cur.second + 1 });
            if (mx[nxt] < mx[cur.first] + pnt[cur.first][nxt]){
                res[nxt] = res[cur.first];
                res[nxt].push_back(nxt);
                
            }
            mx[nxt] = max(mx[nxt], mx[cur.first] + pnt[cur.first][nxt]);
        }
    }
    
    cout << mx[1] << '\n';
    for (int i = 0; i < res[1].size(); i++) {
        cout << res[1][i]<<' ';
    }
}