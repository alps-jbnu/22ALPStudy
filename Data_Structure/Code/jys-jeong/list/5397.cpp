#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		list<char> str = {};
		list<char>::iterator iter;
		iter = str.begin();
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '<') {
				if (iter == str.begin())	continue;
				--iter;
			}
			else if (a[i] == '>') {
				if (iter == str.end())	continue;
				++iter;
			}
			else if (a[i] == '-') {
				if (iter == str.begin())	continue;
				--iter;
				iter = str.erase(iter);
			}
			else {
				str.insert(iter,a[i]);
			}

		}
		for (auto c : str) {
			cout << c;
		}
		cout << "\n";
	}
}