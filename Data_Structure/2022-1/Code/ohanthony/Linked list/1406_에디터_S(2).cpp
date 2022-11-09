#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;

	list<char> L; // 리스트 선언
	for (int i = 0; i < word.length(); i++) {
		L.push_back(word[i]);
	}

	// list<char>::iterator cursor = L.end();
	auto cursor = L.end(); // 커서를 가리키는 변수선언

	int m;
	cin >> m;

	while (m--) {
		string alpha;
		cin >> alpha;

		if (alpha == "L") {
			if (cursor != L.begin()) {
				cursor--;
			}
		}
		else if (alpha == "D") {
			if (cursor != L.end()) {
				cursor++;
			}
		}
		else if (alpha == "B") {
			if (cursor != L.begin()) {
				cursor--; // 선행으로 왼쪽으로 한칸 이동하고
				cursor = L.erase(cursor);
			}
		}
		else
		{
			char plus;
			cin >> plus;
			L.insert(cursor, plus);
		}
	}

	for (auto i : L) {
		cout << i;
	}

	return 0;
}

