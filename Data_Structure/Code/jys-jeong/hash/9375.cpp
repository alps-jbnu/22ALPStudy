#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int cnt = 1;
		cin >> n;
		unordered_map<string, int> m;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		for (auto k : m) {
			cnt *= k.second + 1;
		}
		cout << cnt-1 << '\n';
	}
}