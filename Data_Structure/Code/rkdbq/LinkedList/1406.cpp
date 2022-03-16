#include <iostream>
#include <list>
using namespace std;

list<char> str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	cin >> input;
	for (int i{}; i < input.size(); i++) {
		str.push_back(input[i]);
	}
	list<char>::iterator cursor = str.end();
	int M;
	cin >> M;
	for (int i{}; i < M; i++) {
		char command;
		cin >> command;
		if (command == 'L' && cursor != str.begin()) cursor--;
		else if (command == 'D' && cursor != str.end()) cursor++;
		else if (command == 'B' && cursor != str.begin()) {
			cursor--;
			cursor = str.erase(cursor); //erase 함수가 iterator 반환
		}
		else if (command == 'P') {
			char ch;
			cin >> ch;
			str.insert(cursor, ch);
			//cursor++; 해줄 필요 없음, insert 함수가 해주는 듯
		}
		else {
			continue;
		}
	}
	while (!str.empty()) {
		cout << str.front();
		str.pop_front();
	}
}