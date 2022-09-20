#include<bits/stdc++.h>
using namespace std;

unordered_set<string> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;

	for (int i = 1; i <= word.length(); i++) {
		for (int j = 0; j < word.length(); j++) {
			m.insert(word.substr(j, i));
		}
	}

	cout << m.size();
	return 0;
} 

/*
string 문자열에서 특정 문자를 잘라내는 substr(시작점, 길이)을 활용
*/
