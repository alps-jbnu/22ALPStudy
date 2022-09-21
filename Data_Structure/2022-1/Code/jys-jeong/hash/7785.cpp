#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

unordered_set<string> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, t;
		cin >> name >> t;
		if (t == "enter") {
			s.insert(name);
		}
		else if (t == "leave") {
			s.erase(name);
		}
	}
	vector<string> vec(s.begin(),s.end());
	sort(vec.begin(), vec.end(), greater<string>());
	for (string k : vec) {
		cout << k << '\n';
	}
}