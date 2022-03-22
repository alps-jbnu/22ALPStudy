#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
	list<int> li;
	auto it = li.begin();

	li.insert(it, 1);
	cout << *it;

}