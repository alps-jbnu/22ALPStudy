#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int S, E, Q;
unordered_map<string, bool> in;
unordered_map<string, bool> out;
string nickname;
string tString;
int t;
unordered_map<string, bool> ans;

void setTime(int &t) {
	cin >> tString;
	t = (int)(tString[0] - '0') * 1000 + (int)(tString[1] - '0') * 100 + (int)(tString[3] - '0') * 10 + (int)(tString[4] - '0');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	setTime(S);
	setTime(E);
	setTime(Q);

	//if (cin.eof()) return 0;

	while (cin >> tString) {

		if (cin.eof()) break;
		t = (int)(tString[0] - '0')*1000 + (int)(tString[1] - '0')*100 + (int)(tString[3] - '0') * 10 + (int)(tString[4] - '0');
		cin >> nickname;

		if (t <= S) in[nickname] = true;
		else if (t >= E && t <= Q) out[nickname] = true;

		if (in[nickname] && out[nickname]) { ans[nickname] = true; /*cout << nickname<<"\n";*/ }
	}
	cout << ans.size();
	return 0;
}