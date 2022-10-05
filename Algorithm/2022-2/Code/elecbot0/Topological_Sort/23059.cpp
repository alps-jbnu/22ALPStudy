#include <bits/stdc++.h>

using namespace std;

int N;
unordered_map<string, vector<string>> line;
unordered_map<string, int> indeg;
unordered_map<string, int> order;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string A, B; cin >> A >> B;
        line[A].push_back(B);
        indeg[A] += 0;
        indeg[B] += 1;
    }
    queue<string> q;
    for (auto p : indeg) {
        if (!p.second) {
            q.push(p.first);
            order[p.first] = 0;
        }
    }
    set<pair<int, string>> s;
    while (!q.empty()) {
        string cur = q.front(); q.pop();
        s.insert(make_pair(order[cur], cur));
        for (string a : line[cur]) {
            indeg[a] -= 1;
            if (!indeg[a]) {
                q.push(a);
                order[a] = order[cur] + 1;
            }
        }
    }
    if (s.size() != indeg.size()) {
        cout << -1; return 0;
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->second << "\n";
    }
    return 0;
}