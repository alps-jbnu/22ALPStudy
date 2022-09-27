#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> vec[1005];
int deg[1005];
int cnt[1005];
set<int> mid;
int res[1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m,s,e,k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        ++deg[b];
    }
    cin >> s >> e >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        mid.insert(a);

    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)  q.push(i);
    }
    res[s] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (mid.find(cur) != mid.end())    cnt[cur]++;
        for (int k : vec[cur]) {
            if (cnt[cur] == cnt[k])    res[k] += res[cur];
            else if (cnt[cur] > cnt[k]) {
                res[k] = res[cur];
                cnt[k] = cnt[cur];
            }
            if (--deg[k] == 0) q.push(k);
        }
    }
    if (cnt[e] == k)   cout << res[e];
    else
    {
        cout << 0;
    }
}