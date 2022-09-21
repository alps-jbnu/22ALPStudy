#include<bits/stdc++.h>
using namespace std;


vector<string> vec;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		vec.push_back(s.substr(i, s.length()));
	}
	stable_sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}
