#include <iostream>
#include <unordered_set>
#include<unordered_map>
#include<string>
#include<iterator>
using namespace std;

unordered_map<string, int> s;
string p[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		s.insert({ p[i],i });
	}
	for (int j = 0; j < m; j++) {
		string t;
		cin >> t;
		if (t[0] >= '1' && t[0] <= '9') {
			int num = stoi(t);
			cout << p[num] << '\n';
		}
		else {
			cout << s[t] << '\n';
		}
	}
}
