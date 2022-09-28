#include <iostream>
#include <list>
using namespace std;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int repeat;
	list<char> password;
	list<char>::iterator cursor;
	string pw;
	cin >> repeat;
 
	for (int i = 0; i < repeat; i++) {
		cin >> pw;
		password.clear();
		cursor = password.begin();
		for (int j = 0; j < pw.length(); j++) {
			if (pw[j] == '<' && cursor != password.begin()) cursor--;
			else if (pw[j] == '>' && cursor != password.end()) cursor++;
			else if (pw[j] == '-' && cursor != password.begin()) cursor = password.erase(--cursor);
			else if (pw[j] != '<' && pw[j] != '>' && pw[j] != '-') password.insert(cursor, pw[j]);
		}
		
		for (cursor = password.begin(); cursor != password.end(); cursor++) cout << *cursor;
		cout << '\n';
	}
 
	return 0;
}
