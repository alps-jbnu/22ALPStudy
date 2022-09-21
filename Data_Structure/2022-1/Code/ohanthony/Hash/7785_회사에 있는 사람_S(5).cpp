#include<bits/stdc++.h>
using namespace std;

set<string> s;

bool compare(string a, string b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string name, check;
		cin >> name >> check;

		if (check == "enter") s.insert(name);
		else s.erase(name);
	}

	vector<string> inOffice(s.begin(), s.end());
	sort(inOffice.begin(), inOffice.end(), compare);
	for (auto nxt : inOffice) cout << nxt << "\n";
	return 0;
}
