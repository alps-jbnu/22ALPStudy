#include <iostream>
#include<string>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	int num = a * b * c;
	string s = to_string(num);
	int cnt[10] = {};

	for (auto k : s) {
		cnt[k - '0']++;
	}

	for (int v : cnt) {
		cout << v << '\n';
	}

}