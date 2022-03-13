#include<bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string v;
	cin >> v;	//초기입력
	int n;
	cin >> n;	//갯수입력

	list<char>L(v.begin(),v.end());
	auto cursor = L.end();	//커서가 맨뒤에 있음

	while (n--) {
		char op;
		cin >> op;	//옵션입력

		if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
			
		}
		else if (op == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != L.begin())
				cursor = L.erase(--cursor);
		}
		else if (op == 'P') {
			char a;
			cin >> a;	//추가할 문자입력
			L.insert(cursor, a);
		}
	}
	for (auto c : L)
		cout << c;
	return 0;
}
	