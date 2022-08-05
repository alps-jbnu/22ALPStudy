#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

string S;
unordered_set<string> str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	for (int i{}; i < S.length(); i++) {
		for (int j{ 1 }; j < S.length() - i + 1; j++) {
			str.insert(S.substr(i, j));
		}
	}
	cout << str.size() << "\n";
	return 0;
}