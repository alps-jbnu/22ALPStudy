#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

unordered_map<string, int> mp;
unordered_map<int, string> mp2;
int n;
vector<int> vec[400000];
int cnt = 0;
int deg[400000];
vector<string> ans[400000];
queue<pair<int,int>> q;
int vcnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (mp.find(a) == mp.end()) {

            mp.insert({ a,cnt}); 
            mp2.insert({ cnt,a });
            ++cnt;
        }

        if (mp.find(b) == mp.end()) { 
            mp.insert({ b,cnt}); 
            mp2.insert({ cnt,b });
            ++cnt;
        }
        vec[mp[a]].push_back(mp[b]);
        deg[mp[b]]++;
    }
    for (int i = 0; i < cnt; i++) {
        if (deg[i] == 0) { 
            q.push({ i,0 });
            ans[0].push_back(mp2[i]);
        }
    }
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        ++vcnt;
       
        
        for (int k : vec[cur.first]) {
            deg[k]--;
            if (deg[k] == 0) { 
                q.push({ k,cur.second + 1 }); 
                ans[cur.second + 1].push_back(mp2[k]);
            }
        }
    }
    if (vcnt == cnt) {
        for (int i = 0;; i++) {
            if (ans[i].size() == 0)    return 0;
            sort(ans[i].begin(), ans[i].end());
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << '\n';
            }

        }
    }
    else {
        cout << "-1";
    }
}