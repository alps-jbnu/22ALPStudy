#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long
#define X first
#define Y second

int n;
string a, b;
queue<pair<string, int>> zeroIndeg;
map<string, vector<string>> adj;
map<string, int> deg;
vector<pair<string, int>> ans;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        deg[a] += 0;
        deg[b] += 1;
    }

    for (auto its = deg.begin(); its != deg.end(); its++){
        if (its->Y == 0) zeroIndeg.push({its->X, 0});
    }

    while (!zeroIndeg.empty()){
        auto cur{zeroIndeg.front()};
        zeroIndeg.pop();
        ans.push_back(cur);

        for (int i = 0; i < adj[cur.X].size(); i++){
            auto nxt = adj[cur.X][i];
            if (--deg[nxt] == 0)
                zeroIndeg.push({nxt, cur.Y + 1});
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    if (ans.size() == deg.size()){
		 for (auto its = ans.begin(); its != ans.end(); its++){
			cout << its->X << "\n";
		 }
	}
    else cout << -1 << "\n";

    return 0;
}