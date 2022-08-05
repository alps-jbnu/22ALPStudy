#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map<string, vector<string>>ttop;
unordered_map<string, string> ptot;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string team;
		cin >> team;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string s;
			cin >> s;
			ttop[team].push_back(s);
			ptot.insert({ s,team });
		}
		sort(ttop[team].begin(), ttop[team].end());
	}
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		int num;
		cin >> num;
		if (num == 0) {
			for (auto k : ttop[name]) {
				cout << k << '\n';
			}
		}
		else {
			cout << ptot[name] << '\n';
		}
	}
}