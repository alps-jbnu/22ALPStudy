#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;


unordered_map<string,int> ma;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string a;
		cin >> a;
		if (ma.find(a) != ma.end()) {
			ma.erase(a);
			ma.insert({ a,i });
		}
		else {
			ma.insert({ a,i });
		}
	}
	vector<pair<string, int>> vec(ma.begin(),ma.end());
	sort(vec.begin(), vec.end(), [](auto& a, auto& b) {return a.second < b.second; });
	int si = min(n,(int)ma.size());
	for (int i = 0; i < si; i++) {
		cout << vec[i].first << '\n';
	}
}
