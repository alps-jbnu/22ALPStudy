#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int i{}; i < T; i++) {
		string input;
		cin >> input;
		list<char> str;
		list<char>::iterator cursor = str.end();
		for (int i{}; i < input.size(); i++) {
			if (input[i] == '<') {
				if (cursor != str.begin()) cursor--;
			}
			else if (input[i] == '>') {
				if (cursor != str.end()) cursor++;
			}
			else if (input[i] == '-') {
				if (cursor != str.begin()) {
					cursor--;
					cursor = str.erase(cursor); //erase 함수가 iterator 반환
				}
			}
			else str.insert(cursor, input[i]);
		}
		while (!str.empty()) {
			cout << str.front();
			str.pop_front();
		}
		cout << "\n";
	}
}