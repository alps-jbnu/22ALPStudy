#include<bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	

	while (n--) {
		string v;
		cin >> v;

		list<char>L = {};
		auto cursor = L.begin();

		for (auto op : v) {
			if (op == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else if (op == '<') {
				if (cursor != L.begin())
					cursor--;
			}
			else if (op == '>') {
				if (cursor != L.end())
					cursor++;
			}
			else
				L.insert(cursor, op);
		}
		for (auto op : L)
			cout << op;
		cout << '\n';
	}
}
	