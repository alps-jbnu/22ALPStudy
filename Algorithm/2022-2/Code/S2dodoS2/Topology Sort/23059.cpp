#include <bits/stdc++.h>
using namespace std;

#define MAX 400005

vector<int> adj[MAX];
vector<int> adj2[MAX];
int deg[MAX];
int n;
map<string,int> m;
string str[MAX];

vector<string> topology_sort(int v) {
	vector<string> result;
	queue<int> q;
	queue<int> tmp;
	bool st = 1;
	for (int i = 1; i <= v; i++)
		if (deg[i] == 0) q.push(i);
	while (!tmp.empty() || st == 1) {
		if (st != 1) q = tmp;
		tmp = queue<int> ();
		int si = result.size();
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			result.push_back(str[cur]);
			for (auto nxt : adj[cur]) {
				deg[nxt]--;
				if (deg[nxt] == 0) tmp.push(nxt);
			}
		}
		int ei = result.size();
		sort(result.begin() + si, result.begin() + ei);
		st = 0;
	}

	return result;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int idx = 0;


	for(int i= 0;i<n;i++){
		string s,e;
		cin >> s >> e;
		if (m.find(s) == m.end()) {
			m.insert({ s,++idx });
			str[idx] = s;
		}
		if (m.find(e) == m.end()) {
			m.insert({ e,++idx });
			str[idx] = e;
		}
		int si = m.at(s), ei = m.at(e);
		adj[si].push_back(ei);
		deg[ei]++;
	}

	int sz = m.size();
	vector<string> result = topology_sort(sz);

	if (result.size() != sz)
		cout << "-1";
	else
		for (auto x : result) cout << x << "\n";


}