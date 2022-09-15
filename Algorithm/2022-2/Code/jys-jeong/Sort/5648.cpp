#include<bits/stdc++.h>
using namespace std;


int n;
vector<long long> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		vec.push_back(stoll(s));
	}
	sort(vec.begin(), vec.end());
	for (long long k : vec) {
		cout << k << '\n';
	}
}
