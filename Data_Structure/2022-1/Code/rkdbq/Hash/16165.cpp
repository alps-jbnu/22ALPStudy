#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string groupName, memberName;
int memberNum;
unordered_multimap<string, string> groupKey;
unordered_map<string, string> memberKey;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int j{}; j < N; j++) {
		cin >> groupName >> memberNum;
		for (int i{}; i < memberNum; i++) {
			cin >> memberName;
			groupKey.insert({ groupName, memberName });
			memberKey[memberName] = groupName;
		}
	}
	
	for (int i{}; i < M; i++) {
		string name;
		int quiz;
		cin >> name >> quiz;
		if (quiz == 1) {
			cout << memberKey[name] << "\n";
		}
		else if (quiz == 0) {
			vector<string> ans;
			for (auto it{ groupKey.equal_range(name).first }; it != groupKey.equal_range(name).second; it++) {
				ans.push_back((*it).second);
			}
			sort(ans.begin(), ans.end());
			for (auto it{ ans.begin() }; it != ans.end(); it++) {
				cout << *it << "\n";
			}
		}
	}
	return 0;
}