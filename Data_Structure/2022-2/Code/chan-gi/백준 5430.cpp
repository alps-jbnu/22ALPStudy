#include <bits/stdc++.h>

using namespace std;
void ARR(deque<int>& dq);
void Pf(string p, deque<int>& dq);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		ARR(dq);
		Pf(p, dq);
		dq.clear();
	}

	return 0;
}

void ARR(deque<int>& dq) {
	string s;
	cin >> s;
	int a = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == ',') {
			dq.push_back(a);
			a = 0;
		}
		else a = 10 * a + (s[i] - '0');
	}
	if (a) dq.push_back(a);
}

void Pf(string p, deque<int>& dq) {
	int r = 0, ox = 0;
	for (int i = 0; p[i] != '\0'; i++) {
		if (p[i] == 'R') {
			r = 1 - r;
		}
		else {
			if (dq.empty()) {
				ox = 1;
				break;
			}
			if (!r) dq.pop_front();
			else dq.pop_back();
		}
	}
	if (ox) cout << "error\n";
	else {
		if (r) reverse(dq.begin(), dq.end());
		cout << '[';
		for (int i = 0; i < dq.size(); i++)
		{
			cout << dq[i];
			if (i + 1 != dq.size())
				cout << ',';
		}
		cout << "]\n";
	}
}