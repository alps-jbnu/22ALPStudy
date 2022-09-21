#include <iostream>
#include <unordered_set>
#include<unordered_map>
#include<string>
#include<iterator>
using namespace std;

unordered_set<string> se;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		for (int j = 1; j + i <= s.length(); j++) {
			se.insert(s.substr(i, j));
		}
	}
	cout << se.size();
}
