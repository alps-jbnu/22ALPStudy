#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<string> suffix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	for (int i{}; i < S.length(); i++) suffix.push_back(S.substr(i, S.length() - i));
	sort(suffix.begin(), suffix.end());
	for (auto suf : suffix) cout << suf << "\n";

	return 0;
}