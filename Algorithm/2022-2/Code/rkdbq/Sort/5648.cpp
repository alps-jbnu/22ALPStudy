#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<long long> vec;

void reverse(string &str) {
	if (str.length() < 2) return;
	auto j{ str.end()};
	for (int i{}; i < ((int)str.length()) / 2; i++) {
		char temp{ str[i] };
		str[i] = *--j;
		*j = temp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) {
		string str{};
		cin >> str;
		reverse(str);
		vec.push_back(stoll(str));
	}
	sort(vec.begin(), vec.end());
	for (auto it{ vec.begin() }; it != vec.end(); it++) cout << *it << "\n";
	return 0;
}