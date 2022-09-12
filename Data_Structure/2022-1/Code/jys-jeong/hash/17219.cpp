#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

unordered_map<string, string> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		s.insert({ a,b });
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout<<s[a]<<'\n';
	}
	
}