#include<bits/stdc++.h>
using namespace std;


int main() {
	list<char> alph;
	string a;
	int n;
	cin >> a>>n;
	for (int i = 0; i < a.length(); i++) {
		alph.push_back(a[i]);
	}
	list<char>::iterator iter;
	iter = alph.end();
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		if (a == 'L') {
			if (iter == alph.begin())	continue;
			--iter;
		}
		else if (a == 'D') {
			if (iter == alph.end())	continue;
			++iter;
		}
		else if (a == 'B') {
			if (iter == alph.begin())	continue;
			--iter;
			iter=alph.erase(iter);
			
		}
		else if (a == 'P') {
			char b;
			cin >> b;
			alph.insert(iter,b);

		}
	}
	for (auto c: alph) {
		cout << c;
	}
}