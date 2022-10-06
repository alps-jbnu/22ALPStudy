#include <bits/stdc++.h>

using namespace std;

int N, M;
string people_itos[1002];
unordered_map<string, int> people_stoi;

vector<int> line[1002];
int indeg[1002];
map<string, set<string>> child_map;
set<string> father;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> people_itos[i];
        people_stoi[people_itos[i]] = i;
        child_map.insert(make_pair(people_itos[i], set<string>()));
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string X, Y; cin >> X >> Y;
        int X_num = people_stoi[X];
        int Y_num = people_stoi[Y];
        line[Y_num].push_back(X_num);
        indeg[X_num] += 1;
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (!indeg[i]) {
            q.push(i);
            father.insert(people_itos[i]);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : line[cur]) {
            indeg[nxt] -= 1;
            if (!indeg[nxt]) {
                q.push(nxt);
                child_map[people_itos[cur]].insert(people_itos[nxt]);
            }
        }
    }
    cout << father.size() << "\n";
    for (auto it = father.begin(); it != father.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    for (auto it = child_map.begin(); it != child_map.end(); it++) {
        cout << it->first << " " << it->second.size() << " ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << " ";
        }
        cout << "\n";
    }
    return 0;
}