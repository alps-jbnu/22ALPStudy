#include<bits/stdc++.h>
using namespace std;


int n;
set<string> vec;
vector<string> a;
bool compare(string a, string b) {
	if (a.length() != b.length())	return a.length() < b.length();
	return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vec.insert(s);
	}
	for (string k: vec) {
		a.push_back(k);
	}

	sort(a.begin(), a.end(),compare);
	for (string k : a) {
		cout << k << '\n';
	}
}
