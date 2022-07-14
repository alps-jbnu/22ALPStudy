#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
unordered_set<string> record;
string name, io;
vector<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> name >> io;
		if (io == "enter") record.insert(name);
		else record.erase(name);
	}
	
	auto it = record.begin();
	for (int i{}; i < record.size(); i++) {
		ans.push_back(*record.find((*it++)));
	}
	sort(ans.begin(), ans.end());
	for (int i{ (int)ans.size() - 1 }; i >= 0; i--) {
		cout << ans[i] << "\n";
	}

	return 0;
}