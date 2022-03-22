#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> de;

void push_front_(int x) {
	de.push_front(x);
}

void push_back_(int x) {
	de.push_back(x);
}

int pop_front_() {
	if (de.empty()) {
		return -1;
	}
	else {
		int num = de.front();
		de.pop_front();
		return num;
	}
}

int pop_back_() {
	if (de.empty()) {
		return -1;
	}
	else {
		int num = de.back();
		de.pop_back();
		return num;
	}
}

int size_() {
	return de.size();
}

int empty_() {
	if (de.empty()) {
		return 1;
	}
	else return 0;
}

int front_() {
	if (de.empty()) {
		return -1;
	}
	else return de.front();
}

int back_() {
	if (de.empty()) {
		return -1;
	}
	else return de.back();
}


int main(void) {
	int N, num;
	string str;
	cin >> N;

	while (N--)
	{
		cin >> str;
		if (str == "push_front")
		{
			cin >> num;
			push_front_(num);
		}
		else if (str == "push_back")
		{
			cin >> num;
			push_back_(num);
		}
		else if (str == "pop_front")
		{
			cout << pop_front_() << "\n";
		}
		else if (str == "pop_back")
		{
			cout << pop_back_() << "\n";
		}
		else if (str == "size")
		{
			cout << size_() << "\n";
		}
		else if (str == "empty")
		{
			cout << empty_() << "\n";
		}
		else if (str == "front")
		{
			cout << front_() << "\n";
		}
		else if (str == "back")
		{
			cout << back_() << "\n";
		}
	}

	return 0;
}