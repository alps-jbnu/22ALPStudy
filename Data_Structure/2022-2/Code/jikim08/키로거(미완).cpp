#include <iostream>
#include <list>
using namespace std;

int main() {

	int n;
	cin >> n;
	for (; n > 0; n--) {
		list<char> L;

		string S;
		cin >> S;

		list<char>::iterator it = L.begin();
		
		for (int i = 0; S[i]; i++) {
			if (S[i] == '<' && it != L.begin()) {
				it--;
			}
			else if (S[i] == '>' && it != L.end()) {
				it++;
			}
			else if (S[i] == '-' && it != L.begin()) {
				it = L.erase(--it);
			}
			else if (S[i] != '<' && S[i] != '>') {
				L.insert(it, S[i]);
			}
		}

		for (list<char>::iterator it = L.begin(); it != L.end(); it++) {
			cout << *it;
		}
		cout << '\n';
	}

	
}
